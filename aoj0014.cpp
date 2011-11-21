#include <iostream>

using namespace std;

int main() {
	int d;
	while (cin >> d) {
		int area = 0;
		for (int x = 0; x < 600; x+=d) {
			area += d*x*x;
		}
		cout << area << endl;
	}
	return 0;
}
