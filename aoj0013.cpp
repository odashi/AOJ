#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st;
	int n;
	while (cin >> n) {
		if (n != 0)
			st.push(n);
		else {
			cout << st.top() << endl;
			st.pop();
		}
	}
	return 0;
}
