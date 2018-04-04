#include "HookIncludes.h"
using is_connected_t = bool(__thiscall*)(IVEngineClient*);
bool __stdcall IsConnected()
{
	auto ofunc = hooks::engine.get_original<is_connected_t>(27);
	static void* unk = U::pattern_scan(GetModuleHandleA("client.dll"), "75 04 B0 01 5F") - 2;
	if (_ReturnAddress() == unk && g_Options.Misc.inventoryalwayson)
	{
		return false;
	}
	return ofunc(g_Engine);
}