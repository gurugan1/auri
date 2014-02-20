#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

//============= FFT ============
#define REP(i,n) for(int i=0;i<n;i++)
typedef vector<int> vi;

typedef complex<double> cd;
cd W[1<<18];
template<class S>void fft(S p,cd*y,int n,int k=1){
	if(n>1){ cd q;
		fft(p,y,n/=2,k*2),fft(p+k,y+n,n,k*2);
		for(int i=0,j=0;i<n;++i,j+=k)
			y[i+n]=y[i]-(q=y[i+n]*W[j]),y[i]+=q;
	}else *y=*p;
}
vi mul(vector<int> a,vector<int> b){
	int n=a.size()+b.size();
	for(;n&n-1;++n);
	a.resize(n),b.resize(n);
	vector<cd> Y(n),Z(n);
	REP(i,n)W[i]=polar(1.,2*i*M_PI/n);
	fft(&a[0],&Y[0],n),fft(&b[0],&Z[0],n);
	REP(i,n)Z[i]*=Y[i],W[i]=cd(real(W[i]),-imag(W[i]));
	fft(&Z[0],&Y[0],n);
	REP(i,n)a[i]=(real(Y[i])+0.5)/n;
	for(;a.size() && !a.back();a.erase(a.end()-1));
	return a;
}

char buf[10101];
int main(){
    int t,n;
    scanf("%d",&t);
    while (t--){
        int n;
        vi a,b;
        scanf("%s",buf); n = strlen(buf);
        for(int i=n-1;i>=0;i--) a.push_back(buf[i]-'0');
        scanf("%s",buf); n = strlen(buf);
        for(int i=n-1;i>=0;i--) b.push_back(buf[i]-'0');
        vi ret= mul(a,b);
        REP(i,ret.size()){
            if (ret[i]>=10 && ret.size()==i+1) ret.push_back(0);
            ret[i+1]+=ret[i]/10;
            ret[i]%=10;
        }
        if (ret.size()==0) ret.push_back(0);
        reverse(ret.begin(),ret.end());
        REP(i,ret.size()){
            putchar(ret[i]+'0');
        }
        printf("\n");

        

    }
    return 0;
}
