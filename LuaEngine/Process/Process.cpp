#include "../Header/Process.h"

HGE * Process::hge;
list<hgeFont *> Process::fontList;
list<hgeSprite *> Process::spriteList;
list<hgeEffectSystem *> Process::esList;
LuaStateOwner Process::state;

Process::Process()
{
}

Process::~Process()
{
}

bool Process::FrameFunc()
{
#ifndef __NOTUSELUA
	static LuaFunction<bool> framefunc = state->GetGlobal(LUAFN_HGEFRAMEFUNC);
	return framefunc();
#else
	return FrameFuncSelf();
#endif
}

bool Process::RenderFunc()
{
#ifndef __NOTUSELUA
	static LuaFunction<bool> renderfunc = state->GetGlobal(LUAFN_HGERENDERFUNC);
	return renderfunc();
#else
	return RenderFuncSelf();
#endif
}

bool Process::FocusLostFunc()
{
#ifndef __NOTUSELUA
	static LuaFunction<bool> focuslostfunc = state->GetGlobal(LUAFN_HGEFOCUSLOSTFUNC);
	return focuslostfunc();
#else
	return FocusLostFuncSelf();
#endif
}

bool Process::FocusGainFunc()
{
#ifndef __NOTUSELUA
	static LuaFunction<bool> focusgainfunc = state->GetGlobal(LUAFN_HGEFOCUSGAINFUNC);
	return focusgainfunc();
#else
	return FocusGainFuncSelf();
#endif
}

bool Process::GfxRestoreFunc()
{
#ifndef __NOTUSELUA
	static LuaFunction<bool> gfxrestorefunc = state->GetGlobal(LUAFN_HGEGFXRESTOREFUNC);
	return gfxrestorefunc();
#else
	return GfxRestoreFuncSelf();
#endif
}

bool Process::ExitFunc()
{
#ifndef __NOTUSELUA
	static LuaFunction<bool> exitfunc = state->GetGlobal(LUAFN_HGEEXITFUNC);
	return exitfunc();
#else
	return ExitFuncSelf();
#endif
}


void Process::ClientInitial()
{
	hge = hgeCreate(HGE_VERSION);

	hge->Resource_SetPath(DEFAULT_RESOURCEPATH);

	char respath[_MAX_PATH];
	strcpy(respath, hge->Resource_MakePath(""));
	if(_access(respath, 00) == -1)
	{
		CreateDirectory(respath, NULL);
	}
	SetCurrentDirectory(hge->Resource_MakePath(""));

	hge->System_SetState(HGE_FRAMEFUNC, mp.FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, mp.RenderFunc);
	hge->System_SetState(HGE_FOCUSLOSTFUNC, mp.FocusLostFunc);
	hge->System_SetState(HGE_FOCUSGAINFUNC, mp.FocusGainFunc);
	hge->System_SetState(HGE_GFXRESTOREFUNC, mp.GfxRestoreFunc);
	hge->System_SetState(HGE_EXITFUNC, mp.ExitFunc);

	hge->System_SetState(HGE_WINDOWED, true);

	if (LuaInitial())
	{
		if(hge->System_Initiate())
		{
			hge->System_Start();
		}
	}
}

void Process::Release()
{
	_LuaHelper_hgeFont_DeleteAllFont();
	_LuaHelper_hgeSprite_DeleteAllSprite();
	_LuaHelper_hgeES_DeleteAllES();
	hge->System_Shutdown();
	hge->Release();
}