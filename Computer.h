#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
    char* name;
    float frequency;
    int ram;
    bool hasDVD;
    float price;
public:
    Computer();
    Computer(const char* _name, float _frequency, int _ram, bool _hasDVD, float _price);
    Computer(const Computer& obj);
    Computer& operator=(const Computer& obj);
    ~Computer();

    void setName(const char* _name);
    void setFrequency(float _freq);
    void setRam(int _ram);
    void setHasDVD(bool _dvd);
    void setPrice(float _price);

    const char* getName() const;
    float getFrequency() const;
    int getRam() const;
    bool getHasDVD() const;
    float getPrice() const;

    void showInfo() const;
};
