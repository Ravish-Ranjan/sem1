import networkx as nx
from shortestPath import shortestPathsNeg

def calcCloseness(G:nx.Graph):
    nodes = G.nodes()
    cln = {node:0 for node in nodes}

    for u in nodes:
        sumOfDist = 0
        reachable = 0
        for v in nodes:
            if (u != v):
                shortestDist = shortestPathsNeg(G,u,v,False)
                if (shortestDist != float("inf")):
                    sumOfDist += shortestDist
                    reachable += 1
        if sumOfDist > 0:
            cln[u] = reachable/sumOfDist
        else : 
            cln[u] = 0
    
    print("Closeness of graph")
    for key in cln.keys():
        print(f"{key} : {round(cln[key],2)}")
    print()