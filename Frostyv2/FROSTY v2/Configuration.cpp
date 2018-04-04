#include "Configuration.hpp"
#include "Variables.h"
#include <winerror.h>
#pragma warning( disable : 4091)
#include <ShlObj.h>
#include <string>
#include <sstream>
#include "XorStr.hpp"
#include "HookIncludes.h"


const char* GetWeaponName(int iWeaponID)
{
	switch (iWeaponID)
	{
	default:
		return "none";
	case WEAPON_DEAGLE:
		return "deagle";
	case WEAPON_DUALS:
		return "duals";
	case WEAPON_FIVE7:
		return "five7";
	case WEAPON_GLOCK:
		return "glock";
	case WEAPON_AK47:
		return "ak47";
	case WEAPON_AUG:
		return "aug";
	case WEAPON_AWP:
		return "awp";
	case WEAPON_FAMAS:
		return "famas";
	case WEAPON_G3SG1:
		return "g3sg1";
	case WEAPON_GALIL:
		return "galil";
	case WEAPON_M249:
		return "m249";
	case WEAPON_M4A1:
		return "m4a4";
	case WEAPON_MAC10:
		return "mac10";
	case WEAPON_P90:
		return "p90";
	case WEAPON_UMP45:
		return "ump45";
	case WEAPON_XM1014:
		return "xm1014";
	case WEAPON_BIZON:
		return "bizon";
	case WEAPON_MAG7:
		return "mag7";
	case WEAPON_NEGEV:
		return "negev";
	case WEAPON_SAWEDOFF:
		return "sawedoff";
	case WEAPON_TEC9:
		return "tec9";
	case WEAPON_TASER:
		return "taser";
	case WEAPON_USPS:
		return "usp-s";
	case WEAPON_MP7:
		return "mp7";
	case WEAPON_MP9:
		return "mp9";
	case WEAPON_NOVA:
		return "nova";
	case WEAPON_P250:
		return "p250";
	case WEAPON_SCAR20:
		return "scar20";
	case WEAPON_SG553:
		return "sg556";
	case WEAPON_SCOUT:
		return "ssg08";
	case WEAPON_M4A1S:
		return "m4a1-s";
	case WEAPON_P2000:
		return "p2000";
	case WEAPON_CZ75:
		return "cz75";
	case WEAPON_REVOLVER:
		return "revolver";
	case WEAPON_KNIFE_BAYONET:
		return "bayonet";
	case WEAPON_KNIFE_BUTTERFLY:
		return "butterfly";
	case WEAPON_KNIFE_FALCHION:
		return "falchion";
	case WEAPON_KNIFE_FLIP:
		return "flip";
	case WEAPON_KNIFE_GUT:
		return "gut";
	case WEAPON_KNIFE_KARAMBIT:
		return "karambit";
	case WEAPON_KNIFE_M9BAYONET:
		return "m9";
	case WEAPON_KNIFE_HUNTSMAN:
		return "huntsman";
	case WEAPON_KNIFE_BOWIE:
		return "bowie";
	case WEAPON_KNIFE_DAGGER:
		return "daggers";
	}
}

