# SM64: The Missing Stars Source Code
Source code to SM64: The Missing Stars, from Frauber (messiaen)'s website: https://sites.google.com/site/messiaen64/themissingstars/download

# Compiling
I'm unsure exactly, but make sure you can compile for MIPS with MIPS-linux-gnu-gcc or something similar, more info in makefile in the messy-original-unorganized-code/ folder

# Frauber's readme

"Super Mario 64: The Missing Stars" v1.1 by messiaen (aka frauber) 
------------------------------------------------------------------


This is the first ever "complete" hack of Mario 64. None of the original
levels have been used and the gamplay has been changed in many aspects.


Main Features:
--------------

- 38 stars in about 10 levels
- A Day/night cycle replacing (most) act selectors
- Choose to play as Mario or Luigi
- Modified enemies, objects and bosses (too many to list!)
- Custom music, including one original song (the town "night" music).
- A new final boss fight

To switch between Mario and Luigi in the title screen, press D-pad Left
(Luigi) or D-Pad Right (Mario).

There are also many 'invisible' modifications that make make this hack work:
extended memory support, a new collision pointer system (lookup tables instead
of hardcoded pointers), modified script commands and a bunch of other minor 
stuff. The source code for all these hacks will be available on my site futurely.


Have fun finding all the missing stars!


Thanks to the people who have contributed to this hack:

Skelux - Secret Woods level and major help on [the] underground area.
RDX - Some music ports made with mml2m64 
VL-Tone/Starxxon - Luigi model, as available from TT64 v0.5.9 onwards.
ZZT32 - a pretty cool guy :D who helped me working with MIPS-GCC.
Darkdata - Title screen background and name suggestion.
Stevoisiak - Beta testing some early versions and suggesting some nice improvements
Kostecki - Correcting some text.

The most updated version of the hack and documentation can be found at
http://sites.google.com/site/messiaen64/themissingstars

You can find documentation on SM64 and some tools at my site main page:
http://sites.google.com/site/messiaen64/


WARNING: You are not allowed to redistribute this hack without this readme.txt
file. Instead of providing a direct download link, please link to
http://sites.google.com/site/messiaen64/themissingstars which shall contain
all information needed to play this hack.


#Applying the patch

You'll need a Mario 64 US (NTSC) ROM, usually called "Super Mario 64 (U)!.z64"
in order to play this hack. Here's how you should proceed:

1) Extend your ROM with VL-Tone's Mario 64 ROM Extender:
http://homepage.mac.com/qubedstudios/Mario64Tools.htm.

If you are on Linux, you can try also Cellar Dweller's "alternate" extender:
http://desktop64.homeip.net:8086/newextender-0.02.tar.gz


2) Apply the PPF patch on the extended ROM with PPF-o-Matic 3.0:
http://www.romhacking.net/utils/356/ (there's also a Mac version hosted at the
same site)

The ROM should be loaded on the "ISO file" field (PPF is a format designed for
the Playstation, but works very well for N64 ROMS too) and the .ppf file on
the Patch field.

Note: If you are a Mac user, you'll have to use the ROM Extender v1.3b, which has
been released a few days ago (at the moment of this writing).


These two steps should be simple, but in case you're having trouble,
a tutorial will be uploaded to http://sites.google.com/site/messiaen64/themissingstars


#Setting up your emulator

Once you have sucessfully extended and patched your ROM, there might be a
few adjustments needed depending on the emulator you are using, because this
hack, unlike the original Mario 64 game, uses extended memory (the Expansion
Pak) to get rid of some limitations.

Mupen, MupenPlus and SixtyForce doesn't require any special adjustments.
Nemu64 can't play this hack because it doesn't accepts the extended Mario 64 ROM.

In Project 64 (my personal recomendation), you'll have to change the "Default Memory Size"
to 8MB. To do this, click on Options -> Settings -> Options and uncheck "Hide Advanced
Settings". Click OK and now do Options -> Settings -> Advanced Settings -> Default Memory
Size -> 8MB.

Now load the Missing Stars ROM. If the title screen doesn't show up, go in
Options -> Settings -> ROM Settings -> Memory Size -> 8MB.

Load the ROM again and the hack should be running.




#Video Plugins

There might be some minor graphical glitches depending on the plugin you are using.

Jabo's Direct 3.D 1.6 (do not use version 1.5.2) and glN64 should give you the
best video output. A more detailed plugin report may be uploaded to my site futurely.


#About the camera

Mario 64 uses a set of hardcoded camera positions for each level and I couldn't
get rid of it (so far) in this hack. Some jumps will require more camera work
(the c-buttons) than the original game, and some angles aren't easily acessible.


#FAQ:

Q: PJ64 says the game is trying to read from unmapped space.
A: Read again the part about enabling extended memory.

Q: PJ64 says the game is in a permanent loop that can't be exited.
A: Something went wrong in the patching process. See if you used the
correct ROM and patch.

Q: The game freezes after the title screen.
A: Either your ROM is unvalid (ie, an already modified ROM) or you have applied the
wrong patch (there's a separate patch for MAC users who have extended the ROM with
any version of the ROM Extender before 1.3).

Q: PPF-o-Matic doesn't show the extended ROM in its file selector.
A: Change the file type filter to All Files (*.*).

Q: I can't find metal caps, red coins, stars in a specific level, etc.
A: Listen to what the NPCs have to say, they give good hints about the less obvious stars.

Q: I have found all 38 stars, what do I do now?
A: Just return to the initial area for further instructions.

