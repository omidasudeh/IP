#include <iostream>
#include <utility>
#include <sstream>
#include <climits>
#include <unordered_map>
using namespace std;
int main() {
  string test1 = "apple 12\n"
                 "banana 3\n"
                 "apple 5\n"
                 "pear 1\n"
                 "orange 4\n";

  istringstream iss(test1);
  unordered_map<string,int> map;
  string fruitName;
  string fruitNumStr;
  while(iss >> fruitName)
  {
    iss >> fruitNumStr;
    int fruitNum = std::stoi(fruitNumStr);
    if(map.find(fruitName)!= map.end())//the fruit already exists
    {
        map[fruitName] = map[fruitName] + fruitNum;
    }
    else// the first time we add the fruit
    {
        map[fruitName] = fruitNum;
    }
  }
  // // ===== linear search key val pairs
  pair<string,int> max1;max1.second = INT_MIN;
  pair<string,int> max2;max2.second = INT_MIN;
  pair<string,int> max3;max3.second = INT_MIN;
  //TODO: initiate to MIN_INT 

  for(pair<string,int> keyval: map)
  {
      if(keyval.second>max1.second)
      {
          max3 = max2;
          max2 = max1;
          max1 = keyval;
      }
      else if(keyval.second>max2.second)
      {
          max3 = max2;
          max2 = keyval;
      }
      else if(keyval.second>max3.second)
      {
          max3 = keyval;
      }
  }
  cout<<max1.first<<":"<<max1.second<<endl;
  cout<<max2.first<<":"<<max2.second<<endl;
  cout<<max3.first<<":"<<max3.second<<endl;
  return 0;
}