void CConfig::Setup()
{
	

	SetupValue(g_Options.Ragebot.MainSwitch, false, ("Ragebot"), ("RageToggle"));
	SetupValue(g_Options.Ragebot.Enabled, false, ("Ragebot"), ("Enabled"));
	SetupValue(g_Options.Ragebot.AutoFire, false, ("Ragebot"), ("AutoFire"));
	SetupValue(g_Options.Ragebot.FOV, 0.f, ("Ragebot"), ("FOV"));
	SetupValue(g_Options.Ragebot.Silent, false, ("Ragebot"), ("Silent"));
	SetupValue(g_Options.Ragebot.AutoPistol, false, ("Ragebot"), ("AutoPistol"));
	SetupValue(g_Options.Ragebot.KeyPress, 0, ("Ragebot"), ("Key"));


	SetupValue(g_Options.Ragebot.EnabledAntiAim, false, ("Ragebot"), ("AntiaimEnabled"));
	SetupValue(g_Options.Ragebot.PreAAs, false, ("Ragebot"), ("Pre-set-AAs"));
	SetupValue(g_Options.Ragebot.Pitch, 0, ("Ragebot"), ("AntiaimPitch"));
	SetupValue(g_Options.Ragebot.YawTrue, 0, ("Ragebot"), ("AntiaimYaw-true"));
	SetupValue(g_Options.Ragebot.YawFake, 0, ("Ragebot"), ("AntiaimYaw-fake"));
	SetupValue(g_Options.Ragebot.AtTarget, false, ("Ragebot"), ("attargets"));
	SetupValue(g_Options.Ragebot.Edge, false, ("Ragebot"), ("edge"));
	SetupValue(g_Options.Ragebot.KnifeAA, false, ("Ragebot"), ("KnifeAA"));
	SetupValue(g_Options.Ragebot.BuilderAAs, false, ("Ragebot"), ("Builder-AAs"));
	SetupValue(g_Options.Ragebot.BuilderPitch, 0, ("Ragebot"), ("Builder-Pitch"));
	SetupValue(g_Options.Ragebot.BuilderReal, 0, ("Ragebot"), ("Builder-Yaw"));
	SetupValue(g_Options.Ragebot.BuilderFake, 0, ("Ragebot"), ("Builder-Fake"));
	SetupValue(g_Options.Ragebot.Jitter, false, ("Ragebot"), ("Builder-Jitter"));
	SetupValue(g_Options.Ragebot.JitterRange, 0, ("Ragebot"), ("Builder-Jitter-Range"));
	SetupValue(g_Options.Ragebot.FJitter, false, ("Ragebot"), ("Builder-fJitter"));
	SetupValue(g_Options.Ragebot.FJitterRange, 0, ("Ragebot"), ("Builder-fJitter-Range"));
	SetupValue(g_Options.Ragebot.LBYBreaker, false, ("Ragebot"), ("Builder-LBY-Breaker"));
	SetupValue(g_Options.Ragebot.FakeLag, false, ("Ragebot"), ("Fakelag"));
	SetupValue(g_Options.Ragebot.FakeLagAmt, 0, ("Ragebot"), ("Fakelag Amount"));

	SetupValue(g_Options.Ragebot.FriendlyFire, false, ("Ragebot"), ("FriendlyFire"));
	SetupValue(g_Options.Ragebot.Hitbox, 0, ("Ragebot"), ("Hitbox"));
	SetupValue(g_Options.Ragebot.Hitscan, 0, ("Ragebot"), ("Hitscan"));

	SetupValue(g_Options.Ragebot.AntiRecoil, false, ("Ragebot"), ("AntiRecoil"));
	SetupValue(g_Options.Ragebot.AutoStop, false, ("Ragebot"), ("AutoStop"));
	SetupValue(g_Options.Ragebot.AutoCrouch, false, ("Ragebot"), ("AutoCrouch"));
	SetupValue(g_Options.Ragebot.AutoScope, false, ("Ragebot"), ("AutoScope"));
	SetupValue(g_Options.Ragebot.MinimumDamageSniper, 0.f, ("Ragebot"), ("AutoWallDamageSniper"));
	SetupValue(g_Options.Ragebot.MinimumDamagePistol, 0.f, ("Ragebot"), ("AutoWallDamagePistol"));
	SetupValue(g_Options.Ragebot.MinimumDamageRifle, 0.f, ("Ragebot"), ("AutoWallDamageRifle"));
	SetupValue(g_Options.Ragebot.MinimumDamageHeavy, 0.f, ("Ragebot"), ("AutoWallDamageHeavy"));
	SetupValue(g_Options.Ragebot.MinimumDamageSmg, 0.f, ("Ragebot"), ("AutoWallDamageSmgs"));
	SetupValue(g_Options.Ragebot.MinimumDamageRevolver, 0.f, ("Ragebot"), ("AutoWallDamageRevolver"));
	SetupValue(g_Options.Ragebot.Hitchance, false, ("Ragebot"), ("HitChance"));
	SetupValue(g_Options.Ragebot.HitchanceSniper, 0.f, ("Ragebot"), ("HitChanceSniper"));
	SetupValue(g_Options.Ragebot.HitchancePistol, 0.f, ("Ragebot"), ("HitChancePistol"));
	SetupValue(g_Options.Ragebot.HitchanceHeavy, 0.f, ("Ragebot"), ("HitChanceHeavy"));
	SetupValue(g_Options.Ragebot.HitchanceSmgs, 0.f, ("Ragebot"), ("HitChanceSmgs"));
	SetupValue(g_Options.Ragebot.HitchanceRifle, 0.f, ("Ragebot"), ("HitChanceRifle"));
	SetupValue(g_Options.Ragebot.HitchanceRevolver, 0.f, ("Ragebot"), ("HitChanceRevolver"));
	SetupValue(g_Options.Ragebot.Resolver, false, ("Ragebot"), ("Resolver"));
	SetupValue(g_Options.Ragebot.BAIMkey, 0, ("Ragebot"), ("BAIMKey"));




	SetupValue(g_Options.Legitbot.MainSwitch, false, ("Legitbot"), ("LegitToggle"));
	SetupValue(g_Options.Legitbot.Aimbot.Enabled, false, ("Legitbot"), ("Enabled"));
	SetupValue(g_Options.Legitbot.backtrack, false, ("Legitbot"), ("Backtrack"));
	SetupValue(g_Options.Legitbot.backtrackTicks, 0, ("Legitbot"), ("BacktrackTicks"));
	SetupValue(g_Options.Legitbot.AutoPistol, false, ("Legitbot"), ("AutoPistol"));
	SetupValue(g_Options.Legitbot.SmokeCheck, false, ("Legitbot"), ("SmokeCheck"));


	SetupValue(g_Options.Legitbot.MainKey, 1, ("Legitbot"), ("Key"));
	SetupValue(g_Options.Legitbot.hitboxRifle, 0, ("Legitbot"), ("Hitbox-Rifle"));
	SetupValue(g_Options.Legitbot.Mainfov, 0.f, ("Legitbot"), ("FOV"));
	SetupValue(g_Options.Legitbot.MainSmooth, 1.f, ("Legitbot"), ("Speed"));
	SetupValue(g_Options.Legitbot.main_recoil_min, 0, ("Legitbot"), ("RCS-min"));
	SetupValue(g_Options.Legitbot.main_recoil_max, 0, ("Legitbot"), ("RCS-max"));

	SetupValue(g_Options.Legitbot.PistolKey, 6, ("Legitbot"), ("Key-Pistol"));
	SetupValue(g_Options.Legitbot.hitboxPistol, 0, ("Legitbot"), ("Hitbox-Pistol"));
	SetupValue(g_Options.Legitbot.Pistolfov, 0.f, ("Legitbot"), ("FOV-Pistol"));
	SetupValue(g_Options.Legitbot.PistolSmooth, 1.f, ("Legitbot"), ("Speed-Pistol"));
	SetupValue(g_Options.Legitbot.pistol_recoil_min, 0, ("Legitbot"), ("RCS-min-pistol"));
	SetupValue(g_Options.Legitbot.pistol_recoil_max, 0, ("Legitbot"), ("RCS-max-pistol"));

	SetupValue(g_Options.Legitbot.SniperKey, 6, ("Legitbot"), ("Key-Sniper"));
	SetupValue(g_Options.Legitbot.hitboxSniper, 0, ("Legitbot"), ("Hitbox-Sniper"));
	SetupValue(g_Options.Legitbot.Sniperfov, 0.f, ("Legitbot"), ("FOV-Sniper"));
	SetupValue(g_Options.Legitbot.SniperSmooth, 0.f, ("Legitbot"), ("Speed-Sniper"));
	SetupValue(g_Options.Legitbot.sniper_recoil_min, 0, ("Legitbot"), ("RCS-min-sniper"));
	SetupValue(g_Options.Legitbot.sniper_recoil_max, 0, ("Legitbot"), ("RCS-max-sniper"));

	SetupValue(g_Options.Legitbot.Triggerbot.Enabled, false, ("Triggerbot"), ("Enabled"));
	SetupValue(g_Options.Legitbot.Triggerbot.Key, 6, ("Triggerbot"), ("Key"));
	SetupValue(g_Options.Legitbot.Triggerbot.Delay, 0.f, ("Triggerbot"), ("Delay"));
	SetupValue(g_Options.Legitbot.Triggerbot.hitchance, 0.f, ("Triggerbot"), ("Hitchance"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Head, false, ("Triggerbot"), ("FilterHead"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Chest, false, ("Triggerbot"), ("FilterChest"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Stomach, false, ("Triggerbot"), ("FilterStomach"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Arms, false, ("Triggerbot"), ("FilterArms"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Legs, false, ("Triggerbot"), ("FilterLegs"));





	SetupValue(g_Options.Visuals.Box, false, ("Visuals"), ("Box"));
	SetupValue(g_Options.Visuals.BoxType, 0, ("Visuals"), ("BoxType"));
	SetupValue(g_Options.Visuals.BoxHotkey, false, ("Visuals"), ("BoxHotkey"));
	SetupValue(g_Options.Visuals.Name, false, ("Visuals"), ("Name"));
	SetupValue(g_Options.Visuals.health, false, ("Visuals"), ("HP"));
	SetupValue(g_Options.Visuals.Weapon, false, ("Visuals"), ("Weapon"));
	SetupValue(g_Options.Visuals.wpnmode, 0, ("Visuals"), ("WeaponType"));
	SetupValue(g_Options.Visuals.Chams, false, ("Visuals"), ("Chams"));
	SetupValue(g_Options.Visuals.Skeleton, false, ("Visuals"), ("Skeleton"));
	SetupValue(g_Options.Visuals.speclist, false, ("Misc"), ("speclist"));
	SetupValue(g_Options.Visuals.TeamESP, false, ("Visuals"), ("TeamEsp"));
	SetupValue(g_Options.Visuals.Grenades, false, ("Visuals"), ("GrenadeESP"));
	SetupValue(g_Options.Visuals.AimLine, false, ("Visuals"), ("Aimlines"));

	SetupValue(g_Options.Visuals.NoVisualRecoil, false, ("Visuals"), ("NoVisualRecoil"));
	SetupValue(g_Options.Visuals.Hitmarker, false, ("Visuals"), ("Hitmarker"));
	SetupValue(g_Options.Visuals.Hitsound, 0, ("Visuals"), ("Hitsound"));
	SetupValue(g_Options.Visuals.FOVChanger, 0.f, ("Visuals"), ("fovchanger"));
	SetupValue(g_Options.Visuals.viewmodelChanger, 68.f, ("Visuals"), ("viewmodel_fov"));
	SetupValue(g_Options.Visuals.NoFlash, false, ("Visuals"), ("NoFlash"));
	SetupValue(g_Options.Visuals.NoSmoke, false, ("Visuals"), ("NoSmoke"));
	SetupValue(g_Options.Visuals.Time, false, ("Visuals"), ("Time"));
	SetupValue(g_Options.Visuals.noscopeborder, false, ("Visuals"), ("noscopeborder"));
	SetupValue(g_Options.Visuals.Droppedguns, false, ("Visuals"), ("DroppedGuns"));
	SetupValue(g_Options.Visuals.GrenadePrediction, false, ("Visuals"), ("GrenadePrediction"));
	SetupValue(g_Options.Visuals.tpdist, false, ("Visuals"), ("thirdperson distance"));
	SetupValue(g_Options.Visuals.TPKey, false, ("Visuals"), ("thirdperson key"));
	SetupValue(g_Options.Visuals.ThirdPerson, false, ("Visuals"), ("thirdperson switch"));
	SetupValue(g_Options.Visuals.EventLog, false, ("Visuals"), ("EventLog"));
	SetupValue(g_Options.Visuals.Callout, false, ("Visuals"), ("Callout"));
	SetupValue(g_Options.Visuals.Armor, false, ("Visuals"), ("Armor"));
	SetupValue(g_Options.Visuals.Flashed, false, ("Visuals"), ("EnemyState"));
	SetupValue(g_Options.Visuals.Distance, false, ("Visuals"), ("Distance"));
	SetupValue(g_Options.Visuals.Money, false, ("Visuals"), ("Money"));
	SetupValue(g_Options.Visuals.Chams, false, ("Visuals"), ("PlayerChams"));
	SetupValue(g_Options.Visuals.Teamchams, false, ("Visuals"), ("Teamchams"));
	SetupValue(g_Options.Visuals.Chamweapon, false, ("Visuals"), ("WeaponChams"));
	SetupValue(g_Options.Visuals.XQZ, false, ("Visuals"), ("XQZ Chams"));
	SetupValue(g_Options.Visuals.champlayeralpha, 0, ("Visuals"), ("PlayerCham Alpha"));
	SetupValue(g_Options.Visuals.matierial, 0, ("Visuals"), ("PlayerCham Material"));
	SetupValue(g_Options.Visuals.weaponviewcham, false, ("Visuals"), ("Weapon Chams"));
	SetupValue(g_Options.Visuals.weaponhandalpha, 0, ("Visuals"), ("Weapon Chams Alpha"));
	SetupValue(g_Options.Visuals.handmat, 0, ("Visuals"), ("WeaponCham Material"));
	SetupValue(g_Options.Visuals.handcham, false, ("Visuals"), ("Hand Chams"));
	SetupValue(g_Options.Visuals.chamhandalpha, 0, ("Visuals"), ("Hand Chams Alpha"));
	SetupValue(g_Options.Visuals.weaponmat, 0, ("Visuals"), ("HandCham Material"));
	SetupValue(g_Options.Visuals.glowplayer, false, ("Visuals"), ("PlayerGlow"));
	SetupValue(g_Options.Visuals.teamglow, false, ("Visuals"), ("PlayerGlow Team"));
	SetupValue(g_Options.Visuals.playerglowalpha, 0, ("Visuals"), ("PlayerGlow Alpha"));
	SetupValue(g_Options.Visuals.weaponglow, false, ("Visuals"), ("WeaponGlow"));
	SetupValue(g_Options.Visuals.weaponglowalpha, 0, ("Visuals"), ("WeaponGlow Alpha"));
	SetupValue(g_Options.Visuals.bombglow, false, ("Visuals"), ("BombGlow"));
	SetupValue(g_Options.Visuals.bombglowalpha, 0, ("Visuals"), ("BombGlow Alpha"));
	SetupValue(g_Options.Visuals.GrenadePred, 0, ("Visuals"), ("GrenadePred"));
	SetupValue(g_Options.Visuals.angleLines, false, ("Visuals"), ("AngleLines"));
	SetupValue(g_Options.Visuals.DrawAwall, false, ("Visuals"), ("Awall Indicator"));
	SetupValue(g_Options.Misc.nightMode, false, ("Visuals"), ("Nightmode"));
	SetupValue(g_Options.Visuals.Bomb, false, ("Visuals"), ("BombEsp"));
	SetupValue(g_Options.Visuals.radar, false, ("Visuals"), ("Radar"));




	SetupValue(g_Options.Misc.Bhop, false, ("Misc"), ("Bhop"));
	SetupValue(g_Options.Misc.fps, false, ("Misc"), ("FPSBoost"));
	SetupValue(g_Options.Misc.Skybox, false, ("Misc"), ("Skybox"));
	SetupValue(g_Options.Legitbot.LAA, false, ("Misc"), ("LegitAA"));
	SetupValue(g_Options.Misc.legitBhop, false, ("Misc"), ("LegitBhop"));
	SetupValue(g_Options.Misc.FakePing2, false, ("Misc"), ("FakePing Amount"));
	SetupValue(g_Options.Misc.AutoStrafe, false, ("Misc"), ("Autostrafe"));
	SetupValue(g_Options.Misc.ServerRankRevealAll, false, ("Misc"), ("ShowRanks"));
	SetupValue(g_Options.Misc.AutoAccept, false, ("Misc"), ("AutoAccept"));
	SetupValue(g_Options.Misc.ragequit, 0, ("Misc"), ("ragequit-key"));
	SetupValue(g_Options.Misc.ChromeWorld, false, ("Misc"), ("Chrome World"));
	SetupValue(g_Options.Misc.PurchaseInfo, false, ("Misc"), ("PurchaseInfo"));
	SetupValue(g_Options.Misc.DmgInfo, false, ("Misc"), ("DmgInfo"));
	SetupValue(g_Options.Misc.clantagsxd, false, ("Misc"), ("Clantags Enabled"));
	SetupValue(g_Options.Misc.syncclantags, false, ("Misc"), ("syncclantags"));
	SetupValue(g_Options.Misc.BrdrClr, false, ("Misc"), ("BrdrClr"));
	SetupValue(g_Options.Legitbot.RnbwSliders, false, ("Misc"), ("RainbowSlider"));

	
	SetupValue(g_Options.Skinchanger.Enabled, false, ("skins"), ("enable"));
	SetupValue(g_Options.Skinchanger.WeaponTags, false, ("skins"), ("WeaponTagsOn"));
	SetupValue(g_Options.Skinchanger.StattrakOn, false, ("skins"), ("StattrakOn"));
	SetupValue(g_Options.Skinchanger.gloeskin, 0, ("skins"), ("gloveskin"));
	SetupValue(g_Options.Skinchanger.glove, 0, ("skins"), ("glove"));
	SetupValue(g_Options.Skinchanger.knifemodel, 0, ("skins"), ("modelknife"));

	for (int id = 0; id < 64; id++) { // Weapons
		SetupValue(g_Options.Skinchanger.W[id].ChangerSkin, 0, GetWeaponName(id), ("Skin"));
	}

	for (int id = 500; id <= 516; id++) { // knifes

		if ((id < 505 && id >= 501) || (id > 512 && id < 514))
			continue;

		SetupValue(g_Options.Skinchanger.W[id].ChangerSkin, 0, GetWeaponName(id), ("Skin"));

	}


	SetupValue(g_Options.Colors.C4glow[0], 1.f, ("Colors"), ("C4GlowRed"));
	SetupValue(g_Options.Colors.C4glow[1], 1.f, ("Colors"), ("C4GlowGreen"));
	SetupValue(g_Options.Colors.C4glow[2], 1.f, ("Colors"), ("C4GlowBlue"));
	SetupValue(g_Options.Colors.EnemyChamsNVis[0], 1.f, ("Colors"), ("EnemyChamsNVisRed"));
	SetupValue(g_Options.Colors.color_spread[0], 1.f, ("Colors"), ("Spread CrosshairRed"));
	SetupValue(g_Options.Colors.color_spread[1], 0.f, ("Colors"), ("Spread CrosshairGreen"));
	SetupValue(g_Options.Colors.color_spread[2], 0.f, ("Colors"), ("Spread CrosshairBlue"));
	SetupValue(g_Options.Colors.color_recoil[0], 0.f, ("Colors"), ("Recoil CrosshairRed"));
	SetupValue(g_Options.Colors.color_recoil[1], 1.f, ("Colors"), ("Recoil CrosshairGreen"));
	SetupValue(g_Options.Colors.color_recoil[2], 0.f, ("Colors"), ("Recoil CrosshairBlue"));
	SetupValue(g_Options.Colors.hitmark_color[0], 1.f, ("Colors"), ("Hitmark ColorRed"));
	SetupValue(g_Options.Colors.hitmark_color[1], 0.f, ("Colors"), ("Hitmark ColorGreen"));
	SetupValue(g_Options.Colors.hitmark_color[2], 1.f, ("Colors"), ("Hitmark ColorBlue"));
	SetupValue(g_Options.Colors.backtrackdots_color[0], 1.f, ("Colors"), ("BacktrackTick ColorRed"));
	SetupValue(g_Options.Colors.backtrackdots_color[1], 1.f, ("Colors"), ("BacktrackTick ColorGreen"));
	SetupValue(g_Options.Colors.backtrackdots_color[2], 1.f, ("Colors"), ("BacktrackTick ColorBlue"));
	SetupValue(g_Options.Colors.tracer_color[0], 1.f, ("Colors"), ("GrenadePred ColorRed"));
	SetupValue(g_Options.Colors.tracer_color[1], 1.f, ("Colors"), ("GrenadePred ColorGreen"));
	SetupValue(g_Options.Colors.tracer_color[2], 1.f, ("Colors"), ("GrenadePred ColorBlue"));
	SetupValue(g_Options.Colors.color_skeleton[0], 0.f, ("Colors"), ("Skeleton ColorRed"));
	SetupValue(g_Options.Colors.color_skeleton[1], 1.f, ("Colors"), ("Skeleton ColorGreen"));
	SetupValue(g_Options.Colors.color_skeleton[2], 0.f, ("Colors"), ("Skeleton ColorBlue"));
	SetupValue(g_Options.Colors.EnemyChamsNVis[1], 0.f, ("Colors"), ("EnemyChamsNVisGreen"));
	SetupValue(g_Options.Colors.EnemyChamsNVis[2], 0.f, ("Colors"), ("EnemyChamsNVisBlue"));
	SetupValue(g_Options.Colors.EnemyChamsVis[0], 0.f, ("Colors"), ("EnemyChamsVisRed"));
	SetupValue(g_Options.Colors.EnemyChamsVis[1], 1.f, ("Colors"), ("EnemyChamsVisGreen"));
	SetupValue(g_Options.Colors.EnemyChamsVis[2], 0.f, ("Colors"), ("EnemyChamsVisBlue"));
	SetupValue(g_Options.Colors.EnemyESP[0], 1.f, ("Colors"), ("EnemyESPRed"));
	SetupValue(g_Options.Colors.EnemyESP[1], 0.f, ("Colors"), ("EnemyESPGreen"));
	SetupValue(g_Options.Colors.EnemyESP[2], 0.f, ("Colors"), ("EnemyESPBlue"));
	SetupValue(g_Options.Colors.EnemyGlow[0], 1.f, ("Colors"), ("EnemGlowRed"));
	SetupValue(g_Options.Colors.EnemyGlow[1], 1.f, ("Colors"), ("EnemGlowGreen"));
	SetupValue(g_Options.Colors.EnemyGlow[2], 1.f, ("Colors"), ("EnemGlowBlue"));
	SetupValue(g_Options.Colors.TeamChamsNVis[0], 0.f, ("Colors"), ("TeamChamsNVisRed"));
	SetupValue(g_Options.Colors.TeamChamsNVis[1], 1.f, ("Colors"), ("TeamChamsNVisGreen"));
	SetupValue(g_Options.Colors.TeamChamsNVis[2], 1.f, ("Colors"), ("TeamChamsNVisBlue"));
	SetupValue(g_Options.Colors.TeamChamsVis[0], 0.f, ("Colors"), ("TeamChamsVisRed"));
	SetupValue(g_Options.Colors.TeamChamsVis[1], 0.f, ("Colors"), ("TeamChamsVisGreen"));
	SetupValue(g_Options.Colors.TeamChamsVis[2], 1.f, ("Colors"), ("TeamChamsVisBlue"));
	SetupValue(g_Options.Colors.TeamESP[0], 0.f, ("Colors"), ("TeamESPRed"));
	SetupValue(g_Options.Colors.TeamESP[1], 1.f, ("Colors"), ("TeamESPGreen"));
	SetupValue(g_Options.Colors.TeamESP[2], 0.f, ("Colors"), ("TeamESPBlue"));
	SetupValue(g_Options.Colors.TeamGlow[0], 0.f, ("Colors"), ("TeamGlowRed"));
	SetupValue(g_Options.Colors.TeamGlow[0], 0.f, ("Colors"), ("TeamGlowGreen"));
	SetupValue(g_Options.Colors.TeamGlow[0], 0.f, ("Colors"), ("TeamGlowBlue"));
	SetupValue(g_Options.Colors.WeaponGlow[0], 1.f, ("Colors"), ("WeaponGlowRed"));
	SetupValue(g_Options.Colors.WeaponGlow[1], 1.f, ("Colors"), ("WeaponGlowGreen"));
	SetupValue(g_Options.Colors.WeaponGlow[2], 1.f, ("Colors"), ("WeaponGlowBlue"));
	SetupValue(g_Options.Colors.Flash[0], 1.f, ("Colors"), ("FlashRed"));
	SetupValue(g_Options.Colors.Flash[1], 0.f, ("Colors"), ("FlashGreen"));
	SetupValue(g_Options.Colors.Flash[2], 1.f, ("Colors"), ("FlashBlue"));
	SetupValue(g_Options.Colors.HeG[0], 0.f, ("Colors"), ("HeGRed"));
	SetupValue(g_Options.Colors.HeG[1], 1.f, ("Colors"), ("HeGGreen"));
	SetupValue(g_Options.Colors.HeG[2], 0.f, ("Colors"), ("HeGBlue"));
	SetupValue(g_Options.Colors.Incendiary[0], 0.f, ("Colors"), ("IncendiaryRed"));
	SetupValue(g_Options.Colors.Incendiary[1], 0.f, ("Colors"), ("IncendiaryGreen"));
	SetupValue(g_Options.Colors.Incendiary[2], 1.f, ("Colors"), ("IncendiaryBlue"));
	SetupValue(g_Options.Colors.Decoy[0], 1.f, ("Colors"), ("DecoyRed"));
	SetupValue(g_Options.Colors.Decoy[1], 0.f, ("Colors"), ("DecoyGreen"));
	SetupValue(g_Options.Colors.Decoy[2], 1.f, ("Colors"), ("DecoyBlue"));
	SetupValue(g_Options.Colors.Smoke[0], 0.f, ("Colors"), ("SmokeRed"));
	SetupValue(g_Options.Colors.Smoke[1], 1.f, ("Colors"), ("SmokeGreen"));
	SetupValue(g_Options.Colors.Smoke[2], 1.f, ("Colors"), ("SmokeBlue"));
	SetupValue(g_Options.Colors.MolotovC[0], 1.f, ("Colors"), ("MolotovRed"));
	SetupValue(g_Options.Colors.MolotovC[1], 0.f, ("Colors"), ("MolotovGreen"));
	SetupValue(g_Options.Colors.MolotovC[2], 0.f, ("Colors"), ("MolotovBlue"));
}
void CConfig::SetupValue(int &value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue<int>(category, name, &value));
}

void CConfig::SetupValue(float &value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue<float>(category, name, &value));
}

void CConfig::SetupValue(bool &value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue<bool>(category, name, &value));
}

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path)))
	{


		folder = std::string(path) + ("\\Insidous.cc\\");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Legit1") + XorStr(".Insidous");
			break;
		case 1:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Legit2") + XorStr(".Insidous");
			break;
		case 2:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Legit3") + XorStr(".Insidous");
			break;
		case 3:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Semi-Rage") + XorStr(".Insidous");
			break;
		case 4:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Rage1") + XorStr(".Insidous");
			break;
		case 5:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Rage2") + XorStr(".Insidous");
			break;
		case 6:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Rage3") + XorStr(".Insidous");
			break;
		case 7:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("HvH1") + XorStr(".Insidous");
			break;
		case 8:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("HvH2") + XorStr(".Insidous");
			break;
		case 9:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("HvH3") + XorStr(".Insidous");
			break;
		case 10:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Other") + XorStr(".Insidous");
			break;
		}

	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Insidous.cc\\");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Legit1") + XorStr(".Insidous");
			break;
		case 1:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Legit2") + XorStr(".Insidous");
			break;
		case 2:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Legit3") + XorStr(".Insidous");
			break;
		case 3:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Semi-Rage") + XorStr(".Insidous");
			break;
		case 4:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Rage1") + XorStr(".Insidous");
			break;
		case 5:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Rage2") + XorStr(".Insidous");
			break;
		case 6:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Rage3") + XorStr(".Insidous");
			break;
		case 7:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("HvH1") + XorStr(".Insidous");
			break;
		case 8:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("HvH2") + XorStr(".Insidous");
			break;
		case 9:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("HvH3") + XorStr(".Insidous");
			break;
		case 10:
			file = std::string(path) + ("\\Insidous.cc\\") + std::string("Other") + XorStr(".Insidous");
			break;
		}
	}


	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = (float)atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

CConfig* Config = new CConfig();
Variables g_Options;