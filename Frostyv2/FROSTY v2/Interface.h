#pragma once
#include "Configuration.hpp"
#include "dropboxes.h"
#include "Variables.h"
#include "Themes.h"
#include <cctype>
#include "Logging.h"
#include "Listener.h"
#include "PaintTraverse.h"


#define RandomInt(nMin, nMax) (rand() % (nMax - nMin + 1) + nMin);
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))
#define BUILDSTAMP ( __DATE__ )
typedef void(*CL_FullUpdate_t) (void);
CL_FullUpdate_t CL_FullUpdate = nullptr;

void FullUpdate()
{
	static auto CL_FullUpdate = reinterpret_cast<CL_FullUpdate_t>(U::FindPattern("engine.dll", reinterpret_cast<PBYTE>("\xA1\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x56\xFF\x50\x14\x8B\x34\x85"), "x????x????xxxxxxx"));
	CL_FullUpdate();
}

//--------------------------------------------
//Weapon CFG stuff




const char* weaponnames(int id)
{
	switch (id)
	{
	case 1:
		return "deagle";
	case 2:
		return "elite";
	case 3:
		return "fiveseven";
	case 4:
		return "glock";
	case 7:
		return "ak47";
	case 8:
		return "aug";
	case 9:
		return "awp";
	case 10:
		return "famas";
	case 11:
		return "g3sg1";
	case 13:
		return "galilar";
	case 14:
		return "m249";
	case 60:
		return "m4a1_silencer";
	case 16:
		return "m4a1";
	case 17:
		return "mac10";
	case 19:
		return "p90";
	case 24:
		return "ump45";
	case 25:
		return "xm1014";
	case 26:
		return "bizon";
	case 27:
		return "mag7";
	case 28:
		return "negev";
	case 29:
		return "sawedoff";
	case 30:
		return "tec9";
	case 32:
		return "hkp2000";
	case 33:
		return "mp7";
	case 34:
		return "mp9";
	case 35:
		return "nova";
	case 36:
		return "p250";
	case 38:
		return "scar20";
	case 39:
		return "sg556";
	case 40:
		return "ssg08";
	case 61:
		return "usp_silencer";
	case 63:
		return "cz75a";
	case 64:
		return "revolver";
	case 508:
		return "knife_m9_bayonet";
	case 500:
		return "bayonet";
	case 505:
		return "knife_flip";
	case 506:
		return "knife_gut";
	case 507:
		return "knife_karambit";
	case 509:
		return "knife_tactical";
	case 512:
		return "knife_falchion";
	case 514:
		return "knife_survival_bowie";
	case 515:
		return "knife_butterfly";
	case 516:
		return "knife_push";

	default:
		return "";
	}
}


bool IsUtility(ItemDefinitionIndexx index)
{
	switch (index)
	{
	case ItemDefinitionIndexx::ITEM_NONE:
	case ItemDefinitionIndexx::WEAPON_C4:
	case ItemDefinitionIndexx::WEAPON_FLASH:
	case ItemDefinitionIndexx::WEAPON_HE:
	case ItemDefinitionIndexx::WEAPON_INC:
	case ItemDefinitionIndexx::WEAPON_MOLOTOV:
	case ItemDefinitionIndexx::WEAPON_SMOKE:
	case ItemDefinitionIndexx::WEAPON_DECOY:
	case ItemDefinitionIndexx::WEAPON_KNIFE_T:
	case ItemDefinitionIndexx::WEAPON_KNIFE_CT:
	case ItemDefinitionIndexx::GLOVE_T_SIDE:
	case ItemDefinitionIndexx::GLOVE_CT_SIDE:
	case ItemDefinitionIndexx::GLOVE_SPORTY:
	case ItemDefinitionIndexx::GLOVE_SLICK:
	case ItemDefinitionIndexx::GLOVE_LEATHER_WRAP:
	case ItemDefinitionIndexx::GLOVE_STUDDED_BLOODHOUND:
	case ItemDefinitionIndexx::GLOVE_MOTORCYCLE:
	case ItemDefinitionIndexx::GLOVE_SPECIALIST:
		return true;
	default:
		return false;
	}
}

bool Contains(const std::string &word, const std::string &sentence) {
	if (word == "" || sentence == "")
		return true;

	return sentence.find(word) != std::string::npos;
}

std::string ToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), (int(*)(int))std::tolower);

	return str;
}
//--------------------------------------------
bool defaultk;
bool bayonet;
bool flip;
bool gut;
bool karambit;
bool m9bayonet;
bool huntsman;
bool falchion;
bool bowie;
bool butterfly;
bool daggers;

void doknives(bool* disknife)
{
	defaultk = false;
	bayonet = false;
	flip = false;
	gut = false;
	karambit = false;
	m9bayonet = false;
	huntsman = false;
	falchion = false;
	bowie = false;
	butterfly = false;
	daggers = false;

	*disknife = true;
}

const char* HitmarkSound[] =
{
	"Disabled",
	"Default",
	"Roblox",
	"China",
	"Metallic",
	"Hitler"

};

const char* AngleStyles[] =
{
	"Disabled",
	"Ground",
	"Crosshair"
};

#define MENU_SIZE_X 700
#define MENU_SIZE_Y 600
#define TAB_COUNT 5
#define SUBTAB_COUNT 5

void SubTab(const char* name, int* v, int tab_id) {


	static float r = 1.0f;
	static float g = 0.f;
	static float b = 0.f;

	if (r == 1.f && g >= 0.f && b <= 0.f)
	{
		g += 0.005f;
		b = 0.f;
	}
	if (r <= 1.f && g >= 1.f && b == 0.f)
	{
		g = 1.f;
		r -= 0.005f;
	}
	if (r <= 0.f && g == 1.f && b >= 0.f)
	{
		r = 0.f;
		b += 0.005f;
	}
	if (r == 0.f && g <= 1.f && b >= 1.f)
	{
		b = 1.f;
		g -= 0.005f;
	}
	if (r >= 0.f && g <= 0.f && b == 1.f)
	{
		g = 0.f;
		r += 0.005f;
	}
	if (r >= 1.f && g >= 0.f && b <= 1.f)
	{
		r = 1.f;
		b -= 0.005f;
	}

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4 oldtext = style.Colors[ImGuiCol_Text];
	ImVec4 oldbutton = style.Colors[ImGuiCol_Button];
	ImVec4 oldbuttonhovered = style.Colors[ImGuiCol_ButtonHovered];
	ImVec4 oldbuttonactive = style.Colors[ImGuiCol_ButtonActive];
	if (tab_id != 0)
	{
		ImGui::SameLine();
	}
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(r, g, b, 1.f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(r, g, b, 1.f);
	style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);

	if (*v == tab_id) {
		style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
	}
	if (ImGui::Button(name, ImVec2((MENU_SIZE_X - 25) / SUBTAB_COUNT, 35)))
	{
		*v = tab_id;
	}
	style.Colors[ImGuiCol_ButtonActive] = oldbuttonactive;
	style.Colors[ImGuiCol_ButtonHovered] = oldbuttonhovered;
	style.Colors[ImGuiCol_Button] = oldbutton;
	style.Colors[ImGuiCol_Text] = oldtext;

}

