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

int t,n;
int a[499][499];
char buf[5505];
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        For(i,0,n){
            scanf("%s",buf);
            For(j,0,n)
                a[i][j]=(buf[j]=='1');
        }

        For(i,0,n){
            int pivot=i; 
            For(j,i,n){
                if (a[j][i]==1){
                    pivot=j;
                }
            }
            For(k,0,n) swap(a[i][k],a[pivot][k]);
            For(j,i+1,n){
                if (!a[j][i]) continue;
                For(k,i,n){
                    a[j][k]^=a[i][k];
                }
            }
        }
        bool k=1;

        For(i,0,n) k&=a[i][i];
        if (k) printf("Odd\n"); else printf("Even\n");


    }
    return 0;
}
