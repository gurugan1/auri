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
#define ld long double
const int maxn = 50;

struct matrix{
    ld a[maxn][maxn];
    int n;
    matrix(){ CLR(a,0); n=0;}
    matrix operator+(const matrix &a1) const{
        matrix ret;
        ret.n = a1.n;
        For(i,0,a1.n) For(j,0,a1.n) ret.a[i][j]=a1.a[i][j]+a[i][j];
        return ret;
    }
    void operator*=(const matrix &a1) const{
        matrix ret;
        ret.n = a1.n;
        For(i,0,ret.n){
            For(j,0,ret.n) For(k,0,ret.n){
                ret.a[i][j]+= a[i][k]*a1.a[k][j];
            }
        }
        return ret;
    }
    matrix operator/(double k) const{
        matrix ret ;
        ret.n = n; For(i,0,n ) For(j,0,n) ret.a[i][j]=a[i][j]/k;
        return ret;
    }
    vector<ld> operator*(const vector<ld> &x) const{
        vector<ld> ret(n,0);
        For(i,0,n){
            For(j,0,n) ret[i]+= a[i][j]*x[j];
        }
        return ret;
    }
};

ld dot(vector<ld> &a, vector<ld> &b){
    ld ret=0;
    For(i,0,a.size()) ret+= a[i]*b[i];
    return ret;
}
vector<ld> make_vec(int k,int n){
    vector<ld> ret(n,k+1);
    For(i,0,n){
        ret[i] = min(ret[i],(ld)(i+1));
        ret[i] = min(ret[i],(ld)(n-i));
        ret[i] = min(ret[i],(ld)(n-k));
    }
    //For(i,0,n){
    //    ret[i]/=n-k;
    //}
    return ret;
}

matrix pow(const matrix &a, int k){
    matrix ret;
    if (k==1) return ret=a;
    ret = pow(a,k>>1); 
    ret = ret*ret;
    if (k&1) ret= ret*a;
    return ret;
}
void output(const matrix &a) {
    For(i,0,a.n) {
        For(j,0,a.n){
            cout << a.a[i][j] << ' ';
        }
        cout << endl;
    }

}
void output(const vector<ld> &a){
    For(i,0,a.size()) cout << a[i] << ' ' ;
    cout << endl;

}

struct TheSwapsDivOne{
    public:
       double find(vector <string> sequence, int k) {
           string s;
           For(i,0,sequence.size()) s+=sequence[i];
           int n = s.size();
           vector<ld> a(n); For(i,0,n) a[i]=s[i]-'0';
           matrix cur;
           matrix I; 
           cur.n = I.n = n; For(i,0,n) I.a[i][i]=1;
           int count=0;
           For(i,0,n){
               For(j,0,i){
                   matrix A = I;
                   swap(A.a[i][i],A.a[i][j]);
                   swap(A.a[j][j],A.a[j][i]);
                   cur = cur+A;
                   count++;
               }
           }
           output(cur);
           cur = cur/count;
           cur = pow(cur,k);
           vector<ld> a2 = cur *a;
           //output(a2);
           double ret=0;
           For(i,0,n){
               vector<ld> temp = make_vec(i,n);
               //cout << i << endl;
               //output(temp);
               ret+=dot(a2,temp);
           }
            count = n*(n+1);
            count/=2;
            ret/=count;
        return ret;

       }
};

struct TheNumberGameDivOne{


    string find(long long n){
        int k =0;
        while (n&1==0){
            n>>=1; k++;
        }
        if (k==0) return "Brus";
        if (n==1 && k%2==1){
            return "Brus";
        }
        if (k%2==0) return "John";
        return "Brus";

    }

};

int main(){ 
    //int a[1000]={0};
    //a[0]=0; a[1]=0; a[2]=0;
    //For(i,3,1000){
    //    a[i]=0;
    //    For(j,2,i){
    //        if (i%j==0&& a[i-j]==0){
    //            a[i]=1; break;
    //        }
    //    }
    //    printf("%d %d\n",i,a[i]);
    //}
    
    string s = "45797";
    vector<string> S ; S.pb(s);
    TheSwapsDivOne A;
    
    cout << A.find(S,1) << endl;
    return 0;}
