#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string encode(string &s) {
	int i = 0;
	char ss[10];
	string ret = "";
	while (i < s.size()) {
		char c = s[i];
		int end = i;
		while (end < s.size() && s[end] == c) end++;
		sprintf(ss, "%d%c", end-i, c);
		ret += ss;
		i = end;
	}
	return ret;
}

int main() {
	int n;
	string s;
	while (cin >> n, n) {
		cin >> s;
		for (int i = 0; i < n; i++)
			s = encode(s);
		cout << s << endl;
	}
	return 0;
}

