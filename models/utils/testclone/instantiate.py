import sys,pickle,getopt
from poplib import *
if __name__=="__main__":
    try:
        setDebugValue(0)
    except:setDebug(0)
    optlist, args = getopt.getopt(sys.argv[1:],"r")
    for o in optlist:
        o,v=o
        if o=="-r":
            setReplaceId()
            print "USING '",getReplaceId(), "' AS ID PREFIX"
    try:
        popfile=args[0]
        zerofile=args[1]
    except:
        print "usage:\n %s [-r]popfile 0.xml"%sys.argv[0]
        print "OPTIONS: \n  -r : Prefix agent IDs with string 'REPLACE_ID_'"
        sys.exit()
    try:
        numthreads=int(sys.argv[3])
        print "WILL USE NUMBER OF THREADS:",numthreads
    except:
        try:
            if MULTIPROC:
                import multiprocessing
                numthreads=multiprocessing.cpu_count()
            else:
                numthreads=0
        except:
            numthreads=0
    pop=pickle.load(open(popfile,"rb"))
    globalSetNumRegions(pop.numregions)
    global popguinumregions
    popguinumregions=pop.numregions
    print "popguinumregions",popguinumregions
    try:
        pop.instantiateMEMEFF(open(zerofile,"w"),numthreads=numthreads)
    except:
        pop.instantiate(open(zerofile,"w"))
