.org 0x802E3DE0

JAL 0x80406200
ADDIU R0, R0, 0x0000


.ORG 0x80406200


802E380C: ADDIU SP, SP, 0xFFE0
802E3810: SW RA, 0x0014 (SP)
802E3814: SB R0, 0x001F (SP)
802E3818: LUI T6, 0x8033
802E381C: LB T6, 0x16D4 (T6)
802E3820: ADDIU AT, R0, 0x0001
802E3824: BNE T6, AT, 0x802E3848
802E3828: NOP
802E382C: LUI T7, 0x8033
802E3830: LW T7, 0xD5D4 (T7)
802E3834: ANDI T8, T7, 0x0008
802E3838: BEQ T8, R0, 0x802E3848
802E383C: NOP
802E3840: BEQ R0, R0, 0x802E38D4
802E3844: NOP
802E3848: LUI T9, 0x8034
802E384C: LH T9, 0xB264 (T9)
802E3850: SLTI AT, T9, 0x0064
802E3854: BEQ AT, R0, 0x802E3864
802E3858: NOP
802E385C: ADDIU T0, R0, 0x0001
802E3860: SB T0, 0x001F (SP)
802E3864: LUI A2, 0x8034
802E3868: ADDIU A2, A2, 0x8398
802E386C: ADDIU A0, R0, 0x00F2
802E3870: JAL 0x802d6554           ; PrintStr function
802E3874: ADDIU A1, R0, 0x00D1
802E3878: LB T1, 0x001F (SP)
802E387C: ADDIU AT, R0, 0x0001
802E3880: BNE T1, AT, 0x802E389C
802E3884: NOP
802E3888: LUI A2, 0x8034
802E388C: ADDIU A2, A2, 0x839C
802E3890: ADDIU A0, R0, 0x0102
802E3894: JAL 0x802d6554           ; PrintStr function
802E3898: ADDIU A1, R0, 0x00D1
802E389C: LB A0, 0x001F (SP)
802E38A0: LUI A2, 0x8034
802E38A4: LUI A3, 0x8034
802E38A8: SLL T2, A0, 0x3
802E38AC: SUBU T2, T2, A0
802E38B0: SLL T2, T2, 0x1
802E38B4: OR A0, T2, R0
802E38B8: ADDIU A0, A0, 0x0102
802E38BC: LH A3, 0xB264 (A3)
802E38C0: ADDIU A2, A2, 0x83A0
802E38C4: JAL 0x802d62d8           ; PrintInt function
802E38C8: ADDIU A1, R0, 0x00D1
802E38CC: BEQ R0, R0, 0x802E38D4
802E38D0: NOP
802E38D4: LW RA, 0x0014 (SP)
802E38D8: ADDIU SP, SP, 0x0020
802E38DC: JR RA
802E38E0: NOP
