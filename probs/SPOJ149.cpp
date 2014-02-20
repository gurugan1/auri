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
#include <cmath>
#include <stack>

using namespace std;

#define For(i,a,b) for(typeof(a) i =(a);i<(b);i++)
#define ll long long
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(V) V.begin(),V.end()
/*****************************************************************************/

const int maxn = 100100;
struct point{
    int x,y;
    point(int x1=0, int y1=0):x(x1),y(y1){}

    friend ostream& operator<< (ostream &out, const point &a){
        out << '(' << a.x << ',' << a.y << ')' ;
        return out; 
    }
} ;
point p[maxn],a[maxn],p2[maxn];

bool operator<(const point &a, const point &b){
    return atan2(b.y,b.x) < atan2(a.y,a.x);
}

int sign(const point &a, const point &b){
    int ret = cr(a,b);
    if (ret>0) return 1;
    if (ret<0) return -1;
    return 0;
}
int cr (const point &a, const point &b){
   return a.x*b.y - a.y*b.x;
}

bool inside(const point &a, const point &b, const point &x){
    int ar = abs(cr(a,b));
    //cout << a << ' ' << b << ' ' << x << ' '  << ar <<  ' ' << cr(a,x) << ' ' << cr(b,x) << endl;
    if (abs(cr(a,b)) == abs(cr(a,x)) + abs(cr(x,b))){
        if (ar==0){
            return hypot(x.x,x.y) < max(hypot(a.x,a.y),hypot(b.x,b.y));
        } else return true;
    }
    return false;
}

void normalize(point a[maxn],int n){
    For(i,0,n){
        int k = sign(a[i],a[(i+1)%n]);
        if (k>0)  break;
        if (k<0) { reverse(a,a+n); break;}
    }
    int temp = 0;
    double best = atan2(a[0].y,a[0].x);
    For(i,1,n){
        double cur = atan2(a[i].y,a[i].x);
        if (cur>best) { temp=i; best=cur;}
    }
    rotate(a,a+temp,a+n);
    return ;
}
int norm2(point p[maxn],int m){

        int m2 = 0;
        For(i,0,m) 
            if (!(p[i].x==0 && p[i].y==0)){
                p2[m++]=p[i];
            } else { ret++; }
        For(i,0,m2) p[i]=p2[i]; m=m2;
        sort(p,p+m); reverse(p,p+m);
}


int main(){
    int t,n,m;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&m);
        For(i,0,n){
            scanf("%d%d",&a[i].x,&a[i].y);
        }

        For(i,0,m){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        int ret=0;
        normalize(a,n);
        int j=0 ;
        For(i,0,m){
            double ang = atan2(p[i].y,p[i].x);

            while (true){
                double a1 = atan2(a[j].y,a[j].x),a2= atan2(a[(j+1)%n].y,a[(j+1)%n].x);
                if (j==n-1){

                } else {
                    if (a1>= ang && ang>=a2){
                        break;
                    } else {

                    }
                }
            }   
            if (inside(a[j],a[(j+1)%n],p[i])) ret++;
        }
        printf("%d\n",ret);
    }
    return 0;
}
