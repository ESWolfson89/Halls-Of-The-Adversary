# Halls-Of-The-Adversary
An ascii roguelike game

Requires SDL2 and SDL_image libraries and can be compiled on Windows (Visual Studio) or linux

---

Some known bugs:

Fatal:
1) Having more than 8 companions will lock the game up.
2) If an NPC (not player) fires the artifact "fusion cannon", the game will segfault.

Non Fatal:
1) Map display bug when out of range NPC picks up an item of category "ITEMTYPE_CREDIT"
2) Minor map display defects can occur when player uses "item detector"

---

Tested on Windows and Ubuntu. Screenshots all taken on Ubuntu.

If there is too much keyboard lag, you can change the third SDL_CreateRenderer parameter to 0 to default
to hardware acceleration (near top of graphics.cpp). On my linux machine, the display was garbled unless forced to software mode.
Will have to look more into this.

Licensed under GNU (General Public License) GPL version 3. See LICENSE.txt for more details.

---

![Alt text](/screenshots/screenshot1.jpg?raw=true "Screenshot1")

![Alt text](/screenshots/Casino1.jpg?raw=true "Casino1")

![Alt text](/screenshots/SpecialLevelLayout.jpg?raw=true "SpecialLevelLayout")\

![Alt text](/screenshots/SatelliteTransaction.jpg?raw=true "transaction")

![Alt text](/screenshots/MachinesHaveRandomAttributes2.jpg?raw=true "attributes2")

![Alt text](/screenshots/ArmsDealerHideout.jpg?raw=true "Hideout")

![Alt text](/screenshots/NPCAttackingAnotherNPC.jpg?raw=true "npcattack")

![Alt text](/screenshots/FinalBoss.jpg?raw=true "boss3")

![Alt text](/screenshots/SpecialLevel2.jpg?raw=true "boss2")


