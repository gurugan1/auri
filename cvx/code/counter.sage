
def get_graph(n):
    f = open('output/ramsay%d.out'%n,'r')
    line = f.next()
    n,m = [int(x) for x in line.split()]
    G = graphs.EmptyGraph()
    for i in xrange(m):
        line = f.next()
        x,y = [int(x) for x in line.split()]
        G.add_edge(x,y)
    #G = G.complement()
    
    f.close()

    max_deg = 0
    for i in xrange(n):
        max_deg = max(max_deg,len(G.neighbors(i)))
    I = G.independent_set()
    print(n,max_deg,len(I))
    return G


for i in xrange(10,201,10):
    get_graph(i)
