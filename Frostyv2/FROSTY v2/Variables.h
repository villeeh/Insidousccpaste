#pragma once
#include <set>
#include <map>
#include <unordered_map>

extern void RenderInterface();

struct skinInfo
{
	int seed = -1;
	int paintkit;
	std::string tagName;
};


struct Variables
{
	Variables()
	{

	}

	struct Ragebot_s
	{
		bool	MainSwitch;
		bool 	Enabled;
		bool 	AutoFire;
		float 	FOV;
		bool 	Silent;
		bool	AutoPistol;
		int		KeyPress;
		bool	AimStep;

		//AA Builder
		bool	BuilderAAs;
		bool	Jitter;
		bool	FJitter;
		bool	LBYBreaker;
		float	BuilderReal;
		float	BuilderFake;
		float	BuilderPitch;
		float	JitterRange;
		float	FJitterRange;


		bool	EnabledAntiAim;
		int		SubAATabs;
		bool	PreAAs;
		int		Pitch;
		int		YawTrue;
		int		YawFake;
		int		YawTrueMove;
		float	PitchAdder;
		float	YawTrueAdder;
		float	YawFakeAdder;
		float	YawFakeMove;
		bool	AtTarget;
		bool	Edge;
		bool	KnifeAA;
		bool	FakeLag;
		int		FakeLagAmt;


		bool	FriendlyFire;
		int		Hitbox;
		int		Hitscan;
		float	Pointscale;
		bool	Multipoint;
		float	Multipoints;

		bool	AntiRecoil;
		bool	AutoWall;
		bool	AutoStop;
		bool	AutoCrouch;
		bool	AutoScope;
		float	MinimumDamageSniper;
		float	MinimumDamageRifle;
		float	MinimumDamagePistol;
		float	MinimumDamageHeavy;
		float	MinimumDamageSmg;
		float	MinimumDamageRevolver;
		bool	Hitchance;
		float	HitchanceSniper;
		float	HitchancePistol;
		float	HitchanceRifle;
		float	HitchanceHeavy;
		float	HitchanceSmgs;
		float	HitchanceRevolver;
		bool	Resolver;
		bool	FakeLagFix;
		bool	PosAdjust;
		bool	playerlist;
		int		BAIMkey;
		float	bruteAfterX;
		bool	MovingAA;
	} Ragebot;

	struct
	{
		bool MainSwitch;
		bool backtrack;
		float backtrackTicks;
		bool godwalk;
		bool Silent2;
		struct
		{
			bool 	Enabled;
			bool AutoPistol;
			bool	Resolver;

		} Aimbot;

		int hitboxrifle;
		bool AutoPistol;
		int MainKey = 1;
		float MainSmooth;
		float Mainfov;
		float main_random_smooth;
		float main_recoil_min;
		float main_recoil_max;
		float main_randomized_angle;


		int hitboxpistol;
		int PistolKey = 6;
		float Pistolfov;
		float PistolSmooth;
		float pistol_random_smooth;
		float pistol_recoil_min;
		float pistol_recoil_max;
		float pistol_randomized_angle;

		int hitboxsmg;
	    int SmgKey = 6;
		float SmgFov;
		float SmgSmooth;
		float Smg_random_smooth;
		float Smg_recoil_min;
		float Smg_recoil_max;
		float Smg_randomized_angle;


		int hitboxSniper;
		int hitboxPistol;
		int hitboxRifle;
		int hitboxSmg;
		int SniperKey = 6;
		float Sniperfov;
		float SniperSmooth;
		float sniper_random_smooth;
		float sniper_recoil_min;
		float sniper_recoil_max;
		float sniper_randomized_angle;
		bool LAA;
		bool LegitAA;
		bool DrawFov;
		int SwitchAA;
		bool SmokeCheck;
		bool RnbwSliders;

		struct
		{
			bool Head;
			bool Arms;
			bool Chest;
			bool Stomach;
			bool Legs;
		}Filter;

		struct
		{
			bool	Enabled;
			float Delay;
			int Key = 6;
			float hitchance;
			struct
			{
				bool Head;
				bool Arms;
				bool Chest;
				bool Stomach;
				bool Legs;
			} Filter;

		} Triggerbot;

	} Legitbot;

	struct
	{
		bool MainSwitch;
		bool Enabled;
		bool TeamESP;
		bool Box;
		int BoxType;
		bool health;
		bool Armor;
		bool Money;
		bool VisCheck;
		bool Name;
		bool Distance;
		bool speclist;
		bool Skeleton;
		bool Callout;
		bool Weapon;
		int wpnmode;
		bool Flashed;
		bool Scoped;
		bool Reloading;
		bool Defusing;
		bool AimLine;
		bool Bomb;
		bool angleLines;
		bool LagCompensation;
		bool DrawAwall;
		bool backtrackline;


		bool Droppedguns;
		bool Grenades;

		int chamsubtab = 0;

		bool Chams;
		int matierial;
		bool outline;
		bool Teamchams;
		int champlayeralpha;

		bool Chamweapon;
		bool XQZ;

		bool handcham;
		int chamhandalpha;
		bool weaponviewcham;

		int weaponmat;
		int handmat;
		int weaponhandalpha;

		bool Crosshair;
		bool RecoilCrosshair;
		bool xSpread;
		bool xRecoil;

		bool Hitmarker = true;
		int Hitsound = 4;

		bool EventLog;

