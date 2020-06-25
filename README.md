# Qlone mod
The (rebooted) Qlone mod for Quake III: Arena

This is a reboot of the Qlone project, a small mod bringing some nice stuff to Q3A and allowing me to spare some time playing with the Q3 code =)

This project is now based on [baseq3a](https://github.com/ec-/baseq3a) by Eugene C. which bring a nice codebase with enhancements to the bare Q3A SDK. Among others, some of the cool features is the server-side Unlagged code, originally written by Neil "Haste" Toronto and the PM skins coming from [CPMA](https://playmorepromode.com/).

Qlone adds some nifty stuff like the FreezeTag gameplay, based on the Quake 3 [FreezeTag](https://github.com/dbircsak/freeze-tag) code by Darrell "Doolittle" Bircsak (only server-side ATM).

## New cvars

* freezeTag <0|1> : default to 0. Toggle the Freeze Tag gameplay
* g_noSelfDamage <0|1> : default to 0. Toggle the player self damages
* g_specLock <0|1> : default to 0. When enabled, a team member can only spec teammates
* g_startAmmo*X* <0|200> : allow to define the amount of ammunitions for a weapon. *X* can be MG, SG, GL, RL, LG, RG, PG, BFG, NG, PL, CG
* g_startArmor <0|200> : allow to define the amount of armor at spawn
* g_startHealth <0|200> : allow to define the amount of health at spawn
* g_tossWeapon <0|1> : default to 1. When set to 0, a fragged player won't toss its weapon

### Flagged cvars

The following cvars use a "flag" value which acts as a combination of integers to specify a group of items:

* wpflags "VAL" : what weapons a player should have at spawn.
  
The corresponding values are:

* Machinegun	1
* Shotgun	2
* Grenade Launcher	4
* Rocket Launcher	8
* Lightning Gun	16
* Railgun	32
* Plasma Gun	64
* BFG10K	128
* Nailgun	256
* Prox Launcher	512
* Chaingun	1024

So, in order to let a player starts with a shotgun, a grenade launcher and a rocket launcher you can use "wpflags 14" (for 14 is 2+4+8). Note that players always start with the machinegun and the gauntlet.

The **removeX** cvars allow to choose to remove items from a map, **X** is either **ammo**, **item**, **powerup** or **weapon**:

* removeammo "VAL" use the same numbers as wpflags but for the corresponding ammunition
* removeeapon "VAL" use the same numbers as wpflags
* removeitem "VAL", where VAL can used the following values:
  * item_armor_shard 1
  * item_armor_combat 2
  * item_armor_body 4
  * item_health_small 8
  * item_health 16
  * item_health_large 32
  * item_health_mega 64
  * holdable_teleporter 128
  * holdable_medkit 256
 * removepowerup "VAL", where VAL can used the following values:
  * item_quad 1
  * item_enviro 2
  * item_haste 4
  * item_invis 8
  * item_regen 16
  * item_flight 32
  
In addition, some dynamic cvars may be used to replace an item on a map. The syntax is **replace_ITEM "NEW_ITEM"**, where ITEM is a valid Q3 item classname. If you want to replace the bullets ammo with the rockets ammo use `set replace_ammo_bullets "ammo_rockets"`. Note that replace does only change the classname thus only items of the same type should be safely replaced...
