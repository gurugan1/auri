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

const int maxn = 100100;
char buf[maxn],word[maxn];
void process(vector<string> &ret){
    ret.clear();
    ret.pb(string(buf[0],1));
    bool dig=false;
    if (buf[0]>='0' && buf[0]<='9') dig=true;
    For(i,1,n){
        if (buf[i]>='0' && buf[i]<='9') {
            if (dig){
                ret.back() += buf[i];
            } else{
                ret.pb(string(buf[i],1));
            }
            dig=true;
        } else {
            if (dig){
                ret.pb(string(buf[i],1));
            } else {
                if (buf[i]=='#'){
                        if (ret.back()=='*') ret.back()='#'; else ret.back()='*';
                }
            }
            dig=false;
        }
    }
}

int find_next(const string &s, 

bool doit(int x, int y) {
    if (!isword(regex[x])){
        k = find_next(regex[x+1],y)
        return doit(x+1,k);
    } else{
        bool bad=false;
        For(i,0,regex[x].size()){
            if (regex[x][i]!=word[y+i])
                bad=true;
        }
        if (!bad) return doit(x+1,y+regex[x].size());
    }
}

vector<string> regex,rpar;
int main(){
    regex.reserve(maxn);
    rpar.reserve(maxn);
    for(int cas=1;;cas++){
        scanf("%s",&buf);
        n = strlen(buf);
        process(ret);
        rpar.resize(ret.size());
        rpar.back()=0;
        for(int i=(int)ret.size()-2;i>=0;i--){
            rpar[i]+=rpar[i+1];
            rpar[i]%=2;
        }
        for(int cas2=1;scanf("%s",word)!=-1 && ok(word);cas2++){
            m = strlen(word);
            printf("%d.%d. ",cas,cas2);
            if (doit(0,0))
                printf("match\n");
            else 
                printf("not\n");
        }
    }
    return 0;
}
