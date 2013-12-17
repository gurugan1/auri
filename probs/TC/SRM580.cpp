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
#define MP make_pair
/*****************************************************************************/


const int INF=1000000999;
typedef pair<int,int> pii;

struct ShoutterDiv1{
    public:
    int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1){
        string S1000,S100,S10,S1,T1,T10,T100,T1000;
        For(i,0,s1000.size()) S1000+=s1000[i];
        For(i,0,s100.size()) S100+=s100[i];
        For(i,0,s10.size()) S10+=s10[i];
        For(i,0,s1.size()) S1+=s1[i];
        For(i,0,t1.size()) T1+=s1[i];
        For(i,0,t10.size()) T10+=t10[i];
        For(i,0,t100.size()) T100+=t100[i];
        For(i,0,t1000.size()) T1000+=t1000[i];
        For(i,0,S1.size()){
            s[i].first=(S1000[i]-'0')*1000+(S100[i]-'0')*100+(S10[i]-'0')*10+(S1[i]-'0');
            s[i].second=i;
        }
        For(i,0,T1.size()){
            t[i].first=(T1000[i]-'0')*1000+(T100[i]-'0')*100+(T10[i]-'0')*10+(T1[i]-'0');
            t[i].second = i;
        }



    }

};

struct EelAndRabbit{
    public:

    int uni(set<int> a,set<int> &b){
        for(set<int>::iterator si=b.begin();si!=b.end();si++){
            a.insert(*si);
        }
        return a.size();
    }
    int getmax(vector <int> l, vector <int> t){
        int n= l.size();
        vector<pii> start,end;
        vector< set<int> > V;
        For(i,0,n){
            start.pb(MP(-t[i],i));
            end.pb(MP(-t[i]+l[i],i));
        }
        start.pb(MP(INF,-1)); end.pb(MP(INF,-1));
        int c1=0,c2=0;
        set<int> total;
        while (true){
            int cur = min(start[c1].first,end[c2].first);
            if (cur==INF) break;
            while (start[c1].first==cur){
                total.insert(start[c1].second);
                c1++;
            }
            V.pb(total);
            while (end[c2].first==cur){
                total.erase(end[c2].second);
                c2++;
            }
        }
        int best=0;
        For(i,0,V.size()){
            For(j,0,i){
                int k = uni(V[i],V[j]);
                best=max(best,k);

            }

        }
        return best;
    }

};

int main(){ 
    
    return 0;}
