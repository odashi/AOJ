#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int b[10];
		int left = 0, right = 0;
		bool avail = true;
		for (int j = 0; j < 10; j++)
			cin >> b[j];
		for (int j = 0; j < 10; j++) {
			if (b[j] > left) left = b[j];
			else if (b[j] > right) right = b[j];
			else avail = false;
		}
		cout << (avail ? "YES" : "NO") << endl;
	}
	return 0;
}

