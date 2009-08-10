#include "../Header/FileFactory.h"

#define FILEHANDLELINE		0
#define FILENAMELINE		0
#define TABLENCOLLINE		1
#define TABLENROWLINE		2
#define TABLEFORMATLINE		1
#define TABLECOMMENTLINE	2
#define TABLEDATASTARTLINE	3

#define FLOATBUFFERSIZE 16
#define TABLEFILEGETPOSITION(COL, ROW, NCOL)	((ROW)*(NCOL)+(COL)+TABLEDATASTARTLINE)


FileFactory::FileFactory()
{

}

FileFactory::~FileFactory()
{

}

DWORD FileFactory::_FindFile(DataFactory * df, DWORD handle)
{
	DwordDataSet * _set = &(df->dworddatasettemp);
	if ((HANDLE)handle != INVALID_HANDLE_VALUE)
	{
		for (int i=0; i<_set->size(); i++)
		{
			if (_GetFileHandle(df, i))
			{
				return i;
			}
		}
	}
	return DATAOVERSUB;
}

DWORD FileFactory::_NewFileValue(DataFactory * df)
{
	return df->NewSetData(0, true);
}

bool FileFactory::_SetFileValue(DataFactory * df, DWORD set, DWORD sub, DWORD dval, string sval)
{
	if (set != DATAOVERSUB)
	{
		if (sub == DATAOVERSUB)
		{
			sub = df->GetSubLength(set, true);
		}
		bool ret = true;
		if (!df->SetDwordData(set, sub, dval, true))
		{
			ret = false;
		}
		if (!df->SetStringData(set, sub, sval, true))
		{
			ret = false;
		}
		return ret;
	}
	return false;
}

bool FileFactory::_DeleteFileValue(DataFactory * df, DWORD handle)
{
	DWORD set = _FindFile(df, handle);
	if (set != DATAOVERSUB)
	{
		df->DeleteSetData(set);
		return true;
	}
	return false;
}


string FileFactory::_GetFileName(DataFactory * df, DWORD set)
{
	string strdef = "";
	if (set != DATAOVERSUB)
	{
		strdef = df->GetStringData(set, FILENAMELINE, strdef, true);
	}
	return strdef;
}

bool FileFactory::_SetFileName(DataFactory * df, DWORD set, string filename)
{
	if (set != DATAOVERSUB)
	{
		return df->SetStringData(set, FILENAMELINE, filename, true);
	}
	return false;
}

DWORD FileFactory::_GetFileHandle(DataFactory * df, DWORD set)
{
	DWORD handle = DATAOVERSUB;
	if (set != DATAOVERSUB)
	{
		handle = df->GetDwordData(set, FILEHANDLELINE, handle, true);
	}
	return handle;
}

bool FileFactory::_SetFileHandle(DataFactory * df, DWORD set, DWORD handle)
{
	if (set != DATAOVERSUB)
	{
		return df->SetDwordData(set, FILEHANDLELINE, handle, true);
	}
	return false;
}


DWORD FileFactory::NewBinaryFile(string filename)
{
	FILE * file = fopen(filename.data(), "wb");
	if (file != NULL)
	{
		DWORD set = NewBinaryFileValue();
		SetBinaryFileHandle(set, (DWORD)file);
		SetBinaryFileName(set, filename);
	}
	return (DWORD)file;
}

DWORD FileFactory::OpenBinaryFile(string filename)
{
	FILE * file = fopen(filename.data(), "rb+");
	if (file != NULL)
	{
		DWORD set = NewBinaryFileValue();
		SetBinaryFileHandle(set, (DWORD)file);
		SetBinaryFileName(set, filename);
	}
	return (DWORD)file;
}


bool FileFactory::CloseBinaryFile(DWORD handle)
{
	FILE * file = (FILE *)handle;
	if (file == NULL)
	{
		return false;
	}
	fclose(file);
	return DeleteBinaryFileValue(handle);
}

bool FileFactory::SeekBinaryFile(DWORD handle, DWORD pos, BYTE seekrel)
{
	FILE * file = (FILE *)handle;
	if (file == NULL)
	{
		return false;
	}
	fseek(file, (long)pos, (int)seekrel);
	return true;
}

DWORD FileFactory::ReadBinaryFile(DWORD handle, DWORD defval, BYTE bytes /* = sizeof */, bool tostring /* = false */)
{
	FILE * file = (FILE *)handle;
	DWORD ret = defval;
	if (file == NULL || feof(file))
	{
		return ret;
	}
	if (tostring || bytes > sizeof(DWORD))
	{
		char buffer[STRINGLENGTHMAX];
		if (bytes >= STRINGLENGTHMAX)
		{
			bytes = STRINGLENGTHMAX - 1;
		}
		if (!bytes)
		{
			fscanf(file, "%s", buffer);
		}
		else
		{
			fread(&buffer, 1, bytes, file);
			buffer[bytes] = 0;
		}
		string str = buffer;
		DWORD set = FindBinaryFile(handle);
		AddBinaryFileValue(set, 0, str);
		ret = binaryfiledata.GetSubLength(set, true);
	}
	else
	{
		fread(&ret, 1, bytes, file);
	}
	return ret;
}

