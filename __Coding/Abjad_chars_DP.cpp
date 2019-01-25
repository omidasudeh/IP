/*
TODO: this is still not working
* given the abjad chars and their weight and given a sum number find all subsets that sums up to the sum
* this is equalant for subset sum problem and also coin changing problem
*/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int C(int index){
    if(index >=28 || index<0)
        return -1;
    index++;
    int r = index%9;
    int q = index/9;
    int pow = 1;
    for(int i = 0;i<q;i++) pow *=10;
    return (pow*r);
}
void abjad(int M){
    string abj_alpha = "ʾ b j d h w z ḥ ṭ y k l m n s ʿ f ṣ q̈ r sh t th kh dh ḍ ẓ gh";
    istringstream iss (abj_alpha);
    vector<string> alpha;
    string chr;
    int ind = 0;
    while(iss>>chr){
        alpha.push_back(chr);
        cout<<chr<<":"<<C(ind)<<endl;
        ind++;
    }
    //================ compute
    vector<vector<bool>> F(alpha.size()+1,vector<bool>(M+1, false));
    cout<<F.size()<<"*"<<F[0].size()<<endl;
    for(int i = 1;i<F.size();i++){
        for(int m = 1;m<=M;m++){
            if(m%i==0)
                F[i][m] = true; 
            else if(C(i-1)<=m){
                F[i][m] = ((F[i-1][m-C(i-1)])||(F[i-1][m]));    
            }
            else{
                F[i][m] = F[i-1][m]; 
            }
            cout<<F[i][m]<<" \t";
        }
        cout<<endl;
    }
}
int main(int argc, char** argv){
    int M;    
    if(argc < 2){
        cout<<"Enter a number:"<<endl;
        cin>>M;
    }
    else{
        M = stoi(argv[1]);
    }
    abjad(M);
    return 0;
}