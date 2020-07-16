; used in the new scaling behavior (0x5730)
; called from behavior (0x24 Param 1 = scaling * 4)

ADDIU SP, SP, 0xFFE0
SW RA, 0x0014 (SP)

LUI T3, 0x8036
LW T3, 0x1160 (T3)
LW T3, 0x0188 (T3)     ; reads param 1 (scaling factor)

SRL T3, T3, 0x18       ; isolates byte
SLL T3, T3, 0x02       ; (scaling * 4)

BEQ T3, R0, End
ADDIU R0, R0, 0x0000

LUI AT, 0x42C8
MTC1 AT, F8
MTC1 T3, F4            ; T3 = scaling factor (Param1)
ADDIU R0, R0, 0x0000
CVT.S.W F6, F4         ; convert to floating point
JAL 0x8029F430         ; scaling function
DIV.S F12, F6, F8      ; F12 = scaling factor [float]

End:
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0020
