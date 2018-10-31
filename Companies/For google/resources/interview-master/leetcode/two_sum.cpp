class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> r = vector<int>(2);
        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    r[0] = i + 1;
                    r[1] = j + 1;
                    return r;
                }
            }
            
        }
        
    }
};
