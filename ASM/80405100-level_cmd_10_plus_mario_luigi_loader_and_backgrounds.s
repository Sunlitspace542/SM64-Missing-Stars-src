; extended memory segment loader plus Mario/Luigi and Day/Night conditionals

.ORG 0x80405100

ADDIU SP, SP, 0xFFE8
SW RA, 0x0014 (SP)
LUI T6, 0x8039
LW T6, 0xBE28 (T6) 


LBU A3, 0x0003 (T6)
ADDIU AT, R0, 0x66
BEQ A3, AT, MarioLuigi
ADDIU R0, R0, 0x0000

ADDIU AT, R0, 0x68
BEQ A3, AT, Day_Night
ADDIU R0, R0, 0x0000



RegularLoader:

LW A0, 0x0004 (T6)
LW A1, 0x0008 (T6)
JAL 0x80278504
LW A2, 0x000C (T6)
LUI T6, 0x8039
LW T6, 0xBE28 (T6)
LW A0, 0x0004 (T6)
LUI T7, 0x8000
XOR A0, A0, T7
LBU A3, 0x0003 (T6)
SLL A3, A3, 0x2
LUI T4, 0x8033
ORI T4, T4, 0xB400
ADDU T4, T4, A3
SW A0, 0x0000 (T4)
LUI T7, 0x8039
LW T7, 0xBE28 (T7)
ADDIU T9, T7, 0x0010
LUI AT, 0x8039
SW T9, 0xBE28 (AT)
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018




MarioLuigi:

LUI AT, 0x8040
ORI AT, AT, 0x0001  ; Mario/Luigi Bite  (0 = Mario, 1 = Luigi)
LB AT, 0x0000 (AT)
BNE AT, R0, Luigi    ; if not 0, load Luigi
ADDIU R0, R0, 0x0000 

Mario:

LUI A0, 0x8070
ORI A0, A0, 0x0000
LUI A1, 0x0082
ORI A1, A1, 0x3B64
LUI A2, 0x0085
JAL 0x80278504
ORI A2, A2, 0x8EDC

LUI T4, 0x8033
ORI T4, T4, 0xB410 ; segment 4
LUI A0, 0x0070
ORI A0, A0, 0x0000
SW A0, 0x0000 (T4)

LUI A0, 0x8077
ORI A0, A0, 0x0000
LUI A1, 0x0012
ORI A1, A1, 0x79B0
LUI A2, 0x0012
JAL 0x80278504
ORI A2, A2, 0xA7E0

LUI T4, 0x8033
ORI T4, T4, 0xB45C ; segment ;17
LUI A0, 0x0077
ORI A0, A0, 0x0000
SW A0, 0x0000 (T4)

LUI T7, 0x8039
LW T7, 0xBE28 (T7)
ADDIU T9, T7, 0x000C
LUI AT, 0x8039
SW T9, 0xBE28 (AT)
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018

Luigi:

LUI A0, 0x8070
ORI A0, A0, 0x0000
LUI A1, 0x0160
ORI A1, A1, 0x0000
LUI A2, 0x163
JAL 0x80278504
ORI A2, A2, 0x5378

LUI T4, 0x8033
ORI T4, T4, 0xB410 ; segment 4
LUI A0, 0x0070
ORI A0, A0, 0x0000
SW A0, 0x0000 (T4)

LUI A0, 0x8077
ORI A0, A0, 0x0000
LUI A1, 0x0164
ORI A1, A1, 0x0000
LUI A2, 0x164
JAL 0x80278504
ORI A2, A2, 0x2E2C

LUI T4, 0x8033
ORI T4, T4, 0xB45C ; segment ;17
LUI A0, 0x0077
ORI A0, A0, 0x0000
SW A0, 0x0000 (T4)

LUI T7, 0x8039
LW T7, 0xBE28 (T7)
ADDIU T9, T7, 0x000C
LUI AT, 0x8039
SW T9, 0xBE28 (AT)
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018

Day_Night:

LUI T5, 0x8040
ORI T5, T5, 0x0004
LB T5, 0x0000 (T5)     

SLTIU T5, T5, 0x0009
BEQ T5, R0, SetNight


SetDay:

LUI A0, 0x8060
ORI A0, A0, 0x0000
LUI A1, 0x00C1
ORI A1, A1, 0x2E95
LUI A2, 0x00C3
JAL 0x80278504
ORI A2, A2, 0x2FD5

LUI T4, 0x8033
ORI T4, T4, 0xB428   ; segment 0x0A
LUI A0, 0x0060
ORI A0, A0, 0x0000
SW A0, 0x0000 (T4)

LUI T7, 0x8039
LW T7, 0xBE28 (T7)
ADDIU T9, T7, 0x000C
LUI AT, 0x8039
SW T9, 0xBE28 (AT)
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018



SetNight:

LUI A0, 0x8060
ORI A0, A0, 0x0000
LUI A1, 0x00C3
ORI A1, A1, 0xAFD5
LUI A2, 0x00C4
JAL 0x80278504
ORI A2, A2, 0xF915

LUI T4, 0x8033
ORI T4, T4, 0xB428   ; segment 0x0A
LUI A0, 0x0060
ORI A0, A0, 0x0000
SW A0, 0x0000 (T4)

LUI T7, 0x8039
LW T7, 0xBE28 (T7)
ADDIU T9, T7, 0x000C
LUI AT, 0x8039
SW T9, 0xBE28 (AT)
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018
