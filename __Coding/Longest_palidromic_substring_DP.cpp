class Solution {
public:
// solution 1: the brute force is to check all the O(n^2) substr and find max palindromic substr ==> O(n^3) , O(1)

// solution 2:  DP  time: O(n^2) space: O(n^2)

 // string longestPalindrome(string s) {
 //    int size = s.size();
 //    vector<vector<bool>> map (size,vector<bool>(size,0));
 //    int maxi = 0;
 //    int max = 1;
 //    for(int i = size-2;i>=0;i--){ //
 //        for(int j = i+1;j<size;j++){
 //            map[i][j] = (s[i]==s[j]) && (j-i<3 || (map[i+1][j-1]));
 //            if(map[i][j] && j-i+1 > max){
 //                    max = j-i+1;
 //                    maxi = i;
 //            }
 //        }
 //    }
 //    return s.substr(maxi,max);
 // }
 
// Solution 3  time: O(n^2) space: O(1) 

// For each index, use it as the middle of a palindrome and keep expanding outwards until it is no longer a palindrome (odd length palindromes).
// Check whether the size of the palindrome is bigger than our best and update if it is.
// Check whether for each index and it's neighbour forms a palindrome, if so, expand outwards the same as point 1.
    string longestPalindrome(string s) {
    int pos = 0;
    int max = 1;

    for (int middle = 0; middle < s.size(); ++middle) {//{middle, middles + 1} is the range for the loop, where right variable will be iterator starting from middle until middle+1.
      // Check the odd length palindromes and then the even length palindromes
      for (int right : {middle, middle + 1}) {
        int left = middle;

        // Keep expanding outwords, so long as we still have a palindrome
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
          --left;
          ++right;
        }

        // Do we have a better solution? Keep in mind that left and right are now either side
        // of the palindrome, so to get the correct start and length, left must be moved back.
        int len = right - ++left;
        if (len > max) {
          pos = left;
          max = len;
        }
      }
    }

    return s.substr(pos, max);
  }
};