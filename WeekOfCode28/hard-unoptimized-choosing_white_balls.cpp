// link: https://www.hackerrank.com/contests/w28/challenges/choosing-white-balls/submissions
// wasn't able to optimize, got ~40/60 points. Passed all preliminary test cases but not
// final tests cases. Optimization involved very tricky manipulation of bits 
// which I wasn't able to think of. 

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
#include <iomanip>

using namespace std;
unordered_map<string, double> cache;
//set<string> fast_find;

double recCheck(int k, string& str, int s){
    if(k==0) return 0;
    if(k==1){
        // just want to calculate the probability of whites
        int whiteCount=0;
        for(int i=0;i<s;i++){
            if(str[i]=='W' || str[s-1-i]=='W'){
                whiteCount++;
            }
        }
        
        return (double)(whiteCount)/s;
        //return 1.0/3;
    }
    int countWhite = 0;
    double count = 0;
    
    for(int i=0;i<=ceil(1.0*s/2)-1;i++){
        if(i==ceil(1.0*s/2)-1 && s%2==1){
            string ns2 = str;
            ns2.erase(i,1);
            double one;
            if(cache.find(ns2) != cache.end()){
                one = cache[ns2];
            }else{
                one = recCheck(k-1, ns2, s-1);
                cache[ns2] = one;
          //      fast_find.insert(ns2);
            }
            count+=one;
            if(str[i]=='W')
                countWhite++;
        }else{
            if(str[i]=='W'){
                countWhite+=2;
                
                string ns2 = str;
                ns2.erase(i,1);
                double one;
                if(cache.find(ns2) != cache.end()){
                    one = cache[ns2];
                }else{
                    one = recCheck(k-1, ns2, s-1);
                    cache[ns2] = one;
                //    fast_find.insert(ns2);
                }
                
                if(str[s-1-i]=='W'){
                    // Both are white, pick the one with the higher probability    
                    string ns3 = str;
                    ns3.erase(s-1-i,1);
                    double two;
                    if(cache.find(ns3)!= cache.end()){
                        two = cache[ns3];
                    }else{
                        two = recCheck(k-1,ns3, s-1);
                        cache[ns3] = two;
                     //   fast_find.insert(ns3);
                    }
                    if(one >= two){
                        count += 2*one;
                    }else{
                        count += 2*two;
                    }

                }else{
                    // just pick that white
                    count += 2*one;
                }
            }else if(str[s-1-i]=='W'){
                countWhite += 2;
                string ns2 = str;
                ns2.erase(s-1-i,1);
                double one;
                if(cache.find(ns2)!=cache.end()){
                    one = cache[ns2];
                }else{
                    one = recCheck(k-1, ns2, s-1);
                    cache[ns2] = one;
                  //  fast_find.insert(ns2);
                }
                
                count += 2*one;
            }else{
                string ns2 = str;
                ns2.erase(i,1);
                double one;
                if(cache.find(ns2) != cache.end()){
                    one = cache[ns2];
                }else{
                    one = recCheck(k-1, ns2, s-1);
                    cache[ns2] = one;
                  //  fast_find.insert(ns2);
                }
                
                string ns3 = str;
                ns3.erase(s-1-i,1);
                double two;
                if(cache.find(ns3)!=cache.end()){
                    two = cache[ns3];
                }else{
                    two = recCheck(k-1, ns3, s-1);
                    cache[ns3] = two;
                 //   fast_find.insert(ns3);
                }
                
                if(one >= two){
                //    cout << "for i = " << i << " pushing " << ns2 <<" with probability " << one << endl;
                    count += 2*one;
                }else{
                //    cout << "for i = " << i << " pushing " << ns3 <<" with probability " << two << endl;
                    count += 2*two;
                }
            }
        }
    }

    count/=s;
    count+= (countWhite*1.0/s);
    return count;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    string balls;
    cin >> balls;
    double count = recCheck(k, balls, n);
    cout << setprecision(16) << count << endl;
    // your code goes here
    return 0;
}