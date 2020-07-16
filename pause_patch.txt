; patch so that the "exit level" option is not shown when on Main Area, which leads to stack corruption

.ORG 0x802dcb60

J Patch
ADDIU R0, R0, 0x0000

.ORG 0x80406a00
Patch:

LUI T0, 0x8034
ADDIU T0, T0, 0xB170
LW T1, 0x000C (T0)
LUI AT, 0x0800            ; check for movement (to trigger pause)
AND T2, T1, AT
BEQ T2, R0, DontShowExit
ADDIU R0, R0, 0x0000

LUI T2, 0x8033
LH T2, 0xDDF8 (T2)       ; reads current level ID (these three leves all led to the main town area)
ADDIU AT, R0, 0x0009     ; Bob-omb
BEQ AT, T2, DontShowExit
ADDIU R0, R0, 0x0000

ADDIU AT, R0, 0x0006     ; Inside Castle
BEQ AT, T2, DontShowExit
ADDIU R0, R0, 0x0000

ADDIU AT, R0, 0x0010     ; Castle grounds
BEQ AT, T2, DontShowExit
ADDIU R0, R0, 0x0000

ShowExit:
J 0x802DCB7C
ADDIU R0, R0, 0x0000

DontShowExit:
J 0x802DCB94
ADDIU R0, R0, 0x0000