#include <iostream>
#include <vector>

using namespace std;


bool recurs(int& check, vector<int> nomer, const int& k, string&result) {
	if (nomer.size() == 0) check++;
	if (check == k) return true;
	for (size_t i = 0; i < nomer.size(); i++) {
		vector<int> oleg = {};
		bool deleted = false;
		for (size_t j = 0; j < nomer.size(); j++) {
			if (nomer[j] != nomer[i] || deleted) {
				oleg.push_back(nomer[j]);
			}
			else deleted = true;
		}
		if (recurs(check, oleg, k, result)) {
			char k = nomer[i] + '0';
			result.push_back(k);
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	int k;
	int check = 0;

	string result;

	cin >> n;
	cin >> k;

	vector<int> nomer;
	for (int i = 1; i <= n; i++) {
		nomer.push_back(i);
	}

	recurs(check, nomer, k, result);
	for (int i = n - 1; i >= 0; i--) cout << result[i];
}