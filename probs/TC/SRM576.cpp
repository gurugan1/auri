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
#define MP make_pair
typedef pair<int,int> pii;
/*****************************************************************************/

const int MOD = 1000000009;

ll mem[400][400];
struct TheExperiment{
    int L,A,B;
    vector<int> a;
    int SUM(int x, int y){
        int ret= a[y];
        if (x) ret-=a[x-1];
        return ret;
    }
    ll doit(int n, int x){
        if (n<0) return x==0;
        if (x==0) return 1;
        ll &ret = mem[n][x];
        if (ret>=0) return ret;
        ret=0;
        For(i,0,L-1){
            if(n-i<0) break;
            if (A<=SUM(n-i,n) && SUM(n-i,n)<=B){
                ret+= doit(n-i-1,x-1);
                ret%=MOD;
            }
        }
        if (A<=SUM(n-L,n) && SUM(n-L,n)<=B){
            For(i,0,n-L){
                ret+=doit(n-i,x-1);
                ret%=MOD;
            }
        }
        return ret;
    }
    int countPlacements(vector <string> intsen, int M, int L1, int A1, int B1){
        L = L1; A = A1; B=B1;
        CLR(mem,-1);
        For(i,0,intsen.size()) For(j,0,intsen[i].size()) a.pb(intsen[i][j]-'0');
        For(i,1,a.size()) a[i]+=a[i-1];
        CLR(mem,-1);
        return doit((int)a.size()-1,M);
    }
};

Struct ArcadeManao{
    public:
        bool used[55][55];

    bool valid(pii &x, vector<string> &a){
        if (x.first>=0 && x.second >=0 && x.first<a.size() && x.second<a[0].size()){
            return (!used[x.first][x.second] && a[x.first][x.second]=='X');
        }
        return false;
    }

    int shortestLadder(vector <string> ll1, int cr, int cc){
        int n = ll1.size(),m = ll1[0].size();
        pii ans = MP(cr-1,cc-1);
        
        For(ret,0,n+1){
            queue<pair<int,int> > Q;
            Q.push(MP(n-1,0));
            CLR(used,0);
            while (!Q.empty()){
                pii cur = Q.front(); Q.pop();
                pii tx = cur;
                For(i,0,ret+1){
                    tx.first += i;
                    if (valid(tx,ll1)){
                        used[tx.first][tx.second]=1;
                        Q.push(tx);
                    }
                    tx.first -=2*i; 
                    if (valid(tx,ll1)){
                        used[tx.first][tx.second]=1;
                        Q.push(tx);
                    }
                }
                tx.second+=1;
                if (valid(tx,ll1)){
                    used[tx.first][tx.second]=1;
                    Q.push(tx);
                }
                tx.second-=2;
                if (valid(tx,ll1)){
                    used[tx.first][tx.second]=1;
                    Q.push(tx);
                }
            }
            if (used[ans.first][ans.second]) return ret;
        }
        return -1;
    }
};
