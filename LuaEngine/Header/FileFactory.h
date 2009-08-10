#ifndef _FILEFACTORY_H
#define _FILEFACTORY_H

#include "MainDependency.h"
#include "DataFactory.h"

#define STRINGLENGTHMAX	0xff

#define TABLEFORMAT_BYTE	'b'
#define TABLEFORMAT_BYTEX	'B'
#define TABLEFORMAT_WORD	'w'
#define TABLEFORMAT_WORDX	'W'
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
	bool _SetFileValue(DataFactory * df, DWORD set, DWORD sub, BYTE bval, WORD wval, DWORD dval, string sval);
	bool _DeleteFileValue(DataFactory * df, DWORD handle);

	DWORD _FindBinaryFile(DWORD handle){return _FindFile(&binaryfiledata, handle);};
	DWORD _NewBinaryFileValue(){return _NewFileValue(&binaryfiledata);};
	bool _SetBinaryFileValue(DWORD set, DWORD sub, BYTE bval, WORD wval, DWORD dval, string sval){return _SetFileValue(&binaryfiledata, set, sub, bval, wval, dval, sval);};
	bool _AddBinaryFileValue(DWORD set, BYTE bval, WORD wval, DWORD dval, string sval){return _SetFileValue(&binaryfiledata, set, DATAOVERSUB, bval, wval, dval, sval);};
	bool _DeleteBinaryFileValue(DWORD handle){return _DeleteFileValue(&binaryfiledata, handle);};

	DWORD _FindTableFile(DWORD handle){return _FindFile(&tablefiledata, handle);};
	DWORD _NewTableFileValue(){return _NewFileValue(&tablefiledata);};
	bool _SetTableFileValue(DWORD set, DWORD sub, BYTE bval, WORD wval, DWORD dval, string sval){return _SetFileValue(&tablefiledata, set, sub, bval, wval, dval, sval);};
	bool _AddTableFileValue(DWORD set, BYTE bval, WORD wval, DWORD dval, string sval){return _SetFileValue(&tablefiledata, set, DATAOVERSUB, bval, wval, dval, sval);};
	bool _DeleteTableFileValue(DWORD handle){return _DeleteFileValue(&tablefiledata, handle);};

public:

	// Line_01	0	0	handle	filename
	DWORD NewBinaryFile(string filename);
	DWORD OpenBinaryFile(string filename);
	bool CloseBinaryFile(DWORD handle);
	bool SeekBinaryFile(DWORD handle, DWORD pos, BYTE seekrel);
	DWORD ReadBinaryFile(DWORD handle, DWORD defval, BYTE bytes = sizeof(DWORD), bool tostring = false);
	bool WriteBinaryFile(DWORD handle, DWORD val, BYTE bytes = sizeof(DWORD), bool tostring = false);

	// Line_01	0	0	handle	filename
	// Line_02	0	col	row	format
	// Line_03	0	0	0	comment
	DWORD NewTableFile(string filename, string format);
	DWORD OpenTableFile(string filename, string format);
	bool CloseTableFile(DWORD handle, bool save = true);
	DWORD GetDwordTableFile(DWORD handle, DWORD col, DWORD row, DWORD defval);
	bool SetDwordgTableFile(DWORD handle, DWORD col, DWORD row, DWORD val);
	string GetStringTableFile(DWORD handle, DWORD col, DWORD row, string defval);
	bool SetStringTableFile(DWORD handle, DWORD col, DWORD row, string val);

	DataFactory binaryfiledata;
	DataFactory tablefiledata;

}filefactory;

#endif