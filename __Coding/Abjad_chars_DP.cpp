#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int abjad_weight(int index){
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
    // int ind;
    while(iss>>chr){
        alpha.push_back(chr);
        // cout<<chr<<":"<<abjad_weight(ind)<<endl;
        // ind++;
    }
    //================ compute
    vector<vector<string>> F;
    vector<string> zero;
    zero.push_back("");
    F.push_back(zero);
    for(int i = 1;i<=M;i++){
        vector<string> newSet;
        for(int j = 0;j<i;j++){
            if(i-abjad_weight(j)>=0){
                // cout<<i<<":"<<j<<endl;
                // F[i] = F[i-abjad_weight(alp)] U alp;
                for(string item:F[i-abjad_weight(j)]){
                    string alp = alpha[j];
                    string s = item+"\t"+alp;
                    // cout<<s<<endl;
                    newSet.push_back(s);
                }
            }
        }
        F.push_back(newSet);
    }
    //================= output
    cout<<"result:"<<endl;
    // for(int i = 0;i<F.size();i++){
        auto Set = F[F.size()-1];
        // cout<<i<<endl;
        for(string s: Set){
            cout<<s<<endl;
        }
    // cout<<"============"<<endl;
    // }
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