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
#define CLR(a,x) memset(a,x,sizeof(a))
/*****************************************************************************/
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
bool used[100][100];
struct RotatingBot{

    bool valid (int cx, int cy, int maxx, int minx, int maxy, int miny){
        if (used[cx][cy]) return 0;
        if (!(cx >=minx && cx <=maxx && cy >= miny && cy <= maxy))
            return 0;
        return 1; 
    }
    int minArea(vector <int> moves){
        int dir = 0;
        int maxx,minx,maxy,miny,cx,cy;

        maxx=minx=maxy=miny=cx=cy=0;
        For(i,0,moves.size()){
            int nx,ny;
            nx = cx+moves[i]*dx[dir];
            ny = cy+moves[i]*dy[dir];
            maxx = max(maxx,nx);
            maxy = max(maxy,ny);
            minx = min(minx, nx);
            miny = min(miny, ny);
            cx = nx; cy=ny;
            dir = (dir+1)%4;
        }
        CLR(used,0);
        cx = 0, cy=0;
        For(i,0,moves.size()){
            For(j,0,moves[i]){
                cx += dx[dir]; cy += dy[dir];
                if (valid(cx,cy,maxx,minx, maxy,miny)){
                    used[cx][cy]=1; 
                }
                else {
                    return -1;
                }
            }
            if (i<moves.size()-1 && valid(cx+dx[dir],cy+dy[dir],maxx,minx,maxy,miny))
                return -1;
            dir += 1;
            dir%=4;
        }
        return (maxx-minx)*(maxy-miny);
    }
};

int main(){ return 0;}