Q: How can I select Mario or Luigi in the File Select screen?
A: Use the D-pad Right and D-Pad Left buttons.

Q: My color code doesn't work!
A: The RAM location of Mario colors has been changed because of dynamic memory allocation,
so your color codes won't work and unfortunately I can't help it.

Q: Textures packs don't work.
A: I'm not sure how texture packs work on the emulator side, but my guess is that unless
someone does a hi-res pack specifically for "The Missing Stars" they won't work. 

Q: Can I translate your hack to ______ ?
A: Yes, but only if you have already done something similar and know the basics of translation
like using a text table. You can get in contact with me through YouTube (user 'frauber').


#Custom music used

Title Screen - Good Egg Galaxy (Mario Galaxy)
File Select - Seiken Denetsu 3 File Select
Main City Area - Moo Moo Farms (Mario Kart 64)
Inside Mario's House/Koopa's House (Night) - Piranha Plant's Lullaby
Metal Cap Area - Looping Stairs
Wing Cap/Metal Cap/Boss/Lethal Lava Land/Final Boss - SM64 songs
Abandoned Shack (Day) - Forest Maze/Geno's Forest (Super Mario RPG)
Abandoned Shack (Night) - Milk Bar (Majora's Mask)  (*)
Koopa's House (Day) - SMB3 Athletic
Koopa Race - Butter Building (Kirby) (*)
Secret Woods (Night)/ Main City Area (Night) - Original composition by me
Outside City Area (Day) - Zelda's Lullaby
Outside City Area (Night) - Starfox 64 Boss B
Underground - Boss (Adventure of Link)  (*)
Secret Woods (Day) - Flower Gardens Athletic (Yoshi's Island DS)

(*) Music ports done by RDX.


#Some history and afterthoughts

Working on this hack has been both rewarding and frustrating. Those who know something
about the inner workings on Mario64 and the limitations of the tools available during 
the time I worked on this hack will recognize that this isn't an usual hack. One year ago, 
I doubt anyone (including me!) would think  it would be possible to reach this result with 
such limited methods. Even though a lot of the level design is oriented torwards getting 
around technical limitations, be it hardcoded stuff, collision bugs, slowdowns, I'm very 
satisfied with the end result.

I began tinkering with Mario 64 during the first semester of 2008. I had known about the
existence of Toad's Tool 64 for a while, but it wasn't until VL-Tone came with the "Flatworld
Battlefield" that I really became interested in it. Most of my initial effort went into 
understanding the polygon/collision formats and how the level/geometry/behavior scripts were
laid out from VL-Tone's Mario 64 Hacking Docs. Once I had enough knowledge, I started doing
some simple level hacks using a bunch of custom objects, in an extensively modified version
of Flatworld which I called "Platform Battlefield". There were a bunch of problems with this
method, as objects are only drawn when you are near enough from them, resulting in a very 
artificial experience.

I was almost giving up when Celux came with the amazing "Secret Woods" level done with my 
Platform Battlefield patch. I was really amazed at how much he had done with my custom objects, 
however there were still the same problems: the level was slow as hell (pratically unplayable) and
 objects were only shown when Mario was very near from them. By that time I was learning some MIPS
assembly in order to delve further into the game programming (scripts are only the top of the iceberg!)
and thanks to the help of Cellar Dweller's notes, who has done plenty of low-level work with Mario64,
I eventually came up with a patch that solved the problem. The key point was that whenever the 
collision for a specific object was not loaded (when Mario isn't near enough), the game automatically
stops displaying the object, regardless of the drawing distance setting. By patching a collision routine,
I got the game to display the objects regardless of Mario distance while still keeping the collision 
only loaded when Mario is near enough.

With that set, I knew that a full hack would be possible using only objects as level geometry. I 
initially proposed it as a team hack, and anyone who could, like Celux, make a nice level around these
custom objects would get in. That didn't work. Many people started working on levels and after a while
gave up, and I don't blame them because it's really hard to get a decent result. Meanwhile, I worked on
a few more assembly hacks, such as the day-night system, the play as Mario or Luigi option using VL-Tone's
model and extended memory support, which will be futurely integrated into Toad's Tool 64. When I realized
I would be all by myself on such large project, I got a bit demotivated and stopped working on the hack for
some months. During that period, I mostly hacked the music format and learned about C programming. I had
the idea of writing a music importer, however I couldn't deal with the complexity of MIDI.

By that time, I started hanging around the former Zelda Coalition mostly to share my findings on the 
music format, which is (almost) the same as used in the Zelda games plus in pretty much every Nintendo64
first-party title. In some IRC sessions, ZZT32 showed me some Zelda64 hacks written directly in C using 
the GCC compiler targetting MIPS, and that enabled me to write many of the hacks used in "The Missing Stars".
Cendamos also suggested me to look at the mml (music macro language) format in order to write a music 
importer, and after some weeks mml2m64 came along. It was limited and buggy, but still very useful for 
this hack.

And so, on the beginning of 2009, a lot more confident in MIPS and C, I continued working on "The Missing
Stars" (the name actually came much later, suggested by Darkdata). Towards the end of the hack, I got
some very useful help from Skelux (major work in the undergrounds area), RDX (custom music), and Darkdata
(title screen background) and the hack (v1.0) was finally released on the beginning of May 2009.

visit my YouTube Channel @ http://youtube.com/user/frauber
my Mario 64 site @ http://sites.google.com/site/messiaen64/

# End of Frauber's readme
