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

int main(){ 
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&m);
        For(i,0,n) scanf("%s",&buf[i]);
        For(i,0,n) For(j,0,n) if (buf[i][j]=='N') a[i][j]=inf; else a[i][j]=1;
        For(i,0,n) For(j,0,n) For(k,0,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        
        int maxx =-1;

    }
    return 0;
}
