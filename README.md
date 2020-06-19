# Qlone mod
The (rebooted) Qlone mod for Quake III: Arena

This is a reboot of the Qlone project, a small mod bringing some nice stuff to Q3A and allowing me to spare some time playing with the Q3 code =)

This project is now based on [baseq3a](https://github.com/ec-/baseq3a) by Eugene C. which bring a nice codebase with enhancements to the bare Q3A SDK. Among others, some of the cool features is the server-side Unlagged code, originally written by Neil "Haste" Toronto and the PM skins coming from [CPMA](https://playmorepromode.com/).

Qlone adds some nifty stuff like the FreezeTag gameplay, based on the Quake 3 [FreezeTag](https://github.com/dbircsak/freeze-tag) code by Darrell "Doolittle" Bircsak (only server-side ATM).

## New cvars

* freezeTag <0|1> : toggle the Freeze Tag gameplay
* g_noSelfDamage <0|1> : toggle the player self damages
* g_startAmmo*X* <0|200> : allow to define the amount of ammunitions for a weapon. *X* can be MG, SG, GL, RL, LG, RG, PG, BFG, NG, PL, CG
* g_startArmor <0|200> : allow to define the amount of armor at spawn
* g_startHealth <0|200> : allow to define the amount of health at spawn
