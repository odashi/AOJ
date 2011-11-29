#include <iostream>
#include <algorithm>
using namespace std;

int tonum(char *s) {
	int ret = 0;
	for (int i = 0; i < 8; i++)
		ret = ret*10 + s[i] - '0';
	return ret;
}

int main() {
	int n; cin >> n;
	char s[9];
	for (int i = 0; i < n; i++) {
		cin >> s;
		sort(s, s+8);
		int a = tonum(s);
		sort(s, s+8, greater<char>());
		int b = tonum(s);
		cout << (b-a) << endl;
	}
	return 0;
}

