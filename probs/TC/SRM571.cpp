#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

#define For(i,a,b) for(typeof(a) i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/
/*
const int maxn =55;
vector<int> V[maxn];
vector<int> st;
struct comp{
    bool operator()(const int a, const int b){
        return V[a].size() < V[b].size();
    }
};

int doit(const vector<int> &P, int cur, int inx){
    if (inx == n) return 0;
    For(i,inx,st.size()){

    }


}
struct MagicMolecule{
    public:
    int maxMagicPower(vector <int> P, vector <string> a1){
        n = P.size(); m = m2=0;
        For(i,0,n) For(j,0,i){
            if (a1[i][j]=='N'){
                V[i].pb(j); V[j].pb(i);
                m++;
            } else { m2++; }
        }
        int cur = n/3;
        int rem = n-cur;
        if (rem*(rem-1)/2  > m2) return -1;
        For(i,0,n) st.pb(i);
        sort(ALL(st),comp);
        CLR(done,0);
        return doit(P, cur, 0);
    }
};*/
struct FoxAndMp3{

    void doit(int x, int n, vector<string> &ret){
        if (ret.size()==50) return ;
        char buf[100];
        sprintf(buf,"%d.mp3",x);
        string s = buf;
        ret.pb(s);
        For(i,0,10){
            int cur = x*10+i;
            doit(cur,n,ret);
            if (ret.size()==50) return;
        }
        return;
    }
    vector <string> playList(int n){
        if (n<=200000){
            vector<string> V;
            char buf[100];
            For(i,0,n){
                sprintf(buf,"%d.mp3",i+1);
                string s= buf;
                V.pb(s);
            }
            sort(ALL(V));
            vector<string> ret;
            For(i,0,min(n,50)){
                ret.pb(V[i]);
            }
            return ret;
        }
        vector<string> ret;
        doit(1,n,ret);
        return ret;
    }

};

int main(){ 
    int n= 50;
    char a[n][n];
    CLR(a,'N');
    vector<int> P,order;
    For(i,0,n) P.pb(1+rand()%100);
    int k = 35;
    For(i,0,k){
        For(j,0,i){
            a[i][j]=a[j][i]='Y';
        }
    }

    For(i,0,k*(n-k)/7){
        int x = rand()%k;
        int y = rand()%(n-k);
        y += k;
        cout << "EDGE " << x << ' ' << y << endl;
        assert(x!=y);
        a[x][y]=a[y][x]='Y';

    }
    For(i,0,n){
        order.pb(i);
    }
    random_shuffle(ALL(order));
    cout << "{";
    For(i,0,n){
        int x = order[i];
        cout << P[x] ;
        if (i<n-1) cout << ','; 
    }
    cout << "}";
    cout << endl << "{"; 
    For(i,0,n){
        int x = order[i];
        For(j,0,n){
            int y = order[j];
            cout << a[x][y] ;

        }
        if (i<n-1) 
        cout <<"," ; 
        cout <<  endl;
        

    }
    cout << "}";


    

    kkkkkk
