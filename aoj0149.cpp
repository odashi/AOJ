#include <iostream>
using namespace std;

int abl_l[4] = {0, 0, 0, 0};
int abl_r[4] = {0, 0, 0, 0};

int ability(double f) {
	if (f >= 1.1) return 0;
	if (f >= 0.6) return 1;
	if (f >= 0.2) return 2;
	return 3;
}

int main() {
	double l, r;
	while (cin >> l >> r) {
		abl_l[ability(l)]++;
		abl_r[ability(r)]++;
	}
	for (int i = 0; i < 4; i++)
		cout << abl_l[i] << " " << abl_r[i] << endl;
	return 0;
}

