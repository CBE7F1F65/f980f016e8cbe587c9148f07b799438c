#include "../Header/FileFactory.h"

#define FLOATBUFFERSIZE 16

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
			if ((*_set)[i][0] == handle)
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

bool FileFactory::_SetFileValue(DataFactory * df, DWORD set, DWORD sub, BYTE bval, WORD wval, DWORD dval, string sval)
{
	if (set != DATAOVERSUB)
	{
		if (sub == DATAOVERSUB)
		{
			sub = df->GetSubLength(set, true);
		}
		df->SetByteData(set, sub, bval, true);
		df->SetWordData(set, sub, wval, true);
		df->SetDwordData(set, sub, dval, true);
		df->SetStringData(set, sub, sval, true);
		return true;
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


DWORD FileFactory::NewBinaryFile(string filename)
{
	FILE * file = fopen(filename.data(), "wb");
	if (file != NULL)
	{
		DWORD set = _NewBinaryFileValue();
		_SetBinaryFileValue(set, 0, 0, 0, (DWORD)file, filename);
	}
	return (DWORD)file;
}

DWORD FileFactory::OpenBinaryFile(string filename)
{
	FILE * file = fopen(filename.data(), "rb+");
	if (file != NULL)
	{
		DWORD set = _NewBinaryFileValue();
		_SetBinaryFileValue(set, 0, 0, 0, (DWORD)file, filename);
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
	return _DeleteBinaryFileValue(handle);
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
		DWORD set = _FindBinaryFile(handle);
		_AddBinaryFileValue(set, 0, 0, 0, str);
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
		DWORD set = _FindBinaryFile(handle);
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

DWORD FileFactory::NewTableFile(string filename, string format)
{
	FILE * file = fopen(filename.data(), "wb");
	if (file != NULL)
	{
		DWORD set = _NewTableFileValue();
		WORD col = format.length();
		_SetTableFileValue(set, 0, 0, 0, (DWORD)file, filename);
		_AddTableFileValue(set, 0, col, 1, format);
		_AddTableFileValue(set, 0, 0, 0, format);
	}
	return (DWORD)file;
}

DWORD FileFactory::OpenTableFile(string filename, string format)
{
	FILE * file = fopen(filename.data(), "rb+");
	if (file != NULL)
	{
		DWORD set = _NewTableFileValue();
		WORD col = format.length();
		_SetTableFileValue(set, 0, 0, 0, (DWORD)file, filename);
		_AddTableFileValue(set, 0, col, 1, format);
		char * buffer;
		DWORD bufferlength = STRINGLENGTHMAX * col;
		buffer = (char *)malloc(sizeof(char) * bufferlength);
		fgets(buffer, bufferlength, file);
		string comment = buffer;
		_AddTableFileValue(set, 0, 0, 0, comment);
		int i = 0;
		while (!feof(file))
		{
			char _string[STRINGLENGTHMAX];
			int _int;
			float _float;
			switch (format[i])
			{
			case TABLEFORMAT_BYTE:
			case TABLEFORMAT_WORD:
			case TABLEFORMAT_DWORD:
				fscanf(file, "%d", &_int);
				break;
			case TABLEFORMAT_BYTEX:
			case TABLEFORMAT_WORDX:
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
			case TABLEFORMAT_BYTE:
			case TABLEFORMAT_BYTEX:
				_AddTableFileValue(set, _int, 0, 0, str);
				break;
			case TABLEFORMAT_WORD:
			case TABLEFORMAT_WORDX:
				_AddTableFileValue(set, 0, _int, 0, str);
				break;
			case TABLEFORMAT_DWORD:
			case TABLEFORMAT_DWORDX:
				_AddTableFileValue(set, 0, 0, _int, str);
				break;
			case TABLEFORMAT_FLOAT:
			case TABLEFORMAT_FLOATX:
				_AddTableFileValue(set, 0, 0, CUINT(&_float), str);
				break;
			case TABLEFORMAT_STRING:
			case TABLEFORMAT_STRINGX:
				str = _string;
				_AddTableFileValue(set, 0, 0, 0, str);
				str = "";
				break;
			}
			i++;
			if (i >= col)
			{
				DWORD row = tablefiledata.GetDwordData(set, 1, 1, true);
				tablefiledata.SetDwordData(set, 1, row+1, true);
				i = 0;
			}
		}
	}
	return (DWORD)file;
}

bool FileFactory::CloseTableFile(DWORD handle, bool save /* = true */)
{
	FILE * file = (FILE *)handle;
	DWORD set = _FindTableFile(handle);
	string filename = "";
	filename = tablefiledata.GetStringData(set, 0, filename, true);
	fclose(file);
	if (save)
	{
		file = fopen(filename.data(), "wb");
		if (file == NULL)
		{
			return false;
		}
		string format = "";
		format = tablefiledata.GetStringData(set, 1, format, true);
		string comment = "";
		comment = tablefiledata.GetStringData(set, 2, comment, true);
		WORD col = tablefiledata.GetWordData(set, 1, 0, true);
		DWORD row = tablefiledata.GetDwordData(set, 1, 1, true);
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
				DWORD sub = i * col + j + 3;
				switch (format.data()[j])
				{
				case TABLEFORMAT_BYTE:
				case TABLEFORMAT_BYTEX:
					_int = tablefiledata.GetByteData(set, sub, 0, true);
					break;
				case TABLEFORMAT_WORD:
				case TABLEFORMAT_WORDX:
					_int = tablefiledata.GetWordData(set, sub, 0, true);
					break;
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
				case TABLEFORMAT_BYTE:
				case TABLEFORMAT_WORD:
				case TABLEFORMAT_DWORD:
					fprintf(file, "%d", _int);
					break;
				case TABLEFORMAT_BYTEX:
				case TABLEFORMAT_WORDX:
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
	return _DeleteTableFileValue(handle);
}