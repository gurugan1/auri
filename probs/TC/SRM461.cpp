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
#include <cmath>

using namespace std;

#define For(i,a,b) for(typeof(a) i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/


struct ColoringRectangle{
    public:
    int chooseDisks(int width, int height, vector <int> red, vector <int> blue){
        vector< int > a[2];
        sort(ALL(red)); sort(ALL(blue));
 
        int ans=-1;
        For(trial,0,2){
        	a[0]=red;
        	a[1]=blue;
            int pos=trial;
            int ret=0;
            double w = width;
            double h = height;
            while (w>=0){
                if (a[pos].empty()) { ret=-1; break;}
                ll x = (long long) a[pos].back(); a[pos].pop_back(); pos^=1; 
                if (x<h) { ret=-1; break;}
                w -= sqrt((double)(x*x)-(double)(h*h));
                    ret++;
                printf("used %lld with width %lf\n",x,w);
            }
            printf(" done with %d\n",ret);
            if (ans==-1 || (ret>0 && ret<ans)) ans=ret;
        }

        return ans;
    }
};
