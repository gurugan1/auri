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

struct BallsSeparating {
    int minOperations(vector <int> red, vector <int> green, vector <int> blue){
        int n = red.size(),R,G,B;
        R=G=B=0;
        For(i,0,n) R += red[i];
        For(i,0,n) G += green[i];
        For(i,0,n) B += blue[i];
        int ret = R+G+B;
        For(i,0,n) For(j,0,i) For(k,0,j){
           ret = min(ret,R-red[i]+G-green[j]+B-blue[i]); 
        }
        return ret;

    }
};
