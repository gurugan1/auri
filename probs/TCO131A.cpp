#include <iostream>
#include <climits>
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

const char dir[] = "RDLU";
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

const int maxn = 15*16;
const int V = maxn*2+2;
int src,snk;
const double eps=1e-8;
int flo[V][V],cap[V][V],mark[V];
double cost[V][V],y[V];
vector<int> adj[V];

int aug(int v, int f=INT_MAX){
    if (mark[v]++) return 0;
    if (v==snk) return f;

    For(i,0,adj[v].size()){
        int w = adj[v][i];
        if (flo[v][w]<cap[v][w] && fabs(y[v]+cost[v][w]-y[w])<eps){
            int g = aug(w,min(f,cap[v][w]-flo[v][w]));
            if (g) {
                flo[v][w] += g;
                flo[w][v] -= g;
                return g;
            }
        }
    }
    return 0;
}

double mcmf(){
    double ret=0;
    while (1){
        For(v,0,V) y[v] = 1e9;
        y[src]=0;
        deque<int> q(1,src);

        while (q.size()){
            int v = q.front(); q.pop_front();
            For(i,0,adj[v].size()){
                int w = adj[v][i];
                if (flo[v][w] < cap[v][w] && y[v]+cost[v][w]+eps<=y[w]){
                        y[w] = y[v]+cost[v][w];
                        q.push_back(w);
                }
            }
        }
        CLR(mark,0);
        int f = aug(src);
        if (f==0) break;
        ret+= f*y[snk];
    }
    return ret;
}

void connect(int v, int w, int u , double c){
    cap[v][w]=u;
    cost[v][w]=c;
    cost[w][v]=-c;
    adj[v].pb(w);
    adj[w].pb(v);
}

void resetflow(){
    CLR(flo,0); CLR(cap,0); CLR(cost,0);
    For(v,0,V) adj[v].clear();

}

struct DirectionBoard{
    int getMinimum(vector <string> bb){
       int n = bb.size(), m = bb[0].size();
       For(i,0,n) For(j,0,m){
          int kk=0; 
           For(k,0,4) if (bb[i][j]==dir[k]){
                kk =k; break;
           }
           For(k,0,4){
               int tx = i+dx[k],ty = j+dy[k];
               tx = (tx + n)%n; ty = (ty+m)%m;
               connect(n*m+i*n+j,n*tx+ty,1,1-(k==kk));
           }
       }
       src = 2*n*m; snk= src+1;
       For(i,0,n) For(j,0,m){
           connect(src,n*m+i*n+j,1,0);
            connect(n*i+j,snk,1,0);
       }
       return mcmf();
    }

};


bool used[30300];


struct TheFrog{
    double getMinimum(int D, vector <int> L, vector <int> R){
        CLR(used,0);
        double ret=D+1,rmin=0;
        For(i,0,L.size()){
                rmin = max((double)R[i]-L[i],rmin);
                For(j,L[i],R[i]){
                    used[j]=1;
                }
        }
        vector<int> T;
        For(i,0,L.size()){
            T.pb(L[i]); T.pb(R[i]);
        }
        T.pb(D);
        for(int i=D;i>=1;i--){
            For(tt,0,T.size()){
                double cur = T[tt]/(double)i;
                if (cur<rmin) continue;
                if (cur>ret) continue;
                bool bad=false;
                double x = cur;
                while (cur<D){
                    if (used[(int)cur]) {
                        bad=true;
                        break;
                    }
                    cur+=x;
                }

                if (!bad) {
                    ret = min(ret,x);
                }
            }
        }
        return ret;
    }
};

struct HouseBuilding{
    int getMinimum(vector <string> a){
        int n = a.size(), m= a[0].size();
        int ret=n*m*10;
        For(k,0,10){
            int cur=0;
        For(i,0,n) For(j,0,m){
            cur += abs((a[i][j]-'0')-k);
        }
        ret = min(ret,cur);
        }
        return ret;

    }
};

int main(){
    int D = 29999;
    int n = D/50;
    int cur = 1;
    vector<int> L,R;
    For(i,0,50){
        L.pb(cur);  R.pb(L.back()+n-1);
        cur+=n;
    }
    cout << "{";
    For(i,0,L.size()){
        cout << L[i] << ',';
    }
    cout << "}\n";
     cout << "{";
    For(i,0,R.size()){
        cout << R[i] << ',';
    }
    cout << "}\n";

    return 0;
}
