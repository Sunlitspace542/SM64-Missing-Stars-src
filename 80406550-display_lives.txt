; New Display Lives (Mario or Luigi)

.ORG 0x802E3DB0     ; hook

JAL 0x80406550
NOP

.ORG 0x80406550

ADDIU SP, SP, 0xFFE8
SW RA, 0x0014 (SP)


ADDIU A0, R0, 0x0016
ADDIU A1, R0, 0x00D1

LUI AT, 0x8040
ORI AT, AT, 0x0001       ; Mario/Luigi byte
LB AT, 0x0000 (AT) 
BNE R0, AT, Luigi
ADDIU R0, R0, 0x0000

Mario:

LUI A2, 0x8040
JAL 0x802d6554           ; PrintStr function
ADDIU A2, A2, 0x6540
BEQ R0,R0, Normal
ADDIU R0, R0, 0x0000

Luigi:

LUI A2, 0x8040
JAL 0x802d6554           ; PrintStr function
ADDIU A2, A2, 0x654C

Normal:

LUI A2, 0x8034
ADDIU A2, A2, 0x8384
ADDIU A0, R0, 0x0026
JAL 0x802d6554           ; PrintStr function
ADDIU A1, R0, 0x00D1
LUI A2, 0x8034
LUI A3, 0x8034
LH A3, 0xB260 (A3)
ADDIU A2, A2, 0x8388
ADDIU A0, R0, 0x0036
JAL 0x802d62d8           ; PrintInt function
ADDIU A1, R0, 0x00D1

LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018
