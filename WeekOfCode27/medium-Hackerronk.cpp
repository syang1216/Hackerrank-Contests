// Link: https://www.hackerrank.com/contests/w27/challenges/hackonacci-matrix-rotations

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
    long n;
    long q;
    cin >> n >> q;
    
    bool relation[7] = {false, true, false, true, true, false, false};
    long long cache[4] = {0};
    
    long long count = 0;
    int x = 1;
    for(int i=n;i>0;i--){
        int y = 1;
        for(int j=1;j<=n;j++){
            long long ij = i*j;
            ij = ij*ij;
            long long xy = x*y;
            xy = xy*xy;
            if((!relation[(ij-1) % 7] && relation[(xy-1) % 7]) || (relation[(ij-1) % 7] && !relation[(xy-1) % 7])){
                count++;
            }
            y++;
        }
        x++;
    } 

    cache[1] = count; 
    
    count = 0;
    x = 1;
    for(int i=n;i>0;i--){
        int y = 1;
        for(int j=n;j>0;j--){
            long long ij = i*j;
            ij = ij*ij;
            long long xy = x*y;
            xy = xy*xy;
            if((!relation[(ij-1) % 7] && relation[(xy-1) % 7]) || (relation[(ij-1) % 7] && !relation[(xy-1) % 7])){
                count++;
            }
               
            y++;
        }
        x++;
    }

    cache[2] = count; 
    
    count = 0;
    x = 1;
    for(int i=1;i<=n;i++){
        int y = 1;
        for(int j=n;j>0;j--){
            long long ij = i*j;
            ij = ij*ij;
            long long xy = x*y;
            xy = xy*xy;
            if((!relation[(ij-1) % 7] && relation[(xy-1) % 7]) || (relation[(ij-1) % 7] && !relation[(xy-1) % 7])){
                count++;
            }
            y++;
        }
        x++;
    } 

    cache[3] = count; 
    
    for(int a0 = 0; a0 < q; a0++){
        long angle;
        cin >> angle;
        
        int a = angle % 360;
        cout << cache[a/90] << endl;
    }
    return 0;
}c