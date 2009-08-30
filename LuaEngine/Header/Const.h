#ifndef _CONST_H
#define _CONST_H

#ifdef CINT
	#undef CINT
	#undef CUINT
	#undef CLONGLONG
	#undef CULONGLONG
	#undef CFLOAT
	#undef CDOUBLE

	#undef CINTN
	#undef CUINTN
	#undef CLONGLONGN
	#undef CULONGLONGN
	#undef CFLOATN
	#undef CDOUBLEN
#endif

#define CINT(p)			(*(int *)(p))
#define CUINT(p)		(*(DWORD *)(p))
#define CLONGLONG(p)	(*(LONGLONG *)(p))
#define CULONGLONG(p)	(*(QWORD *)(p))
#define CFLOAT(p)		(*(float *)(p))
#define CDOUBLE(p)		(*(double *)(p))

#define CINTN(p)		(*(int *)(&(p)))
#define CUINTN(p)		(*(DWORD *)(&(p)))
#define CLONGLONGN(p)	(*(LONGLONG *)(&(p)))
#define CULONGLONGN(p)	(*(QWORD *)(&(p)))
#define CFLOATN(p)		(*(float *)(&(p)))
#define CDOUBLEN(p)		(*(double *)(&(p)))

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

#undef  LOG_STR_FILENAME
#define LOG_STR_FILENAME		"LuaEngine.log"

#define M_STRINGMAX		0x80
#define M_MESSAGESTRMAX	0x100

#endif