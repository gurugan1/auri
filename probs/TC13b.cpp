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

struct ScotlandYard {
    int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro){
        n = taxi.size();
        T.n=n;
        For(i,0,n) For(j,0,n) T.a[i][j]=taxi[j][i]=='Y';
        For(i,0,n) For(j,0,n) B.a[i][j]=bus[j][i]=='Y';
        For(i,0,n) For(j,0,n) M.a[i][j]=metro[j][i]=='Y';
       
        return ret;
    }
};

struct FruitTrees{

    int compute(int A, int B, int C, int x, int y){
        int ret = min(x,y);
        ret = min(ret,A-x); ret= min(ret,A-x);
        ret = min(ret,abs(x-y));
        return ret;
    }

    int comput(int A,int B, int off,vector<int> &a){
        int ret= off;
        vector<int>::iterator it = lower_bound(ALL(a),A-off);
        if (it != a.end()){
            ret = min(ret,min(A-(*it+off),(*it+off)));
        } 
        {
            if (it==a.begin()) it = a.end();
            it--;
            ret = min(ret,min(A-(*it+off),(*it+off)));

        }
        return ret;
    }

    int maxDist(int A, int K, int G){
        if (A<K) swap(A,K); if (A<G) swap(A,G);
        if (K<G) swap(K,G);
        vector<int> V,T,W;
        For(i,0,A){
            V.pb((i*K)%A);
            T.pb((i*G)%A);
        }
        For(i,0,K){
            W.pb((i*G)%K);
        }
        sort(ALL(W)); sort(ALL(V)); sort(ALL(T));
        V.resize(unique(ALL(V))-V.begin());
        T.resize(unique(ALL(T))-T.begin());
        W.resize(unique(ALL(W))-W.begin());


        int ret=99999999;
        For(i,0,A){
            For(j,0,A){
                ret=min(ret,comput(A,K,i,V));
                ret=min(ret,comput(A,G,j,T));
                if (i<j){
                    ret = min(ret,comput(K,G,j-i,W));
                } else{
                    ret = min(ret,comput(K,G,j+G-i,W));
                }
            }
        }
        return ret;
    }
};

int main(){ return 0;}
