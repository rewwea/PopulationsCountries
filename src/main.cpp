#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
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
		double total_population{ 0 };
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
		alphabet_out << "Стран с населением более 100 млн: " << big_countries << endl;
		alphabet_out.close();
	}
}