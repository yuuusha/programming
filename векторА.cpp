#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

class candy {

public:
	string name, type, comp;
	int mass, count;

};

int main() {

	ifstream in("input1.txt");

	int n, i = 0;
	vector <candy> bag1(10);

	while (!in.eof()) {
		in >> bag1[i].name >> bag1[i].type >> bag1[i].comp >> bag1[i].mass >> bag1[i].count;
		i++;
	}

	for (int i = 0; i < 5; i++) {
		cout << bag1[i].name << ' ' << bag1[i].type << ' ' << bag1[i].comp << ' ' << bag1[i].mass << ' ' << bag1[i].count;
		cout << endl;
	}
	cout << endl;



	for (int i = 0; i < 3; i++) {
		cin >> bag1[i].name >> bag1[i].type >> bag1[i].comp >> bag1[i].mass >> bag1[i].count;
	}
	for (int i = 0; i < 5; i++) {
		if (bag1[i].type == "chocolate")
			bag1[i].count *= 2;
	}
	cout << endl;


	for (int i = 0; i < 5; i++) {
		cout << bag1[i].name << ' ' << bag1[i].type << ' ' << bag1[i].comp << ' ' << bag1[i].mass << ' ' << bag1[i].count;
		cout << endl;
	}

}

/*

ввод

Fruitella marmalade strawberry 65 4
Montpensier lollipop mint 45 5
Haribo marmalade apple 55 5
Alenka chocolate nuts 50 1
Milka chocolate strawberry 60 1

Marshmallow marmalade apple 55 5
M&Ms chocolate nuts 50 2
Licorice lollipop mint 45 5

вывод

Marshmallow marmalade apple 55 5
M&Ms chocolate nuts 50 4
Licorice lollipop mint 45 5
Alenka chocolate nuts 50 2
Milka chocolate strawberry 60 2

*/