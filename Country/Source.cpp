#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	multimap<string, string> city;

	multimap<string, string> country;

	multimap<string, string> c_c;

	copy(begin(city), end(city), c_c);



	ifstream is("city.csv");

	string s;
	string id_c, city1, country1;
	while (!is.eof()) {
		getline(is, s);
		id_c = s.substr(0, s.find(';'));
		s = s.substr(s.find(';') + 1);
		city1 = s;
		//cout << id_c <<"	"<<city1<< endl;
		city.emplace(city1, id_c);
		//city.insert(pair<string,string>(city,id_c));
	}
	is.close();

	is.open("country.csv");

	while (!is.eof()) {
		getline(is, s);
		id_c = s.substr(0, s.find(';'));
		s = s.substr(s.find(';') + 1);
		country1 = s;
		//cout << id_c <<"	"<< country1 << endl;
		country.emplace(id_c, country1);
	}
	is.close();

	cout << "Введите название города ";
	getline(cin, city1);

	auto it = city.find(city1);

	cout << endl;
	cout << "Страна ";

	auto it1 = country.find(it->second);
	cout << it1->second << endl;


	system("pause");

}