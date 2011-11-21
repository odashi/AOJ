#include <iostream>

using namespace std;

int tri(int a, int b, int c) {
	if (a > b && a > c)
		return (b*b+c*c == a*a);
	if (b > c)
		return (a*a+c*c == b*b);
	return (a*a+b*b == c*c);
}

int main(void) {
	int n;
	int a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		cout << (tri(a,b,c) ? "YES" : "NO") << endl;
	}
	return 0;
}
