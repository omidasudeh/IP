#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, string> a;
	map<int, string>::iterator it;
	a[0] = "This ";
	a[1] = "is";
	a[2] = "funny!\n";
	it = a.find(1);
	if (it != a.end()) {
		cout << it->second << "\n";
	}
	else cout << "1 doesn't exist\n";
	a.erase(it);
	it = a.find(1);
	if (it == a.end()) cout << "1 has been erased!\n";
	a.insert(pair<int, string>(1, "is"));
	it = a.find(1);
	if (it != a.end()) cout << "1 has been inserted back\n";
	return 0;
}
