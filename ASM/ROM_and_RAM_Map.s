ROM Map:

0x11B0000 : Behavior Bank Start
0x11A5000 : Custom ASM Block Start  (mapped to 0x80405000)

Levels:

Main City:

0x1200000 : Main City (Bob-omb)
0x1210000 : Bank 0x0B

0x1230000 - 3000 : Area 1 (Whomp)
0x1240000 : Bank 0x0B

0x1250000 : Area 2 [house 2] (cool cool mountain)
0x1260000 : Bank 0x0B

0x1270000 : Inside House [peach slide]
0x1280000 : Bank 0x0B

0x1290000 : Outside City [jolly roger bay]
0x12A0000 : Bank 0x0B

0x12c0000 : Secret Woods [bob-omb]
0x12d0000 : Bank 0x0b
0x12d6510 : Texture Bank

0x1300000 : Metal Cap course [tall-tall mountain]
0x1310000 : Bank 0x0B
0x1320000 : Textures

0x1320000 : Underground area (Hazy maze)

0x1340000 : Bowser Battle [bowser fight 3]

0x11D0000 : Volcano level [lethal lava land]



-------
RAM MAP (outdated)
-------

0x80384E04: Main loader function (executed before the script interpreter starts)

0x80400001: Mario/Luigi Byte

0x80400004: Current Day/Night cycle

0x80400003: Final Star Byte

0x80405000 - 0x8040FFF0 : Custom ASM Block (check /src directory)