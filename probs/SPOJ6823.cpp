#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>

using namespace std;
const int maxn=5001;
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define FOREACH(V,it) for(auto it : V)
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))



struct edge{
    int x,y,w;
    edge(int x1, int y1, int w1):x(x1),y(y1),w(w1){}
};



string adds(const string &x,const string &y) {
    string ret = x;

    For(i,0,y.size()){
        if (ret.size()<=i) ret+="0";
        int carry = (ret[i]+y[i]-'0'-'0')/10;
        ret[i]=((ret[i]+y[i]-'0'-'0')%10)+'0';
        if (carry>0 && ret.size()==i+1) ret+="0";
        ret[i+1]+=carry;
    }
    //cout << "ADDING " << x << '+' << y << ' '<<  ret << endl;
    return ret;
}
string pow2[maxn];

struct bigint{
    vector<int> a;
    void add(int x){
        //cerr << "ADD CALLED" << x << ' '<< a.size() << endl;
        if (a.size()<=x){
            a.resize(x+1);
        }
        //cerr << x << " JUST RESIZED " << endl;
        a[x]++;
        while (x<a.size()&& a[x]>1){
            a[x]=0;
            if (a.size()==x+1) a.pb(0);
            a[++x]+=1;
        }
        //cerr << "ADD FINISHED" << endl;
    }



    string to_string() const {
        string ret="";
        For(i,0,a.size()){
            if (a[i]==1){
                ret=adds(ret,pow2[i]);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;

    }

};

bool operator<(const bigint &X, const bigint &Y){

    
    if (X.a.empty() || X.a.size()!=Y.a.size()) return X.a.size()<Y.a.size();
    int k = X.a.size()-1;
    while (k>0 && X.a[k]==Y.a[k]){
        k--;
    }
   bool ret =X.a[k]<Y.a[k];
   cout << X.to_string() << ' ' << Y.to_string() << ' ' << ret << endl;
   return ret;
}


bigint operator+(const bigint &x, const bigint &y){
    bigint ret;
    ret.a.resize(max(x.a.size(),y.a.size()));
    For(i,0,ret.a.size()) {
        if (x.a.size()>i)
            ret.a[i]+=x.a[i];

        if (y.a.size()>i)
            ret.a[i]+=y.a[i];
        if (ret.a[i]>2){
            if (i+1>=ret.a.size()) ret.a.push_back(0);
            ret.a[i+1] += ret.a[i]/2;
            ret.a[i] = ret.a[i]%2;
        }
    }
    return ret;
}

bigint operator-(const bigint &x, const bigint &y){
    bigint ret=x;
    for(int i=y.a.size()-1;i>=0;i--){
        ret.a[i]-=y.a[i];
    }
    For(i,0,ret.a.size()){
        if (ret.a[i]>=0) continue;
        int k = (ret.a[i]-1)/2;
        ret.a[i+1]-=k;
        ret.a[i]+=2*k;
    }
    while (ret.a.size()>0 && ret.a.back()==0) ret.a.pop_back();
    return ret;
}

int prev[maxn],event[maxn],a[maxn];
vector<edge> V;
bigint temp[maxn];

struct comp{
    bool operator()(const int a, const int b){

        return temp[a]<temp[b];
    }
};
int n;


set<int> S;


int main(){
    pow2[0]="1";
    for(int i=1;i<maxn;i++)
        pow2[i]=adds(pow2[i-1],pow2[i-1]);
    scanf("%d",&n);
    char buf[1000];
    CLR(prev,-1);
    
    For(i,0,n) {
        scanf("%s%d",buf,&a[i]);
        
        string cur= buf;
        int win = cur.find("win");
        //cout << win << ' '<< cur << endl;
        if (win!=-1){
            prev[a[i]]=i;
            a[i]*=-1;
        } else{
            if (prev[a[i]]!=-1){
                //cout << "EVENT AT " << prev[a[i]] << ' '<< i <<" with value " << a[i] << endl;
                event[i]=event[prev[a[i]]]=prev[a[i]];
            }
        }
    }
    bigint ret; 
    For(i,0,n){
        if (event[i]==0) continue;
        if (event[i]==i){
            //cerr << "INSERTING " << i << endl;
            S.insert(i);
            //cerr << "DONE INSERTING" << i << " with size " << S.size() << endl;

            
        }
        if (event[i]!=i){
            int k = event[i];
            //cerr << "GOING TO DEL" << event[i] << endl;
            bigint cur; cur.add(abs(a[k]));
            //cerr << "WITH VAL" << cur.to_string() << endl;
            if (temp[k]<cur){
                bigint dif = cur-temp[k];
                //cout << "DIF WAS " << dif.to_string() << endl;
                ret= ret + dif;
                //cout << S.size() << "SET S = ";
                for(set<int>::iterator it = S.begin();it!=S.end();it++){
                    //cout << *it << ' ';
                    temp[*it]= temp[*it] + dif;
                }
                //cout << endl;
            }
            S.erase(k);
        }
    }
    printf("%s\n",ret.to_string().c_str());
    return 0;
}
