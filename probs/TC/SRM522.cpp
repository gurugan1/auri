#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define For(i,a,b) for(typeof(a) i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/

struct CorrectMultiplication{
    long long getMinimum(int a, int b, int c){
        
    }
};

int count(int x){
    if (!x) return 0;
    return 1+count(x&(x-1));
}

struct RowAndCoins{
    public:
    string c;
    int mem[1<<15][2];
    int doit(int mask,int f){
        int &ret= mem[mask][f];
        if (ret>=0) return ret;
        int n = c.size();
        if (count(mask)==n) return 1;
        if (count(mask)==n-1){
            For(i,0,n){
                if (mask & (1<<i)) continue;
                if (c[i]-'A'==f){
                    return ret=1;
                } else{
                    return ret=0;
                }
            }
        }
        For(i,0,n) 
            For(j,0,i+1){
                bool empty = 1;
                int cur = 0;
                For(k,j,i+1){
                   cur |= 1<<k;
                   if (mask & (1<<k)){
                       empty =0;
                       break; 
                   }
                }
                if (empty && (mask|cur ==(1<<n)-1)){
                   if (!doit(mask|cur,f^1)) return ret=1;
                }
            }
        return ret=0;
    }

    string getWinner(string cells){
        c = cells;
        CLR(mem,-1);
        if (doit(0,0)) return "Alice";
        return "Bob";
    }

};
