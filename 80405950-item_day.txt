;  Disables certain itens during night
; called once from behavior


.ORG 0x80405950

ADDIU SP, SP, 0xFFE8 
SW RA, 0x0014 (SP)

LUI T5, 0x8040
ORI T5, T5, 0x0004
LB T5, 0x0000 (T5)     ;   current day-night cycle (0x01 to 0x13)

SLTIU T5, T5, 0x0009   ; if == Night
BEQ T5, R0, Night
addiu r0, r0,0x0000

Day:

BEQ R0, R0, End
addiu r0, r0,0x0000

Night:
LUI A0, 0x8036
LW A0, 0x1160 (A0)
JAL 0x802a0568   ; Deactive object
addiu r0, r0,0x0000

End:
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018
