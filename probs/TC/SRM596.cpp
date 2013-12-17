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

#define For(i,a,b) for(int i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/

map<vector<int>,int> M;
struct IncrementAndDoubling {

    int getMin(vector <int> dA){
        int n = dA.size();
        vector<int> cur(n);
        queue< vector<int> > Q;
        
        Q.push(cur);
        M[cur]=0;
        while (!Q.empty()){
            vector<int> cur = Q.front(); Q.pop();
            int cost = M[cur];
            if (cur==dA) return cost;
            For(i,0,n){
                cur[i]++;
                if (cur[i]<dA[i] && M.count(cur)==0) {
                    M[cur]=cost+1;
                    Q.push(cur);
                }
                cur[i]--;
            }
            bool bad=false;
            For(i,0,n){
                cur[i]<<=1;
                if (cur[i]<dA[i]) {
                    bad=true;
                    break;
                }
            }
            if (!bad){
                M[cur]=cost+1;
                Q.push(cur);
            }
        }
        n=0; For(i,0,dA.size()) n+=dA[i];
        return n;

    }


};
