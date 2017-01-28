link: https://www.hackerrank.com/contests/w28/challenges/the-great-xor

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
  /*  for(long x=0;x<100;x++){
        long count = 0;
        for(long i=1;i<x;i++){
            if((i^x) > x){
             //   cout << (i^x) << endl;
                count++;
            }
        }
        cout << x << " " << count << endl;
    }*/
    
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long power = 0;
        long k = x;
        while(k>=2){
            k/=2;
            power++;
        }
      //  cout << power << endl;
        long count = pow(2,power) - (1+(x-pow(2,power)));
        
        cout << count << endl;
    }
    return 0;
}