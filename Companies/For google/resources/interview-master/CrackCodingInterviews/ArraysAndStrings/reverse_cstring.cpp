#include <iostream>

using namespace std;

void reverse(char *str) {
	char *end = str;
	while (*end) ++end;
	--end;
	while (str < end) {
		char tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}
}

int main() {
	char str[100];
	cout << "please enter str:\n";
	cin >> str;
	reverse(str);
	cout << "after reverse, the str is:\n";
	cout << str << endl;
	return 0;
}
