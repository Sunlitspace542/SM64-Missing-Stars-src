.ORG 802A7A84     ; rewritten for more flexibility on x,y,z values

BEQ       $zero,$v0,0x802A7B0C
LUI       $at,0x0000         ; replace with float x,y,z values
ORI       $at,$at,0000  
MTC1      $at,F12
LUI       $a2,0x0000   
ORI       $a2,$a2,0x0000
LUI       $at,0x0000   
ORI       $at,$at,0x0000
MTC1      $at,F14
JAL       0x002A5588
LUI       $a3,0x4348
LUI       $t7,0x8036
LW        $t7,0x1160($t7)
ADDIU     $t6,$zero,0x0008
SW        $t6,0x014C($t7)


0x62A84 in ROM