#include <iostream>
using namespace std;

int main() {
	int a[4],b[4];
	while (cin >> a[0]>>a[1]>>a[2]>>a[3] >> b[0]>>b[1]>>b[2]>>b[3]) {
		int hit = 0;
		int blow = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (b[i] == a[j]) {
					if (i == j) hit++;
					else blow++;
				}
			}
		}
		cout << hit << ' ' << blow << endl;
	}
	return 0;
}

