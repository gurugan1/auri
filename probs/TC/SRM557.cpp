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
vector< vector<bool> > a;
const int maxn=55;
int dep[maxn],lo[maxn],bad[maxn];
int newn[maxn][maxn];
int time1 ;
void dfs(int x){
    dep[x]=++time1;
    lo[x]=dep[x];
    For(i,0,a[x].size()){
        if (a[x][i] && dep[i]==-1){
            dfs(i);
            lo[x]= min(lo[i],lo[x]);
        } else {
            lo[x]= min(lo[x],dep[i]);
        }
    }
}
int done[maxn];

struct Incubator{
    int maxMagicalGirls(vector <string> lov){
        int n = lov.size();
        For(i,0,n){
            vector<bool> temp;
            For(j,0,n)
                temp.pb(lov[i][j]=='Y');
            a.pb(temp); 
        }
        CLR(dep,-1);
        CLR(lo,-1);
        CLR(bad,0);
        time1 = 0;
        For(i,0,n){
            if (dep[i]==-1){
                dfs(i);
            }
        }
        For(i,0,n){
            if (lo[i]!=dep[i]) 
                continue;
            bad[lo[i]]=true;
            For(j,0,n)
                if (a[i][j] && dep[i]==lo[j])
                    bad[lo[i]]=false;
                        
        }
        vector<int> index;
        For(i,0,n)
            index.pb(lo[i]);
        sort(ALL(index));
        index.resize(unique(ALL(index))-index.begin());
        CLR(newn,0);
        For(i,0,n)
            For(j,0,n){
                if (a[i][j])
                    newn[lo[i]][lo[j]]=1;
            }
        int nn = index.size();
        CLR(done,0);
        int ret=0;
        For(k,0,nn){
            int cb=-1;
            int cbid=0;
            int curret=0;
           For(i,0,nn){
               if (done[i]) continue;
               bool cantremove = false;
               int input=0;
                For(j,0,nn){
                    if (!done[j] && newn[index[i]][index[j]]) {
                        cantremove = true;
                        break;
                    }
                    if (newn[index[j]][index[i]])
                        input++;
                }
                
                if (!cantremove){
                    if (input>cbid){
                        cb=i;
                        cbid=input;
                    }
                    if (!bad[i])
                        curret++;

                }
           }
           ret= max(ret,curret);
           done[cbid]=1;
        }
        return ret;
       
    }
};
const string NO = "NO";
struct FoxAndMountainEasy{
    public:
    string possible(int n, int h0, int hn, string h){
        int cur = abs(hn-h0);
        if (n<cur) return NO;
        int fin = 0,low=0;
        For(i,0,h.size()){
            if (h[i]=='U') 
                fin++;
            if (h[i]=='D')
                fin--;
            low = min(fin,low); 
        }
        bool done = false;
        n-=h.size();
        if (h0>=abs(low)){
            h0+=fin;
            done = true;
        }
        if (!done && hn>=abs(low)){
            hn-=fin;
            done=true;
        }
        if (!done){
           n-=abs(low)-h0; 
           h0= abs(low);
           h0 += fin;
           done = true;
        }
        if (n<0) return NO;
        if (abs(hn-h0) > n) return NO;
        n-= abs(hn-h0);
        if (n%2==1) return NO;
        return "YES";
    }

};

int main(){
    return 0;
}
