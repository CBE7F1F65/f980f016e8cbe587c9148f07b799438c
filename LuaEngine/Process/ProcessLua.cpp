#include "../Header/Process.h"
#include "../Header/LuaConstDefine.h"

bool Process::LuaInitial()
{
#ifndef __NOTUSELUA

	LuaRegistFunction();
	LuaRegistConst();
	int iret = state->DoFile(hge->Resource_MakePath(DEFAULT_INITLUAFILE));
	if (iret != 0)
	{
		_LuaHelper_ShowError(LUAERROR_LOADINGSCRIPT, DEFAULT_INITLUAFILE);
		return false;
	}
	LuaFunction<bool> systeminitial = state->GetGlobal(LUAFN_SYSTEMINITIAL);
	return systeminitial();

#else

	return true;

#endif
}

bool Process::_LuaRegistFunction(LuaObject * obj)
{
	LuaObject _globalobj = obj->CreateTable("global");
	_globalobj.Register("Calculate", LuaFn_Global_Calculate);
	_globalobj.Register("ARGB", LuaFn_Global_ARGB);
	_globalobj.Register("GetARGB", LuaFn_Global_GetARGB);
	_globalobj.Register("SetARGB", LuaFn_Global_SetARGB);

	LuaObject _luastateobj = obj->CreateTable("luastate");
	_luastateobj.Register("Reload", LuaFn_LuaState_Reload);
	_luastateobj.Register("DoFile", LuaFn_LuaState_DoFile);
	_luastateobj.Register("GetTableCount", LuaFn_LuaState_GetTableCount);

	return true;
}

bool Process::LuaRegistFunction()
{
	LuaObject obj = state->GetGlobals();
	
	if (!_LuaRegistFunction(&obj))
	{
		return false;
	}
	if (!_LuaRegistHGEFunction(&obj))
	{
		return false;
	}
	if (!_LuaRegistHGEHelpFunction(&obj))
	{
		return false;
	}

	return true;
}

