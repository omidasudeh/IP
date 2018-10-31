#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> merge(unordered_map<string, string> a, unordered_map<string, string> b) {
	unordered_map<string, string> c = a;
	c.insert(b.begin(), b.end());
	return c;
}

int main() {
	unordered_map<string, string> strmap({{"apple", "red"}, {"orange", "orange"}});
	unordered_map<string, string> first;
	unordered_map<string, string> second(strmap.begin(), strmap.end());
	unordered_map<string, string> third({{"banana", "yellow"}, {"peach", "pink"}});
	unordered_map<string, string> fourth(merge(third, first));
	unordered_map<string, string>::iterator it;
	for (it = fourth.begin(); it != fourth.end(); ++it){
		cout << (*it).first << ": " << (*it).second << endl;
	}
	return 0;
}
