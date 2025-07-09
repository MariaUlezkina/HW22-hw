#include "Computer.h"
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Computer> comps;

    comps.push_back(Computer("ARTLINE Business B43v05", 2.4, 8, true, 12500));
    comps.push_back(Computer("Lenovo ThinkPad", 3.1, 16, false, 13700));
    comps.push_back(Computer("Vinga Advanced D6801", 2.9, 32, true, 21000));
    comps.push_back(Computer("Artline Gaming X49v40", 2.2, 4, true, 9000));
    comps.push_back(Computer("Vinga Odin D7101", 3.3, 16, false, 19500));

    cout << "усі комп’ютери: \n";
    for (int i = 0; i < comps.size(); i++)
    {
        comps[i].showInfo();
    }

    char name[50];
    cout << "Введіть назву комп’ютера: ";
    cin.getline(name, 50);

    auto found = find_if(comps.begin(), comps.end(), [name](Computer& c) {
        return strcmp(c.getName(), name) == 0;
        });

    if (found != comps.end())
    {
        cout << "знайшли:  \n";
        found->showInfo();
    }
    else
    {
        cout << "Помилка\n";
    }


    auto min_it = min_element(comps.begin(), comps.end(), [](Computer& a, Computer& b) {
        return a.getFrequency() < b.getFrequency();
        });

    if (min_it != comps.end()) 
    {
        cout << "Видалено пк з мін частотою:\n";
        min_it->showInfo();
        comps.erase(min_it);
    }


    int dvdCount = count_if(comps.begin(), comps.end(), [](Computer& c) {
        return c.getHasDVD();
        });
    cout << "Комп’ютери з дисководом: " << dvdCount << endl;


    for_each(comps.begin(), comps.end(), [](Computer& c)
        {

        if (c.getRam() > 16)
        {
            float newPrice = c.getPrice() * 1.2;
            c.setPrice(newPrice);
        }
        });


    sort(comps.begin(), comps.end(), [](Computer& a, Computer& b) {
        return a.getPrice() < b.getPrice();
        });

    cout << "\n комп ютери за зростанням ціни: \n";
    for (int i = 0; i < comps.size(); i++)
    {
        comps[i].showInfo();
    }


    sort(comps.begin(), comps.end(), [](Computer& a, Computer& b) {
        return a.getPrice() > b.getPrice();
        });

    cout << "\n комп ютери за спаданням ціни: \n";
    for (int i = 0; i < comps.size(); i++)
    {
        comps[i].showInfo();
    }

    return 0;
}
