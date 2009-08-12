#ifndef _PROCESS_H
#define _PROCESS_H

#include "MainDependency.h"

static class Process
{
public:
	Process();
	~Process();

public:
	static bool RenderFunc();
	static bool FrameFunc();
	static bool FocusLostFunc();
	static bool FocusGainFunc();
	static bool GfxRestoreFunc();
	static bool ExitFunc();

	bool LuaInitial();
	bool LuaRegistFunction();

	void ClientInitial();
	void Release();

	static int LuaFn_LuaState_DoFile(LuaState * ls);

	static int LuaFn_hge_System_SetState(LuaState * ls);
	static int LuaFn_hge_System_GetState(LuaState * ls);

public:
	static HGE * hge;
	static LuaStateOwner state;
}mp;

#endif