#include <iostream>
#include <bits/stdc++.h>

//tablica, max 30
//funcja wczytujaca z pliku
//funkcja sortujaca po nazwisko alfabetycznie
//zapisuje do pliku
using namespace std;

struct person
{
    string name, surname;
    int nr;
};

void load_file(string filename, vector<person>& data)
{
    ifstream file;
    file.open(filename);
    string name, surname;
    int nr;
    while(file >> name >> surname >> nr)
    {
        struct person p;
        p.name = name;
        p.surname = surname;
        p.nr = nr;
        data.push_back(p);
    }
    file.close();
}

void save_file(string filename, vector<person>& data)
{
    ofstream file;
    file.open(filename);
    for (auto i: data)
    {
        file << i.name << " " << i.surname << " " << i.nr << endl;
    }
    file.close();
}

void sort_list(vector<person>& data)
{
    sort(data.begin(), data.end(), [](const person& a, const person& b) {
        return a.surname < b.surname;
    });
}

int main()
{
    vector<person> data;
    load_file("input.txt", data);
    sort_list(data);
    save_file("output.txt", data);
    for (auto i: data)
    {
        cout << i.name << " " << i.surname << " " << i.nr << endl;
    }
    return 0;
}
