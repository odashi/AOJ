#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<double> tall;
	double t;
	while (cin >> t) {
		tall.push_back(t);
	}
	sort(tall.begin(), tall.end());
	cout << (tall[tall.size()-1] - tall[0]) << endl;
	return 0;
}

