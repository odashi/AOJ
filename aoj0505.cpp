#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int,int> P;

bool comp(const P& a, const P& b) {
	if (a.first != b.first) return (a.first > b.first);
	return (a.second < b.second);
}

int main() {
	P place[100];
	int n, m;
	while (cin >> n >> m, n||m) {
		for (int i = 0; i < m; i++) {
			place[i].first = 0;
			place[i].second = i+1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int k; cin >> k;
				place[j].first += k;
			}
		}
		
		sort(place, place+m, comp);
		
		cout << place[0].second;
		for (int i = 1; i < m; i++)
			cout << " " << place[i].second;
		cout << endl;
	}
	return 0;
}

