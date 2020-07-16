; King bob-omb triple speed

; UNUSED because this function is also used by Goombas, Koopa-the-Quick and others
; Assemble it for a cool gameshark code :).

.ORG 0x802A07F8      ; x, z "speed"   @ 0x5B7F8

LUI AT, 0x8036
LW AT, 0x1160 (AT)
LWC1 F4, 0x00AC (AT)
LWC1 F6, 0x00A0 (AT)
ADD.S F8, F4, F6      ; x_pos += 0x_ac
ADD.S F8, F8, F4      ; x_pos += 0x_ac
ADD.S F8, F8, F4      ; x_pos += 0x_ac
SWC1 F8, 0x0030 (SP)
LWC1 F10, 0x00B4 (AT)
LWC1 F16, 0x00A8 (AT)
ADD.S F18, F10, F16   ; x_pos += 0xb4
ADD.S F18, F18, F10   ; x_pos += 0xb4
ADD.S F18, F18, F10   ; x_pos += 0xb4
SWC1 F18, 0x002C (SP)
LWC1 F12, 0x0030 (SP)
LW A2, 0x002C (SP)
ADDIU A3, SP, 0x0034
JAL 0x80381900
LWC1 F14, 0x00A4 (AT)
