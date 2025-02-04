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
    double population = 0;
    if (fl.is_open())
    {
        while (fl >> s)
        {
            if ((int(s[0]) > 57) and (int(s[0])> 47))
            {
                countries.push_back(s);
            }
            else
            {
                population += stoi(s);
            }
        }
    }
    cout << population << endl;
}