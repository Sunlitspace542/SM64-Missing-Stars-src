/*  Mario 64 header file v0.1 by messiaen. 
**
**  The information contained in this file is a compilation from many sources, 
**  especially Cellar Dweller's, Nagra's, Yoshielectron's notes along with 
**  some original research by me. This is to be used with the mips-gcc "N64"
**  Toolchain set up by ZZT32. The makefile will also convert the binary output
**  to a Nemu64 code.
**
**  You can a tutorial on setting up the N64 Toolchain on Windows
**  at http://code.google.com/p/gzrt/wiki/Nintendo64ToolchainSetup
**
**  If you are using an *nix environment, check this Wiki for info about the
**  appropriate MIPS-R4300i binutils:
**
**  http://en.wikibooks.org/wiki/N64_Programming
**
**  You can contact me at the Jul SM64 Hacking forum @ http://jul.rustedlogic.net/
*/  

/* Constants - struct pointers */

#define M64_CURR_OBJ_PTR            0x80361160
#define M64_FIRST_OBJ_STRUCT        0x8033D488   /* Pointer to the first object (out of 240) in the circular linked list */
#define M64_MARIO_OBJ_PTR           0x8033B170   /* read from 0x8032d93c */

/* Constants - misc pointers */

#define M64_DISPLAY_STATS_FLAGS     0x8033b26a
#define M64_SEGMENT_TABLE           0x8033b400
#define M64_CURRENT_LEVEL_ID        0x8033ddf8

/* Function Pointers (old, addesses are now on the linker script). */

#define M64_PRINT_XY_FUNC           0x802d66c0 
#define M64_PRINT_INT_FUNC          0x802d62d8           
#define M64_SPAWN_FUNC              0x8029edcc
#define M64_SCALE_FUNC              0x8029f430
#define M64_DMA_COPY_FUNC           0x80278504
#define M64_EXPLODE_OBJECT_FUNC     0x802e6af8
#define M64_SHAKE_SCREEN            0x802a50fc
#define M64_SET_SOUND_FUNC          0x8031eb00
#define M64_CREATE_MESSAGE_FUNC     0x802a4be4
#define M64_CREATE_TEXT_FUNC        0x802d8d08
#define M64_SEGMENTED_TO_VIRTUAL    0x80277f50
#define M64_DEACTIVE_OBJECT_FUNC    0x802a0568

/* Function prototypes (check out linker script for addresses) */

extern void PrintXY(u16 x, u16 y, char* text);
extern void ExplodeObject(u32 obj_ptr);
extern int ShakeScreen(u32 argument);
extern int DeactivateObject(u32 obj_pointer);
extern int SpawnObj(u32 obj_pointer, u16 model_id, u32 behavior);   /* obj_pointer = always M64_CURR_OBJ_PTR -> returrns pointer for spawned object */
extern int CreateStar(float x, float y, float z);
extern void DmaCopy(u32 dst, u32 bottom, u32 top);
extern void CreateTextBox(u16 msg_ID);
extern void PlaySound(u32 argument);
extern int  StopMario(u16 arg);  /* 1 = stop mario  2 = do nothing??  (needs to be tested more)*/ 
extern int SegmentedToVirtual(u32 segmented_pointer);   /* returns RAM pointer of a segmented address*/
extern int PrinText(u32 x_pos, char *text, u32 fade); /* used in Credits. a2 = a float value ? */

