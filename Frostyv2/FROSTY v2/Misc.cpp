#include "Misc.h"
#include "Interfaces.h"
#include "Render.h"
#include <time.h>
#include "BaseClient.h"
#include "Strafer.h"


#define KEY_DOWN(VK_NNM) ((GetAsyncKeyState(VK_NNM) & 0x8000) ? 1:0)

std::string animatedclantag;
int iLastTime;
bool bDone = false;
void misc::OnCreateMove(CInput::CUserCmd *cmd, C_BaseEntity *local)
{
	if (g_Options.Misc.Skybox) { ConVar* skybox = g_CVar->FindVar("sv_skyname"); if (skybox) skybox->SetValue(skybox_models[g_Options.Misc.Skybox]); }


	if (g_Options.Misc.fps)
	{
		if (g_Engine->IsConnected() && g_Engine->IsInGame())
		{
			ConVar* DrawOtherModels = g_CVar->FindVar("mat_postprocess_enable");
			if (DrawOtherModels)
			{
				DrawOtherModels->SetValue(0);
			}
		}
	}
	else
	{
		if (g_Engine->IsConnected() && g_Engine->IsInGame())
		{
			ConVar* DrawOtherModels = g_CVar->FindVar("mat_postprocess_enable");
			if (DrawOtherModels)
			{
				DrawOtherModels->SetValue(1);
			}
		}
	}



	if (g_Options.Misc.FakePing2)
	{
		{
			ConVar* net_fakelag = g_CVar->FindVar("net_fakelag");
			if (g_Options.Misc.FakePing);
			net_fakelag->SetValue(g_Options.Misc.FakePing2);
		}
	}
	else
	{
		{
			ConVar* net_fakelag = g_CVar->FindVar("net_fakelag");
			if (g_Options.Misc.FakePing);
			net_fakelag->SetValue(g_Options.Misc.FakePing2);
		}
	}


	if (g_Options.Misc.Bhop && local->IsAlive())
	{
		if (cmd->buttons & IN_JUMP && !(local->GetMoveType() & MOVETYPE_LADDER))
		{

			int iFlags = local->GetFlags();
			if (!(iFlags & FL_ONGROUND))
				cmd->buttons &= ~IN_JUMP;
		}
	}

	if (g_Options.Misc.MoonWalk)
	{
		if (local->GetMoveType() & (MOVETYPE_NOCLIP | MOVETYPE_LADDER))
			return;
		{
			if (cmd->buttons & IN_FORWARD)
			{
				cmd->forwardmove = 450;
				cmd->buttons &= ~IN_FORWARD;
				cmd->buttons |= IN_BACK;
			}
			else if (cmd->buttons & IN_BACK)
			{
				cmd->forwardmove = -450;
				cmd->buttons &= ~IN_BACK;
				cmd->buttons |= IN_FORWARD;
			}

			if (cmd->buttons & IN_MOVELEFT)
			{
				cmd->sidemove = -450;
				cmd->buttons &= ~IN_MOVELEFT;
				cmd->buttons |= IN_MOVERIGHT;
			}
			else if (cmd->buttons & IN_MOVERIGHT)
			{
				cmd->sidemove = 450;
				cmd->buttons &= ~IN_MOVERIGHT;
				cmd->buttons |= IN_MOVELEFT;

			}
		}
	}

	if (g_Options.Misc.legitBhop && local->IsAlive())
	{
		if (cmd->buttons & IN_JUMP && !(local->GetMoveType() & MOVETYPE_LADDER))
		{

			static bool jumped_last_tick = false;
			static bool should_fake_jump = false;

			if (!jumped_last_tick && should_fake_jump) {
				should_fake_jump = false;
				cmd->buttons |= IN_JUMP;
			}
			else if (cmd->buttons & IN_JUMP) {
				if (local->GetFlags() & FL_ONGROUND) {
					jumped_last_tick = true;
					should_fake_jump = true;
				}
				else {
					cmd->buttons &= ~IN_JUMP;
					jumped_last_tick = false;
				}
			}
			else {
				jumped_last_tick = false;
				should_fake_jump = false;
			}
		}
	}

	if (g_Options.Misc.clantagsxd)
	{


		switch (g_Options.Misc.syncclantags && g_Options.Misc.clantagsxd)
		{
		case 0:
			static int counter = 0;
			static int motion = 0;
			int ServerTime = (float)local->GetTickBase() * g_Globals->interval_per_tick * 2.5;

			if (counter % 48 == 0)
				motion++;
			int value = ServerTime % 1;
			switch (value) {
			case 0: setclantag(XorStr("")); break;

				(g_Options.Misc.clantags = 0);
			}
			counter++;
		}

		if (!g_Options.Misc.animatedclantag && animatedclantag.c_str() != G::AnimatedClantag)
		{
			animatedclantag = G::AnimatedClantag;
		}

		if (g_Options.Misc.animatedclantag && animatedclantag.length() > 1)
		{
			if (int(g_Globals->curtime) != iLastTime)
			{
				auto length = animatedclantag.length();
				animatedclantag.insert(0, 1, animatedclantag[length - 2]);
				animatedclantag.erase(length - 1, 1);

				setclantag(animatedclantag.c_str());
				iLastTime = int(g_Globals->curtime);
			}
		}

		switch (g_Options.Misc.syncclantags)
		{
		case 1:
			static int counter = 0;
			static int motion = 0;
			int ServerTime = (float)local->GetTickBase() * g_Globals->interval_per_tick * 2.5;

			if (counter % 48 == 0)
				motion++;
			int value = ServerTime % 25;
			switch (value) {
			case 0: setclantag(XorStr("               ")); break;
			case 1: setclantag(XorStr("              I")); break;
			case 2: setclantag(XorStr("             In")); break;
			case 3: setclantag(XorStr("            Ins")); break;
			case 4: setclantag(XorStr("           Insi")); break;
			case 5: setclantag(XorStr("          Insid")); break;
			case 6: setclantag(XorStr("         Insido")); break;
			case 7: setclantag(XorStr("        Insidou")); break;
			case 8: setclantag(XorStr("       Insidous")); break;
			case 9: setclantag(XorStr("     Insidous.c")); break;
			case 10: setclantag(XorStr("   Insidous.cc")); break;
			case 11: setclantag(XorStr("  Insidous.cc ")); break;
			case 12: setclantag(XorStr("  Insidous.cc ")); break;
			case 13: setclantag(XorStr(" Insidous.cc  ")); break;
			case 14: setclantag(XorStr("Insidous.cc   ")); break;
			case 15: setclantag(XorStr("nsidous.cc    ")); break;
			case 16: setclantag(XorStr("sidous.cc     ")); break;
			case 17: setclantag(XorStr("idous.cc      ")); break;
			case 18: setclantag(XorStr("dous.cc       ")); break;
			case 19: setclantag(XorStr("ous.cc        ")); break;
			case 20: setclantag(XorStr("us.cc         ")); break;
			case 21: setclantag(XorStr("s.cc          ")); break;
			case 22: setclantag(XorStr(".cc           ")); break;
			case 23: setclantag(XorStr("cc            ")); break;
			case 24: setclantag(XorStr("c             ")); break;
			case 25: setclantag(XorStr("              ")); break;

			}
			counter++;
		}

		if (!g_Options.Misc.animatedclantag && animatedclantag.c_str() != G::AnimatedClantag)
		{
			animatedclantag = G::AnimatedClantag;
		}

		if (g_Options.Misc.animatedclantag && animatedclantag.length() > 1)
		{
			if (int(g_Globals->curtime) != iLastTime)
			{
				auto length = animatedclantag.length();
				animatedclantag.insert(0, 1, animatedclantag[length - 2]);
				animatedclantag.erase(length - 1, 1);

				setclantag(animatedclantag.c_str());
				iLastTime = int(g_Globals->curtime);
			}
		}
		switch (g_Options.Misc.syncclantags)
		{
		case 2:
			static int counter = 0;
			static int motion = 0;
			int ServerTime = (float)local->GetTickBase() * g_Globals->interval_per_tick * 2.5;

			if (counter % 48 == 0)
				motion++;
			int value = ServerTime % 29;
			switch (value) {
			case 0: setclantag(XorStr("/                 ")); break;
			case 1: setclantag(XorStr("-                 ")); break;
			case 2: setclantag(XorStr("I                 ")); break;
			case 3: setclantag(XorStr("I/                ")); break;
			case 4: setclantag(XorStr("I-                ")); break;
			case 5: setclantag(XorStr("In                ")); break;
			case 6: setclantag(XorStr("In/               ")); break;
			case 7: setclantag(XorStr("In-               ")); break;
			case 8: setclantag(XorStr("Ins               ")); break;
			case 9: setclantag(XorStr("Ins/              ")); break;
			case 10: setclantag(XorStr("Ins-             ")); break;
			case 11: setclantag(XorStr("Insi             ")); break;
			case 12: setclantag(XorStr("Insi/             ")); break;
			case 13: setclantag(XorStr("Insi-             ")); break;
			case 14: setclantag(XorStr("Insid             ")); break;
			case 15: setclantag(XorStr("Insid/            ")); break;
			case 16: setclantag(XorStr("Insid-            ")); break;
			case 17: setclantag(XorStr("Insido            ")); break;
			case 18: setclantag(XorStr("Insido/           ")); break;
			case 19: setclantag(XorStr("Insido-           ")); break;
			case 20: setclantag(XorStr("Insidou           ")); break;
			case 21: setclantag(XorStr("Insidou/          ")); break;
			case 22: setclantag(XorStr("Insidou-          ")); break;
			case 23: setclantag(XorStr("Insidous          ")); break;
			case 24: setclantag(XorStr("Insidous/         ")); break;
			case 25: setclantag(XorStr("Insidous-         ")); break;
			case 26: setclantag(XorStr("Insidous.c        ")); break;
			case 27: setclantag(XorStr("Insidous.c/       ")); break;
			case 28: setclantag(XorStr("Insidous.c-       ")); break;
			case 29: setclantag(XorStr("Insidous.cc       ")); break;


			}
			counter++;
		}

		if (!g_Options.Misc.animatedclantag && animatedclantag.c_str() != G::AnimatedClantag)
		{
			animatedclantag = G::AnimatedClantag;
		}

		if (g_Options.Misc.animatedclantag && animatedclantag.length() > 1)
		{
			if (int(g_Globals->curtime) != iLastTime)
			{
				auto length = animatedclantag.length();
				animatedclantag.insert(0, 1, animatedclantag[length - 2]);
				animatedclantag.erase(length - 1, 1);

				setclantag(animatedclantag.c_str());
				iLastTime = int(g_Globals->curtime);
			}
		}
		switch (g_Options.Misc.syncclantags)
		{
		case 3:
			static int counter = 0;
			static int motion = 0;
			int ServerTime = (float)local->GetTickBase() * g_Globals->interval_per_tick * 2.5;

			if (counter % 48 == 0)
				motion++;
			int value = ServerTime % 1;
			switch (value) {
			case 0: setclantag(XorStr("I Love 8--->")); break;




			}
			counter++;
		}

		if (!g_Options.Misc.animatedclantag && animatedclantag.c_str() != G::AnimatedClantag)
		{
			animatedclantag = G::AnimatedClantag;
		}

		if (g_Options.Misc.animatedclantag && animatedclantag.length() > 1)
		{
			if (int(g_Globals->curtime) != iLastTime)
			{
				auto length = animatedclantag.length();
				animatedclantag.insert(0, 1, animatedclantag[length - 2]);
				animatedclantag.erase(length - 1, 1);

				setclantag(animatedclantag.c_str());
				iLastTime = int(g_Globals->curtime);
			}
		}
		switch (g_Options.Misc.syncclantags)
		{
		case 4:
			static int counter = 0;
			static int motion = 0;
			int ServerTime = (float)local->GetTickBase() * g_Globals->interval_per_tick * 2.5;

			if (counter % 48 == 0)
				motion++;
			int value = ServerTime % 4;
			switch (value) {
			case 0: setclantag(XorStr("Insidous")); break;


			}

			counter++;
		}


		if (!g_Options.Misc.animatedclantag && animatedclantag.c_str() != G::AnimatedClantag)
		{
			animatedclantag = G::AnimatedClantag;
		}

		if (g_Options.Misc.animatedclantag && animatedclantag.length() > 1)
		{
			if (int(g_Globals->curtime) != iLastTime)
			{
				auto length = animatedclantag.length();
				animatedclantag.insert(0, 1, animatedclantag[length - 2]);
				animatedclantag.erase(length - 1, 1);

				setclantag(animatedclantag.c_str());
				iLastTime = int(g_Globals->curtime);
			}
		}
	}



	if (g_Options.Misc.Gray)
	{
		if (g_Engine->IsConnected() && g_Engine->IsInGame())
		{
			ConVar* DrawOtherModels = g_CVar->FindVar("mat_drawgray");
			if (DrawOtherModels)
			{
				DrawOtherModels->SetValue(1);
			}
		}
	}
	else
	{
		if (g_Engine->IsConnected() && g_Engine->IsInGame())
		{
			ConVar* DrawOtherModels = g_CVar->FindVar("mat_drawgray");
			if (DrawOtherModels)
			{
				DrawOtherModels->SetValue(0);
			}
		}
	}
	if (g_Options.Misc.crack)
	{
		if (g_Engine->IsConnected() && g_Engine->IsInGame())
		{
			ConVar* DrawOtherModels = g_CVar->FindVar("mat_showmiplevels");
			if (DrawOtherModels)
			{
				DrawOtherModels->SetValue(1);
			}
		}
	}
	else
	{
		if (g_Engine->IsConnected() && g_Engine->IsInGame())
		{
			ConVar* DrawOtherModels = g_CVar->FindVar("mat_showmiplevels");
			if (DrawOtherModels)
			{
				DrawOtherModels->SetValue(0);
			}
		}
	}
	CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)g_EntityList->GetClientEntityFromHandle(local->GetActiveWeaponHandle());

	static bool WasFiring = false;
	if (pWeapon != nullptr)
	{
		if (MiscFunctions::IsPistol(pWeapon) && g_Options.Legitbot.AutoPistol && pWeapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex() != 64)
		{
			if (cmd->buttons & IN_ATTACK && !MiscFunctions::IsKnife(pWeapon) && !MiscFunctions::IsGrenade(pWeapon))
			{
				if (WasFiring)
				{
					cmd->buttons &= ~IN_ATTACK;
				}
			}

			WasFiring = cmd->buttons & IN_ATTACK ? true : false;
		}
	}


	static size_t lastTime = 0;
	static int counter = 0;
	if (GetTickCount() > lastTime)
	{

		counter = counter + 1;
		if (counter > 5)
			counter = 0;
		switch (g_Options.Misc.spammer)
		{
		case 1:
			SayInChat(phooklist[counter]);
			break;
		case 2:
			SayInChat(tuxlist[counter]);
			break;
		case 3:
			SayInChat(ezfragslist[counter]);
			break;
		}

		lastTime = GetTickCount() + 850;



	}
	if (g_Options.Misc.silentstealer)
	{
		bool bDidMeme = false;
		int iNameIndex = -1;
		char chName[130];
		static ConVar* name = g_CVar->FindVar("name");
		{
			for (int iPlayerIndex = 0; iPlayerIndex < g_Engine->GetMaxClients(); iPlayerIndex++)
			{
				C_BaseEntity *pEntity = g_EntityList->GetClientEntity(iPlayerIndex);
				if (!pEntity || pEntity == local || iPlayerIndex == g_Engine->GetLocalPlayer())
					continue;
				if (rand() % 3 == 1)
				{
					iNameIndex = pEntity->GetIndex();
					bDidMeme = true;
				}
			}
			if (bDidMeme)
			{
				player_info_t pInfo;
				g_Engine->GetPlayerInfo(iNameIndex, &pInfo);
				sprintf(chName, "%s ", pInfo.name);
				name->SetValue(chName);
			}
		}

	}


	if (pWeapon != nullptr)
		if (MiscFunctions::IsKnife(pWeapon) && g_Options.Misc.KnifeHand && pWeapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex() != 64)
		{
			g_Engine->ClientCmd_Unrestricted("cl_righthand 0");
		}
		else if (!MiscFunctions::IsKnife(pWeapon) && g_Options.Misc.KnifeHand && pWeapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex() != 64)
		{
			g_Engine->ClientCmd_Unrestricted("cl_righthand 1");
		}


	//ChromeWorld
	if (g_Options.Misc.ChromeWorld)
	{
		ConVar* Chromeworld = g_CVar->FindVar("r_showenvcubemap");
		if (Chromeworld)
		{
			Chromeworld->SetValue(1);
		}
	}
	else
	{
		ConVar* Chromeworld = g_CVar->FindVar("r_showenvcubemap");
		if (Chromeworld)
		{
			Chromeworld->SetValue(0);
		}
	}

	if (g_Options.Misc.DmgInfo)
	{
		logsrun();
	}
	if (g_Options.Misc.PurchaseInfo)
	{
		logsrun2();
	}

}


