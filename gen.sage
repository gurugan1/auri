from subprocess import call
import os

def generate_ineq(G):
    f = open("current.ieq","w")
    n = len(G.vertices())
    f.write("DIM = %d\n"%n)
    f.write("\nVALID\n")
    f.write(" ".join(["0" for x in xrange(n)]) + "\n")
    f.write("\nLOWER_BOUNDS\n")
    f.write(" ".join(["0" for x in xrange(n)])+ "\n")
    f.write("\nUPPER_BOUNDS\n")
    f.write(" ".join(["1" for x in xrange(n)])+ "\n")
    f.write("\nINEQUALITIES_SECTION\n\n")
    for cliq in G.cliques_maximal():
        cur = "+".join([" x%d "%(v+1) for v in cliq]) + " <= 1"
        f.write(cur+"\n")
    f.write("\nEND\n")
    f.close()


def check(filename):
    f= open(filename,"r")
    for line in f:
        if line.find("CONV_SECTION") != -1:
            break

    for line in f:
        if line.find("END")!=-1:
            break
        k = line.find(")")
        line = line[k+1:]

        good = False
        for num in line.split():
            if num.find("/") != -1:
                x,y = [ int(x) for x in num.split("/")]
                if (x*3>=y):
                    good = True
                    break;
            else:
                good = True
                break
        if (not good):
            if (len(line.split())==0):
                continue
            print("LINE IS ",line)
            return False
    return True 


def generate_all( n, output_filename):
    C9 = graphs.CycleGraph(9).complement()
    output = open(output_filename,"w")
    count=0
    for K in graphs.nauty_geng(str(n)+" -c -d 3 "):
        if (K.subgraph_search(C9) is not None):
            continue
        #K = graphs.CycleGraph(9).complement()
        count+=1
        generate_ineq(K)
        if os.path.isfile("current.ieq.poi"):
            os.remove("current.ieq.poi")
        call(["traf current.ieq"],shell=True)
        if not check("current.ieq.poi"):
            print(K.vertices())
            print(K.edges(labels=None))
            K.show()
            raw_input("PAUSE")
        

    print("--------Looks like there are no counter examples after trying %d"%count)


if __name__=="__main__":
    C = graphs.CycleGraph(9)
    generate_all(10,"output.txt")
    print(check("current.ieq.poi"))
    #n = 7 
    #G = graphs.CompleteGraph(n)
    #for i in xrange(n):
    #    G.add_edge(i,i+n)
    #    G.add_edge(i+n,2*n)
    #G.show()
    #raw_input("PRESS ENTER")
    #generate_ineq(G)


