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

def intersect(E):
    def test(A,B):
        if (len(A&B)>0 and len(A&B)<len(A)):
            return 1
        return 0

    A =  [[ test(edge,edge2) for edge2 in E] for edge in E ]
    for row in A:
        print(','.join(str(x) for x in row))



class equation:
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0
        self.an = 0
        self.bn = 0
        self.cn = 0
        self.ans = 0


    def __str__(self):
        return "%d*x_%d + %d*x_%d + %d*x_%d = %d"%(self.a,self.an,self.b,self.bn,self.c,self.cn,self.ans)

def get_new_equations(q,n):
    A = equation()
    A.ans = random.randint(0,q-1)
    A.a  = random.randint(1,q-1)
    A.b  = random.randint(1,q-1)
    A.c  = random.randint(1,q-1)

    A.an,A.bn,A.cn = random.sample(xrange(n),3)
    return A 


def get_graph(E,n,q,t):
    total = dict.fromkeys(xrange(n),0);


    D = [get_disperser(q,t,token) for token in xrange(n)]

    ret = []
    for (num,e1) in enumerate(E):
        for xa in GF(q):
            for xb in GF(q):
                newedge = set()
                xc = mod((e1.ans - e1.a*xa - e1.b*xb)*inverse_mod(e1.c,q),q)
                #print(e1.an,xa,total[e1.an])
                newedge |= D[e1.an][xa][total[e1.an]];
                #print(e1.bn,xb,total[e1.bn])
                newedge |=  D[e1.bn][xb][total[e1.bn]];
                newedge |=  D[e1.cn][xc][total[e1.cn]];
                ret.append(newedge)
        total[e1.an] = total.get(e1.an,0) + 1
        total[e1.bn] = total.get(e1.bn,0) + 1
        total[e1.cn] = total.get(e1.cn,0) + 1
    return ret




def construct_random_set(q,n,t):
    E = []
    count = dict()
    for x in xrange(n):
        count[x]=0
    fails = 0
    while (len(E)<5*n):
        cur = get_new_equations(q,n)
        fails +=1 
        if (count[cur.an] < t-1) and (count[cur.bn]<t-1) and (count[cur.cn]<t-1):
            count[cur.an]+=1
            count[cur.bn]+=1
            count[cur.cn]+=1
            E.append(cur)
            fails = 0
        if (fails >100):
            break

    return E


def max_sat(E,q,n):
    A = range(n)
    best = 0
    for i in xrange(q**n):
        cur = i
        for j in xrange(n):
            A[j]=mod(cur,q)
            cur=int(cur/q)
        cur = 0
        for e in E:
            if (mod(A[e.an]*e.a + A[e.bn]*e.b + A[e.cn]*e.c,q) == e.ans):
                cur+=1
        best = max(best,cur)
    print("MAx satisfiable is %d",best)
    return best



        

        

def main():
    q = 3 
    n = 12 
    t = 5 
    E = construct_random_set(q,n,t)
    for x in E:
        print(x)

    H = get_graph(E,n,q,t)
    #print(len(H),len(E))
    #for edge in H: 
    #    print(",".join("%d-%d-%d"%(a,b,c) for a,b,c in edge))
    max_sat(E,q,n)
    intersect(H)


if __name__ == "__main__":
    main()








            






            
            


