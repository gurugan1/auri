#include <iostream>
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
typedef pair<int,int> pii;
const int maxn =55;

vector<pii> edge[maxn];
bool init[maxn],imp[maxn],valid[maxn];
struct TurnOnLamps{

    bool intersect(pii a, pii b){
        if (a.first == b.first || a.first == b.second) return true;
        if (a.second == b.first || a.second == b.second) return true;
        return false;
    }


    int minimize(vector <int> roads, string initState, string isImportant){
        n= roads.size();
        For(i,0,roads.size()){
            int x= i, y = roads[i];
            edge[x].pb(MP(y,i));
            edge[y].pb(MP(x,i));
        }
        For(i,0,initState.size()) init[i]==initState[i]=='1';
        For(i,0,isImportant.size()) imp[i]==isImportant[i]=='1';
        For(i,0,edge.size()){
            if (initState[i]=='1' && isImportant[i]=='1') valid[i]=0; else valid[i]=1;
        }
        For(i,0,n) {
            if (done[i]) continue;
            conn.clear();
            dfs(i);
            int cur=0;
            For(j,0,conn.size()){
                cur=max(cur);
            }
        }
    }

};

int a[55][55];
struct TravelOnMars{

    int minTimes(vector <int> range, int ss, int es){
        int n = range.size();
        CLR(a,0x3F);
        For(i,0,n){
            For(j,0,range[i]+1){
                a[i][(i+j)%n]=1;
                a[i][(i-j+n)%n]=1;
            }
            a[i][i]=0;
        }
        For(k,0,n) For(i,0,n) For(j,0,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        return a[ss][es];
    }
};


int main(){

    return 0;
}
