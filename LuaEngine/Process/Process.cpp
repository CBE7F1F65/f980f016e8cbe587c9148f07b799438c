#include "../Header/Process.h"

HGE * Process::hge;
list<hgeFont *> Process::fontList;
list<hgeSprite *> Process::spriteList;
list<hgeEffectSystem *> Process::esList;
LuaStateOwner Process::state;

LuaFunction<bool> * Process::framefunc = NULL;
LuaFunction<bool> * Process::renderfunc = NULL;
LuaFunction<bool> * Process::focuslostfunc = NULL;
LuaFunction<bool> * Process::focusgainfunc = NULL;
LuaFunction<bool> * Process::gfxrestorefunc = NULL;
LuaFunction<bool> * Process::exitfunc = NULL;

Process::Process()
{
}

Process::~Process()
{
}

bool Process::FrameFunc()
{
#ifndef __NOTUSELUA
	if (!framefunc)
	{
		static LuaFunction<bool> _f = state->GetGlobal(LUAFN_HGEFRAMEFUNC);
		_f = state->GetGlobal(LUAFN_HGEFRAMEFUNC);
		framefunc = &_f;
	}
	return (*framefunc)();
#else
	return FrameFuncSelf();
#endif
}

bool Process::RenderFunc()
{
#ifndef __NOTUSELUA
	if (!renderfunc)
	{
		static LuaFunction<bool> _f = state->GetGlobal(LUAFN_HGERENDERFUNC);
		_f = state->GetGlobal(LUAFN_HGERENDERFUNC);
		renderfunc = &_f;
	}
	return (*renderfunc)();
#else
	return RenderFuncSelf();
#endif
}

bool Process::FocusLostFunc()
{
#ifndef __NOTUSELUA
	if (!focuslostfunc)
	{
		static LuaFunction<bool> _f = state->GetGlobal(LUAFN_HGEFOCUSLOSTFUNC);
		_f = state->GetGlobal(LUAFN_HGEFOCUSLOSTFUNC);
		focuslostfunc = &_f;
	}
	return (*focuslostfunc)();
#else
	return FocusLostFuncSelf();
#endif
}

bool Process::FocusGainFunc()
{
#ifndef __NOTUSELUA
	if (!focusgainfunc)
	{
		static LuaFunction<bool> _f = state->GetGlobal(LUAFN_HGEFOCUSGAINFUNC);
		_f = state->GetGlobal(LUAFN_HGEFOCUSGAINFUNC);
		focusgainfunc = &_f;
	}
	return (*focusgainfunc)();
#else
	return FocusGainFuncSelf();
#endif
}

bool Process::GfxRestoreFunc()
{
#ifndef __NOTUSELUA
	if (!gfxrestorefunc)
	{
		static LuaFunction<bool> _f = state->GetGlobal(LUAFN_HGEGFXRESTOREFUNC);
		_f = state->GetGlobal(LUAFN_HGEGFXRESTOREFUNC);
		gfxrestorefunc = &_f;
	}
	return (*gfxrestorefunc)();
#else
	return GfxRestoreFuncSelf();
#endif
}

bool Process::ExitFunc()
{
#ifndef __NOTUSELUA
	if (!exitfunc)
	{
		static LuaFunction<bool> _f = state->GetGlobal(LUAFN_HGEEXITFUNC);
		_f = state->GetGlobal(LUAFN_HGEEXITFUNC);
		exitfunc = &_f;
	}
	return (*exitfunc)();
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
//	hge->System_Shutdown();
	hge->Release();
}