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


const int MOD = 1000000007;
const int maxn = 100;
int cost[maxn][maxn],dp[maxn],used[maxn];
struct ColorfulWolves{
    public:
    int n;
    int getmin(vector<string> cc){
        n = cc.size();
        For(i,0,n) {
            int cnt=0;
            For(j,0,n){
                if (cc[i][j]=='Y'){
                    cost[i][j]=cnt;
                    cnt++;
                }
            }
        }
        CLR(dp,0x5F);
        CLR(used,0);
        dp[0]=0; 
        while (true){
            int cur=-1;
            For(i,0,n) if (dp[i]<2501 && !used[i]&& (cur==-1 || dp[cur]>dp[i])){
                cur=i;
            }
            if (cur==-1){
                break;
            }
            used[cur]=1;
            For(i,0,n){
                if (cost[cur][i]>=0)
                    dp[i]=min(dp[i],dp[cur]+cost[cur][i]);
            }
        }
        if (dp[n-1]>2501) return -1;
        return dp[n-1];
    }
};

struct ColorfulChocolates{
    string s;
    int n,rdp[55][55][30],ldp[55][55][30];

    int left_doit(int x, int y, int ch){
        int &ret = ldp[x][y][ch];
        if (ret>=0) return ret;
        ret=0;
        for(int i = y;i>=0;i--){
            if (s[i]==ch+'A'){
                ret+=y-i;
                y--;
            }
            if (x>y) break;
        }
        if (x<=y) ret=3000;
        return ret;
    }

 
    int right_doit(int x, int y, int ch){
        int &ret = rdp[x][y][ch];
        if (ret>=0) return ret;
        ret=0;
        for(int i=x;i<n;i++){
            if (s[i]==ch+'A'){
                ret+=i-x;
                x++;
            }
            if (x>y) break;
        }
        if (x<=y) ret=3000;
        return ret;
    }
   
    int maximumSpread(string c, int ms){
        CLR(rdp,-1); CLR(ldp,-1);
        s = c;
        n = s.size();
        int best=0;
        For(col,0,26){
            For(i,0,n) For(j,0,i+1){
                if (i-j+1<best) break;
                if (left_doit(j,i,col)<=ms ){ best=max(best,i-j+1); break;}
                if (right_doit(j,i,col)<=ms ){ best=max(best,i-j+1); break;}
                For(k,j,i+1){
                    if (left_doit(j,k,col) + right_doit(k,i,col)<=ms){
                        best = max(best,(i-j+1));
                        break;
                    }
                }
            }
        }
        return best;
    }

};


