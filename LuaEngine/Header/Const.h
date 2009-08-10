#ifndef _CONST_H
#define _CONST_H

#ifndef CINT

	#define CINT(p)		(*(int *)(p))
	#define CUINT(p)	(*(DWORD *)(p))
	#define CFLOAT(p)	(*(float *)(p))

#endif

#endif