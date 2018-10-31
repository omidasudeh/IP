// bit vector method
// suppose the string only contain the letters from "a" to "z", so a 26-bit vector is enough

#include <iostream>
#include <string>

using namespace std;

bool unique_char(string s) {
	int bv = 0;
	int one = 1;
	for (int i = 0; i < s.length(); ++i) {
		if (bv & (one << (s[i] - 'a'))) {
			return false;
		}
		bv |= (one << (s[i] - 'a'));
	}
	return true;
}

int main() {
	string s = "";
	cout << "Please enter the string:\n";
	cin >> s;
	if(unique_char(s)) cout << "the string " << s << " has all unique characters" << endl;
	else cout << "the string " << s << " doesn't have all unique characters\n";
	return 0;
}
