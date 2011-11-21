#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> tall;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		tall.push_back(x);
	}
	sort(tall.begin(), tall.end(), greater<int>());
	for (int i = 0; i < 3; i++)
		cout << tall[i] << endl;
	return 0;
}
