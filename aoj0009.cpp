#include <iostream>

int table[1000000];

using namespace std;

void init() {
	for (int i = 0; i < 1000000; i++)
		table[i] = 0;
	for (int i = 2; i < 1000000; i++) {
		if (table[i] != -1) {
			table[i] = table[i-1]+1;
			for (int j = i+i; j < 1000000; j+=i)
				table[j] = -1;
		} else {
			table[i] = table[i-1];
		}
	}
}

int main(void) {
	int n;
	init();
	while (cin >> n) {
		cout << table[n] << endl;
	}
	return 0;
}
