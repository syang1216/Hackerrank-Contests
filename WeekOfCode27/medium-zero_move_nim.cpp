// link: https://www.hackerrank.com/contests/w27/challenges/zero-move-nim
// Combinatorial computer science, learned about grundy numbers.. Pretty useless

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


int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        vector<long> p(n);
        for(int p_i = 0;p_i < n;p_i++){
           cin >> p[p_i];
        }
        
        long cnt = 0;
        
        for(int i:p){
            if(i%2==0){
                cnt^=(long)(i-1);
            }else{
                cnt^=(long)(i+1);
            }
        }
        
        if(cnt){
            cout << "W" << endl;
        }else{
            cout << "L" << endl;
        }
       // cout << cnt << endl;
    }
    return 0;
}