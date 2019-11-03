#include "Elul.h"



Elul::Elul()
{
	_name = "";
	_ptr = nullptr;
}

Elul::Elul(string name, fstream *_ptr = nullptr)
{
	_name = name + ".dat";
	fstream nameF(_name, ios::in | ios::out | ios::binary);
	_ptr = &nameF;
	_file = true;
}

Elul::Elul(Elul &&other)
{
	_name = other._name;
	_ptr = other._ptr;
	other._ptr = nullptr;
	_file = other._file;
}

Elul & Elul::operator=(Elul &&other)
{
	_name = other._name;
	_ptr = other._ptr;
	other._ptr = nullptr;
	_file = other._file;
}



Elul::~Elul()
{
	if (_ptr->is_open())
		_ptr->close();
	delete _ptr;
}

void Elul::isFile(string name)
{
	if(_file)

	_name = name + ".dat";
	fstream nameF(_name, ios::in | ios::out | ios::binary);
	_ptr = &nameF;
	_file = true;
}
