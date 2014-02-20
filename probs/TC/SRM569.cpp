#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <utility>
#include <algorithm>
#include <iomanip>
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
 
 
struct TheJediTest{
    public:
    ll temp[55];
    bool ok[55];
    ll us[55];
    int minimumSupervisors(vector <int> a, int K){
        int n = a.size();
        int ret=0;
        For(i,0,n) ret+=(a[i]+K-1)/K;
        CLR(temp,0); 
        For(i,0,(1<<n)){
            CLR(ok,0);
            For(j,0,n){
                if (i&(1<<j)){
                    ok[j]=true;
                }
            }
            CLR(temp,0);
            bool bad=false;
            For(j,0,n){
                temp[j]=a[j];
                if (a[j]>0 && !ok[j] && (j==0 || !ok[j-1]) && (j==n-1 || !ok[j+1])){
                        bad=true;break;
                }
            }
            if (bad) continue;
          
      		CLR(us,0);
            int cur=0;
            For(j,0,n){
                if (!ok[j]) {
           			temp[j+1]+=temp[j];
                    temp[j]=0;
                 	us[j]=0;
                    continue;
                }
                int tt = temp[j]/K;
                cur+=temp[j]/K;
                us[j]=(temp[j]/K);
                temp[j]%=K;
                if (!ok[j+1]){
                    if (!ok[j+2]){
                        temp[j]+=temp[j+1];
                        cur += (temp[j]+K-1)/K;
                        us[j]+=(temp[j]+K-1)/K;
                        temp[j+1]=0;
                        temp[j]=0;
                    } else{
                        if(temp[j]+temp[j+1]>K){
                            cur += (temp[j]+temp[j+1])/K;
                            us[j] += (temp[j]+temp[j+1])/K;
                            temp[j+1]=(temp[j]+temp[j+1])%K;
                            temp[j]=0;
                        } else{
                          temp[j]+=temp[j+1];
                          cur+=(temp[j]+K-1)/K;
                          us[j]+=(temp[j]+K-1)/K;
                          temp[j+1]=0;
                          temp[j]=0;
                        }
                    }
                } else{
                  if (tt==0) cur+=1,us[j]+=1; 
                  temp[j+1]+=temp[j];
                  temp[j]=0;
                }
               
              //  cout <<  cur << ':' << temp[j] << ' ';
            }
            if (cur<=15){
            	cout << i << ' ';
            	For(j,0,n) cout << /*ok[j] << ':' <<*/ us[j] << '|' << setprecision(2) <<  (double)a[j]/K << ' '; cout << "---" << cur << endl;
            	}
           // cout << cur << endl;
            ret=min(ret,cur);
            
        }
        return ret;
 
    }
 
};

struct TheDevice{
    public:
    int minimumAdditional(vector <string> p){
        int m  = p[0].size(),n=p.size();
        int ret=0;
        For(i,0,m){
            int c0=0,c1=0;
            For(j,0,n){
                if (p[j][i]=='0')c0++;
                if (p[j][i]=='1') c1++;
            }
            cout << c0 << ' ' << c1 << endl;
            if (c0==0&& c1==0) ret=max(ret,3);
            if (c0==0 && c1==1) ret = max(ret,2);
            if (c0==0 && c1>=2) ret =max(ret,1);
            if (c0==1 && c1==0) ret=max(ret,2);
            if (c0>=1 && c1>=2) ret=max(ret,0);
            if (c0==1 && c1==1) ret=max(ret,1);
            if (c0>=2 && c1==0) ret=max(ret,2);
            if (c0>=2 && c1==1) ret=max(ret,1);
        }

        return ret;
    }
};

int main(){

    //TheDevice A;
    //vector<string> p; 
    //p.pb("0"); p.pb("0"); p.pb("0"); p.pb("0");
    //cout << A.minimumAdditional(p) << endl;

    const int a [] = 	{73209352, 3853163, 12325606, 43151646, 91914371, 91376752, 79739292, 60770296, 53858132, 44498231, 95106691, 80633237, 6027229, 50126526, 45338262, 1890363, 96883047, 22963717, 19496893};
    const int K = 66756408;
    vector<int> temp;
    For(i,0,19) temp.pb(a[i]);
    TheJediTest B;
    cout << B.minimumSupervisors(temp,K) << endl;

    return 0;
}
