#include <iostream>
#include <cstdio>
using namespace std;

int num[4];
int r[4];
bool used[4];

char op[3] = { '+', '-', '*' };

int perf(char o, int a, int b) {
	if (o == '+') return a+b;
	if (o == '-') return a-b;
	/* if (o == '*') */ return a*b;
}

bool eval(int depth) {
	if (depth == 0) {
		for (int i = 0; i < 3*3*3; i++) {
			int j = i;
			char o1 = op[j%3]; j /= 3;
			char o2 = op[j%3]; j /= 3;
			char o3 = op[j];
			if (10 == perf(o1, r[0], perf(o2, r[1], perf(o3, r[2], r[3])))) {
				printf("(%d%c(%d%c(%d%c%d)))\n", r[0], o1, r[1], o2, r[2], o3, r[3]);
				return true;
			}
			if (10 == perf(o1, r[0], perf(o2, perf(o3, r[1], r[2]), r[3]))) {
				printf("(%d%c((%d%c%d)%c%d))\n", r[0], o1, r[1], o3, r[2], o2, r[3]);
				return true;
			}
			if (10 == perf(o1, perf(o2, r[0], r[1]), perf(o3, r[2], r[3]))) {
				printf("((%d%c%d)%c(%d%c%d))\n", r[0], o2, r[1], o1, r[2], o3, r[3]);
				return true;
			}
			if (10 == perf(o1, perf(o2, r[0], perf(o3, r[1], r[2])), r[3])) {
				printf("((%d%c(%d%c%d))%c%d)\n", r[0], o2, r[1], o3, r[2], o1, r[3]);
				return true;
			}
			if (10 == perf(o1, perf(o2, perf(o3, r[0], r[1]), r[2]), r[3])) {
				printf("(((%d%c%d)%c%d)%c%d)\n", r[0], o3, r[1], o2, r[2], o1, r[3]);
				return true;
			}
		}
		return false;
	}

	for (int i = 0; i < 4; i++) {
		if (used[i]) continue;
		r[depth-1] = num[i], used[i] = true;
		if (eval(depth-1)) return true;
		used[i] = false;
	}

	return false;
}

int main() {
	while (cin >> num[0] >> num[1] >> num[2] >> num[3],
			num[0]||num[1]||num[2]||num[3]) {
		used[0] = used[1] = used[2] = used[3] = false;
		if (!eval(4))
			cout << 0 << endl;
	}
	return 0;
}

