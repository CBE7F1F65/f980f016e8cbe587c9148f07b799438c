#include "../Header/Process.h"
#include "../Header/LuaConstDefine.h"

bool Process::LuaInitial()
{
#ifndef __NOTUSELUA

	LuaRegistFunction();
	int iret = state->DoFile(hge->Resource_MakePath(DEFAULT_INITLUAFILE));
	LuaFunction<bool> systeminitial = state->GetGlobal(LUAFN_SYSTEMINITIAL);
	return systeminitial();

#else

	return true;

#endif
}

bool Process::_LuaRegistFunction(LuaObject * obj)
{
	obj->Register("LuaFn_Global_ARGB", LuaFn_Global_ARGB);
	obj->Register("LuaFn_LuaState_DoFile", LuaFn_LuaState_DoFile);
	return true;
}

bool Process::LuaRegistFunction()
{
	LuaObject obj = state->GetGlobals();
	
	if (!_LuaRegistFunction(&obj))
	{
		return false;
	}
	LuaObject _hge = obj.CreateTable("hge");
	if (!_LuaRegistHGEFunction(&_hge))
	{
		return false;
	}
	if (!_LuaRegistHGEHelpFunction(&obj))
	{
		return false;
	}

	return true;
}

DWORD Process::_LuaHelper_GetDWORD(LuaObject * obj)
{
	lua_Number lnval = obj->GetNumber();
	return CUINTN(lnval);
}

void Process::_LuaHelper_PushDWORD(LuaState * ls, DWORD dval)
{
	lua_Number lnval = CDOUBLEN(dval);
	ls->PushNumber(lnval);
}

LONGLONG Process::_LuaHelper_GetLONGLONG(LuaObject * obj)
{
	lua_Number lnval = obj->GetNumber();
	return CLONGLONGN(lnval);
}

void Process::_LuaHelper_PushLONGLONG(LuaState * ls, LONGLONG llval)
{
	lua_Number lnval = CDOUBLEN(llval);
	ls->PushNumber(lnval);
}

QWORD Process::_LuaHelper_GetQWORD(LuaObject * obj)
{
	lua_Number lnval = obj->GetNumber();
	return CULONGLONGN(lnval);
}

void Process::_LuaHelper_PushQWORD(LuaState * ls, QWORD qval)
{
	lua_Number lnval = CDOUBLEN(qval);
	ls->PushNumber(lnval);
}

DWORD Process::_LuaHelper_GetColor(LuaObject * obj)
{
	DWORD dret = 0;
	if (obj->IsTable())
	{
		BYTE _a = obj->GetByName("a").GetInteger();
		BYTE _r = obj->GetByName("r").GetInteger();
		BYTE _g = obj->GetByName("g").GetInteger();
		BYTE _b = obj->GetByName("b").GetInteger();
		dret = ARGB(_a, _r, _g, _b);
	}
	else
	{
		dret = _LuaHelper_GetDWORD(obj);
	}
	return dret;
}

int Process::LuaFn_Global_ARGB(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	if (args.Count() > 2)
	{
		dret = ARGB(args[1].GetInteger(), args[2].GetInteger(), args[3].GetInteger(), args[4].GetInteger());
	}
	else
	{
		if (args[1].IsTable())
		{
			LuaObject _obj = args[1];
			dret = _LuaHelper_GetColor(&_obj);
		}
		else
		{
			dret = (((DWORD)(args[1].GetInteger()))<<24) + (DWORD)(args[2].GetInteger());
		}
	}

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_LuaState_DoFile(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = ls->DoFile(hge->Resource_MakePath(args[1].GetString()));
	ls->PushInteger(iret);

	return 1;
}