import networkx as nx
from shortestPath import shortestPathsNeg

def calcNodeBetweenness(G:nx.Graph):
    bns = dict.fromkeys(G.nodes(),0)
    nodes = G.nodes()
    for i in nodes:
        for j in nodes:
            if(i != j):
                paths = shortestPathsNeg(G,i,j)
                sigma_sd = len(paths)
                for path in paths:
                    for v in path[1:-1]:
                        bns[v] += 1 / sigma_sd
    print("Node Between-ness of graph")
    for i in bns.keys():
        print(f"{i} : {round(bns[i],2)}")
    print()

def calcEdgeBetweenness(G:nx.Graph):
    bns = dict.fromkeys(G.edges(),0)
    nodes = list(G.nodes())

    for i in nodes:
        for j in nodes:
            if (i != j):
                paths = shortestPathsNeg(G,i,j)
                sigma_sd = len(paths)
                if (sigma_sd == 0):
                    continue
                for path in paths:
                    edgein = list(zip(path[:-1],path[1:]))
                    for e in edgein:
                        if e in bns:
                            bns[e] += 1/sigma_sd
                        elif (e[1],e[0]) in bns:
                            bns[(e[1],e[0])] += 1/sigma_sd


    print("Edge Between-ness of graph")
    for i in bns.keys():
        print(f"{i} : {round(bns[i],2)}")
    print()
