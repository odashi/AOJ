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

int table[10000];

int main() {
	int k = 0;
	table[0] = 2;
	for (int i = 3, k = 1; k < 10000; i++) {
		if (isprime(i)) {
			table[k] = table[k-1] + i;
			k++;
		}
	}

	int n;
	while (cin >> n, n)
		cout << table[n-1] << endl;

	return 0;
}

