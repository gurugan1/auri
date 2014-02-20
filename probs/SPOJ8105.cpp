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


int main(){
    scanf("%d",&n);
    For(i,0,n){
        scanf("%d.%d %d.%d",&x1,&x2,&y1,&y2);
        a[i].x=  (ll)x1*1000+x2;
        a[i].y= (ll)y1*1000+y2;
        a[i].ind = i;
    }
    sort(a,a+n);
    For(i,0,n){
        ll tot = dot(a[i],a[i]);
        while (!cur.empty() && dot(a[i],cur.back())< tot){
            cur.pop_back();
        }
        cur.push_back(tot);
    }


    return 0;
}
