#include "../Header/Export.h"

HGE * Export::hge = NULL;

Export::Export()
{
}

Export::~Export()
{
	ReleaseHGE();
}

HGE * Export::InitHGE()
{
	if (!hge)
	{
		hge = hgeCreate(HGE_VERSION);
		hge->Resource_SetPath(DEFAULT_RESOURCEPATH);
	}
	return hge;
}

HGE * Export::ReleaseHGE()
{
	if (hge)
	{
		hge->Release();
	}
	hge = NULL;
	return hge;
}

int Export::LoadLuaFile(LuaState * ls, const char * filename, bool bDoFile /* = false */)
{
	bool bTempUseHGE = false;
	if (hge == NULL)
	{
		bTempUseHGE = true;
		InitHGE();
	}
	int iret = 0;
	bool wildcard = false;
	char filenamebuffer[MAX_PATH];
	strcpy(filenamebuffer, filename);
	for (int i=0; i<strlen(filenamebuffer); i++)
	{
		if (filenamebuffer[i] == '*')
		{
			wildcard = true;
			break;
		}
	}
	if (wildcard)
	{
		char * filename;
		char filepath[_MAX_PATH];
		char fullfilename[_MAX_PATH];
		sprintf(filepath, hge->Resource_MakePath(filenamebuffer));
		while (true)
		{
			int _lastindex = strlen(filepath)-1;
			if (filepath[_lastindex] == '\\' || filepath[_lastindex] == '/')
			{
				break;
			}
			filepath[_lastindex] = 0;
		}
		filename = hge->Resource_EnumFiles(filenamebuffer);
		do 
		{
			sprintf(fullfilename, "%s%s", filepath, filename);
			if (bDoFile)
			{
				iret = ls->DoFile(fullfilename);
			}
			else
			{
				iret = ls->LoadFile(fullfilename);
			}
			if (iret != 0)
			{
				break;
			}
		} while (filename = hge->Resource_EnumFiles());
	}
	else
	{
		if (bDoFile)
		{
			iret = ls->DoFile(filenamebuffer);
		}
		else
		{
			iret = ls->LoadFile(filenamebuffer);
		}
	}

	if (bTempUseHGE)
	{
		ReleaseHGE();
	}
	return iret;
}