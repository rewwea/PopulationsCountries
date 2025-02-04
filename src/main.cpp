#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    fstream fl("population.txt");
    vector<string> countries;
    string s, state;
    
    cout << "Введите страну: ";
    cin >> state;

    while (getline(fl, s)) countries.push_back(s);
    fl.close();

    int place = 0;
    double userPopulation = 0;
    
    for (auto v : countries) {
        if (v.find(state) != string::npos) {
            userPopulation = stod(v.substr(v.find_last_of(' ') + 1));
            break;
        }
        place++;
    }

    ofstream ur(state + ".txt");
    for (int i = place + 1; i < countries.size(); i++) {
        double pop = stod(countries[i].substr(countries[i].find_last_of(' ') + 1));
        if (pop < userPopulation) ur << countries[i] << endl;
    }

    return 0;
}