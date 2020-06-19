#include "g_local.h"

// Custom weapons
// Note that the gauntlet and the machinegun are always set up

void G_RegisterWeapon ( void ) {
	if ( g_wpflags.integer & 2 ) {
		RegisterItem( BG_FindItemForWeapon( WP_SHOTGUN ) );
	}
	if ( g_wpflags.integer & 4 ) {
		RegisterItem( BG_FindItemForWeapon( WP_GRENADE_LAUNCHER ) );
	}
	if ( g_wpflags.integer & 8 ) {
		RegisterItem( BG_FindItemForWeapon( WP_ROCKET_LAUNCHER ) );
	}
	if ( g_wpflags.integer & 16 ) {
		RegisterItem( BG_FindItemForWeapon( WP_LIGHTNING ) );
	}
	if ( g_wpflags.integer & 32 ) {
		RegisterItem( BG_FindItemForWeapon( WP_RAILGUN ) );
	}
	if ( g_wpflags.integer & 64 ) {
		RegisterItem( BG_FindItemForWeapon( WP_PLASMAGUN ) );
	}
	if ( g_wpflags.integer & 128 ) {
		RegisterItem( BG_FindItemForWeapon( WP_BFG ) );
	}
#ifdef MISSIONPACK
	if ( g_wpflags.integer & 256 ) {
		RegisterItem( BG_FindItemForWeapon( WP_NAILGUN ) );
	}
	if ( g_wpflags.integer & 512 ) {
		RegisterItem( BG_FindItemForWeapon( WP_PROX_LAUNCHER ) );
	}
	if ( g_wpflags.integer & 1024 ) {
		RegisterItem( BG_FindItemForWeapon( WP_CHAINGUN ) );
	}
#endif
	if ( g_grapple.integer > 0 ) {
		RegisterItem( BG_FindItemForWeapon( WP_GRAPPLING_HOOK ) );
	}
}

// Return the quantity of configured ammo for a weapon

static int getAmmoValue( const char *ammocvar ) {
	int ammo = 0;
	ammo = trap_Cvar_VariableIntegerValue(ammocvar);
	if (ammo < 0)
		return 0;
	if (ammo > 200)
		return 200;
	return ammo;
}

void G_SpawnWeapon ( gclient_t *client ) {
	client->ps.ammo[ WP_MACHINEGUN ] = getAmmoValue ( "g_startAmmoMG" );

	if ( g_weaponlimit.integer & 1 && !( g_wpflags.integer & 1 ) ) {
		client->ps.stats[ STAT_WEAPONS ] &= ~( 1 << WP_MACHINEGUN );
		client->ps.ammo[ WP_MACHINEGUN ] = 0;
	}
	if ( g_wpflags.integer & 2 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_SHOTGUN;
		client->ps.ammo[ WP_SHOTGUN ] = getAmmoValue ( "g_startAmmoSG" );
	}
	if ( g_wpflags.integer & 4 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_GRENADE_LAUNCHER;
		client->ps.ammo[ WP_GRENADE_LAUNCHER ] = getAmmoValue ( "g_startAmmoGL" );
	}
	if ( g_wpflags.integer & 8 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_ROCKET_LAUNCHER;
		client->ps.ammo[ WP_ROCKET_LAUNCHER ] = getAmmoValue ( "g_startAmmoRL" );
	}
	if ( g_wpflags.integer & 16 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_LIGHTNING;
		client->ps.ammo[ WP_LIGHTNING ] = getAmmoValue ( "g_startAmmoLG" );
	}
	if ( g_wpflags.integer & 32 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_RAILGUN;
		client->ps.ammo[ WP_RAILGUN ] = getAmmoValue ( "g_startAmmoRG" );
	}
	if ( g_wpflags.integer & 64 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_PLASMAGUN;
		client->ps.ammo[ WP_PLASMAGUN ] = getAmmoValue ( "g_startAmmoPG" );
	}
	if ( g_wpflags.integer & 128 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_BFG;
		client->ps.ammo[ WP_BFG ] = getAmmoValue ( "g_startAmmoBFG" );
	}
#ifdef MISSIONPACK
	if ( g_wpflags.integer & 256 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_NAILGUN;
		client->ps.ammo[ WP_NAILGUN ] = getAmmoValue ( "g_startAmmoNG" );
	}
	if ( g_wpflags.integer & 512 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_PROX_LAUNCHER;
		client->ps.ammo[ WP_PROX_LAUNCHER ] = getAmmoValue ( "g_startAmmoPL" );
	}
	if ( g_wpflags.integer & 1024 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_CHAINGUN;
		client->ps.ammo[ WP_CHAINGUN ] = getAmmoValue ( "g_startAmmoCG" );
	}
#endif
}

qboolean G_WeaponDisabled ( gitem_t *item ) {
	if ( ( g_weaponlimit.integer & 2 ) && ( !Q_stricmp( item->classname, "weapon_shotgun" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 4 ) && ( !Q_stricmp( item->classname, "weapon_grenadelauncher" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 8 ) && ( !Q_stricmp( item->classname, "weapon_rocketlauncher" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 16 ) && ( !Q_stricmp( item->classname, "weapon_lightning" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 32 ) && ( !Q_stricmp( item->classname, "weapon_railgun" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 64 ) && ( !Q_stricmp( item->classname, "weapon_plasmagun" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 128 ) && ( !Q_stricmp( item->classname, "weapon_bfg" ) ) )
		return qtrue;
#ifdef MISSIONPACK
	if ( ( g_weaponlimit.integer & 256 ) && ( !Q_stricmp( item->classname, "weapon_nailgun" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 512 ) && ( !Q_stricmp( item->classname, "weapon_prox_launcher" ) ) )
		return qtrue;
	if ( ( g_weaponlimit.integer & 1024 ) && ( !Q_stricmp( item->classname, "weapon_chaingun" ) ) )
		return qtrue;
#endif
	return qfalse;
}

qboolean G_AmmoDisabled ( gitem_t *item ) {
	if ( ( g_ammolimit.integer & 1 ) && ( !Q_stricmp( item->classname, "ammo_bullets" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 2 ) && ( !Q_stricmp( item->classname, "ammo_shells" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 4 ) && ( !Q_stricmp( item->classname, "ammo_grenades" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 8 ) && ( !Q_stricmp( item->classname, "ammo_rockets" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 16 ) && ( !Q_stricmp( item->classname, "ammo_lightning" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 32 ) && ( !Q_stricmp( item->classname, "ammo_slugs" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 64 ) && ( !Q_stricmp( item->classname, "ammo_cells" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 128 ) && ( !Q_stricmp( item->classname, "ammo_bfg" ) ) )
		return qtrue;
#ifdef MISSIONPACK
	if ( ( g_ammolimit.integer & 256 ) && ( !Q_stricmp( item->classname, "ammo_nails" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 512 ) && ( !Q_stricmp( item->classname, "ammo_mines" ) ) )
		return qtrue;
	if ( ( g_ammolimit.integer & 1024 ) && ( !Q_stricmp( item->classname, "ammo_belt" ) ) )
		return qtrue;
#endif
	return qfalse;
}
