#include <iostream>
#include <cstdio>
using namespace std;

int sum[1000+1];
int temp[1000+1];
int size;

void update(int score, int weight) {
	for (int i = weight; i <= size; i++) {
		int a = sum[i-weight] + score;
		temp[i] = a > sum[i] ? a : sum[i];
	}
	for (int i = weight; i <= size; i++)
		sum[i] = temp[i];
}

int main() {
	int k = 0, n;
	while (cin >> size, size) {
		k++;
		cin >> n;
		for (int i = 0; i <= size; i++)
			sum[i] = temp[i] = 0;
		
		for (int i = 0; i < n; i++) {
			int a, b; scanf("%d,%d", &a, &b);
			update(a, b);
		}

		int w = size;
		while (w > 0 && sum[w-1] == sum[size]) w--;
		cout << "Case " << k << ":" << endl;
		cout << sum[size] << endl;
		cout << w << endl;
	}
	return 0;
}

