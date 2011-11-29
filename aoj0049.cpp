#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int num[4] = { 0, 0, 0, 0 };
	while (cin >> s) {
		s = s.substr(s.find(',')+1);
		if (s == "A") num[0]++;
		else if (s == "B") num[1]++;
		else if (s == "AB") num[2]++;
		else num[3]++;
	}
	cout << num[0] << endl;
	cout << num[1] << endl;
	cout << num[2] << endl;
	cout << num[3] << endl;
	return 0;
}

