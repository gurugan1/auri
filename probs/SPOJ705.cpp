#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for(int i=0;i<n;i++)
const int N = 50500;

// ========== Suffix Array ============

int n,f[N],p[N],q[N],L[N+N];
bool b[N];
int lcp(int i,int j){
	if(i>j)swap(i,j);
	int res=n;
	for(i+=n,j+=n-1;i<=j;i=i+1>>1,j=j-1>>1)
		res=min(res,min(L[i],L[j]));
	return res;
}
void setlcp(int i,int v){ for(i+=n;L[i]>v;i/=2)L[i]=v; }
bool scmp(int x,int y){ return f[x]<f[y]; }
void suff_sort(){
	REP(i,n)b[i]=0,p[i]=i; b[n]=true;
	for(int i,j,x,h=0;h<n;){
		for(i=j=0;j<=n;++j)if(b[j])sort(p+i,p+j,scmp),i=j;
		for(i=0,j=1;j<n;++i,++j)b[j]|=f[p[i]]!=f[p[j]];
		for(h=h?h*2:1,i=x=0;i<n;f[j]=x+=b[i++])if((j=p[i]-h)<0)j+=n;
	}
}
void suff_sort_withlcp(){
	REP(i,n)b[i]=0,p[i]=i,L[i+1]=L[i+n]=n; b[n]=true;
	for(int i,j,x,y,h=0;h<n;){
		for(i=j=0;j<=n;++j)if(b[j])sort(p+i,p+j,scmp),i=j;
		REP(i,n)q[p[i]]=i;
		for(i=0,j=1;j<n;++i,++j)
			if(!b[j] && f[p[i]]!=f[p[j]])
				b[j]=true,x=p[i]+h,y=p[j]+h,
				setlcp(i,h?h+lcp(q[x<n?x:x-n],q[y<n?y:y-n]):0);
		for(h=h?h*2:1,i=x=0;i<n;f[j]=x+=b[i++])if((j=p[i]-h)<0)j+=n;
	}
}

int t=0;
int main(){
    char buf[N];
    scanf("%d",&t);
    while (t--){
        CLR(p,0); CLR(f,0); CLR(L,0); CLR(q,0); CLR(b,0);
        scanf("%s",buf); n = strlen(buf);
        cout << buf << ' ' << n << endl;
        For(i,0,n) f[i]=buf[i];
        //n++; f[n-1]=-1;
        suff_sort_withlcp();
        long long ret=n-p[0];
        For(i,1,n){
            ret+=n-p[i]-lcp(p[i-1],p[i]);
            printf("%d %d %d\n",p[i],p[i-1],lcp(p[i-1],p[i]));
        }
        printf("%lld\n",ret);
    }
    return 0;
}
