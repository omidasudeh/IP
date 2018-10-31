class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
    
        for (auto i = num.end() - 1; i != num.begin(); --i) {
            if (*(i - 1) < *i) {
                auto min_bigger = i;
                for (auto j = i + 1; j != num.end(); ++j) {
                    if (*min_bigger > *j && *j > *(i - 1)) {
                        min_bigger = j;
                    }
                }
                int t = *(i - 1);
                *(i - 1) = *min_bigger;
                *min_bigger = t;             
                sort(i, num.end());
                return;
            }
        }
        
        sort(num.begin(), num.end());
    }
};
