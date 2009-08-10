#ifndef _DATAFACTORY_H
#define _DATAFACTORY_H

#include "MainDependency.h"

typedef vector<BYTE> ByteData;
typedef vector<WORD> WordData;
typedef vector<DWORD> DwordData;
typedef vector<string> StringData;

typedef vector<ByteData> ByteDataSet;
typedef vector<WordData> WordDataSet;
typedef vector<DwordData> DwordDataSet;
typedef vector<StringData> StringDataSet;

#define DATAOVERSUB	((DWORD)(LONG_PTR)-1)

static class DataFactory
{
public:
	DataFactory();
	~DataFactory();

	DWORD NewByteData(DWORD size = 0, bool temp = false);
	DWORD NewWordData(DWORD size = 0, bool temp = false);
	DWORD NewDwordData(DWORD size = 0, bool temp = false);
	DWORD NewStringData(DWORD size = 0, bool temp = false);
	DWORD NewSetData(DWORD size = 0, bool temp = false);

	DWORD DeleteByteData(DWORD index);
	DWORD DeleteWordData(DWORD index);
	DWORD DeleteDwordData(DWORD index);
	DWORD DeleteStringData(DWORD index);
	DWORD DeleteSetData(DWORD index);

	DWORD GetSetLength(bool temp = false);
	DWORD GetSubLength(DWORD index, bool temp = false);

	bool SetByteData(DWORD index, DWORD sub, BYTE val, bool temp = false);
	bool SetWordData(DWORD index, DWORD sub, WORD val, bool temp = false);
	bool SetDwordData(DWORD index, DWORD sub, DWORD val, bool temp = false);
	bool SetStringData(DWORD index, DWORD sub, string val, bool temp = false);

	BYTE GetByteData(DWORD index, DWORD sub, BYTE defval, bool temp = false);
	WORD GetWordData(DWORD index, DWORD sub, WORD defval, bool temp = false);
	DWORD GetDwordData(DWORD index, DWORD sub, DWORD defval, bool temp = false);
	string GetStringData(DWORD index, DWORD sub, string defval, bool temp = false);

	bool CopyByteData(DWORD fromindex, DWORD toindex, bool fromtemp = false, bool totemp = false);
	bool CopyWordData(DWORD fromindex, DWORD toindex, bool fromtemp = false, bool totemp = false);
	bool CopyDwordData(DWORD fromindex, DWORD toindex, bool fromtemp = false, bool totemp = false);
	bool CopyStringData(DWORD fromindex, DWORD toindex, bool fromtemp = false, bool totemp = false);


public:
	ByteDataSet bytedataset;
	WordDataSet worddataset;
	DwordDataSet dworddataset;
	StringDataSet stringdataset;

	ByteDataSet bytedatasettemp;
	WordDataSet worddatasettemp;
	DwordDataSet dworddatasettemp;
	StringDataSet stringdatasettemp;
}datafactory;

#endif