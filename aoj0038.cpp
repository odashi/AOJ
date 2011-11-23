#include <iostream>
#include <cstdio>
using namespace std;

int hist[14+1];
int group[4+1];
int cont;

bool fourofakind() { return group[4] == 1; }
bool fullhouse() { return (group[2] == 1 && group[3] == 1); }
bool straight() { return cont == 5; }
bool threeofakind() { return group[3] == 1; }
bool twopair() { return group[2] == 2; }
bool onepair() { return group[2] == 1; }

int main() {
	int k;
	while (scanf("%d", &k) == 1) {
		for (int i = 1; i <= 14; i++) hist[i] = 0;
		for (int i = 0; i <= 4; i++) group[i] = 0;
		cont = 0;
		for (int i = 0; i < 5; i++, scanf(",%d", &k)) {
			hist[k]++;
			if (k == 1) hist[14]++;
		}
		for (int i = 1; i <= 13; i++)
			group[hist[i]]++;
		int c = 0;
		for (int i = 1; i <= 14; i++) {
			if (hist[i] == 1) {
				c++;
				if (c > cont) cont = c;
			} else
				c = 0;
		}

		if (fourofakind()) cout << "four card";
		else if (fullhouse()) cout << "full house";
		else if (straight()) cout << "straight";
		else if (threeofakind()) cout << "three card";
		else if (twopair()) cout << "two pair";
		else if (onepair()) cout << "one pair";
		else cout << "null";
		cout << endl;
	}
	return 0;
}

