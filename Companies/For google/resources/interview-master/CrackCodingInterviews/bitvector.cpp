#include <iostream>

using namespace std;

class bitvector {
	int *bitset;
public:
	bitvector(int size) {
		bitset = new int [size >> 5];
	}
	bool get(int pos) {
		int wordnumber = pos >> 5; // divide by 32
		int bitnumber = pos & 0x1F; // mode 32
		return (bitset[wordnumber] & (1 << bitnumber)) != 0;
	}
	void set(int pos) {
		int wordnumber = pos >> 5;
		int bitnumber = pos & 0x1F;
		bitset[wordnumber] |= (1 << bitnumber);
	}
};