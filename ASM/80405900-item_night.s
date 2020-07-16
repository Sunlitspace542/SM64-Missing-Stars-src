; Disables certain itens during day 
; called once from behavior


.ORG 0x80405900

ADDIU SP, SP, 0xFFE8 
SW RA, 0x0014 (SP)

LUI T5, 0x8040
ORI T5, T5, 0x0004
LB T5, 0x0000 (T5)       ; current day-night cycle (0x01 to 0x13)

SLTIU T5, T5, 0x0009     ; if == Night
BEQ T5, R0, End
ADDIU R0, R0, 0x0000

Day:

LUI A0, 0x8036
LW A0, 0x1160 (A0)
JAL 0x802a0568           ; Deactive object
NOP

End:
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018
