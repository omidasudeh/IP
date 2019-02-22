/*
54. Spiral Matrix
Medium

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {            
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        int top = 0;
        int bottom = matrix.size();
        int left = -1;
        int right = matrix[0].size();
        int x = 0;
        int y = 0;
        int dir = 0;//0: to right, 1: downward, 2: to left, 3: upward
        while(left<right && top<bottom){
            ans.push_back(matrix[y][x]);
            if(dir == 0){
                if(x<right-1)
                    x++;
                else if(y<bottom-1){
                    y++;
                    right--;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
            else if(dir == 1){
                if(y<bottom-1)
                    y++;
                else if(x>left+1){
                    x--;
                    bottom--;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
            else if(dir == 2){
                if(x>left+1)
                    x--;
                else if(y>top+1){
                    y--;
                    left++;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
            else if(dir == 3){
                if(y>top+1)
                    y--;
                else if(x<right-1){
                    x++;
                    top++;
                    dir = (dir+1)%4;
                }
                else
                    break;
            }
        }
        return ans;
    }
};