struct mario_obj                    /* 8033b170 */
{
    u32    status;
    u32    flags;                   /* cap & other flags */
    u32    _0x08;
    u32    action;                  /* see Romanian Girl list */
    u32    previous_action;         /* 0x10 */
    u32    _0x14;
    u16    _0x18;
    u16    _0x1a;
    u32    _0x1c;    
    float  _0x20;                   /* 0x20 */
    u16    _0x26;
    s16    hitstun;                 /* hitstun counter (how long Mario will stays invencible after getting hit */
    u32    _0x28;
    u32    _0x2c;    
    u32    _0x30;                   /* 0x30 */
    u32    _0x34;
    u32    _0x38;
    float  x_pos;                   /* re-check */
    float  y_pos;                   /* 0x40 */
    float  z_pos;                   /* re-check */
    u32    _0x48;
    u32    _0x4c;   
    u32    _0x50;                   /* 0x50 */
    u32    _0x54;
    u32    _0x58;
    u32    _0x5c;    
    u32    _0x60;                   /* 0x60 */
    u32    _0x64;
    u32    _0x68_ptr;
    float  _0x6c;    
    float  _0x70;                   /* 0x70 - distance from ground Y ? (recheck) */
    u32    _0x74;                   
    u32    _0x78;
    u32    _0x7c;    
    u32    _0x80;                   /* 0x80 */
    u32    _0x84;
    u32    Mario_obj_ptr;
    u32    _0x8c_ptr;    
    u32    _0x90_ptr;               /* 0x90 */
    u32    _camera_struct_ptr;      /* not 100% sure about this one */
    u32    _0x98_ptr;
    u32    _Pad_struct_ptr;         /* this should be used for reading controller input  */
    u32    _0xa0_ptr;               /* 0xa0 */
    u32    _0xa4;
    s16    coins;
    s16    stars;
    s16    lifes;
    s16    power;
    u32    _0xb0;                   /* 0xb0 */
    u32    _0xb4;
    u32    _0xb8;
    float  _0xbc;    
    float  _0xc0;                   /* 0xc0 */     
};


/* Mario actions (Thanks to RomanianGirl for this list)

0x0C400201: Normal
0x0C400202: Pat back, yawn tired, going to sleep
0x0C000203: Sleeping, laying on back
0x0C000204: Wake up (verify)
0x0C400205: Weak Mario
0x0C40020B: Cold Mario
0x0002033A: Stuck in snow (Top half in snow)
0x0002033C: Stuck in snow (bottom half in snow)
0x0C008220: Duck
0x04008448: Crawl
0x0C008224: Getting up
0x08000206: carry small (?)
0x08000207: pick up thing
0x00000383: Pick up thing
0x08000208: Carry large thing
0x80000589: Throw large thing
0x00000387: Set thing (penguin) down gentle
0x0000132F: Open door with star
0x00001300: In painting (?)
0x00001325: Enter level (?)
0x00001904: Get star
0x00001302: Peace sign after star
0x00001327: Hold cap brush face (after star)
0x00001928: Out of painting when die
0x00020460: Out of level when lose
0x00001336: Using warp
0x00001336: Arrive at destination of warp
0x00800380: Attacking (in general?)
0x20810446: Riding a shell
0x0C400209: Standing against wall
0x04000440: Sneaking against wall
0x08100340: In tree
0x00100342: Grab onto tree
0x00100343: Climb tree up (if activated on ground, immediate death)
0x00100344: Prepare handstand on tree
0x00100345: Handstand in tree already
0x0300088D: Jump from tree
0x04000471: about to land (?)
0x08100340: Mario holding on pole
0x00100343: Climb up pole
0x000004A8: Holding onto hoot's foot
0x00200349: Holding on bar above
0x0020054A: moving across bars
0x00001371: In cannon (if on ground and press a, he will launch! caution: Glitches easily)
0x00880898: Flying, shot out of Cannon
0x00880456: Sliding
0x20001305: Happens after unlocking door with stars
0x20001306: Talking to something
0x00001308: Reading sign
0x0000133D: Put on cap
0x10880899: Flying
0x010208B0: Hit wall
0x00001321: Open door
0x0800034B: hanging of ledge
0x0000054C: Climb up slow
0x0000054F: Climb up fast
0x00840452: Sitting
0x008C0453: Sliding forward
0x00020467: From after dying (Mario: mama mia!)

Hurt stuff (on land):

0x00020462: Hurt by something
0x00020464: Mario hit (no damage)
0x00020465: Hurt by enemy
0x00020338: Shocked
0x00000479: Fall from high up, crushed
0x00020460: Fall from extreme height
0x00021311: Fall from high jump (standing to sit)
0x00020449: Burning
0x010208B7: Jumping from Lava
0x00021312: Sinking in quicksand to die
0x010208B7: Mario pushed off ledge

Jumping stuff:

0x03000880: Single Jump
0x03000881: Double Jump
0x01000882: Triple Jump
0x018008AC: Kick in air
0x108008A4: Spin in air
0x18800238: land from spin
0x0C000230: Land on ground
0x04000472: Land on ground 2
0x04000478: Land on ground 3
0x0800023A: Landed on ground (Mario will not say aha)
0x030008AF: Triple jump (with sparkles after Yoshi)
0x0C000232: land from it
0x01000887: cartwheel in air
0x04000473: Land on ground
0x01000883: Backflip
0x0800022F: Land
0x008008A9: Stomp in air
0x0080023C: Land, stars form out
0x0C00023E: Get up
0x03000888: Long jump (seems to force land sequence)
0x0800023B: Recover from long jump
0x04000440: Run/run/movement? (will not force run animation?)
0x0C00023D: Slide to stop
0x0188088A: Jump launch
0x00880456: Sliding on ground
0x010208B6: Hit wall
0x00000386: Getting up

Water stuff

0x380022C0: Floating in water
0x380022C1: arms together (hold something in water)
0x300022C2: swimming (floating to surface?)
0x300024E0: Throw something in water
0x300024D6: Using shell under water
0x300024E1: Grab/hit something in water
0x300024D1: Breast stroke in water
0x300024D2: Swimming with kicking legs
0x01000889: Jump out of swim water
0x0400044A: Water exit to air/land
0x300222C5: Hurt by something under water
0x300032C4: Drowning
0x00001303: Get star underwater

Bowser stuff:

0x00000390: Grab bowser by tail
0x00000391: Hold bowser by tail
0x00000392: Throw bowser
0x00001302: Get key (win)
0x0000192B: Jump (after win?)
0x00001327: Take key out, throw in air catch (this also animates when Mario wins without a hat)
0x00020226 - Mario hop (Bowser jumps on platform)

Credits stuff: (note: * = ONLY outside castle)

0x0000131A - Mario waving*
0x00001909 - Mario flies to castle to meet peach
0x00001918 - End sequence when Mario rescues Peach* 

*/

