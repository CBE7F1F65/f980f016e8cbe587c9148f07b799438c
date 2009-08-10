#include "../Header/DataFactory.h"

DataFactory::DataFactory()
{

}

DataFactory::~DataFactory()
{

}

DWORD DataFactory::GetSetLength(bool temp /* = false */)
{
	DWORD maxlength = 0;
	ByteDataSet * _bset;
	WordDataSet * _wset;
	DwordDataSet * _dset;
	StringDataSet * _sset;
	if (temp)
	{
		_bset = &(bytedatasettemp);
		_wset = &(worddatasettemp);
		_dset = &(dworddatasettemp);
		_sset = &(stringdatasettemp);
	}
	else
	{
		_bset = &(bytedataset);
		_wset = &(worddataset);
		_dset = &(dworddataset);
		_sset = &(stringdataset);
	}
	maxlength = (_bset->size() > maxlength) ? (_bset->size()) : (maxlength);
	maxlength = (_wset->size() > maxlength) ? (_wset->size()) : (maxlength);
	maxlength = (_dset->size() > maxlength) ? (_dset->size()) : (maxlength);
	maxlength = (_sset->size() > maxlength) ? (_sset->size()) : (maxlength);
	return maxlength;
}

DWORD DataFactory::GetSubLength(DWORD index, bool temp /* = false */)
{
	if (index == DATAOVERSUB)
	{
		return false;
	}
	DWORD maxlength = 0;
	ByteDataSet * _bset;
	WordDataSet * _wset;
	DwordDataSet * _dset;
	StringDataSet * _sset;
	if (temp)
	{
		_bset = &(bytedatasettemp);
		_wset = &(worddatasettemp);
		_dset = &(dworddatasettemp);
		_sset = &(stringdatasettemp);
	}
	else
	{
		_bset = &(bytedataset);
		_wset = &(worddataset);
		_dset = &(dworddataset);
		_sset = &(stringdataset);
	}
	if (_bset->size() <= index)
	{
		return DATAOVERSUB;
	}
	if (_wset->size() <= index)
	{
		return DATAOVERSUB;
	}
	if (_dset->size() <= index)
	{
		return DATAOVERSUB;
	}
	if (_sset->size() <= index)
	{
		return DATAOVERSUB;
	}
	ByteData * _bdata = &((*_bset)[index]);
	WordData * _wdata = &((*_wset)[index]);
	DwordData * _ddata = &((*_dset)[index]);
	StringData * _sdata = &((*_sset)[index]);
	maxlength = (_bdata->size() > maxlength) ? (_bdata->size()) : (maxlength);
	maxlength = (_wdata->size() > maxlength) ? (_wdata->size()) : (maxlength);
	maxlength = (_ddata->size() > maxlength) ? (_ddata->size()) : (maxlength);
	maxlength = (_sdata->size() > maxlength) ? (_sdata->size()) : (maxlength);
	return maxlength;
}

DWORD DataFactory::NewByteData(DWORD size /* = 0 */, bool temp /* = false */)
{
	ByteData _item;
	if (size)
	{
		_item.resize(size);
	}
	ByteDataSet * _set;
	if (temp)
	{
		_set = &bytedatasettemp;
	}
	else
	{
		_set = &bytedataset;
	}
	_set->push_back(_item);
	return _set->size()-1;
}

DWORD DataFactory::NewWordData(DWORD size /* = 0 */, bool temp /* = false */)
{
	WordData _item;
	if (size)
	{
		_item.resize(size);
	}
	WordDataSet * _set;
	if (temp)
	{
		_set = &worddatasettemp;
	}
	else
	{
		_set = &worddataset;
	}
	_set->push_back(_item);
	return _set->size()-1;
}

DWORD DataFactory::NewDwordData(DWORD size /* = 0 */, bool temp /* = false */)
{
	DwordData _item;
	if (size)
	{
		_item.resize(size);
	}
	DwordDataSet * _set;
	if (temp)
	{
		_set = &dworddatasettemp;
	}
	else
	{
		_set = &dworddataset;
	}
	_set->push_back(_item);
	return _set->size()-1;
}

DWORD DataFactory::NewStringData(DWORD size /* = 0 */, bool temp /* = false */)
{
	StringData _item;
	if (size)
	{
		_item.resize(size);
	}
	StringDataSet * _set;
	if (temp)
	{
		_set = &stringdatasettemp;
	}
	else
	{
		_set = &stringdataset;
	}
	_set->push_back(_item);
	return _set->size()-1;
}

