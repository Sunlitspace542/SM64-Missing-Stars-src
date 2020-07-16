; spawn star from Koopa and disables object

.org 0x802FC4D0

ADDIU A2, A2, 0x080c
LW A0, 0x1160 (A0)
JAL 0x8029EDCC           ; spawn function (obj *, model id, behavior)
ADDIU A1, R0, 0x007a     ; star

.ORG 0x802fc4f8

J Koopa
ADDIU R0, R0, 0x0000

Back:
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018

.ORG 0x80406700

Koopa:
LUI A0, 0x8036
JAL 0x802a0568           ; Deactive object
LW A0, 0x1160 (A0)

LUI A0, 0x8036
LUI A2, 0x1300
ADDIU A2, A2, 0x57DC     ; creates new talking yoshi
LW A0, 0x1160 (A0)
JAL 0x8029EDCC           ; spawn function (obj *, model id, behavior)
ADDIU A1, R0, 0x0055

J Back
