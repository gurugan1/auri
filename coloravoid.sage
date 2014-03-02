k = 3
n = k*k
L= []
for nu in xrange(1,k+1):
    for i in xrange(1,k+1):
        for j in xrange(1,k+1):
            L.append( ( (nu-1)*k+i, (i-1)*k + j, (nu-1)*k + j))

for i in xrange(len(L)):
    for j in xrange(i):
        k = sum( ( L[i][t] <=L[j][t] for t in xrange(3)))
        if (k>1):
            print("SHIT")
            print(i,j,L[i],L[j])

L2 = [( y,z+n,x) for (x,y,z) in L]


print(L2)
G = BipartiteGraph(None)
G.add_vertices(range(1,n+1),left=True)
G.add_vertices(range(n+1,2*n+1),right=True)

G.add_edges(L2)

col = {}
for i in xrange(1,n+1):
    col[i] = (i/n,1-i/n,1)
G.plot(color_by_label=True).show()
raw_input("{RESS ENTER")
