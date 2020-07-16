; force arguments for night/day backgrounds

.ORG 0x8037de94      ; 0xfac14

ADDIU SP, SP, 0xFFD8
SW RA, 0x001C (SP)
LUI T6, 0x8039
LW T6, 0xBD80 (T6)

LUI A0, 0x8039
LW A0, 0xBCA0 (A0)

LUI T8, 0x8033
LH T8, 0xDDF8 (T8)

LH A2, 0x0002 (T6)     ; argument

ADDIU AT, R0, 0x0016   ; if (Lethal Lava Land) skip;
BEQ T8, AT, Normal
ADDIU R0, R0, 0x0000

ADDIU AT, R0, 0x0022   ; if (BowserBattle3) skip;
BEQ T8, AT, Normal
ADDIU R0, R0, 0x0000


LUI T5, 0x8040
ORI T5, T5, 0x0004
LB T8, 0x0000 (T5)      ;   current day-night cycle (0x01 to 0x13)
SLTIU T5, T8, 0x0009    ;   if status > 9 (=night)
BEQ T5, R0, Night
ADDIU R0, R0, 0x0000

Day:
BEQ R0, R0, Normal
ADDIU R0, R0, 0x0000

Night:
ADDIU A2, R0, 0X0006    ; night patch
BEQ R0, R0, End
ADDIU R0, R0, 0x0000

Normal:
LH A2, 0x0002 (T6)      ; argument

End:
LW A3, 0x0004 (T6)
SW R0, 0x0010 (SP)
JAL 0x8037BECC
OR A1, R0, R0
SW V0, 0x0024 (SP)
JAL 0x8037CC74
LW A0, 0x0024 (SP)
LUI T7, 0x8039
LW T7, 0xBD80 (T7)
LUI AT, 0x8039
ADDIU T8, T7, 0x0008
SW T8, 0xBD80 (AT)

LW RA, 0x001C (SP)
ADDIU SP, SP, 0x0028
JR RA
ADDIU r0, r0, 0x0000
