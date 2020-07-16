; Day-Night Cycle function (called from Mario Behavior)
; increments time counter

.ORG 0x80405500

LUI T5, 0x8040
ORI T5, T5, 0x0004
LB T5, 0x0000 (T5)     ; current day-night cycle
ADDIU AT, R0, 0x0010

BEQ AT, T5, ResetCycle 
ADDIU R0, R0, 0x0000

ADDIU T5, T5, 0x0002   ; t5 = time + 1
LUI AT, 0x8040
SB T5, 0x0004 (AT)
JR RA
ADDIU R0, R0, 0x0000

ResetCycle:
LUI T5, 0x8040
ADDIU AT, R0, 0x0000
SB AT, 0x0004 (T5)

JR RA
ADDIU R0, R0, 0x0000