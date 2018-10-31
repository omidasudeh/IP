// There are two ways to test whether the two strings are anagrams
// One is sort, and compare
// The other is to count the identical counts of each unique character
// Here the second one is implemented

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int anagram(string s1, string s2) {
	if (s1.length() != s2.length()) return 0;
	vector<int> c1(256, 0);
	vector<int> c2(256, 0);
	for (int i = 0; i < s1.length(); ++i) {
		c1[s1[i]]++;
		c2[s2[i]]++;
	}
	for (int i = 0; i < 256; ++i) {
		if (c1[i] != c2[i]) return 0;
	}
	return 1;
}

int main() {
	string s1, s2;
	cout << "Please enter the first string:\n";
	cin >> s1;
	cout << "Please enter the second string:\n";
	cin >> s2;
	cout << anagram(s1, s2) << endl;
	return 0;
}