bool Process::LuaRegistConst()
{
	LuaObject obj = state->GetGlobals();

	if (!_LuaRegistConst(&obj))
	{
		return false;
	}
	if (!_LuaRegistHGEConst(&obj))
	{
		return false;
	}
	if (!_LuaRegistHGEHelpConst(&obj))
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

void Process::_LuaHelper_PushString(LuaState * ls, const char * sval)
{
	if (!sval)
	{
		ls->PushString("");
	}
	else
	{
		ls->PushString(sval);
	}
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

void Process::_LuaHelper_GetCalculateValue(LuaObject * obj, char calchar, bool buseq, void * val)
{
	int _int;
	DWORD _dword;
	LONGLONG _longlong;
	QWORD _qword;

	switch (calchar)
	{
	case LUACALCULATESTR_INT:
		_int = obj->GetInteger();
		if (buseq)
		{
			if (_int < 0)
			{
				_int = 0;
			}
			CULONGLONG(val) = _int;
		}
		else
		{
			CLONGLONG(val) = _int;
		}
		break;
	case LUACALCULATESTR_DWORD:
		_dword = _LuaHelper_GetDWORD(obj);
		if (buseq)
		{
			CULONGLONG(val) = _int;
		}
		else
		{
			CLONGLONG(val) = _int;
		}
		break;
	case LUACALCULATESTR_LONGLONG:
		_longlong = _LuaHelper_GetLONGLONG(obj);
		if (buseq)
		{
			if (_longlong < 0)
			{
				_longlong = 0;
			}
			CULONGLONG(val) = _longlong;
		}
		else
		{
			CLONGLONG(val) = _longlong;
		}
		break;
	case LUACALCULATESTR_QWORD:
		_qword = _LuaHelper_GetQWORD(obj);
		if (buseq)
		{
			CULONGLONG(val) = _qword;
		}
		else
		{
			CLONGLONG(val) = _qword;
		}
		break;
	}
}

int Process::LuaFn_Global_Calculate(LuaState * ls)
{
	LuaStack args(ls);
	const char * calstr = 0;

	calstr = args[1].GetString();
	if (!calstr || strlen(calstr) < 4)
	{
		ls->PushInteger(0);
		return 1;
	}

	LONGLONG l1, l2, lret;
	QWORD q1, q2, qret;

	bool buseq = false;
	if (calstr[3] == LUACALCULATESTR_QWORD)
	{
		buseq = true;
	}
	LuaObject _obj;
	_obj = args[2];

	_LuaHelper_GetCalculateValue(&_obj, calstr[0], buseq, &l1);
	_obj = args[3];
	_LuaHelper_GetCalculateValue(&_obj, calstr[0], buseq, &l2);

	if (buseq)
	{
		q1 = CULONGLONGN(l1);
		q2 = CULONGLONGN(l2);
	}

	switch (calstr[1])
	{
	case '+':
		if (buseq)
		{
			qret = q1 + q2;
		}
		else
		{
			lret = l1 + l2;
		}
		break;
	case '-':
		if (buseq)
		{
			qret = q1 - q2;
		}
		else
		{
			lret = l1 - l2;
		}
		break;
	case '*':
		if (buseq)
		{
			qret = q1 * q2;
		}
		else
		{
			lret = l1 * l2;
		}
		break;
	case '/':
		if (buseq)
		{
			qret = q1 / q2;
		}
		else
		{
			lret = l1 / l2;
		}
		break;
	case '%':
		if (buseq)
		{
			qret = q1 % q2;
		}
		else
		{
			lret = l1 % l2;
		}
		break;
	}
	if (buseq)
	{
		_LuaHelper_PushQWORD(ls, qret);
	}
	else
	{
		_LuaHelper_PushLONGLONG(ls, lret);
	}
	return 1;
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

int Process::LuaFn_Global_GetARGB(LuaState * ls)
{
	LuaStack args(ls);
	int a, r, g, b;

	LuaObject _obj = args[1];
	DWORD col = _LuaHelper_GetColor(&_obj);
	a = GETA(col);
	r = GETR(col);
	g = GETG(col);
	b = GETB(col);

	ls->PushInteger(a);
	ls->PushInteger(r);
	ls->PushInteger(g);
	ls->PushInteger(b);
	return 4;
}

int Process::LuaFn_Global_SetARGB(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	LuaObject _obj = args[1];
	dret = _LuaHelper_GetColor(&_obj);
	int argb=0;
	int argscount = args.Count();
	if (argscount > 1)
	{
		argb = args[2].GetInteger();
		if (argb >= 0 && argb < 0x100)
		{
			dret = SETA(dret, argb);
		}
		if (argscount > 2)
		{
			argb = args[3].GetInteger();
			if (argb >= 0 && argb < 0x100)
			{
				dret = SETR(dret, argb);
			}
			if (argscount > 3)
			{
				argb = args[4].GetInteger();
				if (argb >= 0 && argb < 0x100)
				{
					dret = SETG(dret, argb);
				}
				if (argscount > 4)
				{
					argb = args[5].GetInteger();
					if (argb >= 0 && argb < 0x100)
					{
						dret = SETB(dret, argb);
					}
				}
			}
		}
	}

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_LuaState_Reload(LuaState * ls)
{
	LuaInitial();
	return 0;
}

int Process::LuaFn_LuaState_DoFile(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = ls->DoFile(hge->Resource_MakePath(args[1].GetString()));
	if (iret != 0)
	{
		_LuaHelper_ShowError(LUAERROR_LOADINGSCRIPT, args[1].GetString());
	}

	ls->PushInteger(iret);
	return 1;
}

int Process::LuaFn_LuaState_GetTableCount(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	LuaObject _obj = args[1].GetMetaTable();
	iret = _obj.GetTableCount();

	ls->PushInteger(iret);
	return 1;
}

void Process::_LuaHelper_ShowError(int errortype, const char * err)
{
	switch (errortype)
	{
	case LUAERROR_LOADINGSCRIPT:
		MessageBox(NULL, err, "Error in loading script!", MB_OK);
		break;
	}
}