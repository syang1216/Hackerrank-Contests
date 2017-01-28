//link to problem: https://www.hackerrank.com/contests/w27/challenges/tailor-shop
// Runtime: nLogn


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
    int p;
    cin >> n >> p;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    sort(a.begin(), a.end());
    long count=0;
    long max=0;
    for(int i=0;i<a.size();i++){
        long j = (long)ceil(a[i]/(double)p);
        if(j<=max){
            j = max+1;
        }
        count+=j;     
        max = j;
    }
    cout << count << endl;
    return 0;
}