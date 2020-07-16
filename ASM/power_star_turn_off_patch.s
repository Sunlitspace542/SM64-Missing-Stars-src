; hack unused due to new ending
; Hook

.ORG 0x8024A228

J 0x80405C00             ; hook in credits
ADDIU R0, R0, 0x0000

.ORG 0x80405C00

ADDIU AT, R0, 0x0001
LUI V0, 0x8040
SB AT, 0x0003 (V0)       ; turn on this flag so that the power star won't be spawned anymore

ADDIU T7, R0, 0x00FA
SW T7, 0x002C (SP)
J 0x8024A248
ADDIU R0, R0, 0x0000