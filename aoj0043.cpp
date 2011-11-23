#include <iostream>
using namespace std;

int num[9];

bool eval(int depth, bool two) {
	if (depth == 0) return true;

	int n = 0;
	while (num[n] == 0) n++;

	if (num[n] >= 2 && !two) {
		num[n] -= 2;
		bool p = eval(depth-1, true);
		num[n] += 2;
		if (p) return true;
	}

	if (num[n] >= 3) {
		num[n] -= 3;
		bool p = eval(depth-1, two);
		num[n] += 3;
		if (p) return true;
	}

	if (n > 7) return false;
	if (num[n+1] < num[n] || num[n+2] < num[n]) return false;
	int k = num[n];
	num[n] -= k, num[n+1] -= k, num[n+2] -= k;
	bool p = eval(depth-k, two);
	num[n] += k, num[n+1] += k, num[n+2] += k;
	return p;
}

int main() {
	char s[13+1];
	while (cin >> s) {
		for (int i = 0; i < 9; i++) num[i] = 0;
		for (int i = 0; i < 13; i++) num[s[i]-'1']++;

		bool first = true;
		for (int i = 0; i < 9; i++) {
			if (num[i] == 4) continue;
			num[i]++;
			if (eval(5, false)) {
				if (first) cout << (i+1), first = false;
				else cout << " " << (i+1);
			}
			num[i]--;
		}

		if (first) cout << 0;
		cout << endl;
	}
	return 0;
}

