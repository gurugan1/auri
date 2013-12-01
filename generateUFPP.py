import random
from rect import Rect


def getmin( hei, a, b):
    ret=hei[b]
    for i in xrange(a,b):
        ret = min(ret,hei[i])
    return ret




def generate_random( n = 0):
    if (n==0):
        n = random.randint(10,100);
    hei = [random.randint(5,2*n) for i in xrange(2*n)]
    L = []
    for i in xrange(n):
        st = random.randint(1,2*n-2)-1
        en = random.randint(st+1,2*n)-1
        
        if (st>en):
            st,en= en,st
        top = getmin(hei,st,en)
        bottom = top - random.randint(1,top)
        L.append(Rect(st,bottom,en,top,random.randint(1,2*n)))
    print(len(L))
    return L

if __name__== "__main__":
    generate_random(0)

