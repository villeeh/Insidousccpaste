#pragma once
#include "singleton.hpp"
#include "MiscClasses.h"
#include "Interfaces.h"
#include "Interface.h"
#include "Sounds.h"
#include "Logging.h"

#pragma comment(lib, "winmm.lib")


char* HitgroupToName(int hitgroup)
{
	switch (hitgroup)
	{
	case 1:
		return "head";
	case 6:
		return "arm";
	case 7:
		return "leg";
	case 3:
		return "stomach";
	default:
		return "body";
	}
}
class item_purchase

	: public singleton<item_purchase>
{
	class item_purchase_listener
		: public IGameEventListener2
	{
	public:
		void start()
		{
			g_EventManager->AddListener(this, "item_purchase", false);
			g_EventManager->AddListener(this, "player_hurt", false);
		}
		void stop()
		{
			g_EventManager->RemoveListener(this);
		}
		void FireGameEvent(IGameEvent *event) override
		{
			singleton()->on_fire_event(event, false);
		}
		int GetEventDebugID(void) override
		{
			return 42 /*0x2A*/;
		}
	};

public:

	static item_purchase* singleton()
	{
		static item_purchase* instance = new item_purchase;
		return instance;
	}

	void initialize()
	{
		listener.start();
	}

	void remove()
	{
		listener.stop();
	}

	void on_fire_event(IGameEvent* event, bool drawing)
	{
		static AppLog log;
		if (drawing)
		{
			log.Draw("Console");
		}

		if (!drawing)
		{
			C_BaseEntity* local = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
			if (!strcmp(event->GetName(), "item_purchase"))
			{
				auto buyer = event->GetInt("userid");
				std::string gun = event->GetString("weapon");

				if	(strstr(gun.c_str(), "kevlar")
					|| strstr(gun.c_str(), "decoy")
					|| strstr(gun.c_str(), "suit")
					|| strstr(gun.c_str(), "vest")
					|| strstr(gun.c_str(), "cutter")
					|| strstr(gun.c_str(), "defuse")
					)  return;
				auto player_index = g_Engine->GetPlayerForUserID(buyer);
				C_BaseEntity* player = (C_BaseEntity*)g_EntityList->GetClientEntity(player_index);
				player_info_t pinfo;

				if (g_Options.Misc.PurchaseInfo)
				if (player && local && g_Engine->GetPlayerInfo(player_index, &pinfo))
				{
					gun.erase(gun.find("weapon_"), 7);
					if (player->GetTeamNum() == local->GetTeamNum())
					{

					}
					else
					{
						g_CVar->ConsoleColorPrintf(Color::Purple(), "[insidous]", pinfo.name, gun.c_str());
						G::Msg(" ""\x04""%s bought %s\n", pinfo.name, gun.c_str());
					}
					
				}
			}

			if (!strcmp(event->GetName(), "player_hurt"))
			{
				int deadfag = event->GetInt("userid");
				int attackingfag = event->GetInt("attacker");
				C_BaseEntity* pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
				if (g_Engine->GetPlayerForUserID(deadfag) != g_Engine->GetLocalPlayer() && g_Engine->GetPlayerForUserID(attackingfag) == g_Engine->GetLocalPlayer())
				{
					C_BaseEntity* hittedplayer = (C_BaseEntity*)(g_Engine->GetPlayerForUserID(deadfag));
					int hit = event->GetInt("hitgroup");
					if (hit >= 0 && hittedplayer && deadfag && attackingfag)
					{
						Globals::missedshots++;
					}
					else
					{
						Globals::missedshots++;
					}
				}
			}

			if (!strcmp(event->GetName(), "player_hurt"))
			{
				auto bitch = event->GetInt("userid");
				auto coolguy49 = event->GetInt("attacker");
				int dmg = event->GetInt("dmg_health");
				int health = event->GetInt("health");


				auto bitch_index = g_Engine->GetPlayerForUserID(bitch);
				auto coolguy49_index = g_Engine->GetPlayerForUserID(coolguy49);
				C_BaseEntity* bitch_ = (C_BaseEntity*)g_EntityList->GetClientEntity(bitch_index);
				C_BaseEntity* coolguy49_ = (C_BaseEntity*)g_EntityList->GetClientEntity(coolguy49_index);
				player_info_t bitch_info;
				player_info_t coolguy49_info;

				if (coolguy49_ == local)
				{
					G::hitmarkeralpha = 1.f;
					switch (g_Options.Visuals.Hitsound)
					{
					case 0: break;
					case 1: PlaySoundA(rawData, NULL, SND_ASYNC | SND_MEMORY); break; // Default
					case 2:	PlaySoundA(roblox, NULL, SND_ASYNC | SND_MEMORY); break; // Anime
					case 3:	PlaySoundA(china, NULL, SND_ASYNC | SND_MEMORY); break; // CHINA
					case 4: PlaySoundA(skeethitmarker_wav, NULL, SND_ASYNC | SND_MEMORY); break; // Skeet
					case 5:	PlaySoundA(hitler_wav, NULL, SND_ASYNC | SND_MEMORY); break; // German
					}

				}
			}
			if (!strcmp(event->GetName(), "player_hurt") && g_Options.Misc.DmgInfo)
			{

				int iAttacker = g_Engine->GetPlayerForUserID(event->GetInt("attacker"));
				int iVictim = g_Engine->GetPlayerForUserID(event->GetInt("userid"));

				if (iAttacker == g_Engine->GetLocalPlayer() && iVictim != g_Engine->GetLocalPlayer())
				{

					auto pVictim = reinterpret_cast<C_BaseEntity*>(g_EntityList->GetClientEntity(iVictim));
					player_info_t pinfo;
					g_Engine->GetPlayerInfo(iVictim, &pinfo);

					g_CVar->ConsoleColorPrintf(Color(200, 255, 0, 255), "[insidous.cc]");
					G::Msg("Hit %s in the %s for %d (%d health remaining) \n", pinfo.name, HitgroupToName(event->GetInt("hitgroup")), event->GetInt("dmg_health"), event->GetInt("health"));

				}
			}
		}
	}
private:
	item_purchase_listener  listener;
};

item_purchase purchase;

