#include "../Header/Process.h"
#include "../Header/LuaConstDefine.h"

HGE * Process::hge;
int Process::texnum = 0;
HTEXTURE * Process::texset = NULL;
hgeChannelSyncInfo Process::channelsyncinfo;
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
		LuaObject _obj = state->GetGlobal(LUAFN_HGEFRAMEFUNC);
		if (!(_obj.IsFunction()))
		{
			_LuaHelper_ShowError(LUAERROR_NOTFUNCTION, LUAFN_HGEFRAMEFUNC);
			return true;
		}
		static LuaFunction<bool> _f = _obj;
		_f = _obj;
		framefunc = &_f;
	}
	bool bret = (*framefunc)();
	if (state->CheckError())
	{
		_LuaHelper_ShowError(LUAERROR_LUAERROR, state->GetError());
		return false;
	}
	return bret;
#else
	return FrameFuncSelf();
#endif
}

bool Process::RenderFunc()
{
#ifndef __NOTUSELUA
	if (!renderfunc)
	{
		LuaObject _obj = state->GetGlobal(LUAFN_HGERENDERFUNC);
		if (!(_obj.IsFunction()))
		{
			_LuaHelper_ShowError(LUAERROR_NOTFUNCTION, LUAFN_HGERENDERFUNC);
			return true;
		}
		static LuaFunction<bool> _f = _obj;
		_f = _obj;
		renderfunc = &_f;
	}
	bool bret = (*renderfunc)();
	if (state->CheckError())
	{
		_LuaHelper_ShowError(LUAERROR_LUAERROR, state->GetError());
		return false;
	}
	return bret;
#else
	return RenderFuncSelf();
#endif
}

bool Process::FocusLostFunc()
{
#ifndef __NOTUSELUA
	if (!focuslostfunc)
	{
		LuaObject _obj = state->GetGlobal(LUAFN_HGEFOCUSLOSTFUNC);
		if (!(_obj.IsFunction()))
		{
			_LuaHelper_ShowError(LUAERROR_NOTFUNCTION, LUAFN_HGEFOCUSLOSTFUNC);
			return true;
		}
		static LuaFunction<bool> _f = _obj;
		_f = _obj;
		focuslostfunc = &_f;
	}
	bool bret = (*focuslostfunc)();
	if (state->CheckError())
	{
		_LuaHelper_ShowError(LUAERROR_LUAERROR, state->GetError());
		return true;
	}
	return bret;
#else
	return FocusLostFuncSelf();
#endif
}

bool Process::FocusGainFunc()
{
#ifndef __NOTUSELUA
	if (!focusgainfunc)
	{
		LuaObject _obj = state->GetGlobal(LUAFN_HGEFOCUSGAINFUNC);
		if (!(_obj.IsFunction()))
		{
			_LuaHelper_ShowError(LUAERROR_NOTFUNCTION, LUAFN_HGEFOCUSGAINFUNC);
			return true;
		}
		static LuaFunction<bool> _f = _obj;
		_f = _obj;
		focusgainfunc = &_f;
	}
	bool bret = (*focusgainfunc)();
	if (state->CheckError())
	{
		_LuaHelper_ShowError(LUAERROR_LUAERROR, state->GetError());
		return true;
	}
	return bret;
#else
	return FocusGainFuncSelf();
#endif
}

bool Process::GfxRestoreFunc()
{
#ifndef __NOTUSELUA
	if (!gfxrestorefunc)
	{
		LuaObject _obj = state->GetGlobal(LUAFN_HGEGFXRESTOREFUNC);
		if (!(_obj.IsFunction()))
		{
			_LuaHelper_ShowError(LUAERROR_NOTFUNCTION, LUAFN_HGEGFXRESTOREFUNC);
			return true;
		}
		static LuaFunction<bool> _f = _obj;
		_f = _obj;
		gfxrestorefunc = &_f;
	}
	bool bret = (*gfxrestorefunc)();
	if (state->CheckError())
	{
		_LuaHelper_ShowError(LUAERROR_LUAERROR, state->GetError());
		return true;
	}
	return bret;
#else
	return GfxRestoreFuncSelf();
#endif
}

bool Process::ExitFunc()
{
#ifndef __NOTUSELUA
	if (!exitfunc)
	{
		LuaObject _obj = state->GetGlobal(LUAFN_HGEEXITFUNC);
		if (!(_obj.IsFunction()))
		{
			_LuaHelper_ShowError(LUAERROR_NOTFUNCTION, LUAFN_HGEEXITFUNC);
			return true;
		}
		static LuaFunction<bool> _f = _obj;
		_f = _obj;
		exitfunc = &_f;
	}
	bool bret = (*exitfunc)();
	if (state->CheckError())
	{
		_LuaHelper_ShowError(LUAERROR_LUAERROR, state->GetError());
		return true;
	}
	return bret;
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
	_LuaHelper_hge_DeleteAllTexture();
	_LuaHelper_hgeFont_DeleteAllFont();
	_LuaHelper_hgeSprite_DeleteAllSprite();
	_LuaHelper_hgeES_DeleteAllES();
//	hge->System_Shutdown();
	hge->Release();
}