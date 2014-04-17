label = {}
def count_len(x, mask, label):



n = 4
L = []
count = 0
for i in xrange(n):
    for j in xrange(i):
        L.append( (i,j))
        label[(i,j)] = count;
        count+=1


ret=0
for x in Permutations(m).list(): 
    ret = max(ret,count_len(x))

print(n,ret)
