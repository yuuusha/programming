#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>
#include <list>

using namespace std;

void print(list<int> a) {
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
}

int main() {

	srand(time(NULL));
	list<int> num;

	for (int i = 0; i < 20; i++) {
		int n = rand() % 100;
		num.push_back(n);
	}
	print(num);

	int k;
	cin >> k;
	auto it = num.begin();
	for (int i = 1; i < k; i++) {
		it++;
	}
	
	list<int> newnum(num.size());
	auto it1 = copy(it, num.end(), newnum.begin());
	copy(num.begin(), it, it1);
	print(newnum);

}