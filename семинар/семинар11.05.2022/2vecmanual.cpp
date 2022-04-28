#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

void eratosp(vector<int> &a) {
	int n = a.size();
	for (int i = 2; i < n; i++)
		a[i] = i;
	for (int i = 2; i * i < n; i++) 
		for (int p = i * i; p < n; p += i)
			a[p] = 0;
}

void print(vector<int> a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	
	srand(time(NULL));
	vector<int> num;
	
	for (int i = 0; i < 20; i++) {
		int n = rand() % 100;
		num.push_back(n);
	}
	print(num);

	int mx = *max_element(num.begin(), num.end());
	vector<int> era(mx + 1);
	eratosp(era);
	
	int k = 0;
	for (int i = 0; i < num.size(); i++) {
		if (find(era.begin(), era.end(), num[i]) != era.end() && num[i] != 0) {
			swap(num[i], num[k]);
			k++;
		}
	}
	print(num);

}