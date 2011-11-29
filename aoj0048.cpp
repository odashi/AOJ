#include <iostream>
using namespace std;

int main() {
	double w;
	while (cin >> w) {
		if (w <= 48.0) cout << "light fly";
		else if (w <= 51.0) cout << "fly";
		else if (w <= 54.0) cout << "bantam";
		else if (w <= 57.0) cout << "feather";
		else if (w <= 60.0) cout << "light";
		else if (w <= 64.0) cout << "light welter";
		else if (w <= 69.0) cout << "welter";
		else if (w <= 75.0) cout << "light middle";
		else if (w <= 81.0) cout << "middle";
		else if (w <= 91.0) cout << "light heavy";
		else cout << "heavy";
		cout << endl;
	}
	return 0;
}

