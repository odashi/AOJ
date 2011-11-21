#include <iostream>

using namespace std;

int main() {
	double v;
	while (cin >> v) {
		v *= v;
		int n;
		for (n = 1; 19.6*(5*n-5) < v; n++);
		cout << n << endl;
	}
}

