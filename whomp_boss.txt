.ORG 0x802C7798

J Patch
ADDIU R0, R0, 0x0000

.ORG 0x80409000

Patch:
LUI T9, 0x8036
LW T9, 0x1160 (T9)
ADDIU T8, R0, 0x000A
SW T8, 0x0150 (T9)

LUI A0, 0x8036
LUI A2, 0x1300
ADDIU A2, A2, 0x07DC
LW A0, 0x1160 (A0)
JAL 0x8029EDCC           ; spawn function (obj *, model id, behavior)
ADDIU A1, R0, 0x008E

J 0x802C7840
ADDIU R0, R0, 0x0000



802B6614 --> spawn function for Second Bowser Battle (key)