DWORD DataFactory::NewSetData(DWORD size /* = 0 */, bool temp /* = false */)
{
	ByteDataSet * _bset;
	WordDataSet * _wset;
	DwordDataSet * _dset;
	StringDataSet * _sset;
	if (temp)
	{
		_bset = &(bytedatasettemp);
		_wset = &(worddatasettemp);
		_dset = &(dworddatasettemp);
		_sset = &(stringdatasettemp);
	}
	else
	{
		_bset = &(bytedataset);
		_wset = &(worddataset);
		_dset = &(dworddataset);
		_sset = &(stringdataset);
	}
	DWORD maxlength = GetSetLength(temp);
	maxlength++;
	while (_bset->size() < maxlength)
	{
		NewByteData(size, temp);
	}
	while (_wset->size() < maxlength)
	{
		NewWordData(size, temp);
	}
	while (_dset->size() < maxlength)
	{
		NewDwordData(size, temp);
	}
	while (_sset->size() < maxlength)
	{
		NewStringData(size, temp);
	}
	return maxlength - 1;
}

DWORD DataFactory::DeleteByteData(DWORD index)
{
	ByteDataSet * _set = &bytedatasettemp;
	if (_set->size() > index)
	{
		ByteDataSet::iterator it = _set->begin();
		it += index;
		_set->erase(it);
	}
	return _set->size();
}

DWORD DataFactory::DeleteWordData(DWORD index)
{
	WordDataSet * _set = &worddatasettemp;
	if (_set->size() > index)
	{
		WordDataSet::iterator it = _set->begin();
		it += index;
		_set->erase(it);
	}
	return _set->size();
}

DWORD DataFactory::DeleteDwordData(DWORD index)
{
	DwordDataSet * _set = &dworddatasettemp;
	if (_set->size() > index)
	{
		DwordDataSet::iterator it = _set->begin();
		it += index;
		_set->erase(it);
	}
	return _set->size();
}

DWORD DataFactory::DeleteStringData(DWORD index)
{
	StringDataSet * _set = &stringdatasettemp;
	if (_set->size() > index)
	{
		StringDataSet::iterator it = _set->begin();
		it += index;
		_set->erase(it);
	}
	return _set->size();
}

DWORD DataFactory::DeleteSetData(DWORD index)
{
	DeleteByteData(index);
	DeleteWordData(index);
	DeleteDwordData(index);
	DeleteStringData(index);
	return GetSetLength(true);
}

bool DataFactory::SetByteData(DWORD index, DWORD sub, BYTE val, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	ByteDataSet * _set;
	if (temp)
	{
		_set = &bytedatasettemp;
	}
	else
	{
		_set = &bytedataset;
	}
	if (_set->size() <= index)
	{
		return false;
	}
	ByteData * _data = &((*_set)[index]);
	while (_data->size() <= sub)
	{
		_data->push_back(0);
	}
	(*_data)[sub] = val;
	return true;
}

bool DataFactory::SetWordData(DWORD index, DWORD sub, WORD val, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	WordDataSet * _set;
	if (temp)
	{
		_set = &worddatasettemp;
	}
	else
	{
		_set = &worddataset;
	}
	if (_set->size() <= index)
	{
		return false;
	}
	WordData * _data = &((*_set)[index]);
	while (_data->size() <= sub)
	{
		_data->push_back(0);
	}
	(*_data)[sub] = val;
	return true;
}

bool DataFactory::SetDwordData(DWORD index, DWORD sub, DWORD val, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	DwordDataSet * _set;
	if (temp)
	{
		_set = &dworddatasettemp;
	}
	else
	{
		_set = &dworddataset;
	}
	if (_set->size() <= index)
	{
		return false;
	}
	DwordData * _data = &((*_set)[index]);
	while (_data->size() <= sub)
	{
		_data->push_back(0);
	}
	(*_data)[sub] = val;
	return true;
}

bool DataFactory::SetStringData(DWORD index, DWORD sub, string val, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	StringDataSet * _set;
	if (temp)
	{
		_set = &stringdatasettemp;
	}
	else
	{
		_set = &stringdataset;
	}
	if (_set->size() <= index)
	{
		return false;
	}
	StringData * _data = &((*_set)[index]);
	string _str = "";
	while (_data->size() <= sub)
	{
		_data->push_back(_str);
	}
	(*_data)[sub] = val;
	return true;
}

BYTE DataFactory::GetByteData(DWORD index, DWORD sub, BYTE defval, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	ByteDataSet * _set;
	BYTE val = defval;
	if (temp)
	{
		_set = &bytedatasettemp;
	}
	else
	{
		_set = &bytedataset;
	}
	if (_set->size() > index)
	{
		ByteData * _data = &((*_set)[index]);
		if (_data->size() > sub)
		{
			val = (*_data)[sub];
		}
	}
	return val;
}