bool FileFactory::WriteBinaryFile(DWORD handle, DWORD val, BYTE bytes /* = sizeof */, bool tostring /* = false */)
{
	FILE * file = (FILE *)handle;
	if (file == NULL)
	{
		return false;
	}
	if (tostring)
	{
		DWORD set = FindBinaryFile(handle);
		string str = "";
		str = binaryfiledata.GetStringData(set, val, str, true);
		if (!bytes)
		{
			bytes = str.length() + 1;
		}
		fwrite(str.data(), 1, bytes, file);
	}
	else
	{
		fwrite(&val, 1, bytes, file);
	}
	return true;
}

DWORD FileFactory::GetTableNCol(DWORD set)
{
	DWORD ncol = 0;
	if (set != DATAOVERSUB)
	{
		ncol = tablefiledata.GetDwordData(set, TABLENCOLLINE, ncol, true);
	}
	return ncol;
}

DWORD FileFactory::GetTableNRow(DWORD set)
{
	DWORD nrow = 0;
	if (set != DATAOVERSUB)
	{
		nrow = tablefiledata.GetDwordData(set, TABLENROWLINE, nrow, true);
	}
	return nrow;
}

bool FileFactory::SetTableNCol(DWORD set, DWORD ncol)
{
	if (set != DATAOVERSUB)
	{
		return tablefiledata.SetDwordData(set, TABLENCOLLINE, ncol, true);
	}
	return false;
}

bool FileFactory::SetTableNRow(DWORD set, DWORD nrow)
{
	if (set != DATAOVERSUB)
	{
		return tablefiledata.SetDwordData(set, TABLENROWLINE, nrow, true);
	}
	return false;
}

string FileFactory::GetTableFormat(DWORD set)
{
	string strdef = "";
	if (set != DATAOVERSUB)
	{
		strdef = tablefiledata.GetStringData(set, TABLEFORMATLINE, strdef, true);
	}
	return strdef;
}

string FileFactory::GetTableComment(DWORD set)
{
	string strdef = "";
	if (set != DATAOVERSUB)
	{
		strdef = tablefiledata.GetStringData(set, TABLECOMMENTLINE, strdef, true);
	}
	return strdef;
}

bool FileFactory::SetTableFormat(DWORD set, string format)
{
	if (set != DATAOVERSUB)
	{
		return tablefiledata.SetStringData(set, TABLEFORMATLINE, format, true);
	}
	return false;
}

bool FileFactory::SetTableComment(DWORD set, string comment)
{
	if (set != DATAOVERSUB)
	{
		return tablefiledata.SetStringData(set, TABLECOMMENTLINE, comment, true);
	}
	return false;
}

DWORD FileFactory::NewTableFile(string filename, string format)
{
	FILE * file = fopen(filename.data(), "wb");
	if (file != NULL)
	{
		DWORD set = NewTableFileValue();
		WORD col = format.length();

		SetTableFileHandle(set, (DWORD)file);
		SetTableFileName(set, filename);
		SetTableNCol(set, col);
		SetTableNRow(set, 1);
		SetTableFormat(set, format);
		SetTableComment(set, format);
	}
	return (DWORD)file;
}

DWORD FileFactory::OpenTableFile(string filename, string format)
{
	FILE * file = fopen(filename.data(), "rb+");
	if (file != NULL)
	{
		DWORD set = NewTableFileValue();
		WORD col = format.length();
		char * buffer;
		DWORD bufferlength = STRINGLENGTHMAX * col;
		buffer = (char *)malloc(sizeof(char) * bufferlength);
		fgets(buffer, bufferlength, file);
		string comment = buffer;

		SetTableFileHandle(set, (DWORD)file);
		SetTableFileName(set, filename);
		SetTableNCol(set, col);
		SetTableNRow(set, 1);
		SetTableFormat(set, format);
		SetTableComment(set, comment);

		int i = 0;
		while (!feof(file))
		{
			char _string[STRINGLENGTHMAX];
			int _int;
			float _float;
			switch (format[i])
			{
			case TABLEFORMAT_DWORD:
				fscanf(file, "%d", &_int);
				break;
			case TABLEFORMAT_DWORDX:
				fscanf(file, "%x", &_int);
				break;
			case TABLEFORMAT_FLOAT:
			case TABLEFORMAT_FLOATX:
				fscanf(file, "%f", &_float);
				break;
			case TABLEFORMAT_STRING:
			case TABLEFORMAT_STRINGX:
				fscanf(file, "%s", _string);
				break;
			}
			if (feof(file))
			{
				break;
			}
			string str = "";
			switch (format[i])
			{
			case TABLEFORMAT_DWORD:
			case TABLEFORMAT_DWORDX:
				AddTableFileValue(set, _int, str);
				break;
			case TABLEFORMAT_FLOAT:
			case TABLEFORMAT_FLOATX:
				AddTableFileValue(set, CUINT(&_float), str);
				break;
			case TABLEFORMAT_STRING:
			case TABLEFORMAT_STRINGX:
				str = _string;
				AddTableFileValue(set, 0, str);
				str = "";
				break;
			}
			i++;
			if (i >= col)
			{
				DWORD row = GetTableNRow(set);
				SetTableNRow(set, row+1);
				i = 0;
			}
		}
	}
	return (DWORD)file;
}

