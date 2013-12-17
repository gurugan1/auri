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
#include <sstream>

using namespace std;

#define For(i,a,b) for(typeof(a) i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/


struct TravellingPurchasingMan{
    int n,mem[1<<16][52];
    int a[55][55],opn[55],cls[55],dur[55];
    int doit(int mask, int x){
        if (mask==0) return a[0][x];
        int &ret=mem[mask][x];
        if (ret>=0 || ret==-2) return ret;
        ret=-2;
        For(i,0,n){
            if (mask &(1<<i)){      
                int time = doit(mask^(1<<i),i);
                if (time>=0 && time<=cls[i]){
                    time = max(time,opn[i])+dur[i];
                    time += a[i][x];
                }
                if (ret==-2 || (ret>=0 && ret<=time)){
                    ret=time;
                }
            }
        }
        return ret;
    }
    int count(int x){
        if (!x) return 0;
        return count(x&(x-1))+1;
    }
    int maxStores(int N, vector <string> iS, vector <string> roads){
        n = N;
        For(i,0,iS.size()){
            stringstream sin(iS[i]);
            sin >> opn[i] >> cls[i] >> dur[i];
        }
        CLR(a,0x5F);
        For(i,0,roads.size()){
            int x,y,cost;
            stringstream sin(roads[i]);
            sin >> x >> y >> cost;
            a[x][y]=a[y][x]=cost;
        }
        For(i,0,n) a[i][i]=0;
        For(i,0,n) For(j,0,n) For(k,0,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        int m = iS.size();

        CLR(mem,-1); int ret=0;
        For(i,0,(1<<m)){
            For(j,0,n) if (doit(i,j)>=0) ret= max(ret,count(i));
        }
        return ret;
    };

};

struct UndoHistory{
    public:

    int prefix(const string &a, const string &x){
        int ret=-1;
        For(i,0,a.size()){
            if (x.size()<=i || a[i]!=x[i]) return -1;
        }
        return x.size();
    }
    int minPresses(vector <string> lines){
        vector<string> undo; undo.pb("");
        string cur = "";
        int ret=0;
        For(i,0,lines.size()){
            int best=0,bestprefix=-1;
            For(j,0,undo.size()){
                if (prefix(undo[j],lines[i])>bestprefix){
                    bestprefix=prefix(undo[j],lines[i]);
                    best=j;
                }
            }
            if (prefix(cur,lines[i])>=bestprefix){

            } else{
                ret+=2;
                cur = undo[best];
            }
            For(j,bestprefix,lines[i].size()){
                ret++;
                cur +=lines[i][j];
                undo.pb(cur);
            }
            ret+=1;
        }
        return ret;
    }

};

int main(){ return 0;}
