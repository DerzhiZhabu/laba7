#include <iostream>
#include <vector>

using namespace std;

bool recurs(int a, vector<int> chisla, const int& s) {
	if (chisla.size() == 0) {
		return (a == s);
	}
	for (size_t i = 0; i < chisla.size(); i++) {
		vector<int> oleg = {};
		bool deleted = false;
		for (size_t j = 0; j < chisla.size(); j++){
			if (chisla[j] != chisla[i] || deleted) {
				oleg.push_back(chisla[j]);
			}
			else deleted = true;
		}

		if (recurs(a + chisla[i], oleg, s)) {
			cout << chisla[i] << " + " ;
			return true; 
		}
		else if (recurs(a * chisla[i], oleg, s)) {
			cout << chisla[i] << " * ";
			return true;
		}
	}
	return false;
}

bool start(vector<int> chisla, const int& s) {
	for (size_t i = 0; i < chisla.size(); i++) {
		vector<int> oleg = {};
		bool deleted = false;
		for (size_t j = 0; j < chisla.size(); j++) {
			if (chisla[j] != chisla[i] || deleted) {
				oleg.push_back(chisla[j]);
			}
			else deleted = true;
		}

		if (recurs(chisla[i], oleg, s)) {
			cout << chisla[i];
			return true;
		}
	}
	return false;
}

int main() {
	int s;
	int n = 4;

	vector<int> chisla = { 89, 65, 56, 43 };

	cin >> s;

	cout << endl << start(chisla, s);
}