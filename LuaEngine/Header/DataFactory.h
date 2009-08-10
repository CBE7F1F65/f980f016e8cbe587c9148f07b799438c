#ifndef _DATAFACTORY_H
#define _DATAFACTORY_H

#include "MainDependency.h"

typedef vector<DWORD> DwordData;
typedef vector<string> StringData;

typedef vector<DwordData> DwordDataSet;
typedef vector<StringData> StringDataSet;

#define DATAOVERSUB	((DWORD)(LONG_PTR)-1)

static class DataFactory
{
public:
	DataFactory();
	~DataFactory();

	DWORD NewDwordData(DWORD size = 0, bool temp = false);
	DWORD NewStringData(DWORD size = 0, bool temp = false);
	DWORD NewSetData(DWORD size = 0, bool temp = false);

	DWORD DeleteDwordData(DWORD index);
	DWORD DeleteStringData(DWORD index);
	DWORD DeleteSetData(DWORD index);

	DWORD GetSetLength(bool temp = false);
	DWORD GetSubLength(DWORD index, bool temp = false);

	bool SetDwordData(DWORD index, DWORD sub, DWORD val, bool temp = false);
	bool SetStringData(DWORD index, DWORD sub, string val, bool temp = false);

	DWORD GetDwordData(DWORD index, DWORD sub, DWORD defval, bool temp = false);
	string GetStringData(DWORD index, DWORD sub, string defval, bool temp = false);

	bool CopyDwordData(DWORD fromindex, DWORD toindex, bool fromtemp = false, bool totemp = false);
	bool CopyStringData(DWORD fromindex, DWORD toindex, bool fromtemp = false, bool totemp = false);


public:
	DwordDataSet dworddataset;
	StringDataSet stringdataset;

	DwordDataSet dworddatasettemp;
	StringDataSet stringdatasettemp;
}datafactory;

#endif