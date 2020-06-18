#include "g_local.h"

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

void G_SpawnWeapon ( gclient_t *client ) {
	if ( g_weaponlimit.integer & 1 && !( g_wpflags.integer & 1 ) ) {
		client->ps.stats[ STAT_WEAPONS ] &= ~( 1 << WP_MACHINEGUN );
		client->ps.ammo[ WP_MACHINEGUN ] = 0;
	}
	if ( g_wpflags.integer & 2 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_SHOTGUN;
		client->ps.ammo[ WP_SHOTGUN ] = 10;
	}
	if ( g_wpflags.integer & 4 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_GRENADE_LAUNCHER;
		client->ps.ammo[ WP_GRENADE_LAUNCHER ] = 5;
	}
	if ( g_wpflags.integer & 8 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_ROCKET_LAUNCHER;
		client->ps.ammo[ WP_ROCKET_LAUNCHER ] = 5;
	}
	if ( g_wpflags.integer & 16 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_LIGHTNING;
		client->ps.ammo[ WP_LIGHTNING ] = 60;
	}
	if ( g_wpflags.integer & 32 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_RAILGUN;
		client->ps.ammo[ WP_RAILGUN ] = 10;
	}
	if ( g_wpflags.integer & 64 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_PLASMAGUN;
		client->ps.ammo[ WP_PLASMAGUN ] = 30;
	}
	if ( g_wpflags.integer & 128 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_BFG;
		client->ps.ammo[ WP_BFG ] = 15;
	}
#ifdef MISSIONPACK
	if ( g_wpflags.integer & 256 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_NAILGUN;
		client->ps.ammo[ WP_NAILGUN ] = 20;
	}
	if ( g_wpflags.integer & 512 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_PROX_LAUNCHER;
		client->ps.ammo[ WP_PROX_LAUNCHER ] = 10;
	}
	if ( g_wpflags.integer & 1024 ) {
		client->ps.stats[ STAT_WEAPONS ] |= 1 << WP_CHAINGUN;
		client->ps.ammo[ WP_CHAINGUN ] = 100;
	}
#endif
}
