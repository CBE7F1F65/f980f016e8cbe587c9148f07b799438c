#include "../Header/Process.h"

HGE * Process::hge;
LuaStateOwner Process::state;

Process::Process()
{
}

Process::~Process()
{
}

bool Process::FrameFunc()
{
	static LuaFunction<bool> framefunc = state->GetGlobal(LUAFN_HGEFRAMEFUNC);
	return framefunc();
}

bool Process::RenderFunc()
{
	static LuaFunction<bool> renderfunc = state->GetGlobal(LUAFN_HGERENDERFUNC);
	return renderfunc();
}

bool Process::FocusLostFunc()
{
	static LuaFunction<bool> focuslostfunc = state->GetGlobal(LUAFN_HGEFOCUSLOSTFUNC);
	return focuslostfunc();
}

bool Process::FocusGainFunc()
{
	static LuaFunction<bool> focusgainfunc = state->GetGlobal(LUAFN_HGEFOCUSGAINFUNC);
	return focusgainfunc();
}

bool Process::GfxRestoreFunc()
{
	static LuaFunction<bool> gfxrestorefunc = state->GetGlobal(LUAFN_HGEGFXRESTOREFUNC);
	return gfxrestorefunc();
}

bool Process::ExitFunc()
{
	static LuaFunction<bool> exitfunc = state->GetGlobal(LUAFN_HGEEXITFUNC);
	return exitfunc();
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
	hge->System_Shutdown();
	hge->Release();
}