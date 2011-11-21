#include <iostream>
using namespace std;

char pos[15+1];

int step(int n) {
	if (n == 0) return 0;
	return 3*step(n-1) + 1;
}

int step2(char dest, int n) {
	if (n == 0) return 0;
	if (dest == 'A') {
		if (pos[n] == 'A') return step2('A', n-1);
		if (pos[n] == 'B') return step2('C', n-1) + 1 + 2*step(n-1);
		return step2('A', n-1) + 2 + 4*step(n-1);
	} else /* if (dest == 'C') */ {
		if (pos[n] == 'C') return step2('C', n-1);
		if (pos[n] == 'B') return step2('A', n-1) + 1 + 2*step(n-1);
		return step2('C', n-1) + 2 + 4*step(n-1);
	}
}

int main() {
	int n, m;
	while (cin >> n >> m, n||m) {
		for (int i = 0; i < 3; i++) {
			int k; cin >> k;
			for (int j = 0; j < k; j++) {
				int l; cin >> l;
				pos[n-l+1] = 'A' + i;
			}
		}
		int a = step2('A', n);
		int b = step2('C', n);
		a = a<b ? a : b;
		cout << (a<=m ? a : -1) << endl;
	}
	return 0;
}

