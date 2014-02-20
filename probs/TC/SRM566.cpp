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

const int maxn = 355;
const int MOD = 1000000007;
struct PenguinEmperor{
    public:
        
    int a[maxn][maxn];
    int n;
    vector<ll> mult(vector<ll> &a, vector<ll> &b){
        vector<ll> ret(a.size());
        For(i,0,n){
            For(j,0,n){
                ret[(i+j)%n]=(a[i]+b[j])%MOD;
            }
        }
        return ret;
    }
    vector<ll> doit(vector<ll> &a, ll x){
        if (x ==1){
            vector<ll> ret=a;
            return ret;
        }
        vector<ll> cur2 = doit(a,x/2);
        vector<ll> ret = mult(cur2,cur2);
        if (x&1){
            ret = mult(ret,a);
        }
        return ret;
    }
    int countJourneys(int n1, long long d){
        n = n1;
        a[0][0]=1;
        For(i,1,n){
            For(j,0,n){
                a[(j+i)%n][i]= (a[(j+i)%n][i]+a[j][i-1])%MOD;
                a[(j+n-i)%n][i] = (a[(j+n-i)%n][i]+a[j][i-1])%MOD;
            }
        }
        vector<ll> cur; 
        if (d<n) return a[0][d];
        For(i,0,n) cur.pb(a[i][n-1]);
        cur = doit(cur,d/n);
        vector<ll> temp;
        For(i,0,n) temp.pb(a[i][d%n]);
        cur = mult(cur,temp);
        return cur[0];
    }
};


struct PenguinSledding{
    public:
        vector<ll> e[55];
        int a[55][55];
    long long countDesigns(int n, vector <int> cp1, vector <int> cp2){
        For(i,0,cp1.size()){
            e[cp1[i]].pb(cp2[i]);
            e[cp2[i]].pb(cp1[i]);
            a[cp1[i]][cp2[i]]=a[cp2[i]][cp1[i]]=1;
        }
        ll ret=0;
        For(i,0,n+1){
            ret+= (1LL << (e[i].size()));
        }
        For(i,0,n)
            For(j,0,i)
                For(k,0,j){
                    if (a[i][j] && a[i][k] && a[j][k]) ret+=1;
                }
        ret -=cp1.size();
        return ret;

    }

};
