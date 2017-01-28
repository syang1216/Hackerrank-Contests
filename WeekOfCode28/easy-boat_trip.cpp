//link: https://www.hackerrank.com/contests/w28/challenges/boat-trip

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
    int n;
    int c;
    int m;
    cin >> n >> c >> m;
  //  vector<int> p(n);
    int num = c*m;
    bool yes = true;
    for(int p_i = 0; p_i < n; p_i++){
     //  cin >> p[p_i];
        int p;
        cin >> p;
        if(p>num){
            yes = false;
            break;
        }
    }
    
    if(yes){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}