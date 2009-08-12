#ifndef _CONST_H
#define _CONST_H

#ifndef CINT

	#define CINT(p)		(*(int *)(p))
	#define CUINT(p)	(*(DWORD *)(p))
	#define CFLOAT(p)	(*(float *)(p))

#endif

#ifdef DEFAULT_RESOURCEPATH
	#undef DEFAULT_RESOURCEPATH
#endif

#define DEFAULT_INITLUAFILE			"Init.lua"
#define LUAFN_SYSTEMINITIAL			"SystemInitial"
#define LUAFN_HGEFRAMEFUNC			"hgeFrameFunc"
#define LUAFN_HGERENDERFUNC			"hgeRenderFunc"
#define LUAFN_HGEFOCUSLOSTFUNC		"hgeFocusLostFunc"
#define LUAFN_HGEFOCUSGAINFUNC		"hgeFocusGainFunc"
#define LUAFN_HGEGFXRESTOREFUNC		"hgeGfxRestoreFunc"
#define LUAFN_HGEEXITFUNC			"hgeExitFunc"

#ifdef __RELEASE
	#define DEFAULT_RESOURCEPATH	"Resource"
#else
	#define DEFAULT_RESOURCEPATH	"../../Resource"
#endif

#ifdef DEFAULT_HGEDLLPATH
	#undef DEFAULT_HGEDLLPATH
#endif

#ifdef __RELEASE
	#define DEFAULT_HGEDLLPATH		"Resource/hge.dll"
#else
	#ifdef _DEBUG
		#define DEFAULT_HGEDLLPATH		"../../Resource/Debug/hge.dll"
	#else
		#define DEFAULT_HGEDLLPATH		"../../Resource/hge.dll"
	#endif // _DEBUG
#endif // __RELEASE

#ifdef LOG_STR_FILENAME
	#define LOG_STR_FILENAME		"LuaEngine.log"
#endif // LOG_STR_FILENAME

#endif