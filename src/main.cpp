#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fl("population.txt");
    vector <string> countries;
    string s;
    if (fl.is_open())
    {
        while (getline(fl, s))
        {
            countries.push_back(s);
        }
    }
    else
    {
        cout << "Error" << endl;
    }
    for (auto v: countries)
    {
        cout << v << endl;
    }
}