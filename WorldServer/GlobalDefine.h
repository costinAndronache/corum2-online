#ifndef __GLOBAL_DEFINE_H__
#define __GLOBAL_DEFINE_H__
#pragma once

/*====================== THE GAME SYSTEM DEFINITIONS ===========================*/
#define	GUILD_WAR
#define	NEW_COMMAND	
//#define	CHECK_KEEP_ALIVE
//#define	GUILD_WARTEST 
//#define	WORLD_MOVE_CHK
/*==============================================================================*/


enum QUERY_TYPE_VALUE
{
	QUERY_TYPE_LOGIN					= 1,
	QUERY_TYPE_ONLINE_CHECK				= 2,
	QUERY_TYPE_CHR_SELECT_INFO			= 3,
	QUERY_TYPE_CREATE_NEW_CHAR			= 4,
	QUERY_TYPE_MESSAGE					= 5,
	QUERY_TYPE_MESSAGE2					= 6,
	QUERY_TYPE_MESSAGERQ				= 7,
	QUERY_TYPE_MESSAGEDEL				= 8,
	QUERY_TYPE_CREATE_CHAR_INIT_BINARY	= 9,
	QUERY_TYPE_USER_INFO				= 10,
	QUERY_TYPE_GUILD_USER				= 10,
	QUERY_TYPE_GUILD_CHK				= 11,
	QUERY_TYPE_GUILD_COUNT				= 12,
	QUERY_TYPE_GUILD_RANK				= 13,
	QUERY_TYPE_GM_CHECK					= 15,
	QUERY_GUILD_ID						= 17,
	QUERY_TYPE_MASTER					= 18,
	QUERY_TYPE_SKILLKEY					= 19,
	QUERY_TYPE_OWNER					= 20,
	QUERY_TYPE_GUILD_LEVEL				= 22,
	QUERY_TYPE_MESSENGER				= 23,
	QUERY_TYPE_CHARACTERINFO			= 24,
	QUERY_TYPE_GUILDUSER_DELETE			= 25,
	QUERY_TYPE_WORLDCHK					= 26,
	QUERY_TYPE_PARTY_FRIEND				= 27,
	QUERY_TYPE_LADDER_INFO				= 28
};

#define HASH_SIZE_GROUP				12
#define HASH_SIZE_PARTY				1500
#define HASH_SIZE_PARTYBOARD		1500
#define HASH_SIZE_OFFLINEUSER		15000
#define HASH_SIZE_MESSENGERTABLE	5000
#define POOL_SIZE_GROUP				12
#define POOL_SIZE_PARTY				1500
#define POOL_SIZE_PARTYBOARD		1500
#define POOL_SIZE_OFFLINEUSER		15000
#define POOL_SIZE_MESSENGERTABLE	5000
#define POOL_SIZE_MESSENGERUSER		32000

#define CHINA_BILLING_FREE_LEVEL_LIMIT 100

extern BOOL g_bEnableChatLog;


#endif 


