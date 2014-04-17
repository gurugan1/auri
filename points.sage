from sage.plot.plot3d.shapes2 import Line
n = 5
L = []
for k in xrange(n):
    for i in xrange(1,n+1):
        for j in xrange(1,n+1):
            L.append((i+k*n,j+k*n,(i-1)*n+j))

L2 = Line(L,corner_cutoff=0)
show(L2)
raw_input("ENTER")
for i in L:
    print(i)

print("DONE LIST L")
        
M= {}
for i  in xrange(len(L)):
    for j in xrange(len(L)):
        vec = (L[i][0]-L[j][0],L[i][1]-L[j][1],L[i][2]-L[j][2])
        M[vec] = M.get(vec,0) + 1

for i in xrange(1,len(L)):
    j = i-1
    vec = (L[i][0]-L[j][0],L[i][1]-L[j][1],L[i][2]-L[j][2])
    print(vec)
#
#a = M.items()
#a.sort(key=(lambda x: x[1]))
#for x in a:
#    print(x)

