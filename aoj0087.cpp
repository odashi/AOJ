#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	stack<double> st;
	while (getline(cin, s)) {
		int tail;
		while (1) {
			tail = s.find(' ');
			string ss = s.substr(0, tail);
			int val = atoi(ss.c_str());
			if (val != 0 || ss[0] == '0')
				st.push((double)val);
			else {
				double b = st.top(); st.pop();
				double a = st.top(); st.pop();
				switch (ss[0]) {
					case '+': st.push(a+b); break;
					case '-': st.push(a-b); break;
					case '*': st.push(a*b); break;
					case '/': st.push(a/b); break;
				}
			}

			if (tail == string::npos)
				break;
			s = s.substr(tail+1);
		}

		printf("%.6f\n", st.top());
		while (!st.empty())
			st.pop();
	}
	return 0;
}

