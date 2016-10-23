#include "actor.h"
#include "info.h"
#include "p_local.h"
#include "p_spec.h"
#include "a_sharedglobal.h"
#include "m_random.h"
#include "gi.h"
#include "doomstat.h"
#include "gstrings.h"
#include "vm.h"
#include "g_level.h"
#include "p_enemy.h"
#include "a_doomglobal.h"
#include "a_specialspot.h"
#include "templates.h"
#include "m_bbox.h"
#include "portal.h"
#include "d_player.h"
#include "p_maputl.h"
#include "serializer.h"
#include "g_shared/a_pickups.h"
#include "vm.h"

// Include all the other Doom stuff here to reduce compile time
#include "a_archvile.cpp"
#include "a_bossbrain.cpp"
#include "a_demon.cpp"
#include "a_doomimp.cpp"
#include "a_doomweaps.cpp"
#include "a_fatso.cpp"
#include "a_keen.cpp"
#include "a_lostsoul.cpp"
#include "a_painelemental.cpp"
#include "a_possessed.cpp"
#include "a_revenant.cpp"
#include "a_spidermaster.cpp"
#include "a_scriptedmarine.cpp"

// The barrel of green goop ------------------------------------------------

DEFINE_ACTION_FUNCTION(AActor, A_BarrelDestroy)
{
	PARAM_SELF_PROLOGUE(AActor);

	if (dmflags2 & DF2_BARRELS_RESPAWN)
	{
		self->Height = self->GetDefault()->Height;
		self->renderflags |= RF_INVISIBLE;
		self->flags &= ~MF_SOLID;
	}
	else
	{
		self->Destroy ();
	}
	return 0;
}
