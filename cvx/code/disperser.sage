import random
from math import log


def get_disperser(q,t,token):
    d = int(4*q*q*log(q)/t + 12*q*(1+log(q))+1)
    St = Permutations(t)
    Pi = [ [ St.random_element() for i2 in xrange(d)] for i1 in xrange(q)]
    def get_edge(i,j):
        return set([(Pi[j][k][i],k,token) for k in xrange(t)])

    E = [ [get_edge(i,j) for i in xrange(t)] for j in xrange(q)]

    return E

def M(E):
    def test(A,B):
        if (x==y):
            return 0
        if (len(x&y)>0):
            return 1
        return 0

    A =  [[ test(x,y) for y in E] for x in E]


class equation:
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0
        self.ans = 0


def get_graph(E):

    total = dict();
    for e1 in E:
        total[e1.a] = total.get(e1.a,0) + 1;
        total[e1.b] = total.get(e1.b,0) + 1;
        total[e1.c] = total.get(e1.c,0) + 1;
        print(max(total[e1.a],total[e1.b],total[e1.c]))

    D = [get_disperser(q,t,t) for t in xrange(E.n)]

    ret = []
    for (num,e1) in enumerate(E):
        for xa in GF(q):
            for xb in GF(q):
                newedge = [] 
                xc = (e1.ans - e1.a*xa + e1*b*xb)/e.c;
                newedge.append( D[e1.a][xa][num]);
                newedge.append( D[e1.b][xb][num]);
                newedge.append( D[e1.c][xc][num]);
                ret.append(newedge)
    return ret











            






            
            


