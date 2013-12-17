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

struct FoxAndChess{

    public:
    string ableToMove(string b, string t){
        string sB,sT;
        vector<int> L[2],R[2];
        For(i,0,b.size()){
            if (b[i]=='L') L[0].pb(i);
            if (b[i]=='R') R[0].pb(i);
            if (b[i]!='.') sB+=b[i];
        }
        For(i,0,t.size()){
            if (t[i]=='L') L[1].pb(i);
            if (t[i]=='R') R[1].pb(i);
            if (t[i]!='.') sT+=t[i];
        }
        bool bad=(sB==sT);
        For(i,0,L[0].size()){
            if (L[1][i]>L[0][i]) bad=true;
            if (R[1][i]<R[0][i]) bad=true;
        }
        if (bad) return "Impossible";
        return "Possible";
    }

};
