#include "../Header/Process.h"
#include "../Header/LuaConstDefine.h"

bool Process::_LuaRegistHGEFunction(LuaObject * obj)
{
	obj->Register("System_SetState", LuaFn_hge_System_SetState);
	obj->Register("System_GetState", LuaFn_hge_System_GetState);
	obj->Register("System_Log", LuaFn_hge_System_Log);

	obj->Register("System_GetErrorMessage", LuaFn_hge_System_GetErrorMessage);
	obj->Register("System_Launch", LuaFn_hge_System_Launch);
	obj->Register("System_Snapshot", LuaFn_hge_System_Snapshot);

	obj->Register("System_Set2DMode", LuaFn_hge_System_Set2DMode);
	obj->Register("System_Set3DMode", LuaFn_hge_System_Set3DMode);
	obj->Register("System_GetFarPoint", LuaFn_hge_System_GetFarPoint);
	obj->Register("System_Is2DMode", LuaFn_hge_System_Is2DMode);
	obj->Register("System_Transform3DPoint", LuaFn_hge_System_Transform3DPoint);

	obj->Register("Resource_Load", LuaFn_hge_Resource_Load);
	obj->Register("Resource_Free", LuaFn_hge_Resource_Free);
	obj->Register("Resource_AttachPack", LuaFn_hge_Resource_AttachPack);
	obj->Register("Resource_RemovePack", LuaFn_hge_Resource_RemovePack);
	obj->Register("Resource_RemoveAllPacks", LuaFn_hge_Resource_RemovePack);
	obj->Register("Resource_SetPath", LuaFn_hge_Resource_SetPath);
	obj->Register("Resource_MakePath", LuaFn_hge_Resource_MakePath);
	obj->Register("Resource_EnumFiles", LuaFn_hge_Resource_EnumFiles);
	obj->Register("Resource_EnumFolders", LuaFn_hge_Resource_EnumFolders);
	obj->Register("Resource_CreatePack", LuaFn_hge_Resource_CreatePack);
	obj->Register("Resource_AddFileInPack", LuaFn_hge_Resource_AddFileInPack);
	obj->Register("Resource_GetCRC", LuaFn_hge_Resource_GetCRC);
	obj->Register("Resource_GetPackFirstFileName", LuaFn_hge_Resource_GetPackFirstFileName);

	obj->Register("Ini_SetInt", LuaFn_hge_Ini_SetInt);
	obj->Register("Ini_GetInt", LuaFn_hge_Ini_GetInt);
	obj->Register("Ini_SetFloat", LuaFn_hge_Ini_SetFloat);
	obj->Register("Ini_GetFloat", LuaFn_hge_Ini_GetFloat);
	obj->Register("Ini_SetString", LuaFn_hge_Ini_SetString);
	obj->Register("Ini_GetString", LuaFn_hge_Ini_GetString);

	obj->Register("Random_Seed", LuaFn_hge_Random_Seed);
	obj->Register("Random_Int", LuaFn_hge_Random_Int);
	obj->Register("Random_Float", LuaFn_hge_Random_Float);

	obj->Register("Timer_GetTime", LuaFn_hge_Timer_GetTime);
	obj->Register("Timer_GetDelta", LuaFn_hge_Timer_GetDelta);
	obj->Register("Timer_GetFPS", LuaFn_hge_Timer_GetFPS);
	obj->Register("Timer_GetWorstFPS", LuaFn_hge_Timer_GetWorstFPS);
	obj->Register("Timer_GetCurrentSystemTime", LuaFn_hge_Timer_GetCurrentSystemTime);

	obj->Register("Effect_Load", LuaFn_hge_Effect_Load);
	obj->Register("Effect_Free", LuaFn_hge_Effect_Free);
	obj->Register("Effect_Play", LuaFn_hge_Effect_Play);
	obj->Register("Effect_PlayEx", LuaFn_hge_Effect_Play);

	obj->Register("Stream_Load", LuaFn_hge_Stream_Load);
	obj->Register("Stream_Free", LuaFn_hge_Stream_Free);
	obj->Register("Stream_Play", LuaFn_hge_Stream_Play);

	obj->Register("Channel_SetPanning", LuaFn_hge_Channel_SetPanning);
	obj->Register("Channel_SetVolume", LuaFn_hge_Channel_SetVolume);
	obj->Register("Channel_SetPitch", LuaFn_hge_Channel_SetPitch);
	obj->Register("Channel_Pause", LuaFn_hge_Channel_Pause);
	obj->Register("Channel_Resume", LuaFn_hge_Channel_Resume);
	obj->Register("Channel_Stop", LuaFn_hge_Channel_Stop);
	obj->Register("Channel_PauseAll", LuaFn_hge_Channel_Pause);
	obj->Register("Channel_ResumeAll", LuaFn_hge_Channel_Resume);
	obj->Register("Channel_StopAll", LuaFn_hge_Channel_Stop);
	obj->Register("Channel_IsPlaying", LuaFn_hge_Channel_IsPlaying);
	obj->Register("Channel_GetLength", LuaFn_hge_Channel_GetLength);
	obj->Register("Channel_GetPos", LuaFn_hge_Channel_GetPos);
	obj->Register("Channel_SetPos", LuaFn_hge_Channel_SetPos);
	obj->Register("Channel_SetStartPos", LuaFn_hge_Channel_SetStartPos);
	obj->Register("Channel_SlideTo", LuaFn_hge_Channel_SlideTo);
	obj->Register("Channel_IsSliding", LuaFn_hge_Channel_IsSliding);
	obj->Register("Channel_SetLoop", LuaFn_hge_Channel_SetLoop);
	obj->Register("Channel_RemoveLoop", LuaFn_hge_Channel_RemoveLoop);

	obj->Register("Input_GetMousePos", LuaFn_hge_Input_GetMousePos);
	obj->Register("Input_SetMousePos", LuaFn_hge_Input_SetMousePos);
	obj->Register("Input_GetMouseWheel", LuaFn_hge_Input_GetMouseWheel);
	obj->Register("Input_IsMouseOver", LuaFn_hge_Input_IsMouseOver);
	obj->Register("Input_KeyDown", LuaFn_hge_Input_KeyDown);
	obj->Register("Input_KeyUp", LuaFn_hge_Input_KeyUp);
	obj->Register("Input_GetKeyState", LuaFn_hge_Input_GetKeyState);
	obj->Register("Input_GetKeyName", LuaFn_hge_Input_GetKeyName);
	obj->Register("Input_GetKey", LuaFn_hge_Input_GetKey);
	obj->Register("Input_GetChar", LuaFn_hge_Input_GetChar);
	obj->Register("Input_GetEvent", LuaFn_hge_Input_GetEvent);

	obj->Register("Input_GetDIKey", LuaFn_hge_Input_GetDIKey);
	obj->Register("Input_SetDIKey", LuaFn_hge_Input_SetDIKey);
	obj->Register("Input_GetDIJoy", LuaFn_hge_Input_GetDIJoy);
	obj->Register("Input_HaveJoy", LuaFn_hge_Input_HaveJoy);

	obj->Register("Gfx_BeginScene", LuaFn_hge_Gfx_BeginScene);
	obj->Register("Gfx_EndScene", LuaFn_hge_Gfx_EndScene);
	obj->Register("Gfx_Clear", LuaFn_hge_Gfx_Clear);
	obj->Register("Gfx_RenderLine", LuaFn_hge_Gfx_RenderLine);
	obj->Register("Gfx_RenderTriple", LuaFn_hge_Gfx_RenderTriple);
	obj->Register("Gfx_RenderQuad", LuaFn_hge_Gfx_RenderQuad);
	obj->Register("Gfx_StartBatch", LuaFn_hge_Gfx_StartBatch);
	obj->Register("Gfx_FinishBatch", LuaFn_hge_Gfx_FinishBatch);
	obj->Register("Gfx_SetClipping", LuaFn_hge_Gfx_SetClipping);
	obj->Register("Gfx_SetTransform", LuaFn_hge_Gfx_SetTransform);
	obj->Register("Gfx_SetTransform", LuaFn_hge_Gfx_SetTransform);

	obj->Register("Target_Create", LuaFn_hge_Target_Create);
	obj->Register("Target_Free", LuaFn_hge_Target_Free);
	obj->Register("Target_GetTexture", LuaFn_hge_Target_GetTexture);

	obj->Register("Texture_Create", LuaFn_hge_Texture_Create);
	obj->Register("Texture_Load", LuaFn_hge_Texture_Load);
	obj->Register("Texture_Free", LuaFn_hge_Texture_Free);
	obj->Register("Texture_GetWH", LuaFn_hge_Texture_GetWH);
	obj->Register("Texture_Lock", LuaFn_hge_Texture_Lock);
	obj->Register("Texture_Unlock", LuaFn_hge_Texture_Unlock);

	obj->Register("Font_Load", LuaFn_hge_Font_Load);
	obj->Register("Font_Free", LuaFn_hge_Font_Free);
	obj->Register("Gfx_RenderText", LuaFn_hge_Gfx_RenderText);
	obj->Register("Gfx_RenderTextToTarget", LuaFn_hge_Gfx_RenderTextToTarget);

	return true;
}


