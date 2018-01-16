/**
 * @file src/cpdetect/signatures/yara/database/x86/pe/packer/packer_39.cpp
 * @brief Database of signatures.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

const char *x86PePacker_39 =
R"x86_pe_packer(
rule rule_1076_PEiD_Bundle {
	meta:
		tool = "P"
		name = "PEiD-Bundle"
		version = "1.02 - 1.03"
		pattern = "60E89C00000000000000000000000000000036??????2E??????000000000000000000000000000000000000000001000080000000004B65726E656C33322E44"
	strings:
		$1 = { 60 E8 9C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 36 ?? ?? ?? 2E ?? ?? ?? 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 80 00 00 00 00 4B 65 72 6E 65 6C 33 32 2E 44 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1077_PEiD_Bundle {
	meta:
		tool = "P"
		name = "PEiD-Bundle"
		version = "1.02 - 1.04"
		pattern = "60E8??00000000000000000000000000000036??????2E??????000000000000000000000000000000000000000001000080000000004B65726E656C33322E44"
	strings:
		$1 = { 60 E8 ?? 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 36 ?? ?? ?? 2E ?? ?? ?? 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 80 00 00 00 00 4B 65 72 6E 65 6C 33 32 2E 44 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1078_PELock {
	meta:
		tool = "P"
		name = "PELock"
		version = "1.06"
		pattern = "0000000000000000????????????????000000004C6F61644C6962726172794100005669727475616C416C6C6F63004B45"
	strings:
		$1 = { 00 00 00 00 00 00 00 00 ?? ?? ?? ?? ?? ?? ?? ?? 00 00 00 00 4C 6F 61 64 4C 69 62 72 61 72 79 41 00 00 56 69 72 74 75 61 6C 41 6C 6C 6F 63 00 4B 45 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1079_PELock {
	meta:
		tool = "P"
		name = "PELock"
		version = "NT 2.01"
		pattern = "EB03CD20EBEB01EB1EEB01EBEB02CD209CEB03CD"
	strings:
		$1 = { EB 03 CD 20 EB EB 01 EB 1E EB 01 EB EB 02 CD 20 9C EB 03 CD }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1080_PELock {
	meta:
		tool = "P"
		name = "PELock"
		version = "NT 2.02c"
		pattern = "EB02C7851EEB03CD20EBEB01EB9CEB01EBEB02CD"
	strings:
		$1 = { EB 02 C7 85 1E EB 03 CD 20 EB EB 01 EB 9C EB 01 EB EB 02 CD }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1081_PELock {
	meta:
		tool = "P"
		name = "PELock"
		version = "NT 2.03"
		pattern = "EB02C7851EEB03CD20C79CEB0269B160EB02EB01"
	strings:
		$1 = { EB 02 C7 85 1E EB 03 CD 20 C7 9C EB 02 69 B1 60 EB 02 EB 01 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1082_PELock {
	meta:
		tool = "P"
		name = "PELock"
		version = "NT 2.04"
		pattern = "EB??CD??????????CD??????????EB??EB??EB??EB??CD??????????E8????????E9????????50C3"
	strings:
		$1 = { EB ?? CD ?? ?? ?? ?? ?? CD ?? ?? ?? ?? ?? EB ?? EB ?? EB ?? EB ?? CD ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? 50 C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1083_PEMangle {
	meta:
		tool = "P"
		name = "PEMangle"
		pattern = "609CBE????????8BFEB9????????BB44524F4CAD33C3"
	strings:
		$1 = { 60 9C BE ?? ?? ?? ?? 8B FE B9 ?? ?? ?? ?? BB 44 52 4F 4C AD 33 C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1084_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		pattern = "558BEC81EC780500005356BE04010000578D8594FDFFFF5633DB5053FF15????40008D8594FDFFFF56508D8594FDFFFF50FF15????40008B3D??20400053536A03536A018D8594FDFFFF680000008050"
	strings:
		$1 = { 55 8B EC 81 EC 78 05 00 00 53 56 BE 04 01 00 00 57 8D 85 94 FD FF FF 56 33 DB 50 53 FF 15 ?? ?? 40 00 8D 85 94 FD FF FF 56 50 8D 85 94 FD FF FF 50 FF 15 ?? ?? 40 00 8B 3D ?? 20 40 00 53 53 6A 03 53 6A 01 8D 85 94 FD FF FF 68 00 00 00 80 50 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1085_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		pattern = "558BEC81EC7C050000535657BE04010000568D8590FDFFFF33DB5053895DF4FF1538204000568D8590FDFFFF5050FF15342040008B3D3020400053536A03536A0168000000808D8590FDFFFF50FFD783"
	strings:
		$1 = { 55 8B EC 81 EC 7C 05 00 00 53 56 57 BE 04 01 00 00 56 8D 85 90 FD FF FF 33 DB 50 53 89 5D F4 FF 15 38 20 40 00 56 8D 85 90 FD FF FF 50 50 FF 15 34 20 40 00 8B 3D 30 20 40 00 53 53 6A 03 53 6A 01 68 00 00 00 80 8D 85 90 FD FF FF 50 FF D7 83 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1086_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		version = "1.0"
		pattern = "558BEC83C4D05356578D75FC8B442430250000FFFF81384D5A900074072D00100000EBF18945FCE8C8FFFFFF2D0F0500008945F48B068B403C03068B407803068BC88B512003168B5924031E895DF08B591C031E895DEC8B41188BC84985C9725A4133C08BD8C1E30203DA8B3B033E813F4765745075408BDF83C304813B726F634175338BDF83C308813B64647265752683C70C66813F7373"
	strings:
		$1 = { 55 8B EC 83 C4 D0 53 56 57 8D 75 FC 8B 44 24 30 25 00 00 FF FF 81 38 4D 5A 90 00 74 07 2D 00 10 00 00 EB F1 89 45 FC E8 C8 FF FF FF 2D 0F 05 00 00 89 45 F4 8B 06 8B 40 3C 03 06 8B 40 78 03 06 8B C8 8B 51 20 03 16 8B 59 24 03 1E 89 5D F0 8B 59 1C 03 1E 89 5D EC 8B 41 18 8B C8 49 85 C9 72 5A 41 33 C0 8B D8 C1 E3 02 03 DA 8B 3B 03 3E 81 3F 47 65 74 50 75 40 8B DF 83 C3 04 81 3B 72 6F 63 41 75 33 8B DF 83 C3 08 81 3B 64 64 72 65 75 26 83 C7 0C 66 81 3F 73 73 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1087_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		version = "1.0"
		pattern = "609CBE001040008BFEB9????????BB78563412AD33C3ABE2FA9D61E9??????FF"
	strings:
		$1 = { 60 9C BE 00 10 40 00 8B FE B9 ?? ?? ?? ?? BB 78 56 34 12 AD 33 C3 AB E2 FA 9D 61 E9 ?? ?? ?? FF }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1088_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		version = "2.0"
		pattern = "EB250000F7BF000000000000000000001200E8005669727475616C50726F746563740000000000E8000000005D81ED2C1040008DB514104000E833000000898510104000BF000040008BF7037F3C8B4F5451568D85"
	strings:
		$1 = { EB 25 00 00 F7 BF 00 00 00 00 00 00 00 00 00 00 12 00 E8 00 56 69 72 74 75 61 6C 50 72 6F 74 65 63 74 00 00 00 00 00 E8 00 00 00 00 5D 81 ED 2C 10 40 00 8D B5 14 10 40 00 E8 33 00 00 00 89 85 10 10 40 00 BF 00 00 40 00 8B F7 03 7F 3C 8B 4F 54 51 56 8D 85 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1089_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		version = "3.0"
		pattern = "E8000000005D81ED051040008DB5241040008BFEB90F000000BB????????AD33C3E2FA"
	strings:
		$1 = { E8 00 00 00 00 5D 81 ED 05 10 40 00 8D B5 24 10 40 00 8B FE B9 0F 00 00 00 BB ?? ?? ?? ?? AD 33 C3 E2 FA }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1090_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		version = "3.1"
		pattern = "E9??????00F00FC6"
	strings:
		$1 = { E9 ?? ?? ?? 00 F0 0F C6 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1091_PEncrypt {
	meta:
		tool = "P"
		name = "PEncrypt"
		version = "4.0b"
		pattern = "66????006683??00"
	strings:
		$1 = { 66 ?? ?? 00 66 83 ?? 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1092_PEnguinCrypt {
	meta:
		tool = "P"
		name = "PEnguinCrypt"
		version = "1.0"
		pattern = "B893????0055506764FF360000676489260000BD4B484342B804000000CC3C0475049090C39067648F060000585DBB0000400033C933C0"
	strings:
		$1 = { B8 93 ?? ?? 00 55 50 67 64 FF 36 00 00 67 64 89 26 00 00 BD 4B 48 43 42 B8 04 00 00 00 CC 3C 04 75 04 90 90 C3 90 67 64 8F 06 00 00 58 5D BB 00 00 40 00 33 C9 33 C0 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1093_PENightMare {
	meta:
		tool = "P"
		name = "PENightMare"
		version = "1.3"
		pattern = "60E8000000005DB9????????8031154181F9"
	strings:
		$1 = { 60 E8 00 00 00 00 5D B9 ?? ?? ?? ?? 80 31 15 41 81 F9 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1094_PENightMare {
	meta:
		tool = "P"
		name = "PENightMare"
		version = "2 Beta"
		pattern = "60E9????????EF4003A7078F071C375D43A704B92C3A"
	strings:
		$1 = { 60 E9 ?? ?? ?? ?? EF 40 03 A7 07 8F 07 1C 37 5D 43 A7 04 B9 2C 3A }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1095_PEQuake {
	meta:
		tool = "P"
		name = "PEQuake"
		version = "0.06"
		pattern = "E8A5000000"
	strings:
		$1 = { E8 A5 00 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1096_PEShit {
	meta:
		tool = "P"
		name = "PEShit"
		pattern = "B8????????B9????????83F9007E068030??40E2F5E9??????FF"
	strings:
		$1 = { B8 ?? ?? ?? ?? B9 ?? ?? ?? ?? 83 F9 00 7E 06 80 30 ?? 40 E2 F5 E9 ?? ?? ?? FF }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1097_PESpin {
	meta:
		tool = "P"
		name = "PESpin"
		version = "0.1"
		pattern = "EB01??60E8000000008B1C2483C312812BE8B10600FE4BFD822C245CCB46000BE4749E7501????????????????????19770043B7F6C36BB70000F9FFE3C9C20800??????????5D33C941E217EB07??????????????E801000000??5A83EA0BFFE28B??????????8B423C03C289??????????41C1E1078B0C0103CA8B591003DA8B1B89??????????538F85????????BB????????B9A50800008D??????????4F301C39FECBE2F9682D010000598D??????????C00C3902E2FAE802000000FF15????????4F5600BB54130B00D1E32BC3FFE0E801000000"
	strings:
		$1 = { EB 01 ?? 60 E8 00 00 00 00 8B 1C 24 83 C3 12 81 2B E8 B1 06 00 FE 4B FD 82 2C 24 5C CB 46 00 0B E4 74 9E 75 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 19 77 00 43 B7 F6 C3 6B B7 00 00 F9 FF E3 C9 C2 08 00 ?? ?? ?? ?? ?? 5D 33 C9 41 E2 17 EB 07 ?? ?? ?? ?? ?? ?? ?? E8 01 00 00 00 ?? 5A 83 EA 0B FF E2 8B ?? ?? ?? ?? ?? 8B 42 3C 03 C2 89 ?? ?? ?? ?? ?? 41 C1 E1 07 8B 0C 01 03 CA 8B 59 10 03 DA 8B 1B 89 ?? ?? ?? ?? ?? 53 8F 85 ?? ?? ?? ?? BB ?? ?? ?? ?? B9 A5 08 00 00 8D ?? ?? ?? ?? ?? 4F 30 1C 39 FE CB E2 F9 68 2D 01 00 00 59 8D ?? ?? ?? ?? ?? C0 0C 39 02 E2 FA E8 02 00 00 00 FF 15 ?? ?? ?? ?? 4F 56 00 BB 54 13 0B 00 D1 E3 2B C3 FF E0 E8 01 00 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1098_PESpin {
	meta:
		tool = "P"
		name = "PESpin"
		version = "0.3"
		pattern = "EB016860E8000000008B1C2483C312812BE8B10600FE4BFD822C24B7CD46000BE4749E7501C7817304D77AF72F817319770043B7F6C36BB70000F9FFE3C9C20800A3687201FF5D33C941E217EB07EAEB01EBEB0DFFE801000000EA5A83EA0BFFE28B95CB2C40008B423C03C28985D52C400041C1E1078B0C0103CA8B591003DA8B1B899DE92C4000538F85B62B4000BB??000000B9750A00008DBD7E2D40004F301C39FECBE2F9683C010000598DBDB6364000C00C3902E2FAE802000000FF155A8D851F535600BB54130B00D1E32BC3FFE0E80100000068E81A0000008D3428B908000000B8????????2BC983C9150FA3C80F83810000008DB40DDC2C4000"
	strings:
		$1 = { EB 01 68 60 E8 00 00 00 00 8B 1C 24 83 C3 12 81 2B E8 B1 06 00 FE 4B FD 82 2C 24 B7 CD 46 00 0B E4 74 9E 75 01 C7 81 73 04 D7 7A F7 2F 81 73 19 77 00 43 B7 F6 C3 6B B7 00 00 F9 FF E3 C9 C2 08 00 A3 68 72 01 FF 5D 33 C9 41 E2 17 EB 07 EA EB 01 EB EB 0D FF E8 01 00 00 00 EA 5A 83 EA 0B FF E2 8B 95 CB 2C 40 00 8B 42 3C 03 C2 89 85 D5 2C 40 00 41 C1 E1 07 8B 0C 01 03 CA 8B 59 10 03 DA 8B 1B 89 9D E9 2C 40 00 53 8F 85 B6 2B 40 00 BB ?? 00 00 00 B9 75 0A 00 00 8D BD 7E 2D 40 00 4F 30 1C 39 FE CB E2 F9 68 3C 01 00 00 59 8D BD B6 36 40 00 C0 0C 39 02 E2 FA E8 02 00 00 00 FF 15 5A 8D 85 1F 53 56 00 BB 54 13 0B 00 D1 E3 2B C3 FF E0 E8 01 00 00 00 68 E8 1A 00 00 00 8D 34 28 B9 08 00 00 00 B8 ?? ?? ?? ?? 2B C9 83 C9 15 0F A3 C8 0F 83 81 00 00 00 8D B4 0D DC 2C 40 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1099_PESpin {
	meta:
		tool = "P"
		name = "PESpin"
		version = "0.41"
		pattern = "EB01??60E8000000008B1C2483C312812BE8B10600FE4BFD822C2402D246000BE4749E7501????????????????????19770043B7F6C36BB70000F9FFE3C9C20800??????????5D33C941E217EB07??????????????E801000000??5A83EA0BFFE28B??????????8B423C03C289??????????41C1E1078B0C0103CA8B591003DA8B1B89??????????538F??????????BB????????B9????????8D??????????4FEB01AB301C39FECBE2F9EB01??683C010000598D??????????C00C3902E2FAE802000000FF15????????595600BB54130B00D1E32BC3FFE0E801000000??E81A000000"
	strings:
		$1 = { EB 01 ?? 60 E8 00 00 00 00 8B 1C 24 83 C3 12 81 2B E8 B1 06 00 FE 4B FD 82 2C 24 02 D2 46 00 0B E4 74 9E 75 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 19 77 00 43 B7 F6 C3 6B B7 00 00 F9 FF E3 C9 C2 08 00 ?? ?? ?? ?? ?? 5D 33 C9 41 E2 17 EB 07 ?? ?? ?? ?? ?? ?? ?? E8 01 00 00 00 ?? 5A 83 EA 0B FF E2 8B ?? ?? ?? ?? ?? 8B 42 3C 03 C2 89 ?? ?? ?? ?? ?? 41 C1 E1 07 8B 0C 01 03 CA 8B 59 10 03 DA 8B 1B 89 ?? ?? ?? ?? ?? 53 8F ?? ?? ?? ?? ?? BB ?? ?? ?? ?? B9 ?? ?? ?? ?? 8D ?? ?? ?? ?? ?? 4F EB 01 AB 30 1C 39 FE CB E2 F9 EB 01 ?? 68 3C 01 00 00 59 8D ?? ?? ?? ?? ?? C0 0C 39 02 E2 FA E8 02 00 00 00 FF 15 ?? ?? ?? ?? 59 56 00 BB 54 13 0B 00 D1 E3 2B C3 FF E0 E8 01 00 00 00 ?? E8 1A 00 00 00 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1100_PESpin {
	meta:
		tool = "P"
		name = "PESpin"
		version = "0.7"
		pattern = "EB01??60E8000000008B1C2483C312812BE8B10600FE4BFD822C2483D546000BE4749E7501????????????????????19770043B7F6C36BB70000F9FFE3C9C20800??????????5D33C941E217EB07??????????????E801000000??5A83EA0BFFE2EB04??EB0400EBFBFF8B??????????8B423C03C289??????????EB01??41C1E1078B0C0103CAE803000000EB04??EBFB??8304240CC3"
	strings:
		$1 = { EB 01 ?? 60 E8 00 00 00 00 8B 1C 24 83 C3 12 81 2B E8 B1 06 00 FE 4B FD 82 2C 24 83 D5 46 00 0B E4 74 9E 75 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 19 77 00 43 B7 F6 C3 6B B7 00 00 F9 FF E3 C9 C2 08 00 ?? ?? ?? ?? ?? 5D 33 C9 41 E2 17 EB 07 ?? ?? ?? ?? ?? ?? ?? E8 01 00 00 00 ?? 5A 83 EA 0B FF E2 EB 04 ?? EB 04 00 EB FB FF 8B ?? ?? ?? ?? ?? 8B 42 3C 03 C2 89 ?? ?? ?? ?? ?? EB 01 ?? 41 C1 E1 07 8B 0C 01 03 CA E8 03 00 00 00 EB 04 ?? EB FB ?? 83 04 24 0C C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1101_PESpin {
	meta:
		tool = "P"
		name = "PESpin"
		version = "0.b"
		pattern = "EB01??60E8000000008B1C2483C312812BE8B10600FE4BFD822C2472C846000BE4749E7501????????????????????19770043B7F6C36BB70000F9FFE3C9C20800??????????5D33C941E226E801000000??5A33C9????????????8B423C03C289??????????41C1E1078B0C0103CA8B591003DA8B1B????????????8B592403DA8B1B????????????53????????????????????????6A0C5B6A1759300C0302CB4B75F8408D9D418F4E005053812C2401780E00????????????C392EB1568??????????B9??080000????????????4F301C39FECBE2F9681D01000059????????????C00C3902E2FA68????????50016C2404E8BD09000033C00F84C0080000????????????50????????????????????????FFE0C38D642404E8530A0000D7585B51C3F7F332DA????????????????????????812C24A300000058????????????53FFE0"
	strings:
		$1 = { EB 01 ?? 60 E8 00 00 00 00 8B 1C 24 83 C3 12 81 2B E8 B1 06 00 FE 4B FD 82 2C 24 72 C8 46 00 0B E4 74 9E 75 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 19 77 00 43 B7 F6 C3 6B B7 00 00 F9 FF E3 C9 C2 08 00 ?? ?? ?? ?? ?? 5D 33 C9 41 E2 26 E8 01 00 00 00 ?? 5A 33 C9 ?? ?? ?? ?? ?? ?? 8B 42 3C 03 C2 89 ?? ?? ?? ?? ?? 41 C1 E1 07 8B 0C 01 03 CA 8B 59 10 03 DA 8B 1B ?? ?? ?? ?? ?? ?? 8B 59 24 03 DA 8B 1B ?? ?? ?? ?? ?? ?? 53 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 6A 0C 5B 6A 17 59 30 0C 03 02 CB 4B 75 F8 40 8D 9D 41 8F 4E 00 50 53 81 2C 24 01 78 0E 00 ?? ?? ?? ?? ?? ?? C3 92 EB 15 68 ?? ?? ?? ?? ?? B9 ?? 08 00 00 ?? ?? ?? ?? ?? ?? 4F 30 1C 39 FE CB E2 F9 68 1D 01 00 00 59 ?? ?? ?? ?? ?? ?? C0 0C 39 02 E2 FA 68 ?? ?? ?? ?? 50 01 6C 24 04 E8 BD 09 00 00 33 C0 0F 84 C0 08 00 00 ?? ?? ?? ?? ?? ?? 50 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? FF E0 C3 8D 64 24 04 E8 53 0A 00 00 D7 58 5B 51 C3 F7 F3 32 DA ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 81 2C 24 A3 00 00 00 58 ?? ?? ?? ?? ?? ?? 53 FF E0 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
rule rule_1102_PESpin {
	meta:
		tool = "P"
		name = "PESpin"
		version = "1.0"
		pattern = "EB01??60E8000000008B1C2483C312812BE8B10600FE4BFD822C24C8DC46000BE4749E7501????????????????????19770043B7F6C3??????????????C9C20800??????????5D33C941E217EB07??????????????E801000000??5A83EA0BFFE2EB04??EB04??EBFBFF8B??????????8B423C03C289??????????EB02????F97208730EF983042417C3E8040000000FF57311EB06????????????????????????????????????????FF3424C341C1E1078B0C0103CAE803000000EB04????????8304240CC3"
	strings:
		$1 = { EB 01 ?? 60 E8 00 00 00 00 8B 1C 24 83 C3 12 81 2B E8 B1 06 00 FE 4B FD 82 2C 24 C8 DC 46 00 0B E4 74 9E 75 01 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 19 77 00 43 B7 F6 C3 ?? ?? ?? ?? ?? ?? ?? C9 C2 08 00 ?? ?? ?? ?? ?? 5D 33 C9 41 E2 17 EB 07 ?? ?? ?? ?? ?? ?? ?? E8 01 00 00 00 ?? 5A 83 EA 0B FF E2 EB 04 ?? EB 04 ?? EB FB FF 8B ?? ?? ?? ?? ?? 8B 42 3C 03 C2 89 ?? ?? ?? ?? ?? EB 02 ?? ?? F9 72 08 73 0E F9 83 04 24 17 C3 E8 04 00 00 00 0F F5 73 11 EB 06 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? FF 34 24 C3 41 C1 E1 07 8B 0C 01 03 CA E8 03 00 00 00 EB 04 ?? ?? ?? ?? 83 04 24 0C C3 }
	condition:
		for any of them : ( $ at pe.entry_point )
}
)x86_pe_packer";