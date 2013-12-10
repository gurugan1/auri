n = int(raw_input())
val = [0 for i in  xrange(n)]
tot = [0 for i in  xrange(n)]
event = {}
prev = {}
for i in xrange(n):
    line = raw_input().split()
    val[i]= 2**int(line[1])
    if (line[0]=="win") :
        prev[val[i]]=i
    else:
        if (val[i] in prev):
            #print(prev[val[i]],i)
            event[prev[val[i]]]=event[i]=prev[val[i]]

S = set()
ret=0 
for i in xrange(n):
    if (i not in event):
        continue
    if (i in event and event[i]==i):
        #print("ADDING %d"%i)
        S.add(i)
        continue

    k = event[i]
    if (tot[k]< val[k]):
        dif = val[k]-tot[k]
        ret+= dif
        for j in S:
            tot[j]+= dif
    #print("REMOVE %d %d"%(k,i))
    try:
        S.remove(k)
    except KeyError:
        assert False
print(ret)




