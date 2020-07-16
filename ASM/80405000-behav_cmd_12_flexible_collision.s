; the collision distance wasn't inplemented in the version used in this hack

# Behavior command 12

12 00 00 [00] [xx xx xx xx]
          |     \-->segmented address for beggining of collision pointer list
          \--> 1 = process collision distance. 0 = specify it manually by '0e 43'



.ORG 0x80400100

ADDIU SP, SP, 0xFFE0
SW RA, 0x0014 (SP)
LUI T6, 0x8036
LW T6, 0x1164 (T6)    # Pointer to current behavior command

LW S0, 0x0000 (T6)
ANDI S0, S0, 0x00FF   # get arg byte.

LW A0, 0x0004 (T6)    # A0 = segmented base address for ROM pointer list

ADDIU T7, R0, 0x0001  # initializes   for { i = 1; i < 100; i++ }  loop
ADDIU AT, R0, 0x0100
 
Loop:                 # to discover what Model ID the object is using
SLL T8, T7, 0x2       # i * 4
LUI T4, 0x8033               
LW T4, 0xDDC4 (T4)    # T4 = Pointer to beggining of Graphic Pointer list (generated from 0x22 command values)
ADDU T6, T4, T8       # T6 = T4 + (i * 4)
LW T4, 0x0000 (T6)    # T4 = value from T6
LUI T9, 0x8036
LW T9, 0x1160 (T9)    # Pointer for RAM Object
LW T9, 0x0014 (T9)    # Load value from 0x14 = Graphic Pointer

BEQ T4, T9, LoadCollision # if ( Obj->0x14 == Graphic Pointer List->(i*4) )
NOP

BNE T7, AT, Loop
ADDIU T7, T7, 0x0001   # i++;
 
BEQ R0, R0, End
NOP

LoadCollision:
SLL T9, T7, 0x1      # i * 2
ADDU T8, T8, T9      # T8 = (i * 4) + (i *2)
JAL 0x80277F50       # segmented_to_virtual (convert A0 [already set] into RAM pointer)
SW T8, 0x001C (SP)   # store  T8 in stack because the function above uses it

LW T8, 0x001C (SP)   # restore   
ADDU T6, V0, T8      # V0 = virtual memory value of A0. Adds (i * 4 + i * 2) to get the right collision pointer.
LW A0, 0x0000 (T6)   # A0 = load segmented collision pointer and convert it

JAL 0x80277F50
SW T6, 0x001C (SP)   # store

LUI T8, 0x8036
LW T8, 0x1160 (T8)   # Get RAM obect pointer again
SW V0, 0x0218 (T8)   # store final virtual memory collision pointer into offset 0x218.

LW T6, 0x001C (SP)   # restore pointer to collision

LW A3, 0x0004 (T6)   # read collision distance

LUI T9, 0xFFFF
ORI T9, T9, 0x0000

AND A3, A3, T9       # clear 4 last bytes
SRL A3, A3, 0x16     # >> 16

BEQ A3, R0, End      # if arg3 == 0 skip (default value will be loaded);
NOP

BEQ S0, R0, End      # if process_bytes == 0 skip;
NOP

LoadCollisionDistance: 
MTC1 A3, F4
NOP
CVT.S.W f6, f4       # convert signed int to float
SWC1 F6, 0x0194 (T8) # store float into obj->0x194

End:
LUI T9, 0x8036
LW T9, 0x1164 (T9)
ADDIU T0, T9, 0x0008  #  current behavior position + 8
LUI AT, 0x8036
SW T0, 0x1164 (AT)
LW RA, 0x0014 (SP)
JR RA
ADDIU SP, SP, 0x0020 