#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		bool first = true;
		for (int i = 0; i < 10; i++) {
			if (n & (1<<i)) {
				if (first)
					first = false;
				else
					cout << " ";
				cout << (1<<i);
			}
		}
		cout << endl;
	}
	return 0;
}

