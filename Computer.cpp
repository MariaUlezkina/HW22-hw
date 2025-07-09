#include "Computer.h"

Computer::Computer()
{
    name = new char[10] {"no"};
    frequency = 0;
    ram = 0;
    hasDVD = false;

    price = 0;
}

Computer::Computer(const char* _name, float _frequency, int _ram, bool _hasDVD, float _price)
{
    int size = strlen(_name) + 1;
    name = new char[size];
    strcpy_s(name, size, _name);

    frequency = _frequency;
    ram = _ram;
    hasDVD = _hasDVD;
    price = _price;
}

Computer::Computer(const Computer& obj)
{
    int size = strlen(obj.name) + 1;
    name = new char[size];
    strcpy_s(name, size, obj.name);

    frequency = obj.frequency;
    ram = obj.ram;
    hasDVD = obj.hasDVD;
    price = obj.price;
}

Computer& Computer::operator=(const Computer& obj)
{
    if (this == &obj)
    {
        return *this;
    }

    delete[] name;
    int size = strlen(obj.name) + 1;
    name = new char[size];
    strcpy_s(name, size, obj.name);

    frequency = obj.frequency;
    ram = obj.ram;
    hasDVD = obj.hasDVD;
    price = obj.price;
    return *this;
}

Computer::~Computer()
{
    delete[] name;
}

void Computer::setName(const char* _name)
{
    delete[] name;
    int size = strlen(_name) + 1;
    name = new char[size];
    strcpy_s(name, size, _name);
}

void Computer::setFrequency(float _freq) 
{
    frequency = _freq; 
}
void Computer::setRam(int _ram) 
{ 
    ram = _ram; 
}
void Computer::setHasDVD(bool _dvd) 
{ 
    hasDVD = _dvd; 
}
void Computer::setPrice(float _price) 
{
    price = _price; 
}

const char* Computer::getName() const 
{
    return name; 
}
float Computer::getFrequency() const 
{ 
    return frequency; 
}
int Computer::getRam() const 
{ 
    return ram; 
}
bool Computer::getHasDVD() const 
{ 
    return hasDVD;
}
float Computer::getPrice() const 
{ 
    return price;
}

void Computer::showInfo() const
{
    cout << "Назва: " << name << endl;
    cout << "Частота: " << frequency << " ghz" << endl;
    cout << "Оперативна пам’ять: " << ram << " gb" << endl;
    cout << "Дисковод: " << (hasDVD ? "Так" : "Ні") << endl;
    cout << "Ціна: " << price << " грн" << endl;
    cout << "===================================================\n";
}