void Process::_LuaHelper_GetVertex(LuaObject * obj, hgeVertex * vertex)
{
	if (obj->IsTable())
	{
		LuaObject _para;
		_para = obj->GetByName("col");
		if (_para.IsNumber() || _para.IsTable())
		{
			vertex->col = _LuaHelper_GetColor(&_para);
		}
		_para = obj->GetByName("tx");
		if (_para.IsNumber())
		{
			vertex->tx = _para.GetFloat();
		}
		_para = obj->GetByName("ty");
		if (_para.IsNumber())
		{
			vertex->ty = _para.GetFloat();
		}
		_para = obj->GetByName("x");
		if (_para.IsNumber())
		{
			vertex->x = _para.GetFloat();
		}
		_para = obj->GetByName("y");
		if (_para.IsNumber())
		{
			vertex->y = _para.GetFloat();
		}
		_para = obj->GetByName("z");
		if (_para.IsNumber())
		{
			vertex->z = _para.GetFloat();
		}
	}
}

void Process::_LuaHelper_GetTriple(LuaObject * obj, hgeTriple * triple)
{
	if (obj->IsTable())
	{
		LuaObject _para;
		_para = obj->GetByName("v");
		if (_para.IsTable())
		{
			LuaObject _ver;
			for (int i=0; i<HGEPRIM_TRIPLES; i++)
			{
				_ver = _para.GetByIndex(i+1);
				_LuaHelper_GetVertex(&_ver, &(triple->v[i]));
			}
		}
		_para = obj->GetByName("blend");
		if (_para.IsNumber())
		{
			triple->blend = _para.GetInteger();
		}
		_para = obj->GetByName("tex");
		if (_para.IsNumber())
		{
			triple->tex = _LuaHelper_GetDWORD(&_para);
		}
	}
}

