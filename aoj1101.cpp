#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string text,in,dum;
int cur,len;

int main()
{
	int CS, n;
	cin >> CS; getline(cin, dum);
	for (int cs = 0; cs < CS; cs++) {
		getline(cin,text);
		cin >> n; getline(cin, dum);
		len = text.size();
		cur = 0;
		for (int i = 0; i < n; i++) {
			getline(cin, in);
			if (in == "forward char")
				cur = min(cur+1,len);
			else if (in == "backward char")
				cur = max(cur-1,0);
			else if (in == "forward word") {
				while (cur < len && text[cur] == ' ') cur++;
				while (cur < len && text[cur] != ' ') cur++;
			} else if (in == "backward word") {
				while (cur > 0 && text[cur-1] == ' ') cur--;
				while (cur > 0 && text[cur-1] != ' ') cur--;
			} else if (in == "delete char") {
				if (cur >= len) continue;
				text.erase(text.begin()+cur);
				len--;
			} else if (in.find("insert") != in.npos) {
				int s = in.find('"'), t = in.find('"',s+1);
				int l = t-s-1;
				text = text.substr(0,cur) + in.substr(s+1,l) + text.substr(cur);
				cur += l;
				len += l;
			} else if (in == "delete word") {
				int s = cur, t;
				while (text[s] == ' ') s++;
				if (s >= len) continue;
				while (text[s] != ' ' && s < len) s++;
				text = text.substr(0,cur) + text.substr(s);
				len -= s-cur;
			}
		}
		cout << text.substr(0,cur) << "^" << text.substr(cur) << endl;
	}
	return 0;
}

