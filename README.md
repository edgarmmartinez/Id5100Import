# Id5100Import

Convert ID5100a ICF to bin:
    ./icfToBin.py ID5100_Plano.icf > ID5100_Plano.bin

Convert all to text with memory address:
    ./icfToBin.py ID5100_Test.icf | xxd -c 49 -g 1 | awk -F: '{x=strtonum("0x"$1); printf ("%05d: %05x: %s\n",x/49,x,$2);}'

    ./icfToBin.py ID5100_Test.icf | xxd -c 49 -g 1 -b | awk -F: '{x=strtonum("0x"$1); printf ("%05d: %05x: %s\n",x/49,x,$2);}' | less -S

ID-5100a ICF file format:

Text file, binary encoded in hex:


Freqs 0 - 117.999, are not valid
Freqs 118 - 136.999, only AM and AM-N modes are valid, along with TS 8.33k, 25k, and Auto
Freqs 137 - 174, only FM, FM-N, and DV modes are valid, and TS 8.33 and Auto are not selectable
Freqs 174.00001 - 374.9999, are not valid
Freqs 375 - 549.9999, only FM, FM-N, and DV modes are valid, and TS 8.33 and Auto are not selectable

49 bytes per memory record, starting from byte 0
1000 entries of 49 bytes each, one entry for each of 1000 memories
Memory entries are 0-999. Memory offset for each is x * 49
Empty memory slots still have their space allocated, so no "compression" or "packing".
Skip and PSkip settings are not within these 49 bytes

Memory number is determined by position. e.g.
    Ch 0 is at offset 0
    Ch 1 is at 49 (0x31)
    Ch 2 is at 108 (0x62)
    Ch 10 is at 490 (0x01ea)

(0-2) u24 frequency     
unknown:7       Changes may indicate what multiplier to use in frequency field
    0x00: multiplier = 0.005 (only used in FM)
    0x12: multiplier = 0.00625 (only used in FM when freq is XXX.XXX5
    0x24: multiplier = 0.0083333333 (only used in AM)
frequency:17    multiply by 0.005 to get the frequency in MHz
    If whole u24 hex starts with 0x25xxxx, then the multiplier is 0.00625
    If whole u24 hex starts with 0x48xxxx, then multiply freq by 0.00833333
    e.g.
    0x2513d6 -> convert freq field 0x113d6*0.00625 = 441.3375 MHz
    0x483c6c -> convert freq field 0x3c6c * 0.0083333 = 128.900
(3-4) u16 offset        Multiply by "multiplier" used in "frequency" field above to get frequency in MHz
(5-6) u16 toneSqlValue  
tone:6  enums 0 - 49 (67.0 - 254.1)
tsql:6  enums 0 - 49 (67.0 - 254.1)
modulation:4    0 - FM
    1 - FM-N
    3 - AM
    4 - AM-N
    5 - DV
(7) u8 DTCS     enum 0 - 103 (023 - 754)
(8) u8 TSandUnk 
tuningStep:4    0 - 5k
    1 - 6.25k
    2 - 8.33k
    3 - ?
    4 - 10k
    5 - 12.5k
    6 - 15k
    7 - 20k
    8 - 25k
    9 - 30k
    10 - 50k
    11 - ?
    12 - ?
    13 - ?
    14 - Auto
unk:4   
(9) u8 unk      Always 0xe4
(10) u8 toneModelDup    
toneMode:4      0 - OFF
    1 - TONE
    3 - TSQL
    5 - DTCS
    6 - TSQL-R
    7 - DTCS-R
    8 - DTCS(T)
    9 - TONE-T/DTCS-R
    A - DTCS(T)/TSQL-R
    B = TONE-T/TSQL-R
DUP:2   0 - DUP Off
    1 - DUP-
    2 - DUP+
DTCS Polarity:2 0 - Both N
    1 - TN-RR
    2 - TR-RN
    3 - Both R
(11-27) char name[17]   Channel alphanum name, padded with spaces, last char always null 0x00
(28-34) u8 your[7]      "Your"/"UR" (called callsign), 8 text chars, encoded 7 bits each (CQCQCQ), space padded, no NULL
(35-41) u8 RPT1[7]      Repeater 1 callsign, 8 text chars, encoded 7 bits each, space padded, no NULL
(42-48) u8 RPT2[7]      Repeater 2 callsign, 8 text chars, encoded 7 bits each, space padded, no NULL

