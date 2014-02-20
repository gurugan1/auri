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
/*****************************************************************************/

struct StrIIRec{
    public:
    string recovstr(int n, int minInv, string minStr){
        string s = getstr(n);
        if (s>=minStr)
            return s;
        return minStr;

    }

};
