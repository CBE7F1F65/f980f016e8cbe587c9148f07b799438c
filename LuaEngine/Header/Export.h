#ifndef _EXPORT_H
#define _EXPORT_H

#include "MainDependency.h"

class Export
{
public:
	Export();
	~Export();
public:
	static HGE * InitHGE();
	static HGE * ReleaseHGE();

	static int LoadLuaFile(LuaState * ls, const char * filename, bool bDoFile = false);
	static int DoLuaFile(LuaState * ls, const char * filename){return LoadLuaFile(ls, filename, true);};

	static int ReadLuaFileTable(LuaState * ls){return DoLuaFile(ls, DEFAULT_LUAFILETABLEFILE);};
public:
	static HGE * hge;
};

#endif