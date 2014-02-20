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


int dp[512][55];

struct Bribes{
    public:
        vector<int> inf,res;
        int n;

    int doit(int mask,int x){
        int &ret=dp[mask][x];
        if (ret>=0) return ret;
        if (x==n){
            return ret=0;
        }
        int cur = res[i];
        For(i,0,8){
            if (mask & (1<<i)){
                res[i]-=inf[x-i-1]>>(i+1);

            }
        }
        For(i,8,16){

        }
    }
    int minBribes(vector <int> inf, vector <int> res){
        ::inf = inf;
        ::res = res;
        n = inf.size();
        CLR(dp,-1);
        return  doit(0,0);

    }

};
struct BestApproximationDiv1{
    string findFraction(int maxDen, string number){
        double x;
        char buf[100];
        sscanf(number.c_str(),"%lf",&x);
        int ret=-1,rnum=0,rden=1;
        For(d,1,maxDen+1){
            For(k,0,2){
                int num = (int)(x*d+0.5*k);
                sprintf(buf,"%.8lf",double(num)/d);
                int cur=0;
                for(cur=0;cur<number.size();cur++){
                    if (number[cur]!=buf[cur]) break;
                }
                cur-=2;
                if (ret==cur){
                    if (rnum>num){
                        rnum=num;
                        rden = d;
                    }
                }
                if (ret<cur){
                    rnum=num;
                    rden=d;
                    ret=cur;
                }
            }
        }
        sprintf(buf,"%d/%d has %d exact digits",rnum,rden,ret);
        number = buf;
        return number;
    }
};

int main(){ return 0; }
