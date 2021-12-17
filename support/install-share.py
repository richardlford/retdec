#!/usr/bin/env python3

"""
Get RetDec share directory.
"""

import sys
import hashlib
import os
import shutil
import tarfile
import urllib.request

def cleanup(support_dir):
    shutil.rmtree(support_dir, ignore_errors=True)


def get_args(argv):
    if len(argv) != 5:
        print('ERROR: Unexpected number of arguments.')
        print('       Expecting tuple: (install path, URL, SHA256, version).')
        sys.exit(1)
    else:
        return (argv[1], argv[2], argv[3], argv[4])


def main():
    install_path, arch_url, sha256hash_ref, version = get_args(sys.argv)
    support_dir = os.path.join(install_path, 'share', 'retdec', 'support')
    arch_path = os.path.join(support_dir, 'retdec-support.tar.xz')

    # Share directory exists.
    if os.path.exists(support_dir):
        version_path = os.path.join(support_dir, 'version.txt')
        if os.path.isfile(version_path):
            with open(version_path) as version_file:
                version_from_file = version_file.read().split('\n')[0]

            if version == version_from_file:
                print('-- Up-to-date: %s (version is OK)' % support_dir)
                sys.exit(0)
            else:
                print('version is not as expected -> replace with the expected version')
        cleanup(support_dir)

    # Make sure destination directory exists.
    os.makedirs(support_dir, exist_ok=True)

    # Download archive
    try:
        urllib.request.urlretrieve(arch_url, arch_path)
    except (urllib.request.HTTPError, urllib.request.URLError) as ex:
        print('ERROR: download failed:', ex)
        cleanup(support_dir)
        sys.exit(1)

    # Compute hash of the downloaded archive.
    print('Verifying archive\'s checksum ...')
    sha256 = hashlib.sha256()
    with open(arch_path, 'rb') as f:
        try:
            sha256.update(f.read())
        except IOError as ex:
            print('ERROR: failed to compute the SHA-256 hash of the archive:', ex)
            cleanup(support_dir)
            sys.exit(1)
    sha256hash = sha256.hexdigest()

    # Check that hash is ok.
    if sha256hash != sha256hash_ref:
        print('ERROR: downloaded archive is invalid (SHA-256 hash check failed)')
        cleanup(support_dir)
        sys.exit(1)

    # Unpack archive.
    print('Unpacking archive ...')
    with tarfile.open(arch_path) as tar:
        try:
            mems = [m for m in tar.getmembers() if m.name.startswith("generic/yara_patterns")]
            tar.extractall(support_dir, mems)
        except tarfile.ExtractError as ex:
            print('ERROR: failed to unpack the archive', ex)
            cleanup(support_dir)
            sys.exit(1)

    # Remove archive.
    os.remove(arch_path)

    print('RetDec support directory downloaded OK')
    sys.exit(0)


if __name__ == "__main__":
    main()
