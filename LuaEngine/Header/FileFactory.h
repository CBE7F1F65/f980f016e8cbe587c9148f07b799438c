#ifndef _FILEFACTORY_H
#define _FILEFACTORY_H

#include "MainDependency.h"
#include "DataFactory.h"

#define STRINGLENGTHMAX	0xff

#define TABLEFORMAT_DWORD	'd'
#define TABLEFORMAT_DWORDX	'D'
#define TABLEFORMAT_FLOAT	'f'
#define TABLEFORMAT_FLOATX	'F'
#define TABLEFORMAT_STRING	's'
#define TABLEFORMAT_STRINGX	'S'

static class FileFactory
{
public:
	FileFactory();
	~FileFactory();

	DWORD _FindFile(DataFactory * df, DWORD handle);
	DWORD _NewFileValue(DataFactory * df);
	bool _SetFileValue(DataFactory * df, DWORD set, DWORD sub, DWORD dval, string sval);
	bool _DeleteFileValue(DataFactory * df, DWORD handle);

	DWORD FindBinaryFile(DWORD handle){return _FindFile(&binaryfiledata, handle);};
	DWORD NewBinaryFileValue(){return _NewFileValue(&binaryfiledata);};
	bool SetBinaryFileValue(DWORD set, DWORD sub, DWORD dval, string sval){return _SetFileValue(&binaryfiledata, set, sub, dval, sval);};
	bool AddBinaryFileValue(DWORD set, DWORD dval, string sval){return _SetFileValue(&binaryfiledata, set, DATAOVERSUB, dval, sval);};
	bool DeleteBinaryFileValue(DWORD handle){return _DeleteFileValue(&binaryfiledata, handle);};

	DWORD FindTableFile(DWORD handle){return _FindFile(&tablefiledata, handle);};
	DWORD NewTableFileValue(){return _NewFileValue(&tablefiledata);};
	bool SetTableFileValue(DWORD set, DWORD sub, DWORD dval, string sval){return _SetFileValue(&tablefiledata, set, sub, dval, sval);};
	bool AddTableFileValue(DWORD set, DWORD dval, string sval){return _SetFileValue(&tablefiledata, set, DATAOVERSUB, dval, sval);};
	bool DeleteTableFileValue(DWORD handle){return _DeleteFileValue(&tablefiledata, handle);};

public:
	string _GetFileName(DataFactory * df, DWORD set);
	bool _SetFileName(DataFactory * df, DWORD set, string filename);
	DWORD _GetFileHandle(DataFactory * df, DWORD set);
	bool _SetFileHandle(DataFactory * df, DWORD set, DWORD handle);

	string GetBinaryFileName(DWORD set){return _GetFileName(&binaryfiledata, set);};
	bool SetBinaryFileName(DWORD set, string filename){return _SetFileName(&binaryfiledata, set, filename);};
	DWORD GetBinaryFileHandle(DWORD set){return _GetFileHandle(&binaryfiledata, set);};
	bool SetBinaryFileHandle(DWORD set, DWORD handle){return _SetFileHandle(&binaryfiledata, set, handle);};

	string GetTableFileName(DWORD set){return _GetFileName(&tablefiledata, set);};
	bool SetTableFileName(DWORD set, string filename){return _SetFileName(&tablefiledata, set, filename);};
	DWORD GetTableFileHandle(DWORD set){return _GetFileHandle(&tablefiledata, set);};
	bool SetTableFileHandle(DWORD set, DWORD handle){return _SetFileHandle(&tablefiledata, set, handle);};

public:

	// Line_01	handle	filename
	DWORD NewBinaryFile(string filename);
	DWORD OpenBinaryFile(string filename);
	bool CloseBinaryFile(DWORD handle);
	bool SeekBinaryFile(DWORD handle, DWORD pos, BYTE seekrel);
	DWORD ReadBinaryFile(DWORD handle, DWORD defval, BYTE bytes = sizeof(DWORD), bool tostring = false);
	bool WriteBinaryFile(DWORD handle, DWORD val, BYTE bytes = sizeof(DWORD), bool tostring = false);

	// Line_01	handle	filename
	// Line_02	col	format
	// Line_03	row	comment

	DWORD GetTableNCol(DWORD set);
	DWORD GetTableNRow(DWORD set);
	string GetTableFormat(DWORD set);
	string GetTableComment(DWORD set);
	bool SetTableNCol(DWORD set, DWORD ncol);
	bool SetTableNRow(DWORD set, DWORD nrow);
	bool SetTableFormat(DWORD set, string format);
	bool SetTableComment(DWORD set, string format);

	DWORD NewTableFile(string filename, string format);
	DWORD OpenTableFile(string filename, string format);
	bool CloseTableFile(DWORD handle, bool save = true);
	DWORD GetDwordTableFile(DWORD set, DWORD col, DWORD row, DWORD defval);
	bool SetDwordTableFile(DWORD set, DWORD col, DWORD row, DWORD val);
	string GetStringTableFile(DWORD set, DWORD col, DWORD row, string defval);
	bool SetStringTableFile(DWORD set, DWORD col, DWORD row, string val);

	DataFactory binaryfiledata;
	DataFactory tablefiledata;

}filefactory;

#endif