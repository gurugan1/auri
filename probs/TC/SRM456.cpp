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
#define ALL(V) V.begin(),V.end()
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
/*****************************************************************************/
const double EPS = 1e-10;

struct CutSticks{
    public:
        double maxKth(vector <int> s, int C, int K){
            double best = 0;
            For(i,0,s.size())
                best+=s[i];
            best/=K;
            double hi=best,lo=0,mid=0;
            best = -1;
            while (hi-lo>=EPS){
                mid = (lo+hi)/2;
                ll cur = 0,temp=0;
                For(i,0,s.size()){
                    cur += (ll)(s[i]/mid);
                    temp += (s[i]>=mid);
                }
                if (cur >=K && temp +C >= K){
                    lo = mid;
                    best = max(best,mid);
                } else {
                    hi = mid;
                }
            }
            return best;
        }

};

struct SilverDistance{
    public:

    int dist(int x, int y, int tx, int ty){
        if ((x-tx)%2 ==1) return 999999999;
        if ((y-ty)%2 ==1) return 999999999;
        return (abs(x-tx)+abs(y-ty))>>1;
    }
    int minSteps(int sx, int sy, int gx, int gy){
        int x = sy - sx;
        int y = sy + sx;

        int tx = gy - gx;
        int ty = gy + gx;

        int ret = 999999999;
        if (x<tx && y < ty){
            int k = min(tx-x,ty-y);
            ret = min(ret,dist(x+k,y+k,tx,ty)+k);
            ret = min(ret,dist(x+k-1,y+k-1,tx,ty)+k);
        }
        ret = min(ret,dist(x,y,tx,ty));
        ret = min(ret,dist(x+1,y+1,tx,ty));


    }

};

int main(){

    return 0;
}
