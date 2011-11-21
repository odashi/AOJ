#include <iostream>

using namespace std;

int main(void) {
	int week;
	int n = 100000;
	cin >> week;
	for (int i = 0; i < week; i++) {
		n = n*105/100;
		if (n%1000)
			n = (n/1000+1)*1000;
	}
	cout << n << endl;
	return 0;
}
