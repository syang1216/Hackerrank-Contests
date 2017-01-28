// link: https://www.hackerrank.com/contests/w28/challenges/value-of-friendship
// first hard problem solved in contests

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

long long int size;

void DFS(int n, vector<long long int> nodes[], bool visited[])
{
    size++;
    visited[n] = true;
    for(vector<long long int>::iterator i = nodes[n].begin(); i !=nodes[n].end() ; i++)
    {
        if(!visited[*i])
            DFS(*i, nodes, visited);
    }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        
        vector<long long int> nodes[n+1];
        for(int i=0;i<=n;i++){
            nodes[i].clear();
        }
        bool visited[n+1] = {false};
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            cin >> x >> y;
            // your code goes here
            nodes[x].push_back(y);
            nodes[y].push_back(x);
        }
        
        vector<long long int> sizes;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                int k = i;
                size = 0;
                DFS(i, nodes, visited);
                if(size!=1)
                    sizes.push_back(size);
            }
        }
        
        sort (sizes.begin(), sizes.end());
            
        long long int total = 0;
        long long int countFriends = 0;
        long long int countSize = 0;
       // int maxValue = 0;
        for(int i=sizes.size()-1;i>=0;i--){
            // use formula for increasing arithematic progression
            // a0n + d0*n(n-1)/2 + d*(n)(n-1)(n-2)/6
            long long int size = sizes[i];
            
            total += ((2+countFriends)*(size-1)) + (4)*(size-1)*(size-2)/2 + (2)*(size-1)*(size-2)*(size-3)/6;
            countFriends += size*(size-1);
         //   maxValue+=size*(size-1);
           // cout << maxValue << endl;
            
            countSize += (size-1);
        }
        
    //    cout << total << endl;
        total+= (m-countSize)*countFriends;
        cout << total << endl;
    }
    return 0;
}
