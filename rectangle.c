#include <string.h>
const int maxn = 10;
int mem[1<<maxn][1<<maxn];
int deg[maxn];
int a[maxn][maxn];

int init(int n){
    memset(mem,0,sizeof(mem));
    For(i,0,n) deg[i]=0;
}

int add_edge(int x, int y){
    a[deg[x]++]=y; 
    a[deg[y]++]=x;

}
