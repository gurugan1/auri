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

#define For(i,a,b) for(int i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/
const int maxn=10;
int mem[maxn][maxn][maxn][maxn],mem2[maxn][maxn];
int mem3[55][maxn][maxn];
const int MOD = 1000000009;

int doit(int n, int m,int x, int y){
    int &ret=mem[n][m][x][y];
    if (ret>=0) return ret;
    ret=0;
    For(i,x,y){
        For(j,y,n){
            ret+= doit(n,m-1,i,j);
            ret%=MOD;
        }
    }
    return ret;
};
int doit2(int n,int m){
    int &ret=mem2[n][m];
    if (ret>=0) return ret;
    ret=doit(n,m,0,1);
    return ret;
}

int go(int n, int m, int st,  const string &A, const string &B){
    int &ret=mem3[st][n][m];
    if (ret>=0) return ret;
    ret=0;
    if (A.size()!=B.size()) return ret=0;
    if (A[st]!=B[st]) return ret=0;
    For(i,st+2,n){
        if (A[i]==B[i]){
            For(i1,0, i-st+2){

            }

        }
    }
    return ret;


}

struct StringPath{
    int countBoards(int n, int m, string A, string B){
        int n2= A.size();
    
        go(0,n2-1,A,B);
    }

};

struct TheTree{

    int maximumDiameter(vector <int> cnt){
        int ret=cnt.size();
        int cur=0;
        For(i,0,cnt.size()){
            cnt[i]--;
            if (cnt[i]==0){
                cur=0;
            } else{
                cur++;
            }
        }
        return ret;
    }

};

int main(){


    return 0;
}
