#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

/* int main()
{
  ifstream f1("Population.txt");
  vector<string> country;
  string s;

  if (f1.is_open())
  {
    while (getline(f1, s))
    {
      country.push_back(s);
    }
  }
  f1.close();

  for (int i = 65; i < 91; i++)
  {
    ofstream alphabet("Country/" + string(1, char(i)) + ".txt", ios::app);
    for (auto v : country)
    {
      if (v[0] == char(i))
      {
        alphabet << v << endl;
      }
    }
  }

  for (int i = 65; i < 91; i++)
  {
    long long total_population{ 0 };
    int count = 0, big_countries = 0;
    string strana;
    ifstream alphabet_in("Country/" + string(1, char(i)) + ".txt");

    while (alphabet_in >> strana)
    {
      if (strana[0] >= '0' && strana[0] <= '9')
      {
        count++;
        double population = stod(strana);
        total_population += population;
        if (population > 100000000)
        {
          big_countries++;
        }
      }
    }
    alphabet_in.close();

    ofstream alphabet_out("Country/" + string(1, char(i)) + ".txt", ios::app);
    alphabet_out << "\nОбщее население: " << total_population << endl;
    alphabet_out << "Количество стран: " << count << endl;
    alphabet_out << "Среднее население: " << (count ? total_population / count : 0) << endl;
    alphabet_out << "Стран с населением более 100 млн: " << big_countries;
    alphabet_out.close();
  }
}*/

int main() {
    string dir_path = "Country";

    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        cerr << "Ошибка: папка 'Country' не найдена!" << endl;
        return 1;
    }

    cout << "Файлы с более чем 15 странами:\n";
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        if (fs::is_regular_file(entry)) {
            int country_count = 0;
            double total_population = 0;
            ifstream file(entry.path());
            string line;

            while (getline(file, line)) {
                if (line.find("Общее население") != string::npos) {
                    total_population = stod(line.substr(line.find(":") + 1));
                    break;
                }
                country_count++;
            }
            file.close();

            if (country_count > 15) {
                cout << entry.path().filename().string() << " - " << country_count << " стран\n";
            }

            if (total_population > 500000000) {
                cout << "⚠ " << entry.path().filename().string() << " - население " << total_population << "\n";
            }
        }
    }
    return 0;
}