void RenderInterface() {


	auto& style = ImGui::GetStyle();
	bool is_renderer_active = renderer->IsActive();
	if (is_renderer_active)
	{
		g_Options.Menu.bShowTabs = true;
		if (style.Alpha < 1.f)
			style.Alpha += 0.01f;
	}
	if (!is_renderer_active)
	{

		if (style.Alpha > 0.f)
			style.Alpha -= 0.01f;
		g_Options.Menu.bShowTabs = false;
	}

	if (is_renderer_active)
	{


		
			
		if (g_Options.Menu.iTab == 0)
		{
			//normal font push
			//style.Alpha = g_Options.Menu.flTabsAlpha;
			style.WindowPadding = ImVec2(0, 0);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Always);
			ImGui::SetNextWindowSize(ImVec2(615, 330));
			if (ImGui::Begin("##tabarea", &is_renderer_active, ImVec2(615, 330), 2.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}

				style.Colors[ImGuiCol_Button] = ImVec4(0.11, 0.11, 0.11, 1.f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);

				ImGui::Text("                                                                   INSIDOUS.CC");
				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);

				if (g_Options.Misc.BrdrClr)
				{
					style.Colors[ImGuiCol_Border] = ImVec4(r, g, b, 1.f);
					style.Colors[ImGuiCol_MenuBarBg] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}

				ImGui::BeginChild("New Child", ImVec2(675, 330), true); 
				ImGui::PushFont(insidous_3);
				if (ImGui::Button("l", ImVec2(200, 150))) g_Options.Menu.iTab = 2; 
				ImGui::SameLine();
				if (ImGui::Button("V", ImVec2(200, 150))) g_Options.Menu.iTab = 3;
				ImGui::SameLine();
				if (ImGui::Button("s", ImVec2(200, 150))) g_Options.Menu.iTab = 5;
				
				if (ImGui::Button("r", ImVec2(200, 150))) g_Options.Menu.iTab = 1;
				ImGui::SameLine();
				if (ImGui::Button("M", ImVec2(200, 150))) g_Options.Menu.iTab = 4;
				ImGui::SameLine();
				if (ImGui::Button("c", ImVec2(200, 150))) g_Options.Menu.iTab = 6;
				ImGui::PopFont();
				ImGui::EndChild(); 
			}ImGui::End();
		}
		else if (g_Options.Menu.iTab == 1)
		{

			style.WindowPadding = ImVec2(8, 8);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter (ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(840, 500));
			if (ImGui::Begin("Ragebot", &g_Options.Menu.Opened, ImVec2(300, 300), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}
				if (g_Options.Misc.BrdrClr)
				{
					style.Colors[ImGuiCol_Border] = ImVec4(r, g, b, 1.f);
					style.Colors[ImGuiCol_MenuBarBg] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}

				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);

				ImGui::Text("                                                                                      INSIDOUS.CC");
				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				if (ImGui::Button("Back")) g_Options.Menu.iTab = 0;
				ImGui::SameLine();
				ImGui::PushFont(fDefault);

				if (g_Options.Menu.rageSubtab == 0)
				{
					ImGui::Text("Ragebot");
					ImGui::BeginChild("first child", ImVec2(200, 420), true);
					{
						ImGui::Checkbox(XorStr("Active"), &g_Options.Ragebot.MainSwitch);
						ImGui::Checkbox(XorStr("Enabled"), &g_Options.Ragebot.Enabled);
						ImGui::PushItemWidth(184);
						ImGui::SliderFloat(XorStr("FOV"), &g_Options.Ragebot.FOV, 1.f, 180.f, "%.0f");
						ImGui::Checkbox(XorStr("Auto Fire"), &g_Options.Ragebot.AutoFire);
						ImGui::Checkbox(XorStr("Silent Aim"), &g_Options.Ragebot.Silent);
						ImGui::Checkbox(XorStr("AutoPistol"), &g_Options.Ragebot.AutoPistol);
						ImGui::Checkbox(XorStr("NoRecoil"), &g_Options.Ragebot.AntiRecoil);
						ImGui::Checkbox(XorStr("Auto Stop"), &g_Options.Ragebot.AutoStop);
						ImGui::Checkbox(XorStr("Auto Crouch"), &g_Options.Ragebot.AutoCrouch);
						ImGui::Checkbox(XorStr("Auto Scope"), &g_Options.Ragebot.AutoScope);
						ImGui::Checkbox(XorStr("Fakelag"), &g_Options.Ragebot.FakeLag);
						ImGui::SliderInt(XorStr("Amount"), &g_Options.Ragebot.FakeLagAmt, 0, 15, "%1.f");

					}ImGui::EndChild();
					ImGui::SameLine();
					ImGui::BeginChild("second child", ImVec2(200, 420), true);
					{

						ImGui::PushItemWidth(184);
						ImGui::SliderFloat(("Min dmg Snipers"), &g_Options.Ragebot.MinimumDamageSniper, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Min dmg Rifles"), &g_Options.Ragebot.MinimumDamageRifle, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Min dmg Pistols"), &g_Options.Ragebot.MinimumDamagePistol, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Min dmg Heavies"), &g_Options.Ragebot.MinimumDamageHeavy, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Min dmg SMGs"), &g_Options.Ragebot.MinimumDamageSmg, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Min dmg Revolver/Deag"), &g_Options.Ragebot.MinimumDamageRevolver, 1.f, 100.f, "%.2f");
						ImGui::PushItemWidth(184);
						ImGui::Checkbox(XorStr("Hitchance Enabled"), &g_Options.Ragebot.Hitchance);
						ImGui::SliderFloat(XorStr("Snipers"), &g_Options.Ragebot.HitchanceSniper, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr("Rifles"), &g_Options.Ragebot.HitchanceRifle, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr("Pistols"), &g_Options.Ragebot.HitchancePistol, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr("SMGs"), &g_Options.Ragebot.HitchanceSmgs, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr("Heavies"), &g_Options.Ragebot.HitchanceHeavy, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr("Revolver / Deagle"), &g_Options.Ragebot.HitchanceRevolver, 0.f, 100.f, "%.1f");

					}ImGui::EndChild();
					ImGui::SameLine();
					ImGui::BeginChild("third child", ImVec2(200, 420), true);
					{
						ImGui::Text(XorStr("Accuracy"));
						//ImGui::Separator();
						ImGui::Checkbox(XorStr("Friendly Fire"), &g_Options.Ragebot.FriendlyFire);
						ImGui::Combo(XorStr("Hitbox"), &g_Options.Ragebot.Hitbox, aimBones, ARRAYSIZE(aimBones));
						ImGui::Combo(XorStr("Hitscan"), &g_Options.Ragebot.Hitscan, hitscan, ARRAYSIZE(hitscan));
						ImGui::Separator();
						ImGui::PushItemWidth(184);
						ImGui::Checkbox(XorStr("Resolver"), &g_Options.Ragebot.Resolver);
						ImGui::Text(XorStr("Bruteforce after X bullets:"));
						ImGui::SliderFloat(XorStr("Shots: "), &g_Options.Ragebot.bruteAfterX, 0, 10, "%1.f");
						ImGui::Checkbox(XorStr("Fakelag Fix"), &g_Options.Ragebot.FakeLagFix);
						ImGui::Checkbox(XorStr("Position Adjustment"), &g_Options.Ragebot.PosAdjust);
						ImGui::Text(XorStr("BAIM Key"));
						ImGui::Hotkey(XorStr("BAIM key"), &g_Options.Ragebot.BAIMkey);

					}ImGui::EndChild();
					ImGui::SameLine();
					ImGui::BeginChild("fourth child", ImVec2(200, 420), true);
					{
						ImGui::Checkbox(XorStr("Anti-Aim Enabled"), &g_Options.Ragebot.EnabledAntiAim);
						ImGui::Separator();
						if (ImGui::Button(XorStr("Pre-Set")))
						{
							g_Options.Ragebot.SubAATabs = 0;
						}
						ImGui::SameLine();
						if (ImGui::Button(XorStr("Builder")))
						{
							g_Options.Ragebot.SubAATabs = 1;
						}
						if (g_Options.Ragebot.SubAATabs == 0)
						{
							ImGui::Checkbox(XorStr("Enable"), &g_Options.Ragebot.PreAAs);
							ImGui::Combo(XorStr("Pitch"), &g_Options.Ragebot.Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
							ImGui::SliderFloat(XorStr("Pitch: "), &g_Options.Ragebot.PitchAdder, -180, 180, "%1.f");
							ImGui::Separator();
							ImGui::Combo(XorStr("Yaw"), &g_Options.Ragebot.YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));
							ImGui::SliderFloat(XorStr("Real: "), &g_Options.Ragebot.YawTrueAdder, -180, 180, "%1.f");
							ImGui::Separator();
							ImGui::Combo(XorStr("Fake-Yaw"), &g_Options.Ragebot.YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
							ImGui::SliderFloat(XorStr("Fake: "), &g_Options.Ragebot.YawFakeAdder, -180, 180, "%1.f");
							ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.LBYBreaker);
						}
						if (g_Options.Ragebot.SubAATabs == 1)
						{
							ImGui::Checkbox(XorStr("Enable"), &g_Options.Ragebot.BuilderAAs);
							ImGui::SliderFloat(XorStr("Pitch Angle: "), &g_Options.Ragebot.BuilderPitch, -89, 89, "%1.f");
							ImGui::SliderFloat(XorStr("Real Angle: "), &g_Options.Ragebot.BuilderReal, -180, 180, "%1.f");
							ImGui::SliderFloat(XorStr("Fake Angle: "), &g_Options.Ragebot.BuilderFake, -180, 180, "%1.f");
							ImGui::Checkbox(XorStr("Enable Real Jitter"), &g_Options.Ragebot.Jitter);
							ImGui::SliderFloat(XorStr("Jitter Range: "), &g_Options.Ragebot.JitterRange, -90, 90, "%1.f");
							ImGui::Checkbox(XorStr("Enable Fake Jitter"), &g_Options.Ragebot.FJitter);
							ImGui::SliderFloat(XorStr("FJitter Range: "), &g_Options.Ragebot.FJitterRange, -90, 90, "%1.f");
							ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.LBYBreaker);

						}
						ImGui::Separator();
						ImGui::Checkbox(XorStr("Moving AA"), &g_Options.Ragebot.MovingAA);
						//ImGui::Combo(XorStr("Yaw"), &g_Options.Ragebot.YawTrueMove, antiaimyawtruemove, ARRAYSIZE(antiaimyawtruemove));
						//ImGui::Combo(XorStr("Fake-Yaw"), &g_Options.Ragebot.YawFakeMove, antiaimyawfakemove, ARRAYSIZE(antiaimyawfakemove));
						ImGui::Checkbox(("At Players"), &g_Options.Ragebot.AtTarget);
						ImGui::Checkbox(XorStr("Edge"), &g_Options.Ragebot.Edge);
						ImGui::Checkbox(XorStr("AntiAim on knife"), &g_Options.Ragebot.KnifeAA);
						ImGui::PopFont();
					}ImGui::EndChild();
				}ImGui::End();
				
				}

		}
		else if (g_Options.Menu.iTab == 2)
		{
			style.WindowPadding = ImVec2(8, 8);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(840, 500));
			if (ImGui::Begin("Legitbot", &g_Options.Menu.Opened, ImVec2(840, 500), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}

				if (g_Options.Misc.BrdrClr)
				{
					style.Colors[ImGuiCol_Border] = ImVec4(r, g, b, 1.f);
					style.Colors[ImGuiCol_MenuBarBg] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}

				static int subtab1 = 0;
				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);

				ImGui::Text("                                                                                      INSIDOUS.CC");
				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				if (ImGui::Button("Back")) g_Options.Menu.iTab = 0;
				ImGui::SameLine();

				ImGui::Text("Legitbot");
				ImGui::SameLine();
				ImGui::Checkbox(XorStr("Enable"), &g_Options.Legitbot.MainSwitch);
				ImGui::SameLine();
				ImGui::Checkbox(XorStr("Rainbow Sliders"), &g_Options.Legitbot.RnbwSliders);
				if (g_Options.Legitbot.RnbwSliders)
				{
					style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}
				ImGui::BeginChild("first child", ImVec2(580, 420), true);
				{
					ImGui::PushFont(Icons3);
					SubTab(XorStr("W"), &subtab1, 0);
					SubTab(XorStr("A"), &subtab1, 1);
					SubTab(XorStr("Z"), &subtab1, 2);
					SubTab(XorStr("O"), &subtab1, 3);
					ImGui::PopFont();
					ImGui::Separator();
					ImGui::PushFont(fDefault);
					ImGui::PushItemWidth(184);
					switch (subtab1)
					{
					case 0:
					{
						ImGui::Hotkey(XorStr("##Key##0"), &g_Options.Legitbot.MainKey);
						//ImGui::Combo(("Key##0"), &g_Options.Legitbot.MainKey, keyNames, ARRAYSIZE(keyNames));
						//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxrifle, aimBones, ARRAYSIZE(aimBones));
						ImGui::SliderFloat(XorStr("Smooth##0"), &g_Options.Legitbot.MainSmooth, 1.00f, 100.00f, "%.2f");
						ImGui::SliderFloat(XorStr("FOV##0"), &g_Options.Legitbot.Mainfov, 0.00f, 30.00f, "%.2f");
						ImGui::SliderFloat(XorStr("Min RCS##0"), &g_Options.Legitbot.main_recoil_min, 1.00f, 100.00f, "%.2f");
						ImGui::SliderFloat(XorStr("Max RCS##0"), &g_Options.Legitbot.main_recoil_max, 1.00f, 100.00f, "%.2f");
						//ImGui::Text(XorStr("Prefered hitbox"));
						//ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxRifle, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
						ImGui::Separator();
						ImGui::Checkbox(("Legit Backtrack"), &g_Options.Legitbot.backtrack);
						ImGui::SameLine();
						ImGui::SliderFloat(("Ticks"), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
						ImGui::Checkbox(XorStr("Draw Fov"), &g_Options.Legitbot.DrawFov);
						ImGui::Checkbox(("Backtrack line"), &g_Options.Visuals.backtrackline);
						ImGui::Checkbox(("Auto Pistol"), &g_Options.Legitbot.AutoPistol);
						ImGui::Checkbox(("Smoke Check"), &g_Options.Legitbot.SmokeCheck);
						break;
					}
					case 1:
					{ImGui::PushItemWidth(184);
					ImGui::Hotkey(XorStr("##Key##1"), &g_Options.Legitbot.PistolKey);
					//ImGui::Combo(("Key##1"), &g_Options.Legitbot.PistolKey, keyNames, ARRAYSIZE(keyNames));
					//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxpistol, aimBones, ARRAYSIZE(aimBones));
					ImGui::SliderFloat(XorStr("Smooth##1"), &g_Options.Legitbot.PistolSmooth, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("FOV##1"), &g_Options.Legitbot.Pistolfov, 0.00f, 30.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Min RCS##1"), &g_Options.Legitbot.pistol_recoil_min, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Max RCS##1"), &g_Options.Legitbot.pistol_recoil_max, 1.00f, 100.00f, "%.2f");
					//ImGui::Text(XorStr("Prefered hitbox"));
					//ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxPistol, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
					ImGui::Separator();
					ImGui::Checkbox(("Legit Backtrack"), &g_Options.Legitbot.backtrack);
					ImGui::SliderFloat(("Ticks"), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
					ImGui::Checkbox(XorStr("Draw Fov"), &g_Options.Legitbot.DrawFov);
					ImGui::Checkbox(("Backtrack line"), &g_Options.Visuals.backtrackline);
					ImGui::Checkbox(("Auto Pistol"), &g_Options.Legitbot.AutoPistol);
					ImGui::Checkbox(("Smoke Check"), &g_Options.Legitbot.SmokeCheck);
					break;
					}
					case 2:
					{
						ImGui::PushItemWidth(184);
						ImGui::Hotkey(XorStr("##Key##2"), &g_Options.Legitbot.SniperKey);
						//ImGui::Combo(("Key##2"), &g_Options.Legitbot.SniperKey, keyNames, ARRAYSIZE(keyNames));
						//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxsniper, aimBones, ARRAYSIZE(aimBones));
						ImGui::SliderFloat(XorStr("Smooth##2"), &g_Options.Legitbot.SniperSmooth, 1.00f, 100.00f, "%.1f");
						ImGui::SliderFloat(XorStr("FOV##2"), &g_Options.Legitbot.Sniperfov, 0.00f, 30.00f, "%.2f");
						ImGui::SliderFloat(XorStr("Min RCS##2"), &g_Options.Legitbot.sniper_recoil_min, 1.00f, 100.00f, "%.2f");
						ImGui::SliderFloat(XorStr("Max RCS##2"), &g_Options.Legitbot.sniper_recoil_max, 1.00f, 100.00f, "%.2f");
						//ImGui::Text(XorStr("Prefered hitbox"));
						//ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxSniper, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
						ImGui::Separator();
						ImGui::Checkbox(("Legit Backtrack"), &g_Options.Legitbot.backtrack);
						ImGui::SameLine();
						ImGui::SliderFloat(("Ticks"), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
						ImGui::Checkbox(XorStr("Draw Fov"), &g_Options.Legitbot.DrawFov);
						ImGui::Checkbox(("Backtrack line"), &g_Options.Visuals.backtrackline);
						ImGui::Checkbox(("Auto Pistol"), &g_Options.Legitbot.AutoPistol);
						ImGui::Checkbox(("Smoke Check"), &g_Options.Legitbot.SmokeCheck);
						break;
					}
					case 3:
					{
						ImGui::PushItemWidth(184);
						ImGui::Hotkey(XorStr("##Key##5"), &g_Options.Legitbot.MainKey);
						//ImGui::Combo(("Key##9"), &g_Options.Legitbot.SmgKey, keyNames, ARRAYSIZE(keyNames));
						//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxrifle, aimBones, ARRAYSIZE(aimBones));
						ImGui::SliderFloat(XorStr("Smooth##9"), &g_Options.Legitbot.SmgSmooth, 1.00f, 100.00f, "%.2f");
						ImGui::SliderFloat(XorStr("FOV##8"), &g_Options.Legitbot.SmgFov, 0.00f, 30.00f, "%.2f");
						ImGui::SliderFloat(XorStr("Min RCS##8"), &g_Options.Legitbot.Smg_recoil_min, 1.00f, 100.00f, "%.2f");
						ImGui::SliderFloat(XorStr("Max RCS##8"), &g_Options.Legitbot.Smg_recoil_max, 1.00f, 100.00f, "%.2f");
						//ImGui::Text(XorStr("Prefered hitbox"));
						//ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxSmg, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
						ImGui::Separator();
						ImGui::Checkbox(("Legit Backtrack"), &g_Options.Legitbot.backtrack);
						ImGui::SameLine();
						ImGui::SliderFloat(("Ticks"), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
						ImGui::Checkbox(XorStr("Draw Fov"), &g_Options.Legitbot.DrawFov);
						ImGui::Checkbox(("Backtrack line"), &g_Options.Visuals.backtrackline);
						ImGui::Checkbox(("Auto Pistol"), &g_Options.Legitbot.AutoPistol);
						ImGui::Checkbox(("Smoke Check"), &g_Options.Legitbot.SmokeCheck);
						break;
						
					}
					}ImGui::EndChild();
					ImGui::SameLine();
					ImGui::BeginChild("Joku Lapsi", ImVec2(225, 420), true);
					{
						ImGui::Text("Triggerbot");
						//ImGui::Separator();
						ImGui::PushItemWidth(184);
						ImGui::Checkbox(XorStr("Enable Triggerbot"), &g_Options.Legitbot.Triggerbot.Enabled);
						//ImGui::SliderFloat(XorStr("Delay"), &g_Options.Legitbot.Triggerbot.Delay, 1.f, 150.f, "%.0f");
						ImGui::Hotkey(XorStr("Key##3"), &g_Options.Legitbot.Triggerbot.Key);
						//ImGui::Combo(("Triggerbot key"), &menu.Legitbot.Triggerbot.Key, keyNames, ARRAYSIZE(keyNames));
						ImGui::SliderFloat(XorStr("Hitchance"), &g_Options.Legitbot.Triggerbot.hitchance, 1.f, 100.f, "%.0f");

						ImGui::Text(XorStr("Filter"));

						ImGui::BeginChild(XorStr("Filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 21 * 5));
						{
							ImGui::Selectable(XorStr(" Head"), &g_Options.Legitbot.Triggerbot.Filter.Head);
							ImGui::Selectable(XorStr(" Arms"), &g_Options.Legitbot.Triggerbot.Filter.Arms);
							ImGui::Selectable(XorStr(" Chest"), &g_Options.Legitbot.Triggerbot.Filter.Chest);
							ImGui::Selectable(XorStr(" Stomach"), &g_Options.Legitbot.Triggerbot.Filter.Stomach);
							ImGui::Selectable(XorStr(" Legs"), &g_Options.Legitbot.Triggerbot.Filter.Legs);
						}ImGui::EndChild();
					}ImGui::EndChild();
					
				}ImGui::End();
			}
		}

				/*ImGui::BeginChild("second child", ImVec2(200, 420), true);
				{
					ImGui::PushFont(Icons3);
					ImGui::Text("A");
					ImGui::PopFont();
					ImGui::Separator();
					ImGui::PushFont(fDefault);
					ImGui::PushItemWidth(184);
					ImGui::Hotkey(XorStr("Key##1"), &g_Options.Legitbot.PistolKey);
					//ImGui::Combo(("Key##1"), &g_Options.Legitbot.PistolKey, keyNames, ARRAYSIZE(keyNames));
					//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxpistol, aimBones, ARRAYSIZE(aimBones));
					ImGui::SliderFloat(XorStr("Smooth##1"), &g_Options.Legitbot.PistolSmooth, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("FOV##1"), &g_Options.Legitbot.Pistolfov, 0.00f, 30.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Min RCS##1"), &g_Options.Legitbot.pistol_recoil_min, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Max RCS##1"), &g_Options.Legitbot.pistol_recoil_max, 1.00f, 100.00f, "%.2f");
					ImGui::Separator();
					ImGui::Text(XorStr("HitBoxes"));
					ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxPistol, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
					ImGui::PopFont();
				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("third child", ImVec2(200, 420), true);
				{
					ImGui::PushFont(Icons3);
					ImGui::Text("Z");
					ImGui::PopFont();
					ImGui::Separator();
					ImGui::PushFont(fDefault);
					ImGui::PushItemWidth(184);
					ImGui::Hotkey(XorStr("Key##2"), &g_Options.Legitbot.SniperKey);
					//ImGui::Combo(("Key##2"), &g_Options.Legitbot.SniperKey, keyNames, ARRAYSIZE(keyNames));
					//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxsniper, aimBones, ARRAYSIZE(aimBones));
					ImGui::SliderFloat(XorStr("Smooth##2"), &g_Options.Legitbot.SniperSmooth, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("FOV##2"), &g_Options.Legitbot.Sniperfov, 0.00f, 30.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Min RCS##2"), &g_Options.Legitbot.sniper_recoil_min, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Max RCS##2"), &g_Options.Legitbot.sniper_recoil_max, 1.00f, 100.00f, "%.2f");
					ImGui::Separator();
					ImGui::Text(XorStr("HitBoxes"));
					ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxSniper, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
					ImGui::PopFont();
				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("fourth child", ImVec2(200, 420), true);
				{
					ImGui::PushFont(Icons3);
					ImGui::Text("O");
					ImGui::PopFont();
					ImGui::Separator();
					ImGui::PushFont(fDefault);
					ImGui::PushItemWidth(184);
					ImGui::Hotkey(XorStr("Key##0"), &g_Options.Legitbot.MainKey);
					//ImGui::Combo(("Key##9"), &g_Options.Legitbot.SmgKey, keyNames, ARRAYSIZE(keyNames));
					//ImGui::Combo(XorStr("Hitbox"), &g_Options.Legitbot.hitboxrifle, aimBones, ARRAYSIZE(aimBones));
					ImGui::SliderFloat(XorStr("Smooth##9"), &g_Options.Legitbot.SmgSmooth, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("FOV##8"), &g_Options.Legitbot.SmgFov, 0.00f, 30.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Min RCS##8"), &g_Options.Legitbot.Smg_recoil_min, 1.00f, 100.00f, "%.2f");
					ImGui::SliderFloat(XorStr("Max RCS##8"), &g_Options.Legitbot.Smg_recoil_max, 1.00f, 100.00f, "%.2f");
					ImGui::Separator();
					ImGui::Text(XorStr("HitBoxes"));
					ImGui::Combo("##hitbox", &g_Options.Legitbot.hitboxSmg, iHitboxLegit, ARRAYSIZE(iHitboxLegit));
					ImGui::PopFont();
					}ImGui::EndChild();
				}*/
			
		
		else if (g_Options.Menu.iTab == 3)
		{
			style.WindowPadding = ImVec2(8, 8);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(840, 500));
			if (ImGui::Begin("Visuals", &g_Options.Menu.Opened, ImVec2(840, 500), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}
				if (g_Options.Misc.BrdrClr)
				{
					style.Colors[ImGuiCol_Border] = ImVec4(r, g, b, 1.f);
					style.Colors[ImGuiCol_MenuBarBg] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}

				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);

				ImGui::Text("                                                                                      INSIDOUS.CC");

				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				if (ImGui::Button("Back")) g_Options.Menu.iTab = 0;
				ImGui::SameLine();


				ImGui::Text("Visuals");
				ImGui::BeginChild("first child", ImVec2(200, 420), true);
				{
					ImGui::Checkbox(XorStr("Box"), &g_Options.Visuals.Box);
					ImGui::Combo("##boxkek", &g_Options.Visuals.BoxType, "Full\0\rCorners\0\r3D\0\0", -1);
					ImGui::Checkbox(XorStr("Skeleton"), &g_Options.Visuals.Skeleton);
					ImGui::Checkbox(XorStr("Name"), &g_Options.Visuals.Name);
					ImGui::Checkbox(XorStr("Weapon"), &g_Options.Visuals.Weapon);
					ImGui::Checkbox(XorStr("Armor"), &g_Options.Visuals.Armor);
					ImGui::Checkbox(XorStr("Health"), &g_Options.Visuals.health);
					ImGui::Checkbox(XorStr("Money"), &g_Options.Visuals.Money);
					ImGui::Checkbox(XorStr("Callout"), &g_Options.Visuals.Callout);
					ImGui::Checkbox(XorStr("Grenade Prediction"), &g_Options.Visuals.GrenadePrediction);
					ImGui::Checkbox(XorStr("Spread Crosshair"), &g_Options.Visuals.Crosshair);
					ImGui::Checkbox(XorStr("Recoil Crosshair"), &g_Options.Visuals.RecoilCrosshair);
					ImGui::Checkbox(XorStr("Distance"), &g_Options.Visuals.Distance);
					ImGui::Checkbox(XorStr("Aimlines"), &g_Options.Visuals.AimLine);
					ImGui::Checkbox(XorStr("Bomb ESP"), &g_Options.Visuals.Bomb);
					ImGui::Checkbox(XorStr("Grenades"), &g_Options.Visuals.Grenades);
					ImGui::Checkbox(XorStr("Radar"), &g_Options.Visuals.radar);

				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("second child", ImVec2(200, 420), true);
				{
					ImGui::Text("Custom-Skybox:");
					ImGui::PushItemWidth(146);
					ImGui::Combo(("##aadk342"), &g_Options.Misc.Skybox, skybox_items, _ARRAYSIZE(skybox_items));
					ImGui::Separator();
					ImGui::PushItemWidth(184);
					ImGui::SliderFloat(XorStr("FOV"), &g_Options.Visuals.FOVChanger, 0, 60, "%.0f");
					ImGui::SliderFloat(XorStr("VFOV"), &g_Options.Visuals.viewmodelChanger, 0, 130, "%.0f");
					ImGui::Checkbox(XorStr("No Smoke"), &g_Options.Visuals.NoSmoke);
					ImGui::Checkbox(XorStr("No Flash"), &g_Options.Visuals.NoFlash);
					ImGui::Checkbox(XorStr("No Scope"), &g_Options.Visuals.noscopeborder);
					ImGui::Separator();
					ImGui::Checkbox(XorStr("Angle Lines"), &g_Options.Visuals.angleLines);
					ImGui::Checkbox(XorStr("aWall Indicator"), &g_Options.Visuals.DrawAwall);
					ImGui::Checkbox(XorStr("Spectators"), &g_Options.Visuals.speclist);
					ImGui::Checkbox(("Dynamic Light"), &g_Options.Visuals.DLight);
					ImGui::Checkbox(("Enemy Scoped"), &g_Options.Visuals.Scoped);
					ImGui::Checkbox(("Enemy Reloading"), &g_Options.Visuals.Reloading);
					ImGui::Checkbox(XorStr("Enemy Flashed?"), &g_Options.Visuals.Flashed);
					ImGui::Checkbox(("Time"), &g_Options.Visuals.Time);
					ImGui::Checkbox(("NoVisualRecoil"), &g_Options.Visuals.NoVisualRecoil);
				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("third child", ImVec2(200, 420), true);
				{
					ImGui::Text("Transparencies");
					ImGui::Separator();
					ImGui::Text("Weapon");
						ImGui::PushItemWidth(184);
						ImGui::SliderInt(XorStr(" ##wga"), &g_Options.Visuals.weaponglowalpha, 0, 100);
						ImGui::Separator();
						ImGui::Text("Bomb");
						ImGui::PushItemWidth(184);
						ImGui::SliderInt(XorStr(" ##bga"), &g_Options.Visuals.bombglowalpha, 0, 100);
						ImGui::Separator();
						ImGui::Text("Chams");
						ImGui::PushItemWidth(184);
						ImGui::SliderInt(XorStr(" ##pca"), &g_Options.Visuals.champlayeralpha, 0, 100);
						ImGui::Separator();
						ImGui::Text("Hands");
						ImGui::SliderInt(XorStr(" ##hca"), &g_Options.Visuals.chamhandalpha, 0, 100);
						ImGui::Separator();
						ImGui::Text("Glow");
						ImGui::SliderInt(XorStr(" ##pga"), &g_Options.Visuals.playerglowalpha, 0, 100);
						ImGui::Text("ChamVModel");
						ImGui::SliderInt(XorStr(" ##wca"), &g_Options.Visuals.weaponhandalpha, 0, 100);
						ImGui::Separator();


						ImGui::EndChild();
						ImGui::SameLine();
					}

				

				ImGui::BeginChild("fourth child", ImVec2(200, 420), true);
				{
					ImGui::Text("Filters");
					ImGui::Separator();
					ImGui::Checkbox(XorStr("Team ESP"), &g_Options.Visuals.TeamESP);
					ImGui::Checkbox(XorStr("Glow Players"), &g_Options.Visuals.glowplayer);
					ImGui::Checkbox(XorStr("Glow Team"), &g_Options.Visuals.teamglow);
					ImGui::Separator();
					ImGui::Text("Chams");
					ImGui::Checkbox(XorStr("Cham Players"), &g_Options.Visuals.Chams);
					ImGui::Checkbox(XorStr("Cham Team"), &g_Options.Visuals.Teamchams);
					ImGui::Checkbox(XorStr("Cham Hands"), &g_Options.Visuals.handcham);
					ImGui::Checkbox(XorStr("Cham Weapon"), &g_Options.Visuals.Chamweapon);
					ImGui::Checkbox(XorStr("Cham Viewmodel"), &g_Options.Visuals.weaponviewcham);
					ImGui::Checkbox(XorStr("XQZ"), &g_Options.Visuals.XQZ);
					ImGui::Text("Styles");
					ImGui::Separator();
					ImGui::PushItemWidth(184);
					ImGui::Text(XorStr("Chams"));
					ImGui::Combo("##sdgl", &g_Options.Visuals.matierial, "Normal\0\rFlat\0\rWireframe\0\rGlass\0\rGold\0\rPlatinum\0\rPlastic\0\rCrystal\0\0", -1);
					ImGui::Text(XorStr("Hands"));
					ImGui::Combo("##aw43", &g_Options.Visuals.handmat, "Normal\0\rFlat\0\rWireframe\0\rGlass\0\rGold\0\rPlatinum\0\rPlastic\0\rCrystal\0\0", -1);
					ImGui::Text(XorStr("Weapons"));
					ImGui::Combo("##sdgl2", &g_Options.Visuals.weaponmat, "Normal\0\rFlat\0\rWireframe\0\rGlass\0\rGold\0\rPlatinum\0\rPlastic\0\rCrystal\0\0", -1);
				}ImGui::EndChild();


			}ImGui::End();
		}
		else if (g_Options.Menu.iTab == 4)
		{

			style.WindowPadding = ImVec2(8, 8);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(840, 500));
			if (ImGui::Begin("Misc", &g_Options.Menu.Opened, ImVec2(840, 500), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}
				if (g_Options.Misc.BrdrClr)
				{
					style.Colors[ImGuiCol_Border] = ImVec4(r, g, b, 1.f);
					style.Colors[ImGuiCol_MenuBarBg] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}

				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);

				ImGui::Text("                                                                                      INSIDOUS.CC");
				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				if (ImGui::Button("Back")) g_Options.Menu.iTab = 0;
				ImGui::SameLine();

				ImGui::Text("Misc");
				ImGui::BeginChild("first child", ImVec2(200, 420), true);
				{
					ImGui::Checkbox("Anti-Untrusted", &g_Options.Misc.antiuntrusted);
					ImGui::Checkbox("Auto Accept", &g_Options.Misc.AutoAccept);
					ImGui::Checkbox("Show Ranks", &g_Options.Misc.ServerRankRevealAll);
					ImGui::Checkbox("SlideWalk", &g_Options.Misc.MoonWalk);
					ImGui::Separator();
					ImGui::Text("FakePing Amount");
					ImGui::SliderInt(XorStr("##fakeping"), &g_Options.Misc.FakePing2, 0.f, 900.f, "%.0f"); //pFakePing
					ImGui::Separator();
					ImGui::Text("Config");
					ImGui::Combo(("File"), &g_Options.Menu.ConfigFile, configFiles, ARRAYSIZE(configFiles));
					if (ImGui::Button("Save Config")) Config->Save();

					if (ImGui::Button("Load Config")) Config->Load();
				

				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("second child", ImVec2(200, 420), true);
				{
					ImGui::Text("ClanTags");
					ImGui::Checkbox("Clantags Enabled", &g_Options.Misc.clantagsxd);
					ImGui::Combo("##clantagsxd", &g_Options.Misc.syncclantags, "None\0\rInsidous1\0\rInsidous2\0\rGay\0\rStatic\0\0", -1);
					ImGui::Separator();
					ImGui::Text("ChatSpams");
					ImGui::Combo(("##ChatSpams"), &g_Options.Misc.spammer, spammers, ARRAYSIZE(spammers));
					ImGui::Separator();
					ImGui::Text("2Click = noname");
					if (ImGui::Button("Noname"))
					{
						static ConVar* name = g_CVar->FindVar("name");
						if (name)
						{
							*(int*)((DWORD)&name->fnChangeCallback + 0xC) = NULL;
							name->SetValue("\n\xAD\xAD\xAD");
						}
					}
					ImGui::Separator();
					ImGui::Text("LogEvents");
					ImGui::Checkbox("DmgInfo", &g_Options.Misc.DmgInfo);
					ImGui::Checkbox("DmgInfo in chat", &g_Options.Misc.DmgInfo2);
					ImGui::Checkbox("PurchaseInfo", &g_Options.Misc.PurchaseInfo);
					ImGui::Separator();
					ImGui::Checkbox("Color Switching menu", &g_Options.Misc.BrdrClr);


				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("third child", ImVec2(200, 420), true);
				{
					ImGui::Checkbox(XorStr("Bunny Hop"), &g_Options.Misc.Bhop);
					ImGui::Checkbox(XorStr("AutoStrafe"), &g_Options.Misc.AutoStrafe);
					ImGui::Checkbox(("FPS Boost"), &g_Options.Misc.fps);
					ImGui::Checkbox(XorStr("Nightmode"), &g_Options.Misc.nightMode);
					ImGui::Checkbox(("Chrome  World"), &g_Options.Misc.ChromeWorld);
					ImGui::Checkbox(("LsdMode"), &g_Options.Misc.crack);
					ImGui::Checkbox(("GrayMode"), &g_Options.Misc.Gray);
					ImGui::Checkbox(XorStr("LeftHandedKnife"), &g_Options.Misc.KnifeHand);
					ImGui::Checkbox(XorStr("Legit Bhop"), &g_Options.Misc.legitBhop);
					ImGui::Checkbox(XorStr("LegitAA"), &g_Options.Legitbot.LAA);
					ImGui::Checkbox(XorStr("Inventory ON"), &g_Options.Misc.inventoryalwayson);
					ImGui::Separator();
					ImGui::Checkbox(XorStr("Thirdperson"), &g_Options.Visuals.ThirdPerson);
					ImGui::SliderFloat(XorStr("##tpdist"), &g_Options.Visuals.tpdist, 50.f, 450.f, "%.0f");
					ImGui::SameLine();
					ImGui::Text("Distance");
					ImGui::Separator();
					ImGui::Checkbox(XorStr("Hitmarker"), &g_Options.Visuals.Hitmarker);
					ImGui::Separator();
					ImGui::Text(XorStr("HitSound:"));
					ImGui::Combo(XorStr("##asad4asds"), &g_Options.Visuals.Hitsound, HitmarkSound, ARRAYSIZE(HitmarkSound));

				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("fourth child", ImVec2(200, 420), true);
				{
					ImGui::PushFont(fDefault);
					ImGui::PushItemWidth(184);
					ImGui::Text("BoxEsp Toggle/Hotkey");
					ImGui::Hotkey(("BoxHotkey"), &g_Options.Visuals.BoxHotkey);
					ImGui::Separator();
					ImGui::Text("Skeleton Toggle/Hotkey");
					ImGui::Hotkey(("SkeleHotkey"), &g_Options.Visuals.SkeleHotkey);
					ImGui::Separator();
					ImGui::Text(XorStr("ThirdPerson Toggle/Hotkey"));
					ImGui::Hotkey(("##TPKey"), &g_Options.Visuals.TPKey);
					ImGui::Separator();
					ImGui::Text(XorStr("Radar Toggle/Hotkey"));
					ImGui::Hotkey(("##RadKey"), &g_Options.Visuals.RadarHotkey);

					ImGui::PopFont();
				}ImGui::EndChild();
			}ImGui::End();
		}
		else if (g_Options.Menu.iTab == 5)
		{

			style.WindowPadding = ImVec2(8, 8);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(840, 500));
			static char filterWeapons[32];
			static char filterSkins[32];

			if (ImGui::Begin(XorStr("Skinchanger"), &g_Options.Menu.Opened, ImVec2(840, 500), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}

				if (g_Options.Misc.BrdrClr)
				{
					style.Colors[ImGuiCol_Border] = ImVec4(r, g, b, 1.f);
					style.Colors[ImGuiCol_MenuBarBg] = ImVec4(r, g, b, 1.f);
				}
				else
				{
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
					style.Colors[ImGuiCol_Border] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);
				}

				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54117647058f, 0.16470588235f, 0.8862745098f, 1.00f);

				ImGui::Text("                                                                                      INSIDOUS.CC");
				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				if (ImGui::Button(XorStr("Back"))) g_Options.Menu.iTab = 0;
				ImGui::SameLine();


				ImGui::Checkbox(XorStr("Skinchanger"), &g_Options.Skinchanger.Enabled);
				ImGui::SameLine();
				ImGui::Checkbox(XorStr("WeaponNamesOn"), &g_Options.Skinchanger.WeaponTags);
				ImGui::SameLine();
				ImGui::Checkbox(XorStr("Stattrak Weapons"), &g_Options.Skinchanger.StattrakOn);
				ImGui::BeginChild("first child", ImVec2(200, 420), true);
				{
					ImGui::PushItemWidth(-1);
					ImGui::InputText(XorStr("##FILTERWEAPONS"), filterWeapons, IM_ARRAYSIZE(filterWeapons));
					ImGui::PopItemWidth();
					ImGui::ListBoxHeader(XorStr("##GUNS"), ImVec2(-1, -1));
					for (auto it : ItemDefinitionIndexMap)
					{
						bool isDefault = (int)it.first < 0;
						if (!isDefault && !Contains(ToLower(std::string(filterWeapons)), ToLower(ItemDefinitionIndexMap.at(it.first).entityName)))
							continue;

						if (IsUtility(it.first))
							continue;

						const bool item_selected = ((int)it.first == (int)g_Options.Menu.currentWeapon);
						ImGui::PushID((int)it.first);
						std::string formattedName;

						formattedName = ItemDefinitionIndexMap.at(it.first).entityName;
						if (ImGui::Selectable(formattedName.c_str(), item_selected))
						{
							g_Options.Menu.currentWeapon = (int)it.first;
						}
						//ImGui::PopID();
					}
					ImGui::ListBoxFooter();
				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("second child", ImVec2(200, 420), true);
				{
					std::string skinName = weaponnames(g_Options.Menu.currentWeapon);
					{
						ImGui::PushItemWidth(-1);
						ImGui::InputText(XorStr("##FILTERSKINS"), filterSkins, IM_ARRAYSIZE(filterSkins));
						ImGui::InputInt(XorStr("##custom ID"), &g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin);
						ImGui::PopItemWidth();
						ImGui::ListBoxHeader(XorStr("##SKINS"), ImVec2(-1, -1));
						std::string skinStr = "";
						int curItem = -1;
						int s = 0;
						for (auto skin : g_Options.Skinchanger.weaponSkins[skinName])
						{
							int pk = g_Options.Skinchanger.skinMap[skin].paintkit;
							if (pk == g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin)
								curItem = s;
							bool selected = g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin == pk;

							skinStr = g_Options.Skinchanger.skinNames[g_Options.Skinchanger.skinMap[skin].tagName].c_str();
							skinStr += " | ";
							skinStr += std::to_string(g_Options.Skinchanger.skinMap[skin].paintkit);
							if (!Contains(ToLower(std::string(filterSkins)), ToLower(skinStr)))
								continue;
							if (ImGui::Selectable(skinStr.c_str(), selected))
							{
								pk = g_Options.Skinchanger.skinMap[skin].paintkit;
								g_Options.Skinchanger.W[g_Options.Menu.currentWeapon].ChangerSkin = pk;
								
								break;
							}
							s++;
						}

						ImGui::ListBoxFooter();
					}
				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("third child", ImVec2(200, 420), true);
				{
					ImGui::ListBoxHeader("##KNIVES", ImVec2(-1, -1));
					{
						if (ImGui::RadioButton(XorStr("Default"), &g_Options.Skinchanger.knifemodel, 0))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Bayonet"), &g_Options.Skinchanger.knifemodel, 1))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Flip Knife"), &g_Options.Skinchanger.knifemodel, 2))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Gut Knife"), &g_Options.Skinchanger.knifemodel, 3))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Karambit"), &g_Options.Skinchanger.knifemodel, 4))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("M9 Bayonet"), &g_Options.Skinchanger.knifemodel, 5))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Huntsman"), &g_Options.Skinchanger.knifemodel, 6))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Falchion"), &g_Options.Skinchanger.knifemodel, 7))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Bowie"), &g_Options.Skinchanger.knifemodel, 8))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Butterfly Knife"), &g_Options.Skinchanger.knifemodel, 9))
						{
							;
						}
						if (ImGui::RadioButton(XorStr("Shadow Daggers"), &g_Options.Skinchanger.knifemodel, 10))
						{
							;
						}
					}
					ImGui::ListBoxFooter();
				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("fourth child", ImVec2(200, 420), true);
				{
					if (ImGui::RadioButton(XorStr("Bloodhound"), &g_Options.Skinchanger.glove, 1))
					{
						;
					}
					if (ImGui::RadioButton(XorStr("Sport"), &g_Options.Skinchanger.glove, 2))
					{
						;
					}
					if (ImGui::RadioButton(XorStr("Driver"), &g_Options.Skinchanger.glove, 3))
					{
						;
					}
					if (ImGui::RadioButton(XorStr("Hand Wraps"), &g_Options.Skinchanger.glove, 4))
					{
						;
					}
					if (ImGui::RadioButton(XorStr("Motorcycle"), &g_Options.Skinchanger.glove, 5))
					{
						;
					}
					if (ImGui::RadioButton(XorStr("Specialist"), &g_Options.Skinchanger.glove, 6))
					{
						;
					}
					if (ImGui::RadioButton(XorStr("Hydra"), &g_Options.Skinchanger.glove, 7))
					{
						;
					}

					const char* gstr;
					if (g_Options.Skinchanger.glove == 1)
					{
						gstr = "Charred\0\rSnakebite\0\rBronzed\0\rGuerilla\0\0";
					}
					else if (g_Options.Skinchanger.glove == 2)
					{
						gstr = "Hedge Maze\0\rPandoras Box\0\rSuperconductor\0\rArid\0\rAmphibious\0\rVice\0\0";
					}
					else if (g_Options.Skinchanger.glove == 3)
					{
						gstr = "Lunar Weave\0\rConvoy\0\rCrimson Weave\0\rDiamondback\0\rImperial Blade\0\0";
					}
					else if (g_Options.Skinchanger.glove == 4)
					{
						gstr = "Leather\0\rSpruce DDPAT\0\rSlaughter\0\rBadlands\0\0";
					}
					else if (g_Options.Skinchanger.glove == 5)
					{
						gstr = "Eclipse\0\rSpearmint\0\rBoom!\0\rCool Mint\0\rPOW\0\rPolygon\0\0";
					}
					else if (g_Options.Skinchanger.glove == 6)
					{
						gstr = "Forest DDPAT\0\rCrimson Kimono\0\rEmerald Web\0\rFoundation\0\rFade\0\0";
					}
					else if (g_Options.Skinchanger.glove == 7)
					{
						gstr = "Case Hardened\0\rEmerald\0\rRattler\0\rMangrove\0\0";
					}
					else
					{
						gstr = "";
					}
					ImGui::PushItemWidth(-1);
					if (ImGui::Combo(XorStr("##2"), &g_Options.Skinchanger.gloeskin, gstr, -1))
					

					ImGui::PopItemWidth();

				}ImGui::EndChild();

				if (ImGui::Button(XorStr("Full Update"), ImVec2(-1, 20))) FullUpdate();
			}ImGui::End();

			}
		else if (g_Options.Menu.iTab == 6)
		{

			style.WindowPadding = ImVec2(8, 8);
			style.ItemSpacing = ImVec2(8, 4);
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(840, 500));
			if (ImGui::Begin("Colors", &g_Options.Menu.Opened, ImVec2(840, 500), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ShowBorders))
			{

				static float r = 1.0f;
				static float g = 0.f;
				static float b = 0.f;

				if (r == 1.f && g >= 0.f && b <= 0.f)
				{
					g += 0.005f;
					b = 0.f;
				}
				if (r <= 1.f && g >= 1.f && b == 0.f)
				{
					g = 1.f;
					r -= 0.005f;
				}
				if (r <= 0.f && g == 1.f && b >= 0.f)
				{
					r = 0.f;
					b += 0.005f;
				}
				if (r == 0.f && g <= 1.f && b >= 1.f)
				{
					b = 1.f;
					g -= 0.005f;
				}
				if (r >= 0.f && g <= 0.f && b == 1.f)
				{
					g = 0.f;
					r += 0.005f;
				}
				if (r >= 1.f && g >= 0.f && b <= 1.f)
				{
					r = 1.f;
					b -= 0.005f;
				}



				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0, 0, 1);
				style.Colors[ImGuiCol_Text] = ImVec4(r, g, b, 1.f);
				ImGui::Text("                                                                                      INSIDOUS.CC");
				style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
				if (ImGui::Button("Back")) g_Options.Menu.iTab = 0;
				ImGui::SameLine();

				ImGui::Text("Colors");
				ImGui::BeginChild("first child", ImVec2(200, 420), true);
				{
					ImGui::Text(XorStr("ESP Colors"));
					ImGui::Separator();
					ImGui::MyColorEdit3("##teamglow", g_Options.Colors.TeamGlow, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("TeamGlow Colors"));

					ImGui::MyColorEdit3("##EdddSP", g_Options.Colors.EnemyESP, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("EnemyESP Colors"));

					ImGui::MyColorEdit3("##glow", g_Options.Colors.EnemyGlow, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("EnemyGlow Colors"));

					ImGui::MyColorEdit3("##ESP2", g_Options.Colors.TeamESP, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("TeamESP Colors"));

					ImGui::MyColorEdit3(XorStr("##04593"), (float*)&g_Options.Colors.color_skeleton, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Skeleton Color"));

					ImGui::MyColorEdit3(XorStr("##95340"), (float*)&g_Options.Colors.color_recoil, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Recoil Crosshair Color"));

					ImGui::MyColorEdit3(XorStr("##23452"), (float*)&g_Options.Colors.color_spread, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Spread Crosshair Color"));

					ImGui::MyColorEdit3(XorStr("##232gd"), (float*)&g_Options.Colors.backtrackdots_color, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Backtrack Ticks Color"));

					ImGui::MyColorEdit3(XorStr("##272gd"), (float*)&g_Options.Colors.backtrackdotsR_color, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("RageBacktrackTicks Color"));

				}ImGui::EndChild();
				ImGui::SameLine();


					ImGui::BeginChild("second child", ImVec2(200, 420), true);
					{
						ImGui::Text(XorStr("Chams Colors"));
						ImGui::Separator();
						ImGui::MyColorEdit3("##45ESP", g_Options.Colors.EnemyChamsVis, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("EnemyChamsVis Colors"));

						ImGui::MyColorEdit3("##E772SP", g_Options.Colors.TeamChamsVis, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("TeamChamsVis Colors"));

						ImGui::MyColorEdit3("##43ESP", g_Options.Colors.EnemyChamsNVis, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("EnemyChamsInvis Colors"));

						ImGui::MyColorEdit3("##ES234P", g_Options.Colors.HandCham, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("HandsChams Colors"));

						ImGui::MyColorEdit3("##45ESs", g_Options.Colors.HandsColor, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("Hand Colors"));

					}ImGui::EndChild();
					ImGui::SameLine();

					ImGui::BeginChild("Third child", ImVec2(200, 420), true);
					{
						ImGui::Text(XorStr("Weapon Colors"));
						ImGui::Separator();
						ImGui::MyColorEdit3("##Easd445SP", g_Options.Colors.WeaponViewCham, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("WeaponViewChams Color"));

						ImGui::MyColorEdit3("##ESP", g_Options.Colors.WeaponGlow, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("WeaponGlow Color"));

						ImGui::MyColorEdit3("##ESP", g_Options.Colors.C4glow, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("C4Glow Colors"));

						ImGui::MyColorEdit3(("##fd5432"), g_Options.Colors.hitmark_color, 1 << 7);
						ImGui::SameLine();
						ImGui::Text(XorStr("HitMarker Color"));

				}ImGui::EndChild();
				ImGui::SameLine();

				ImGui::BeginChild("Fourth child", ImVec2(200, 420), true);
				{
					ImGui::Text(XorStr("Grenade Txt Colors"));
					ImGui::Separator();
					ImGui::MyColorEdit3(XorStr("##5352"), (float*)&g_Options.Colors.MolotovC, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Molotov Txt Color"));

					ImGui::MyColorEdit3(XorStr("##5752"), (float*)&g_Options.Colors.Smoke, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Smoke Txt Color"));

					ImGui::MyColorEdit3(XorStr("##5392"), (float*)&g_Options.Colors.Decoy, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Decoy Txt Color"));

					ImGui::MyColorEdit3(XorStr("##5952"), (float*)&g_Options.Colors.Incendiary, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Incendiary Txt Color"));

					ImGui::MyColorEdit3(XorStr("##535252"), (float*)&g_Options.Colors.HeG, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("He Grenade Txt Color"));

					ImGui::MyColorEdit3(XorStr("##5962"), (float*)&g_Options.Colors.Flash, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("Flashbang Txt Color"));
					ImGui::Separator();

					ImGui::MyColorEdit3(XorStr("##1234"), (float*)&g_Options.Colors.tracer_color, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("GrenadePred Color"));

					ImGui::MyColorEdit3(("##kl423"), (float*)&g_Options.Colors.GrenadePredEnd, 1 << 7);
					ImGui::SameLine();
					ImGui::Text(XorStr("GrenadePredEnd"));

				}ImGui::EndChild();
			}ImGui::End();
		}
		}

	}
