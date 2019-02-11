/*
Given two sets of intervals return the intersection set. Suppose both the sets are sorted.
example:
A: [1,5][6,8][11,18]
B: [3,7]
result: [3,5][6,7]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
/*
1. combine two intervals
2. sort the combined vector by the start
3. intersect the combined vector
time: O(n log(n)) for sorting + O(n) on pass
space: O(log(n)) for sorting + O(n) result vector
*/
bool compare(const Interval A, const Interval B){
    return A.start<B.start;
}
class Solution {
public:
    vector<Interval> Intersect(vector<Interval>& A,vector<Interval>& B ) {
        if(A.size() == 0) return B;
        if(B.size() == 0) return A;
        vector<Interval> ans;
        //1. combine
        for(auto item : B)
            A.push_back(item);
        //2. sort
        std::sort(A.begin(), A.end(), compare);
        //3. intersect
        Interval rem = A[0];
        for(int i = 1;i<A.size();i++){
            Interval inter(max(rem.start, A[i].start),min(rem.end, A[i].end) );
            // cout<<"rem:"<<rem.start<<"\t"<<rem.end<<endl;
            // cout<<"inter:"<<inter.start<<"\t"<<inter.end<<endl<<endl;
            if(inter.start <inter.end){ // if valid interval 
                if(ans.empty() || inter.start>ans.back().end)
                    ans.push_back(inter); //add it to the result
                else{
                    Interval merged (ans.back().start, max(ans.back().end, inter.end));
                    ans.pop_back();
                    ans.push_back(merged);  
                }
                rem.start = min(rem.end, A[i].end); // update the remainder
                rem.end = max(rem.end, A[i].end);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
/// ==================== A    
    vector<Interval> A;
    Interval I(1,5);
    A.push_back(I);

    I.start = 6;
    I.end = 8;
    A.push_back(I);

    I.start = 15;
    I.end = 18;
    A.push_back(I);
///===================== B
    vector<Interval> B;

    I.start = 3;
    I.end = 7;
    B.push_back(I);

    I.start = 1;
    I.end = 18;
    B.push_back(I);
///==================== compute intersect
    vector<Interval> ans = s.Intersect(A,B);
    cout<<"Intersections:"<<endl;
    for(auto item : ans){
        cout<<item.start<<"->"<<item.end<<endl;
    }
}