struct object
{
    u16    graph_node_type;        /* 0x00 */
    u16    graph_flags;
    u32    *prev;
    u32    *next;
    u32    graph_parent;
    u32    graph_child;            /* 0x10 */
    u32    geo_layout_ptr; 
    u32    _0x18;
    u32    _0x1c;
    float  float_0x20;             /* 0x20 */
    float  float_0x24;
    float  float_0x28;
    float  x_size;
    float  y_size;                 /* 0x30 */
    float  z_size;
    u16    _0x38;
    u16    _0x3a;
    u32    animation;              /* 0x3c - current animation */
    u16    _0x40;                  /* 0x40 */
    u16    _0x42;
    u32    _0x44;
    u32    _0x48;
    u32    _0x4c;
    u32    matrix_ptr;             /* 0x50 */
    float  float_0x54;
    float  float_0x58;
    float  float_0x5c;
    u32    next_object_ptr;        /* 0x60: re-check this */
    u32    _0x64;
    u32    next_object_ptr2;       /* 0x68: re-check this (child_obj?) */
    u32    _0x6c;
    u32    _0x70;                  /* 0x70 */
    u16    active;                 /* 0x0000 = inactive, 0x0101 = active */
    u16    _0x76;
    u32    _0x78;
    u32    _0x7c;
    u32    _0x80;                  /* 0x80 */
    u32    _0x84;
    u32    _0x88;
    u32    obj_flags;
    u32    _0x90;                  /* 0x90 */
    u32    _0x94;
    u32    _0x98;
    u32    _0x9c;
    float  x_pos;                  /* 0xa0 */
    float  y_pos;
    float  z_pos;
    u32    _0xac;
    u32    _0xb0;                  /* 0xb0 */
    u32    _0xb4;
    u32    _0xb8;
    u32    _0xbc;
    u32    _0xc0;                  /* 0xc0 */
    u32    x_rot;
    u32    y_rot;
    u32    z_rot;
    u32    x_rot2;                 /* 0xd0 */
    u32    y_rot2;
    u32    z_rot2;
    u32    _0xd8;
    u32    _0xe0;                  /* 0xe0 */
    float  _0xe4;
    u32    _0xe8;
    u32    _0xec;
    u32    _0xf0;                  /* 0xf0 */
    u32    _0xf4;
    u32    _0xf8;
    u32    _0xfc;
    u32    _0x100;                 /* 0x100 */
    u32    _0x104;
    u32    _0x108;
    u32    _0x10c;
    u32    _0x110;                 /* 0x110 */
    u32    _0x114;
    u32    _0x118;
    u32    _0x11c;
    u32    animation_ptr;          /* 0x120 = (set by 0x27 26 behavior command) */
    u32    _0x124;
    float  _0x128;
    float  _0x12c;
    u32    _0x130;                 /* 0x130 */
    u32    _0x134;
    u32    _0x138;
    u32    _0x13c;
    u32    _0x140;                 /* 0x140 */
    u32    behav_param;            /* behav param */
    u32    _0x148;
    u32    action;
    u32    _0x150;                 /* 0x150 */
    u32    _0x154;
    float  _0x158;                 /* also some sort of distance from mario? */
    float  distance_from_mario;
    u32    _0x160;                 /* 0x160 */
    float  _0x164_x;
    float  _0x168_y;
    float  _0x16c_z;
    float  _0x170;                 /* 0x170 */
    float  _0x174;
    u32    _0x178;
    u32    transparency;
    u32    _0x180;                 /* 0x180 */
    u32    _0x184;
    u32    behav_param2;  /* re-check */
    u32    _0x18c;
    u32    _0x190;                 /* 0x190 */
    float  collision_distance;
    u32    _0x198;
    float  disappear_distance;
    u32    _0x1a0;                 /* 0x1a0 */
    u32    _0x1a4;
    u32    _0x1a8;
    u32    _0x1ac;
    u32    _0x1b0;                 /* 0x1b0 */
    u32    _0x1b4;
    u32    _0x1b8;
    u32    _0x1bc;
    u32    _0x1c0;                 /* 0x1c0 */
    u32    _0x1c4;
    u32    _0x1c8;
    u32    script_ptr;
    u32    stack_index;            /* 0x1d0 */
    u32    stack;
    u32    _0x1d8;
    u32    _0x1dc;
    u32    _0x1e0;                 /* 0x1e0 */
    u32    _0x1e4;
    u32    _0x1e8;
    u32    _0x1ec;
    u32    _0x1f0;                 /* 0x1f0 */
    u16    _0x1f4;
    u16    _0x1f6;
    float  col_sphere_x;
    float  col_sphere_y;
    float  _0x200;                 /* 0x200 */
    float  _0x204;
    float  _0x208;
    u32    behavior_script_entry;
    u32    _0x210;                 /* 0x210 */
    u32    _0x214;
    u32    collision_ptr;
    u32    _0x21c;
    u32    _0x220;                 /* 0x220 */
    u32    _0x224;
    u32    _0x228;
    u32    _0x22c;
    u32    _0x230;                 /* 0x230 */
    u32    _0x234;
    u32    _0x238;
    u32    _0x23c;
    u32    _0x240;                 /* 0x240 */
    u32    _0x244;
    u32    _0x248;
    u32    _0x24c;
    u32    _0x250;                 /* 0x250 */
    u32    _0x254;
    u32    _0x258;
    u32    behav_param_copy_ptr;
};
 
 
/* old */
      
typedef int (*TEXT_INT)
(
	u16 x,
	u16 y,
	u32 pointer,
	u32 arg4
);

typedef float (*SCALE)
(
	float obj_scaling
);

typedef int (*SOUND)
(
    u32 arg0;
    u32 arg1;
);

typedef int (*MESSAGE)
(
    u16 arg0;
    u16 arg1;
    u16 x_position;
    u16 message_id;        
);

typedef int (*MESSAGE2)
(
    u16 message_id;
);
