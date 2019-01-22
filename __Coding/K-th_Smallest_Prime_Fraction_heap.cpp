/**
A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]

 */
struct compare{
  bool operator()(const pair<int,int>& op1,const pair<int,int>& op2 ){
      return (op1.first*op2.second < op2.first*op1.second);
  }  
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq; // we need a max-heap
        int count = 0;
        for(int i = 0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                if(A[i]<A[j]){
                    if(count<K){ // if heap is not full just add
                        pq.push(pair<int,int>(A[i],A[j])); 
                        count++;
                    }
                    else{ // o.w. remove the max and the next item
                        pair<int,int> top = pq.top();
                        if(A[i]*top.second < A[j]*top.first){
                            pq.pop();
                            pq.push(pair<int,int>(A[i],A[j])); 
                        }
                    }
                }
            }
        }
        // at this point the heap has least k elements
        pair<int, int> r = pq.top();
        return vector<int>({r.first,r.second});
    }
};