		bool NoVisualRecoil;
		bool showBacktrack;
		float FOVChanger;
		float viewmodelChanger = 68;
		bool NoFlash;
		bool NoSmoke;
		int TPKey;
		float tpdist = 200;
		bool ThirdPerson;
		bool Time = true;

		bool noscopeborder;
		bool GrenadePrediction;

		int glowsubtab = 0;
		bool glowplayer;
		int playerglowalpha;
		bool teamglow;

		bool weaponglow;
		int weaponglowalpha;

		bool bombglow;
		int bombglowalpha;

		bool GrenadePred;
		bool DLight;
		bool radar;
		int BoxHotkey;;
		int SkeleHotkey;
		int RadarHotkey;



	} Visuals;

	struct
	{
        bool MainSwitch;
		bool antiuntrusted = true;
		bool silentstealer;
		bool ChromeWorld;
		int ragequit;
		bool 	Bhop;
		bool 	AutoStrafe;
		float MinVel;
		float FakeLag;
		bool AdaptiveFakeLag;
		bool nightMode;
		int NameSpammer;
		bool NameChangerFix;
		bool NoName;
		int		ChatSpamMode;
		bool ClantagChanger;
		int clantags;
		bool clantagsxd;
		int syncclantags;
		int ClanTagSpeed;
		bool FPSBooster;
		int SkyBoxChanger;
		int Skybox;
		bool namespam;
		int spammer;
		bool Spam;
		bool isRecording;
		bool isReplaying;
		bool RecordPath;
		bool AutoAccept;
		bool ServerRankRevealAll;
		bool SpoofConfirmation = false;
		bool animatedclantag = false;
		int customtab;
		int Slowmo;
		bool MoonWalk;
		bool crack;
		bool Gray;
		bool fps;
		bool FakePing;
		int FakePing2;
		bool PurchaseInfo;
		bool DmgInfo;
		bool DmgInfo2;
		bool BacktrackExploitChk;
		bool KnifeHand;
		bool skyboxTest;
		bool spofff;
		bool lAA;
		bool LegitAA;
		bool legitBhop;
		int FakePingAmt;
		bool BrdrClr;
		bool inventoryalwayson;


	} Misc;
	struct
	{
		bool Enabled;

		int knifemodel;

		int glove;
		int gloeskin;


		struct
		{
			bool ChangerEnabled = false;
			int ChangerSkin = 0;
			char ChangerName[32] = "";
			int ChangerStatTrak = 0;
			int ChangerSeed = 0;
			float ChangerWear = 0;
			
		} W[519]; // CHANGE HERE

		std::unordered_map<std::string, std::set<std::string>> weaponSkins;
		std::unordered_map<std::string, skinInfo> skinMap;
		std::unordered_map<std::string, std::string> skinNames;
		bool WeaponTags;
		bool StattrakOn;
		int SkinNamesxd;
		std::vector<std::string> weaponNames;
	} Skinchanger;

	struct
	{
		bool	Opened = true;
		int 	Key;
		int		rageSubtab;
		int		ConfigFile = 0;
		int		Theme = 0;
		int		iTab;
		bool	bShowTabs;
		float   flMainAlpha;
		float   flTabsAlpha;
		int currentWeapon;
	} Menu;

	struct
	{
		float TeamESP[3] = { 0, 1.f, 0 };
		float EnemyESP[3] = { 1.f, 0, 0 };
		float TeamDLights[3] = { 0, 1.f, 0 };
		float EnemyDLights[3] = { 1.f, 0, 0 };
		float EnemyGlow[3] = { 1.f, 0, 0 };
		float TeamGlow[3] = { 0, 1.f, 0 };
		float WeaponGlow[3] = { 1.f, 0, 0 };
		float C4glow[3] = { 1.f, 0, 0 };
		float EnemyChamsVis[3] = { 1.f, 0, 0 };
		float EnemyChamsNVis[3] = { 1.f, 0, 0 };
		float TeamChamsVis[3] = { 0, 1.f, 0 };
		float TeamChamsNVis[3] = { 0, 1.f, 0 };
		float WeaponCham[3] = { 1.f, 0, 0 };
		float HandCham[3] = { 1.f, 0, 0 };
		float WeaponViewCham[3] = { 1.f, 0, 0 };
		float color_skeleton[3] = { 1.f, 1.f, 1.f };
		float backtrackdots_color[3] = { 1.f, 0, 0 };
		float tracer_color[3] = { 1.f, 0, 0 };
		float hitmark_color[3] = { 0, 0, 1.f };
		float color_spread[3] = { 0, 1.f, 0 };
		float color_recoil[3] = { 0, 0, 1.f };
		float dlight_color[3] = { 0, 1.f, 0 };
		float MolotovC[3] = { 0, 1.f, 0 };
		float Incendiary[3] = { 0, 1.f, 0 };
		float Decoy[3] = { 0, 1.f, 0 };
		float Flash[3] = { 1.f, 0, 0 };
		float HeG[3] = { 0, 0, 1.f };
		float Smoke[3] = { 0, 1.f, 0 };
		float GrenadePredEnd[3] = { 0, 1.f, 1.f };
		float backtrackdotsR_color[3] = { 1.f, 0, 1.f };
		float Border[3] = { 1.f, 1.f, 1.f };
		float HandsColor[3] = { 0.f, 0.f, 1.f };
	}Colors;
};

extern Variables g_Options;