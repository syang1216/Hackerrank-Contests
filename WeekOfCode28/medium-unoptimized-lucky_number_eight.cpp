//link: https://www.hackerrank.com/contests/w28/challenges/lucky-number-eight
// very interesting problem, wasn't able to solve completely in O(N).
// Had a solution but wasn't able to code it up in time

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*long backtrack(string str, string number, long pos){
    long count = 0;
    for(long i=pos;i<number.length();i++){
        str.push_back(number[i]);
     //   cout << str << endl;
        if(str.length()<=3){
            if(stol(str) % 8==0){
                count++;
            }
        }else{
            string temp = str.substr(str.length()-3, str.length());
            if(stol(temp) % 8==0){
                count++;
            }
        }
        
        count+=backtrack(str, number, i+1);
        str.pop_back();
    }
    return count;
}*/

int main(){
    int n;
    cin >> n;
    string number;
    cin >> number;
    // your code goes here
    
    
  /*  string empty = "";
    long count = backtrack(empty, number, 0);
    cout << count << endl;*/
    long count = 0;
    for(int i=0;i<n;i++){
        if((number[i]-'0')==8 || number[i]-'0'==0){
          //  cout << number[i]-'0' << endl;
            count++;
            count%=1000000007;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(((number[i]-'0')*10+(number[j]-'0'))%8==0 || ((number[i]-'0')*10+(number[j]-'0'))==0){
               // cout << (number[i]-'0')*10+(number[j]-'0') << endl;
                count ++;
                count%=1000000007;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(((number[i]-'0')*100+(number[j]-'0')*10+(number[k]-'0'))%8==0 || ((number[i]-'0')*100+(number[j]-'0')*10+(number[k]-'0'))==0){
                 //   cout << (number[i]-'0')*100+(number[j]-'0')*10+(number[k]-'0') << endl;
                    count+=pow(2,i);
                    count%=1000000007;
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}