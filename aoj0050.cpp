#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; getline(cin, s);
	int pos1, pos2;
	int begin = 0;
	while (1) {
		pos1 = s.find("peach", begin);
		pos2 = s.find("apple", begin);
		if (pos1 == string::npos && pos2 == string::npos)
			break;
		else if (pos2 == string::npos)
			s.replace(pos1, 5, "apple"), begin = pos1+1;
		else if (pos1 == string::npos)
			s.replace(pos2, 5, "peach"), begin = pos2+1;
		else if (pos1 < pos2)
			s.replace(pos1, 5, "apple"), begin = pos1+1;
		else
			s.replace(pos2, 5, "peach"), begin = pos2+1;
	}
	cout << s << endl;
	return 0;
}

