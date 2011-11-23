#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n) {
	if (n==2 || n==3) return true;
	if (!(n%2)) return false;
	if (!(n%3)) return false;
	int lim = (int)sqrt((double)n) + 1;
	for (int i = 6; i <= lim; i += 6) {
		if (!(n%(i-1))) return false;
		if (!(n%(i+1))) return false;
	}
	return true;
}

int main() {
	int n;
	while (cin >> n) {
		int k;
		for (k = n-1; !isprime(k); k--);
		cout << k;
		for (k = n+1; !isprime(k); k++);
		cout << " " << k << endl;
	}
	return 0;
}

