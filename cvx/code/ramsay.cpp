#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>


using namespace std;
#define MP make_pair
#define For(i,a,b) for(int i=a;i<b;i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pb push_back

typedef pair<int,int> pii;

const int maxn = 1500;
vector<pii> E;
int a[maxn][maxn];
int deg[maxn];


string getfilename(int d){
    stringstream ss;
    ss << "output/ramsay" << d << ".out";
    return ss.str();
}

int main(){
    srand(time(NULL));

    for (int n=10;n<=200;n+=10){
        
        E.clear(); 
        CLR(a,0);
        CLR(deg,0);
        For(i,0,n){
            For(j,0,i){
                E.push_back(MP(j,i));
            }
        }

        vector<pii> actE;

        while (!E.empty()){
            int cur = rand()%E.size();
            actE.pb(E[cur]);
            int x = E[cur].first;
            int y = E[cur].second;
            swap(E[cur],E[(int)E.size()-1]);
            E.pop_back();
            a[x][y]=a[y][x]=1;
            deg[x]++; deg[y]++;
            set<pii> rem;
            For(i,0,n){
                if (i==x || i==y) continue;
                if (a[x][i]) rem.insert(MP(min(i,y),max(i,y)));
                if (a[y][i]) rem.insert(MP(min(i,x),max(i,x)));
                if (a[x][i] && a[y][i]) cerr << "WTF " << i << ' ' << x << ' ' << y << endl;
            }
            vector<pii> newE;
            For(i,0,E.size()){
                if (rem.find(E[i]) != rem.end())
                    continue;
                newE.pb(E[i]);
            }
            E = newE;
            //cout << E.size() << endl;
        }
        int maxdeg=0;
        For(i,0,n) maxdeg = max(maxdeg,deg[i]);
        cout << "number of vertices and their max degree " << n << ',' << maxdeg <<endl;
        string filename = getfilename(n);
        FILE *f = fopen(filename.c_str(),"w");
        fprintf(f,"%d %d\n",n,actE.size());
        For(i,0,actE.size()){
            fprintf(f,"%d %d\n",actE[i].first,actE[i].second);
        }
        fclose(f);
    }

    return 0;
}
