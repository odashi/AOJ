#include <iostream>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double ax,ay,ar,bx,by,br;
		cin >> ax >> ay >> ar >> bx >> by >> br;
		double dd = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
		double rsum = (ar+br)*(ar+br);
		double rdiff = (ar-br)*(ar-br);
		if (dd > rsum)
			cout << 0 << endl;
		else if (dd < rsum && dd > rdiff)
			cout << 1 << endl;
		else if (dd < rdiff)
			cout << (ar > br ? 2 : -2) << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}

