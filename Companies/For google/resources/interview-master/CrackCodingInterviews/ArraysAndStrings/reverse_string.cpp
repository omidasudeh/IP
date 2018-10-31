#include <iostream>
#include <string>

using namespace std;

string reverse(string s) {
	string r = "";
	for (int i = s.length() - 1; i >= 0; --i) {
		r += s[i];
	}
	return r;
}

int main() {
	string s = "";
	cout << "Please enter the string:\n";
	cin >> s;
	s = reverse(s);
	cout << "After reverse, the string is:\n";
	cout << s << endl;
	return 0;
}
