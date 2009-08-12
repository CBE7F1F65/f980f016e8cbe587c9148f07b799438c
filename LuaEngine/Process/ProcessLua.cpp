#include "../Header/Process.h"
#include "../Header/LuaConstDefine.h"

bool Process::LuaInitial()
{
	LuaRegistFunction();
	int iret = state->DoFile(hge->Resource_MakePath(DEFAULT_INITLUAFILE));
	LuaFunction<bool> systeminitial = state->GetGlobal(LUAFN_SYSTEMINITIAL);
	return systeminitial();
}

bool Process::LuaRegistFunction()
{
	LuaObject obj = state->GetGlobals();
	obj.Register("LuaFn_LuaState_DoFile", LuaFn_LuaState_DoFile);

	obj.Register("LuaFn_hge_System_SetState", LuaFn_hge_System_SetState);

	return true;
}

int Process::LuaFn_LuaState_DoFile(LuaState * ls)
{
	LuaStack args(ls);

	int ret = ls->DoFile(hge->Resource_MakePath(args[1].GetString()));
	ls->PushInteger(ret);

	return 1;
}

int Process::LuaFn_hge_System_SetState(LuaState * ls)
{
	LuaStack args(ls);

	int hgestate = args[1].GetNumber();
	switch (hgestate & HGE_STATE_MASK)
	{
	case HGE_STATE_BOOLTEST:
		hge->System_SetState((hgeBoolState)hgestate, args[2].GetBoolean());
		break;
	case HGE_STATE_FUNCTEST:
		break;
	case HGE_STATE_HWNDTEST:
		hge->System_SetState((hgeHwndState)hgestate, (HWND)((DWORD)(args[2].GetNumber())));
		break;
	case HGE_STATE_INTTEST:
		hge->System_SetState((hgeIntState)hgestate, args[2].GetInteger());
		break;
	case HGE_STATE_STRINGTEST:
		hge->System_SetState((hgeStringState)hgestate, args[2].GetString());
		break;
	}
	
	return 0;
}

int Process::LuaFn_hge_System_GetState(LuaState * ls)
{
	LuaStack args(ls);

	int hgestate = args[1].GetNumber();
	bool pushed = false;
	switch (hgestate & HGE_STATE_MASK)
	{
	case HGE_STATE_BOOLTEST:
		ls->PushBoolean(hge->System_GetState((hgeBoolState)hgestate));
		pushed = true;
		break;
	case HGE_STATE_FUNCTEST:
		break;
	case HGE_STATE_HWNDTEST:
		ls->PushNumber((DWORD)hge->System_GetState((hgeHwndState)hgestate));
		pushed = true;
		break;
	case HGE_STATE_INTTEST:
		ls->PushInteger(hge->System_GetState((hgeIntState)hgestate));
		pushed = true;
		break;
	case HGE_STATE_STRINGTEST:
		ls->PushString(hge->System_GetState((hgeStringState)hgestate));
		pushed = true;
		break;
	}

	if (pushed)
	{
		return 1;
	}
	return 0;
}
