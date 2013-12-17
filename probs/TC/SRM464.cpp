#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
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

struct ColorfulStrings{
    bool ok(string x){
        set<long long> S;
        For(i,0,x.size()){
            ll temp =1;
            For(j,0,i+1){
                temp *= x[j]-'0';
            }
            if (S.count(temp)>0 )
                return 0;
            S.insert(temp);
        }
        return 1;
    }

    string getKth(int n, int k){
        vector<string> cur;
        For(i,0,10){
            string temp="0";
            temp[0]+=i;
            cur.pb(temp);
        }
        For(siz,1,n){
            vector<string> next;
            For(i,0,cur.size()){
                For(j,2,10){
                    string temp = cur[i];
                    temp += (char)('0'+j);
                    cout << temp << ' ' << ok(temp) << endl;
                    if (ok(temp)) next.pb(temp);
                }

            }
            cur = next;
        }
        if (k>=cur.size()) return "";
        return cur[k-1];
    }
};

int main(){ return 0;}