void misc::logsrun()
{
	static auto developer = g_CVar->FindVar("developer");
	developer->SetValue(1);
	static auto con_filter_text = g_CVar->FindVar("con_filter_text");
	static auto con_filter_text_out = g_CVar->FindVar("con_filter_text_out");
	static auto con_filter_enable = g_CVar->FindVar("con_filter_enable");

	con_filter_text->SetValue("hit ");
	con_filter_text_out->SetValue("");
	con_filter_enable->SetValue(2);
}

void misc::logsrun2()
{
	static auto developer = g_CVar->FindVar("developer");
	developer->SetValue(1);
	static auto con_filter_text = g_CVar->FindVar("con_filter_text");
	static auto con_filter_text_out = g_CVar->FindVar("con_filter_text_out");
	static auto con_filter_enable = g_CVar->FindVar("con_filter_enable");

	con_filter_text->SetValue("bought");
	con_filter_text_out->SetValue("");
	con_filter_enable->SetValue(2);
}




static vec_t Normalize_y(vec_t ang)
{
	while (ang < -180.0f)
		ang += 360.0f;
	while (ang > 180.0f)
		ang -= 360.0f;
	return ang;
}


void misc::AutoStrafe(CInput::CUserCmd *cmd, C_BaseEntity *local, QAngle oldangles)
{
	static AutoStrafer Strafer;

	static float move = 450;
	float s_move = move * 0.5065f;
	if (local->GetMoveType() & (MOVETYPE_NOCLIP | MOVETYPE_LADDER))
		return;
	if (cmd->buttons & (IN_FORWARD | IN_MOVERIGHT | IN_MOVELEFT | IN_BACK))
		return;

	if (cmd->buttons & IN_JUMP || !(local->GetFlags() & FL_ONGROUND))
	{
		if (local->GetVelocity().Length2D() == 0 && (cmd->forwardmove == 0 && cmd->sidemove == 0))
		{
			cmd->forwardmove = 450.f;
		}
		else if (cmd->forwardmove == 0 && cmd->sidemove == 0)
		{
			if (cmd->mousedx > 0 || cmd->mousedx > -0)
			{
				cmd->sidemove = cmd->mousedx < 0.f ? -450.f : 450.f;
			}
			else
			{
				auto airaccel = g_CVar->FindVar("sv_airaccelerate");
				auto maxspeed = g_CVar->FindVar("sv_maxspeed");

				static int zhop = 0;
				double yawrad = Normalize_y(oldangles.y) * PI / 180;

				float speed = maxspeed->GetFloat();
				if (cmd->buttons & IN_DUCK)
					speed *= 0.333;

				double tau = g_Globals->interval_per_tick, MA = speed * airaccel->GetFloat();

				int Sdir = 0, Fdir = 0;
				Vector velocity = local->GetVelocity();
				double vel[3] = { velocity[0], velocity[1], velocity[2] };
				double pos[2] = { 0, 0 };
				double dir[2] = { std::cos((oldangles[1] + 10 * zhop) * PI / 180), std::sin((oldangles[1] + 10 * zhop) * PI / 180) };
				oldangles.y = Normalize_y(yawrad * 180 / PI);
				Strafer.strafe_line_opt(yawrad, Sdir, Fdir, vel, pos, 30.0, tau, MA, pos, dir);
				cmd->sidemove = Sdir * 450;
			}
		}

	}
	movementfix(oldangles, cmd);


}