#include <iostream>
#include <string>
using namespace std;

char rtable[26];

string affine(const string &s, int a, int b) {
	string ret = s;
	for (int i = 0; i < ret.size(); i++)
		ret[i] = ((ret[i]-'a')*a + b) % 26 + 'a';
	return ret;
}

void setrtable(int a, int b) {
	for (int x = 0; x < 26; x++) {
		int y = (x*a + b) % 26;
		rtable[y] = (char)(x + 'a');
	}
}

int main() {
	int n; cin >> n;
	string s;
	getline(cin, s); // dummy
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int aa, bb;
		bool found = false;
		for (int a = 1; a < 26 && !found; a += 2) {
			if (a == 13) continue;
			for (int b = 0; b < 26; b++) {
				string a1 = affine("this", a, b);
				string a2 = affine("that", a, b);
				if (s.find(a1) != string::npos || s.find(a2) != string::npos) {
					aa = a, bb = b;
					found = true;
					break;
				}
			}
		}
		setrtable(aa, bb);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= 'a' && s[j] <= 'z')
				cout << rtable[s[j] - 'a'];
			else
				cout << s[j];
		}
		cout << endl;
	}
	return 0;
}

