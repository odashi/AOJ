#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int dist(int a, int b) {
	int d = b-a;
	if (d >= 26)
		return d-26;
	if (d < 0)
		return d+26;
	return d;
}

int main() {
	char s[81];
	while (cin.getline(s, 81)) {
		int len = strlen(s);
		int shift;
		for (int i = 0; i <= len-4; i++) {
			if (dist(s[i],s[i+1]) != dist('t','h'))
				continue;
			if (
					(dist(s[i+1], s[i+2]) == dist('h','a') && dist(s[i+2],s[i+3]) == dist('a','t')) ||
					(dist(s[i+1], s[i+2]) == dist('h','i') && dist(s[i+2],s[i+3]) == dist('i','s')) ||
					dist(s[i+1], s[i+2]) == dist('h','e'))
				shift = dist(s[i],'t');
		}
		if (
				dist(s[len-3],s[len-2]) == dist('t','h') &&
				dist(s[len-2],s[len-1]) == dist('h','e'))
			shift = dist(s[len-3], 't');
		for (int i = 0; i < len; i++) {
			if (isalpha(s[i]))
				s[i] = (s[i]-'a'+shift)%26+'a';
		}
		cout << s << endl;
	}
	return 0;
}

