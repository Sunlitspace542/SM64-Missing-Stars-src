; Get rids of act selectors (except for Lethal Lava Land and Secret Woods)

.ORG 0x8024bf50    ; hook
J Patch
ADDIU R0, R0, 0x0000

.ORG 0x80406000

Patch:

LUI T0, 0x8033
LH T0, 0xDDF8 (T0)  ; level

ADDIU AT, R0, 0x0016     ; if (Lethal Lava Land)
BEQ T0, AT, HaveSelector
ADDIU R0, R0, 0x0000

ADDIU AT, R0, 0x000A     ; if (TinyHuge Island) [secret woods]
BEQ T0, AT, HaveSelector
ADDIU R0, R0, 0x0000

J  0x8024BF90    ; jump selector
OR V0, R0, R0

HaveSelector:
J 0x8024BF58
ADDIU R0, R0, 0x0000
