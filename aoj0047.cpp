#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ball[3] = { true, false, false };
	string s;
	while (cin >> s) {
		int x = s[0]-'A', y = s[2]-'A';
		int temp = ball[x];
		ball[x] = ball[y];
		ball[y] = temp;
	}
	cout << (ball[0] ? 'A' : ball[1] ? 'B' : 'C') << endl;
	return 0;
}

