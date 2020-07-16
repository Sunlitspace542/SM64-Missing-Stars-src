;  Creates power star if stars > 25 

;; UNUSED because of new bowser's fight


.ORG 0x80405b50

ADDIU SP, SP, 0xFFE8 
SW RA, 0x0014 (SP)

ADDIU V0, R0, 0x0001
LUI AT, 0x8040
LB AT, 0x0003 (AT)
BEQ AT, V0, End
ADDIU R0, R0, 0x0000

LUI V0, 0x8034
LH V0, 0xB21A (V0)

SLTIU V0, V0, 0x001c    ; number of stars required (28)

BEQ V0, R0, CreateStar
ADDIU R0, R0, 0x0000

End:
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0018


CreateStar:
LUI A0, 0x8036
LUI A2, 0x1300
ADDIU A2, A2, 0x1714
LW A0, 0x1160 (A0)
JAL 0x8029EDCC           ; spawn function (obj *, model id, behavior)
ADDIU A1, R0, 0x007A

BEQ R0, R0, End
ADDIU R0, R0, 0x0000

