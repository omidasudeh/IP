class Solution {
public:
    string roman;
    int interger[7] = {1, 5, 10, 50, 100, 500, 1000};
    int rom[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int subint[7] = {-1, 4, 9, 40, 90, 400, 900};
    string subrom[7] = {"", "IV", "IX", "XL", "XC", "CD", "CM"};
    
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        roman = "";
        int t;
        for (int i = 6; i >= 0; --i) {
            if (t = num / interger[i]) {
                if (t >= 4) {
                    for (int j = 0; j < interger[i + 1] - t; ++j) {
                        roman += rom[i];
                    }
                    roman += rom[i + 1];
                    continue;
                }
                for (int j = 0; j < t; ++j) {
                    roman += rom[i];
                }
                num -= interger[i] * t;
                ++i;
            }
            else if (t = num / subint[i]) {
                roman += subrom[i];
                num -= subint[i] * t;
            }
        }
        return roman;  
    }
};
