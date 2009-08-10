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
	DwordDataSet * _dset;
	StringDataSet * _sset;
	if (temp)
	{
		_dset = &(dworddatasettemp);
		_sset = &(stringdatasettemp);
	}
	else
	{
		_dset = &(dworddataset);
		_sset = &(stringdataset);
	}
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
	DwordDataSet * _dset;
	StringDataSet * _sset;
	if (temp)
	{
		_dset = &(dworddatasettemp);
		_sset = &(stringdatasettemp);
	}
	else
	{
		_dset = &(dworddataset);
		_sset = &(stringdataset);
	}
	if (_dset->size() <= index)
	{
		return DATAOVERSUB;
	}
	if (_sset->size() <= index)
	{
		return DATAOVERSUB;
	}
	DwordData * _ddata = &((*_dset)[index]);
	StringData * _sdata = &((*_sset)[index]);
	maxlength = (_ddata->size() > maxlength) ? (_ddata->size()) : (maxlength);
	maxlength = (_sdata->size() > maxlength) ? (_sdata->size()) : (maxlength);
	return maxlength;
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
	DwordDataSet * _dset;
	StringDataSet * _sset;
	if (temp)
	{
		_dset = &(dworddatasettemp);
		_sset = &(stringdatasettemp);
	}
	else
	{
		_dset = &(dworddataset);
		_sset = &(stringdataset);
	}
	DWORD maxlength = GetSetLength(temp);
	maxlength++;
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
	DeleteDwordData(index);
	DeleteStringData(index);
	return GetSetLength(true);
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