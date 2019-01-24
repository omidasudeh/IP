/**
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 * use a queue of the size of the window
 * keep the sum of the window
 * 
 * */
#include <queue>
#include <iostream>
using namespace std;
 class MovingAvg{
    private:
        int winSize;
        int count;
        int sum;
        queue<int> q;
    public:
        MovingAvg(int windowSize):winSize(windowSize){
            count = 0;
            sum = 0;
        }
        void feedNumber(int num){
            if(count<winSize){ // if the window is not full
                q.push(num);
                sum+=num;
                count++;
            }else{// window already full
                int front = q.front();
                q.pop();
                q.push(num);
                sum=(sum - front+num);
            }
        }
        float getAvg(){
            if(count == 0)
                __throw_logic_error("empty window!");
            return (float)sum/count;
        }
    public:

 };
 int main(){
    MovingAvg MA(3);
    try{
        MA.getAvg();
    }
    catch(std::logic_error& e){
        cout<<e.what()<<endl;
    }
    MA.feedNumber(10);
    cout<<MA.getAvg()<<endl; //10/1

    MA.feedNumber(5);
    cout<<MA.getAvg()<<endl;// 15/2
    
    MA.feedNumber(2);
    cout<<MA.getAvg()<<endl;// 17/3

    MA.feedNumber(7);
    cout<<MA.getAvg()<<endl;// 14/3

    MA.feedNumber(12);
    cout<<MA.getAvg()<<endl;// 21/3

    return 0;
 }