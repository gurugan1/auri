#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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

void doit(const vector<int> &cur){
    For(i,0,cur.size()) work[cur[i]]=1;
    For(i,0,V.size()){
        int mask = V[i].second;
        For(j,0,n){
            if (mask & (1<<j)){
                work[mask]+=work[mask^(1<<j)];
            }
        }
    }
    For(i,0,cur.size()){


    }



}

int main(){
    scanf("%d",&n);
    N=1<<n;
    For(i,0,n) scanf("%d",a+i);
    For(i,0,n){
        int sum=0,count=0;
        For(j,0,n){
            if (i&(1<<j)){
                sum+=a[i];
                count++;
            }
        }
        M[sum].pb(i);
        V.pb(MP(count,i));
    }
    sort(ALL(V));
    FOREACH(M,it){
        const vector<int> &cur=it->second;
        if(cur.size()>1000){
            doit(cur);
        } else {
            For(i,0,cur.size()){
                For(j,0,i){
                    if (cur[i]&cur[j]) continue;
                    ans[cur[i]|cur[j]]=1;
                }
            }
        }

    }
    

    return 0;
}