WORD DataFactory::GetWordData(DWORD index, DWORD sub, WORD defval, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	WordDataSet * _set;
	WORD val = defval;
	if (temp)
	{
		_set = &worddatasettemp;
	}
	else
	{
		_set = &worddataset;
	}
	if (_set->size() > index)
	{
		WordData * _data = &((*_set)[index]);
		if (_data->size() > sub)
		{
			val = (*_data)[sub];
		}
	}
	return val;
}

DWORD DataFactory::GetDwordData(DWORD index, DWORD sub, DWORD defval, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	DwordDataSet * _set;
	DWORD val = defval;
	if (temp)
	{
		_set = &dworddatasettemp;
	}
	else
	{
		_set = &dworddataset;
	}
	if (_set->size() > index)
	{
		DwordData * _data = &((*_set)[index]);
		if (_data->size() > sub)
		{
			val = (*_data)[sub];
		}
	}
	return val;
}

string DataFactory::GetStringData(DWORD index, DWORD sub, string defval, bool temp /* = false */)
{
	if (index == DATAOVERSUB || sub == DATAOVERSUB)
	{
		return false;
	}
	StringDataSet * _set;
	string val = defval;
	if (temp)
	{
		_set = &stringdatasettemp;
	}
	else
	{
		_set = &stringdataset;
	}
	if (_set->size() > index)
	{
		StringData * _data = &((*_set)[index]);
		if (_data->size() > sub)
		{
			val = (*_data)[sub];
		}
	}
	return val;
}

bool DataFactory::CopyByteData(DWORD fromindex, DWORD toindex, bool fromtemp /* = false */, bool totemp /* = false */)
{
	if (fromindex == DATAOVERSUB || toindex == DATAOVERSUB)
	{
		return false;
	}
	ByteDataSet * _fromset;
	if (fromtemp)
	{
		_fromset = &bytedatasettemp;
	}
	else
	{
		_fromset = &bytedataset;
	}
	if (_fromset->size() <= fromindex)
	{
		return false;
	}
	ByteData * _data;
	_data = &((*_fromset)[fromindex]);
	for (int i=0; i<_data->size(); i++)
	{
		SetByteData(toindex, i, (*_data)[i], totemp);
	}
	return true;
}

bool DataFactory::CopyWordData(DWORD fromindex, DWORD toindex, bool fromtemp /* = false */, bool totemp /* = false */)
{
	if (fromindex == DATAOVERSUB || toindex == DATAOVERSUB)
	{
		return false;
	}
	WordDataSet * _fromset;
	if (fromtemp)
	{
		_fromset = &worddatasettemp;
	}
	else
	{
		_fromset = &worddataset;
	}
	if (_fromset->size() <= fromindex)
	{
		return false;
	}
	WordData * _data;
	_data = &((*_fromset)[fromindex]);
	for (int i=0; i<_data->size(); i++)
	{
		SetWordData(toindex, i, (*_data)[i], totemp);
	}
	return true;
}

bool DataFactory::CopyDwordData(DWORD fromindex, DWORD toindex, bool fromtemp /* = false */, bool totemp /* = false */)
{
	if (fromindex == DATAOVERSUB || toindex == DATAOVERSUB)
	{
		return false;
	}
	DwordDataSet * _fromset;
	if (fromtemp)
	{
		_fromset = &dworddatasettemp;
	}
	else
	{
		_fromset = &dworddataset;
	}
	if (_fromset->size() <= fromindex)
	{
		return false;
	}
	DwordData * _data;
	_data = &((*_fromset)[fromindex]);
	for (int i=0; i<_data->size(); i++)
	{
		SetDwordData(toindex, i, (*_data)[i], totemp);
	}
	return true;
}

bool DataFactory::CopyStringData(DWORD fromindex, DWORD toindex, bool fromtemp /* = false */, bool totemp /* = false */)
{
	if (fromindex == DATAOVERSUB || toindex == DATAOVERSUB)
	{
		return false;
	}
	StringDataSet * _fromset;
	if (fromtemp)
	{
		_fromset = &stringdatasettemp;
	}
	else
	{
		_fromset = &stringdataset;
	}
	if (_fromset->size() <= fromindex)
	{
		return false;
	}
	StringData * _data;
	_data = &((*_fromset)[fromindex]);
	for (int i=0; i<_data->size(); i++)
	{
		SetStringData(toindex, i, (*_data)[i], totemp);
	}
	return true;
}