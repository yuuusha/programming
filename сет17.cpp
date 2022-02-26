#include <iostream>
#include <set>
#include <string>

using namespace std;

void show(set<int> a) {
	for (auto x : a)
		cout << x << ' ';
	cout << endl << endl;
}

void insert(set<int> &a, int n) {
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.insert(num);
	}
}

int main() {

	int n;
	set<int> mass;

	cin >> n;

	insert(mass, n);
	show(mass);
	
	for (auto it = mass.begin(); it != --mass.end(); it++) {

		auto it2 = it;
		it2++;

		string s = to_string(*it);
		string s2 = to_string(*it2);
		string ans = "";

		for (int i = 0; i < s.size(); i++)
			if (s2.find(s[i]) == string::npos)
				ans.insert(ans.size(), 1, s[i]);

		(ans != "") ? (cout << ans << endl) : (cout << "none" << endl);

	}

}