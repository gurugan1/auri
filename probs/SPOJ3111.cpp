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
    scanf("%d%d",&n,&m);
    For(i,0,n) {
        scanf("%s",&buf[i]);
    }
    For(j,0,m){
        scanf("%d",&type[i]);
    }
    For(i,0,m){
        For(j,0,m){
            if (buf[type[i]][type[j]]=='C'){
                connect(in(i),out(j));
            } else {
                connect(out(i),in(j));
            }
        }
    }

    return 0;
}
