#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void add(string &a, string &b) {
	if (a.size() > 80 || b.size() > 80) {
		cout << "overflow" << endl;
		return;
	}

	string aa = a;
	string bb = b;
	reverse(aa.begin(), aa.end());
	reverse(bb.begin(), bb.end());
	string cc;
	int carry = 0;
	int sa = a.size();
	int sb = b.size();
	int ss = sa>sb ? sa : sb;
	for (int i = 0; i < ss; i++) {
		char ca = i < sa ? aa[i] : '0';
		char cb = i < sb ? bb[i] : '0';
		char code = ca + cb + carry - '0';
		if (code > '9') {
			code -= 10;
			carry = 1;
		} else
			carry = 0;
		cc += code;
	}

	if (carry)
		cc += '1';

	if (cc.size() > 80)
		cout << "overflow" << endl;
	else {
		reverse(cc.begin(), cc.end());
		cout << cc << endl;
	}
}

int main() {
	int n;
	string a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		add(a, b);
	}
	return 0;
}

