#include <iostream>
#include <string>
using namespace std;

int num(char c) {
	switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
	return 0;
}

int main() {
	string s;
	while (cin >> s) {
		int n = 0;
		for (int i = 0; i < s.size(); i++) {
			int a = num(s[i]);
			int b = i+1 < s.size() ? num(s[i+1]) : 0;
			if (a >= b)
				n += a;
			else
				n += b-a, i++;
		}
		cout << n << endl;
	}
	return 0;
}

