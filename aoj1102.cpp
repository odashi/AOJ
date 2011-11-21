#include <iostream>
#include <string>
using namespace std;

// 注意点：
// 1. 単項+/-演算子が登場する
// 2. intのサイズを超える数字も入力される

struct complex {
	int re;
	int im;
	bool overflow;
};

bool check(complex &z) {
	return (z.re > 10000 || z.re < -10000 || z.im > 10000 || z.im < -10000);
}

complex operate(const complex &a, const complex &b, char o) {
	complex c;
	if (o == '+') {
		c.re = a.re + b.re;
		c.im = a.im + b.im;
	} else if (o == '-') {
		c.re = a.re - b.re;
		c.im = a.im - b.im;
	} else /* if (0 == '*') */ {
		c.re = a.re*b.re - a.im*b.im;
		c.im = a.re*b.im + a.im*b.re;
	}
	c.overflow = a.overflow || b.overflow ? true : check(c);
	return c;
}

complex expr(string&);
complex term(string&);
complex fctr(string&);

complex expr(string &s) {
	complex a = term(s);
	while (s[0] == '+' || s[0] == '-') {
		char o = s[0];
		s.erase(0, 1);
		complex b = term(s);
		a = operate(a, b, o);
	}
	return a;
}

complex term(string &s) {
	complex a = fctr(s);
	while (s[0] == '*') {
		s.erase(0, 1);
		complex b = fctr(s);
		a = operate(a, b, '*');
	}
	return a;
}

complex fctr(string &s) {
	complex z = {0, 0, false};
	if (s[0] == '(') {
		s.erase(0, 1);
		z = expr(s);
		s.erase(0, 1);
		return z;
	}

	int sign = 1;
	if (s[0] == '+')
		s.erase(0, 1);
	else if (s[0] == '-') {
		s.erase(0, 1);
		sign = -1;
	}

	if (s[0] == 'i') {
		s.erase(0, 1);
		z.im = sign;
		return z;
	}
	
	int i = 0;
	while (s[i] >= '0' && s[i] <= '9') {
		z.re = z.re * 10 + s[i] - '0';
		i++;
		if (z.re > 10000) z.overflow = true;
	}
	z.re *= sign;
	s.erase(0, i);
	return z;
}

void print(const complex &z) {
	if (z.im == 0)
		cout << z.re << endl;
	else if (z.re == 0)
		cout << z.im << "i" << endl;
	else {
		cout << z.re;
		if (z.im > 0)
			cout << "+";
		cout << z.im << "i" << endl;
	}
}

int main() {
	string s;
	while (cin >> s) {
		complex z = expr(s);
		if (z.overflow)
			cout << "overflow" << endl;
		else
			print(z);
	}
	return 0;
}