void Process::_LuaHelper_GetQuad(LuaObject * obj, hgeQuad * quad)
{
	if (obj->IsTable())
	{
		LuaObject _para;
		_para = obj->GetByName("v");
		if (_para.IsTable())
		{
			LuaObject _ver;
			for (int i=0; i<HGEPRIM_QUADS; i++)
			{
				_ver = _para.GetByIndex(i+1);
				_LuaHelper_GetVertex(&_ver, &(quad->v[i]));
			}
		}
		_para = obj->GetByName("blend");
		if (_para.IsNumber())
		{
			quad->blend = _para.GetInteger();
		}
		_para = obj->GetByName("tex");
		if (_para.IsNumber())
		{
			quad->tex = _LuaHelper_GetDWORD(&_para);
		}
	}
}

int Process::LuaFn_hge_System_SetState(LuaState * ls)
{
	LuaStack args(ls);

	int hgestate = args[1].GetInteger();
	LuaObject _obj = args[2];
	HWND _hwnd;
	switch (hgestate & HGE_STATE_MASK)
	{
	case HGE_STATE_BOOLTEST:
		hge->System_SetState((hgeBoolState)hgestate, args[2].GetBoolean());
		break;
	case HGE_STATE_FUNCTEST:
		break;
	case HGE_STATE_HWNDTEST:
		_hwnd = (HWND)(_LuaHelper_GetDWORD(&_obj));
		hge->System_SetState((hgeHwndState)hgestate, _hwnd);
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

	int hgestate = args[1].GetInteger();
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
		_LuaHelper_PushDWORD(ls, (DWORD)hge->System_GetState((hgeHwndState)hgestate));
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

int Process::LuaFn_hge_System_Log(LuaState * ls)
{
	LuaStack args(ls);

	hge->System_Log(args[1].GetString());

	return 0;
}

int Process::LuaFn_hge_System_GetErrorMessage(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;

	sret = hge->System_GetErrorMessage();

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_System_Launch(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->System_Launch(args[1].GetString());

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_System_Snapshot(LuaState * ls)
{
	LuaStack args(ls);
	char * filename = 0;

	if (args.Count())
	{
		filename = (char *)(args[1].GetString());
	}
	hge->System_Snapshot(filename);

	return 0;
}

int Process::LuaFn_hge_System_Set2DMode(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	hge3DPoint ptfar;
	if (args[1].IsTable())
	{
		ptfar.x = args[1].GetByName("x").GetFloat();
		ptfar.y = args[1].GetByName("y").GetFloat();
		ptfar.z = args[1].GetByName("z").GetFloat();
	}
	else
	{
		ptfar.x = args[1].GetFloat();
		ptfar.y = args[2].GetFloat();
		ptfar.z = args[3].GetFloat();
	}
	bret = hge->System_Set2DMode(ptfar);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_System_Set3DMode(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->System_Set3DMode();

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_System_GetFarPoint(LuaState * ls)
{
	LuaStack args(ls);
	hge3DPoint * ptfar;
	float fret[4];

	ptfar = hge->System_GetFarPoint();
	LuaStackObject table;
	table = ls->CreateTable();
	table.SetNumber("x", ptfar->x);
	table.SetNumber("y", ptfar->y);
	table.SetNumber("z", ptfar->z);
	table.SetNumber("scale", ptfar->scale);

	ls->PushValue(table);
	return 1;
}

int Process::LuaFn_hge_System_Is2DMode(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->System_Is2DMode();

	ls->PushValue(bret);
	return 1;
}

int Process::LuaFn_hge_System_Transform3DPoint(LuaState * ls)
{
	LuaStack args(ls);
	float fret;

	hge3DPoint ptfar;
	if (args[1].IsTable())
	{
		ptfar.x = args[1].GetByName("x").GetFloat();
		ptfar.y = args[1].GetByName("y").GetFloat();
		ptfar.z = args[1].GetByName("z").GetFloat();
	}
	else
	{
		ptfar.x = args[1].GetFloat();
		ptfar.y = args[2].GetFloat();
		ptfar.z = args[3].GetFloat();
	}
	fret = hge->System_Transform3DPoint(&ptfar);

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Resource_Load(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	DWORD size;

	dret = (DWORD)(hge->Resource_Load(args[1].GetString(), &size));

	_LuaHelper_PushDWORD(ls, dret);
	_LuaHelper_PushDWORD(ls, size);

	return 2;
}

int Process::LuaFn_hge_Resource_Free(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	DWORD _dword = _LuaHelper_GetDWORD(&_obj);
	hge->Resource_Free((void *)(_dword));

	return 0;
}

int Process::LuaFn_hge_Resource_AttachPack(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	int password = 0;

	if (args.Count() > 1)
	{
		password = args[2].GetInteger();
	}
	bret = hge->Resource_AttachPack(args[1].GetString(), password);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Resource_RemovePack(LuaState * ls)
{
	LuaStack args(ls);

	if (args.Count() > 0)
	{
		hge->Resource_RemovePack(args[1].GetString());
	}
	else
	{
		hge->Resource_RemoveAllPacks();
	}

	return 0;
}

int Process::LuaFn_hge_Resource_SetPath(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;

	sret = hge->Resource_SetPath(args[1].GetString());

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Resource_MakePath(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;

	sret = hge->Resource_MakePath(args[1].GetString());

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Resource_EnumFiles(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;
	char * wildcard = 0;

	if (args.Count() > 0)
	{
		wildcard = (char *)(args[1].GetString());
	}
	sret = hge->Resource_EnumFiles(wildcard);

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Resource_EnumFolders(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;
	char * wildcard = 0;

	if (args.Count() > 0)
	{
		wildcard = (char *)(args[1].GetString());
	}
	sret = hge->Resource_EnumFolders(wildcard);

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Resource_CreatePack(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	hgeMemoryFile memfile;

	LuaObject _obj = args[3].GetByName("data");
	DWORD _data = _LuaHelper_GetDWORD(&_obj);
	memfile.data = (BYTE *)(_data);
	memfile.filename = (char *)(args[3].GetByName("filename").GetString());
	_obj = args[3].GetByName("size");
	DWORD _size = _LuaHelper_GetDWORD(&_obj);
	memfile.size = _size;

	bret = hge->Resource_CreatePack(args[1].GetString(), args[2].GetInteger(), &memfile, NULL);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Resource_AddFileInPack(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	hgeMemoryFile memfile;

	LuaObject _obj = args[3].GetByName("data");
	DWORD _data = _LuaHelper_GetDWORD(&_obj);
	memfile.data = (BYTE *)(_data);
	memfile.filename = (char *)(args[3].GetByName("filename").GetString());
	_obj = args[3].GetByName("size");
	DWORD _size = _LuaHelper_GetDWORD(&_obj);
	memfile.size = _size;

	bret = hge->Resource_AddFileInPack(args[1].GetString(), args[2].GetInteger(), &memfile);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Resource_GetCRC(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	LuaObject _obj = args[1];
	DWORD _content = _LuaHelper_GetDWORD(&_obj);
	_obj = args[2];
	DWORD _size = _LuaHelper_GetDWORD(&_obj); 
	dret = hge->Resource_GetCRC((BYTE *)(_content), _size);

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Resource_GetPackFirstFileName(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;

	sret = hge->Resource_GetPackFirstFileName(args[1].GetString());

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Ini_SetInt(LuaState * ls)
{
	LuaStack args(ls);

	hge->Ini_SetInt(args[1].GetString(), args[2].GetString(), args[3].GetInteger());

	return 0;
}

int Process::LuaFn_hge_Ini_GetInt(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = hge->Ini_GetInt(args[1].GetString(), args[2].GetString(), args[3].GetInteger());

	ls->PushInteger(iret);
	return 1;
}

int Process::LuaFn_hge_Ini_SetFloat(LuaState * ls)
{
	LuaStack args(ls);

	hge->Ini_SetFloat(args[1].GetString(), args[2].GetString(), args[3].GetFloat());

	return 0;
}

int Process::LuaFn_hge_Ini_GetFloat(LuaState * ls)
{
	LuaStack args(ls);
	float fret;

	fret = hge->Ini_GetFloat(args[1].GetString(), args[2].GetString(), args[3].GetFloat());

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Ini_SetString(LuaState * ls)
{
	LuaStack args(ls);

	hge->Ini_SetString(args[1].GetString(), args[2].GetString(), args[3].GetString());

	return 0;
}

int Process::LuaFn_hge_Ini_GetString(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;

	sret = hge->Ini_GetString(args[1].GetString(), args[2].GetString(), args[3].GetString());

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Random_Seed(LuaState * ls)
{
	LuaStack args(ls);
	int seed = 0;

	if (args.Count() > 0)
	{
		seed = args[1].GetInteger();
	}
	hge->Random_Seed(seed);

	return 0;
}

int Process::LuaFn_hge_Random_Int(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = hge->Random_Int(args[1].GetInteger(), args[2].GetInteger());

	ls->PushInteger(iret);
	return 1;
}

int Process::LuaFn_hge_Random_Float(LuaState * ls)
{
	LuaStack args(ls);
	float fret;

	fret = hge->Random_Float(args[1].GetFloat(), args[2].GetFloat());

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Timer_GetTime(LuaState * ls)
{
	LuaStack args(ls);
	float fret;

	fret = hge->Timer_GetTime();

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Timer_GetDelta(LuaState * ls)
{
	LuaStack args(ls);
	float fret;

	fret = hge->Timer_GetDelta();

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Timer_GetFPS(LuaState * ls)
{
	LuaStack args(ls);
	float fret;
	int mod = 0;

	if (args.Count() > 0)
	{
		mod = args[1].GetInteger();
	}
	fret = hge->Timer_GetFPS(mod);

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Timer_GetWorstFPS(LuaState * ls)
{
	LuaStack args(ls);
	float fret;

	fret = hge->Timer_GetWorstFPS(args[1].GetInteger());

	ls->PushNumber(fret);
	return 1;
}

int Process::LuaFn_hge_Timer_GetCurrentSystemTime(LuaState * ls)
{
	LuaStack args(ls);
	LONGLONG _longlong;

	_longlong = hge->Timer_GetCurrentSystemTime();

	_LuaHelper_PushLONGLONG(ls, _longlong);
	return 1;
}

int Process::LuaFn_hge_Effect_Load(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	DWORD size = 0;

	if (args.Count() > 1)
	{
		LuaObject _obj = args[2];
		size = _LuaHelper_GetDWORD(&_obj);
	}
	dret = (DWORD)(hge->Effect_Load(args[1].GetString(), size));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Effect_Free(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HEFFECT _heffect = (HEFFECT)(_LuaHelper_GetDWORD(&_obj));
	hge->Effect_Free(_heffect);

	return 0;
}

int Process::LuaFn_hge_Effect_Play(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	int volume = 100;
	int pan = 0;
	float pitch = 1.0f;
	bool loop = false;

	LuaObject _obj = args[1];
	HEFFECT _heffect = (HEFFECT)(_LuaHelper_GetDWORD(&_obj));
	int argscount = args.Count();
	if (argscount > 1)
	{
		volume = args[2].GetInteger();
		if (argscount > 2)
		{
			pan = args[3].GetInteger();
			if (argscount > 3)
			{
				pitch = args[4].GetFloat();
				if (argscount > 4)
				{
					loop = args[5].GetBoolean();
				}
			}
		}
	}
	if (argscount > 1)
	{
		dret = (DWORD)(hge->Effect_PlayEx(_heffect, volume, pan, pitch, loop));
	}
	else
	{
		dret = (DWORD)(hge->Effect_Play(_heffect));
	}

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Stream_Load(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	DWORD size = 0;
	bool bLoad = true;

	int argscount = args.Count();
	if (argscount > 1)
	{
		LuaObject _obj = args[2];
		size = _LuaHelper_GetDWORD(&_obj);
		if (argscount > 2)
		{
			bLoad = args[3].GetBoolean();
		}
	}
	dret = (DWORD)(hge->Stream_Load(args[1].GetString(), size, bLoad));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Stream_Free(LuaState * ls)
{
	LuaStack args(ls);


	LuaObject _obj = args[1];
	HSTREAM _hstream = (HSTREAM)(_LuaHelper_GetDWORD(&_obj));
	hge->Stream_Free(_hstream);

	return 0;
}

int Process::LuaFn_hge_Stream_Play(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	int volume = 100;

	if (args.Count() > 2)
	{
		volume = args[3].GetInteger();
	}
	LuaObject _obj = args[1];
	HSTREAM _hstream = (HSTREAM)(_LuaHelper_GetDWORD(&_obj));
	dret = (DWORD)(hge->Stream_Play(_hstream, args[2].GetBoolean(), volume));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Channel_SetPanning(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_SetPanning(_hchannel, args[2].GetInteger());

	return 0;
}

int Process::LuaFn_hge_Channel_SetVolume(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_SetVolume(_hchannel, args[2].GetInteger());

	return 0;
}

int Process::LuaFn_hge_Channel_SetPitch(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_SetPitch(_hchannel, args[2].GetFloat());

	return 0;
}

int Process::LuaFn_hge_Channel_Pause(LuaState * ls)
{
	LuaStack args(ls);

	if (args.Count() > 0)
	{
		LuaObject _obj = args[1];
		HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
		hge->Channel_Pause(_hchannel);
	}
	else
	{
		hge->Channel_PauseAll();
	}

	return 0;
}

int Process::LuaFn_hge_Channel_Resume(LuaState * ls)
{
	LuaStack args(ls);

	if (args.Count() > 0)
	{
		LuaObject _obj = args[1];
		HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
		hge->Channel_Resume(_hchannel);
	}
	else
	{
		hge->Channel_ResumeAll();
	}

	return 0;
}

int Process::LuaFn_hge_Channel_Stop(LuaState * ls)
{
	LuaStack args(ls);
	if (args.Count() > 0)
	{
		LuaObject _obj = args[1];
		HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
		hge->Channel_Stop(_hchannel);
	}
	else
	{
		hge->Channel_StopAll();
	}

	return 0;
}

int Process::LuaFn_hge_Channel_IsPlaying(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_IsPlaying(_hchannel);

	return 0;
}

int Process::LuaFn_hge_Channel_GetLength(LuaState * ls)
{
	LuaStack args(ls);
	QWORD _qword;

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	_qword = hge->Channel_GetLength(_hchannel);

	_LuaHelper_PushQWORD(ls, _qword);
	return 1;
}

int Process::LuaFn_hge_Channel_GetPos(LuaState * ls)
{
	LuaStack args(ls);
	int _int;
	QWORD _qword;

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	_qword = hge->Channel_GetPos(_hchannel);

	_LuaHelper_PushQWORD(ls, _qword);
	return 1;
}

int Process::LuaFn_hge_Channel_SetPos(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	_obj = args[2];
	QWORD pos = _LuaHelper_GetQWORD(&_obj);

	hge->Channel_SetPos(_hchannel, pos);

	return 0;
}

int Process::LuaFn_hge_Channel_SetStartPos(LuaState * ls)
{
	LuaStack args(ls);
	hgeChannelSyncInfo csi;

	LuaObject _alllength = args[2].GetByName("alllength");
	csi.allLength = _LuaHelper_GetQWORD(&_alllength);
	LuaObject _introlength = args[2].GetByName("introlength");
	csi.introLength = _LuaHelper_GetQWORD(&_introlength);
	LuaObject _startpos = args[2].GetByName("startpos");
	csi.startPos = _LuaHelper_GetQWORD(&_startpos);
	LuaObject _sync = args[2].GetByName("sync");
	csi.sync = _LuaHelper_GetDWORD(&_sync);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_SetStartPos(_hchannel, &csi);

	return 0;
}

int Process::LuaFn_hge_Channel_SlideTo(LuaState * ls)
{
	LuaStack args(ls);
	int _int;
	int pan = -101;
	float pitch = -1;

	int argscount = args.Count();
	if (argscount > 3)
	{
		pan = args[4].GetInteger();
		if (argscount > 4)
		{
			pitch = args[5].GetFloat();
		}
	}
	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_SlideTo(_hchannel, args[2].GetFloat(), args[3].GetInteger(), pan, pitch);

	return 0;
}

int Process::LuaFn_hge_Channel_IsSliding(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	bret = hge->Channel_IsSliding(_hchannel);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Channel_SetLoop(LuaState * ls)
{
	LuaStack args(ls);
	hgeChannelSyncInfo csi;

	LuaObject _alllength = args[2].GetByName("alllength");
	csi.allLength = _LuaHelper_GetQWORD(&_alllength);
	LuaObject _introlength = args[2].GetByName("introlength");
	csi.introLength = _LuaHelper_GetQWORD(&_introlength);
	LuaObject _startpos = args[2].GetByName("startpos");
	csi.startPos = _LuaHelper_GetQWORD(&_startpos);
	LuaObject _sync = args[2].GetByName("sync");
	csi.sync = _LuaHelper_GetDWORD(&_sync);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_SetLoop(_hchannel, &csi);

	return 0;
}

int Process::LuaFn_hge_Channel_RemoveLoop(LuaState * ls)
{
	LuaStack args(ls);
	hgeChannelSyncInfo csi;

	LuaObject _alllength = args[2].GetByName("alllength");
	csi.allLength = _LuaHelper_GetQWORD(&_alllength);
	LuaObject _introlength = args[2].GetByName("introlength");
	csi.introLength = _LuaHelper_GetQWORD(&_introlength);
	LuaObject _startpos = args[2].GetByName("startpos");
	csi.startPos = _LuaHelper_GetQWORD(&_startpos);
	LuaObject _sync = args[2].GetByName("sync");
	csi.sync = _LuaHelper_GetDWORD(&_sync);

	LuaObject _obj = args[1];
	HCHANNEL _hchannel = (HCHANNEL)(_LuaHelper_GetDWORD(&_obj));
	hge->Channel_RemoveLoop(_hchannel, &csi);

	return 0;
}

int Process::LuaFn_hge_Input_GetMousePos(LuaState * ls)
{
	LuaStack args(ls);
	float x;
	float y;

	hge->Input_GetMousePos(&x, &y);

	ls->PushNumber(x);
	ls->PushNumber(y);
	return 2;
}

int Process::LuaFn_hge_Input_SetMousePos(LuaState * ls)
{
	LuaStack args(ls);

	hge->Input_SetMousePos(args[1].GetFloat(), args[2].GetFloat());

	return 0;
}

int Process::LuaFn_hge_Input_GetMouseWheel(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = hge->Input_GetMouseWheel();

	ls->PushInteger(iret);
	return 1;
}

int Process::LuaFn_hge_Input_IsMouseOver(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->Input_IsMouseOver();

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_KeyDown(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->Input_KeyDown(args[1].GetInteger());

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_KeyUp(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->Input_KeyUp(args[1].GetInteger());

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_GetKeyState(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->Input_GetKeyState(args[1].GetInteger());

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_GetKeyName(LuaState * ls)
{
	LuaStack args(ls);
	char * sret;

	sret = hge->Input_GetKeyName(args[1].GetInteger());

	ls->PushString(sret);
	return 1;
}

int Process::LuaFn_hge_Input_GetKey(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = hge->Input_GetKey();

	ls->PushInteger(iret);
	return 1;
}

int Process::LuaFn_hge_Input_GetChar(LuaState * ls)
{
	LuaStack args(ls);
	int iret;

	iret = hge->Input_GetChar();

	ls->PushInteger(iret);
	return 1;
}

int Process::LuaFn_hge_Input_GetEvent(LuaState * ls)
{
	LuaStack args(ls);
	hgeInputEvent inputevent;

	hge->Input_GetEvent(&inputevent);
	LuaStackObject table = ls->CreateTable();
	table.SetInteger("chr", inputevent.chr);
	table.SetInteger("flags", inputevent.flags);
	table.SetInteger("key", inputevent.key);
	table.SetInteger("type", inputevent.type);
	table.SetInteger("wheel", inputevent.wheel);
	table.SetNumber("x", inputevent.x);
	table.SetNumber("y", inputevent.y);

	ls->PushValue(table);
	return 1;
}

int Process::LuaFn_hge_Input_GetDIKey(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	BYTE statetype = DIKEY_PRESSED;

	if (args.Count() > 1)
	{
		statetype = args[2].GetInteger();
	}
	bret = hge->Input_GetDIKey(args[1].GetInteger(), statetype);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_SetDIKey(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	bool set = true;

	if (args.Count() > 1)
	{
		set = args[2].GetBoolean();
	}
	bret = hge->Input_SetDIKey(args[1].GetInteger(), set);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_GetDIJoy(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	BYTE statetype = DIKEY_PRESSED;

	if (args.Count() > 1)
	{
		statetype = args[2].GetInteger();
	}
	bret = hge->Input_GetDIJoy(args[1].GetInteger(), statetype);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Input_HaveJoy(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;

	bret = hge->Input_HaveJoy();

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Gfx_BeginScene(LuaState * ls)
{
	LuaStack args(ls);
	bool bret;
	HTARGET target = 0;

	if (args.Count() > 0)
	{
		LuaObject _obj = args[1];
		target = (HTARGET)_LuaHelper_GetDWORD(&_obj);
	}
	bret = hge->Gfx_BeginScene(target);

	ls->PushBoolean(bret);
	return 1;
}

int Process::LuaFn_hge_Gfx_EndScene(LuaState * ls)
{
	LuaStack args(ls);

	hge->Gfx_EndScene();

	return 0;
}

int Process::LuaFn_hge_Gfx_Clear(LuaState * ls)
{
	LuaStack args(ls);
	DWORD col;

	LuaObject obj = args[1];
	col = _LuaHelper_GetColor(&obj);
	hge->Gfx_Clear(col);

	return 0;
}

int Process::LuaFn_hge_Gfx_RenderLine(LuaState * ls)
{
	LuaStack args(ls);
	DWORD col = 0xffffffff;
	float z = 0.5f;

	int argscount = args.Count();
	if (argscount > 4)
	{
		LuaObject obj = args[5];
		col = _LuaHelper_GetColor(&obj);
		if (argscount > 5)
		{
			z = args[6].GetFloat();
		}
	}
	hge->Gfx_RenderLine(args[1].GetFloat(), args[2].GetFloat(), args[3].GetFloat(), args[4].GetFloat(), col, z);

	return 0;
}

int Process::LuaFn_hge_Gfx_RenderTriple(LuaState * ls)
{
	LuaStack args(ls);
	hgeTriple triple;

	LuaObject obj = args[1];
	_LuaHelper_GetTriple(&obj, &triple);
	hge->Gfx_RenderTriple(&triple);

	return 0;
}

int Process::LuaFn_hge_Gfx_RenderQuad(LuaState * ls)
{
	LuaStack args(ls);
	hgeQuad quad;

	LuaObject obj = args[1];
	_LuaHelper_GetQuad(&obj, &quad);
	hge->Gfx_RenderQuad(&quad);

	return 0;
}

int Process::LuaFn_hge_Gfx_StartBatch(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	LuaObject _obj = args[1];
	HTEXTURE _htexture = (HTEXTURE)_LuaHelper_GetDWORD(&_obj);
	_obj = args[4];
	int * _max_prim = (int *)_LuaHelper_GetDWORD(&_obj);
	dret = (DWORD)(hge->Gfx_StartBatch(args[1].GetInteger(), _htexture, args[3].GetInteger(), _max_prim));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Gfx_FinishBatch(LuaState * ls)
{
	LuaStack args(ls);

	hge->Gfx_FinishBatch(args[1].GetInteger());

	return 0;
}

int Process::LuaFn_hge_Gfx_SetClipping(LuaState * ls)
{
	LuaStack args(ls);
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;

	int argscount = args.Count();
	if (argscount > 0)
	{
		x = args[1].GetFloat();
		if (argscount > 1)
		{
			y = args[2].GetFloat();
			if (argscount > 2)
			{
				w = args[3].GetFloat();
				if (argscount > 3)
				{
					h = args[4].GetFloat();
				}
			}
		}
	}
	hge->Gfx_SetClipping(x, y, w, h);

	return 0;
}

int Process::LuaFn_hge_Gfx_SetTransform(LuaState * ls)
{
	LuaStack args(ls);

	int argscount = args.Count();
	if (argscount > 1 && args[2].IsTable())
	{
		D3DMATRIX matrix;
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4;j++)
			{
				matrix.m[i][j] = args[2].GetByIndex(i*4+j+1);
			}
		}
		hge->Gfx_SetTransform((D3DTRANSFORMSTATETYPE)(args[1].GetInteger()), &matrix);
	}
	else if (argscount > 0)
	{
		float x = 0;
		float y = 0;
		float dx = 0;
		float dy = 0;
		float rot = 0;
		float hscale = 0;
		float vscale = 0;

		x = args[1].GetFloat();
		if (argscount > 1)
		{
			y = args[2].GetFloat();
			if (argscount > 2)
			{
				dx = args[3].GetFloat();
				if (argscount > 3)
				{
					dy = args[4].GetFloat();
					if (argscount > 4)
					{
						rot = args[5].GetFloat();
						if (argscount > 5)
						{
							hscale = args[6].GetFloat();
							if (argscount > 6)
							{
								vscale = args[7].GetFloat();
							}
						}
					}
				}
			}
		}
		hge->Gfx_SetTransform(x, y, dx, dy, rot, hscale, vscale);
	}
	return 0;
}

int Process::LuaFn_hge_Target_Create(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	dret = (DWORD)(hge->Target_Create(args[1].GetInteger(), args[2].GetInteger(), args[3].GetBoolean()));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Target_Free(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HTARGET _htarget = (HTARGET)_LuaHelper_GetDWORD(&_obj);
	hge->Target_Free(_htarget);

	return 0;
}

int Process::LuaFn_hge_Target_GetTexture(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	LuaObject _obj = args[1];
	HTARGET _htarget = (HTARGET)_LuaHelper_GetDWORD(&_obj);
	dret = (DWORD)(hge->Target_GetTexture(_htarget));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Texture_Create(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	dret = (DWORD)(hge->Texture_Create(args[1].GetInteger(), args[2].GetInteger()));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Texture_Load(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	DWORD size = 0;
	bool bMipmap = false;

	int argscount = args.Count();
	if (argscount > 1)
	{
		LuaObject _obj = args[2];
		size = _LuaHelper_GetDWORD(&_obj);
		if (argscount > 2)
		{
			bMipmap = args[3].GetBoolean();
		}
	}
	dret = (DWORD)(hge->Texture_Load(args[1].GetString(), size, bMipmap));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Texture_Free(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HTEXTURE _htexture = (HTEXTURE)_LuaHelper_GetDWORD(&_obj);
	hge->Texture_Free(_htexture);

	return 0;
}

int Process::LuaFn_hge_Texture_GetWH(LuaState * ls)
{
	LuaStack args(ls);
	int width;
	int height;
	HTEXTURE tex;
	bool bOriginal = false;

	LuaObject _obj = args[1];
	tex = (HTEXTURE)_LuaHelper_GetDWORD(&_obj);
	if (args.Count() > 1)
	{
		bOriginal = args[2].GetBoolean();
	}
	width = hge->Texture_GetWidth(tex, bOriginal);
	height = hge->Texture_GetHeight(tex, bOriginal);

	ls->PushInteger(width);
	ls->PushInteger(height);
	return 2;
}

int Process::LuaFn_hge_Texture_Lock(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	bool bReadOnly = true;
	int left = 0;
	int top = 0;
	int width = 0;
	int height = 0;

	int argscount = args.Count();
	if (argscount > 1)
	{
		bReadOnly = args[2].GetBoolean();
		if (argscount > 2)
		{
			left = args[3].GetInteger();
			if (argscount > 3)
			{
				top = args[4].GetInteger();
				if (argscount > 4)
				{
					width = args[5].GetInteger();
					if (argscount > 5)
					{
						height = args[6].GetInteger();
					}
				}
			}
		}
	}
	LuaObject _obj = args[1];
	HTEXTURE _htexture = (HTEXTURE)_LuaHelper_GetDWORD(&_obj);
	dret = (DWORD)(hge->Texture_Lock(_htexture, bReadOnly, left, top, width, height));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Texture_Unlock(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HTEXTURE _htexture = (HTEXTURE)_LuaHelper_GetDWORD(&_obj);
	hge->Texture_Unlock(_htexture);

	return 0;
}

int Process::LuaFn_hge_Font_Load(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;

	dret = (DWORD)(hge->Font_Load(args[1].GetString(), args[2].GetInteger()));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}

int Process::LuaFn_hge_Font_Free(LuaState * ls)
{
	LuaStack args(ls);

	LuaObject _obj = args[1];
	HD3DFONT _hd3dfont = (HD3DFONT)_LuaHelper_GetDWORD(&_obj);
	hge->Font_Free(_hd3dfont);

	return 0;
}

int Process::LuaFn_hge_Gfx_RenderText(LuaState * ls)
{
	LuaStack args(ls);
	DWORD col = 0xffffffff;

	if (args.Count() > 6)
	{
		LuaObject obj = args[7];
		col = _LuaHelper_GetColor(&obj);
	}
	LuaObject _obj = args[1];
	HD3DFONT _hd3dfont = (HD3DFONT)_LuaHelper_GetDWORD(&_obj);
	hge->Gfx_RenderText(_hd3dfont, args[2].GetString(), args[3].GetFloat(), args[4].GetFloat(), args[5].GetFloat(), args[6].GetFloat(), col);

	return 0;
}

int Process::LuaFn_hge_Gfx_RenderTextToTarget(LuaState * ls)
{
	LuaStack args(ls);
	DWORD dret;
	DWORD col = 0xffffffff;

	if (args.Count() > 7)
	{
		LuaObject obj = args[8];
		col = _LuaHelper_GetColor(&obj);
	}
	LuaObject _obj = args[1];
	HTARGET _htarget = (HTARGET)_LuaHelper_GetDWORD(&_obj);
	_obj = args[2];
	HD3DFONT _hd3dfont = (HD3DFONT)_LuaHelper_GetDWORD(&_obj);
	dret = (DWORD)(hge->Gfx_RenderTextToTarget(_htarget, _hd3dfont, args[3].GetString(), args[4].GetFloat(), args[5].GetFloat(), args[6].GetFloat(), args[7].GetFloat(), col));

	_LuaHelper_PushDWORD(ls, dret);
	return 1;
}