#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(void) {
	char s[21];
	cin >> s;
	reverse(s, s+strlen(s));
	cout << s << endl;
	return 0;
}