bool FileFactory::CloseTableFile(DWORD handle, bool save /* = true */)
{
	FILE * file = (FILE *)handle;
	DWORD set = FindTableFile(handle);
	string filename = "";
	filename = GetTableFileName(set);
	fclose(file);
	if (save)
	{
		file = fopen(filename.data(), "wb");
		if (file == NULL)
		{
			return false;
		}
		string format = "";
		format = GetTableFormat(set);
		string comment = "";
		comment = GetTableComment(set);
		DWORD col = GetTableNCol(set);
		DWORD row = GetTableNRow(set);
		fprintf(file, "%s", comment.data());
		for (int i=0; i<row-1; i++)
		{
			for (int j=0; j<col ;j++)
			{
				int _int;
				float _float;
				DWORD _dword;
				string _string;
				string _strdef = "";
				char buffer[FLOATBUFFERSIZE];
				DWORD sub = TABLEFILEGETPOSITION(j, i, col);
				switch (format.data()[j])
				{
				case TABLEFORMAT_DWORD:
				case TABLEFORMAT_DWORDX:
					_int = tablefiledata.GetDwordData(set, sub, 0, true);
					break;
				case TABLEFORMAT_FLOAT:
				case TABLEFORMAT_FLOATX:
					_dword = (tablefiledata.GetDwordData(set, sub, 0, true));
					_float = CFLOAT(&_dword);
					break;
				case TABLEFORMAT_STRING:
				case TABLEFORMAT_STRINGX:
					_string = tablefiledata.GetStringData(set, sub, _strdef, true);
					break;
				}
				switch (format.data()[j])
				{
				case TABLEFORMAT_DWORD:
					fprintf(file, "%d", _int);
					break;
				case TABLEFORMAT_DWORDX:
					fprintf(file, "%x", _int);
					break;
				case TABLEFORMAT_FLOAT:
				case TABLEFORMAT_FLOATX:
					sprintf(buffer, "%f", _float);
					while (buffer[strlen(buffer)-1] == '0')
					{
						buffer[strlen(buffer)-1] = 0;
					}
					if (buffer[strlen(buffer)-1] == '.')
					{
						buffer[strlen(buffer)-1] = 0;
					}
					fprintf(file, "%s", buffer);
					break;
				case TABLEFORMAT_STRING:
				case TABLEFORMAT_STRINGX:
					fprintf(file, "%s", _string.data());
					break;
				}
				if (j != col-1)
				{
					fprintf(file, "\t");
				}
				else
				{
					fprintf(file, "\r\n");
				}
			}
		}
		fclose(file);
	}
	return DeleteTableFileValue(handle);
}

DWORD FileFactory::GetDwordTableFile(DWORD set, DWORD col, DWORD row, DWORD defval)
{
	DWORD ret = defval;
	if (set != DATAOVERSUB)
	{
		DWORD ncol = GetTableNCol(set);
		DWORD sub = TABLEFILEGETPOSITION(col, row, ncol);
		defval = tablefiledata.GetDwordData(set, sub, defval, true);
	}
	return defval;
}

bool FileFactory::SetDwordTableFile(DWORD set, DWORD col, DWORD row, DWORD val)
{
	if (set != DATAOVERSUB)
	{
		DWORD ncol = GetTableNCol(set);
		DWORD sub = TABLEFILEGETPOSITION(col, row, ncol);
		return tablefiledata.SetDwordData(set, sub, val, true);
	}
	return false;

}

string FileFactory::GetStringTableFile(DWORD set, DWORD col, DWORD row, string defval)
{
	if (set != DATAOVERSUB)
	{
		DWORD ncol = GetTableNCol(set);
		DWORD sub = TABLEFILEGETPOSITION(col, row, ncol);
		defval = tablefiledata.GetStringData(set, sub, defval, true);
	}
	return defval;
}

bool FileFactory::SetStringTableFile(DWORD set, DWORD col, DWORD row, string val)
{
	if (set != DATAOVERSUB)
	{
		DWORD ncol = GetTableNCol(set);
		DWORD sub = TABLEFILEGETPOSITION(col, row, ncol);
		return tablefiledata.SetStringData(set, sub, val, true);
	}
	return false;

}