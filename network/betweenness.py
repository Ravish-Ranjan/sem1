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

    for s_idx in range(len(nodes)):
        for t_idx in range(s_idx + 1, len(nodes)):
            s = nodes[s_idx]
            t = nodes[t_idx]
            paths = shortestPathsNeg(G, s, t)
            sigma_st = len(paths)

            if sigma_st == 0:
                continue
            for path in paths:
                for i in range(len(path) - 1):
                    u, v = path[i], path[i+1]
                    edge = tuple(sorted((u, v)))
                    if (u,v) in G.edges():
                        bns[(u,v)] += 1 / sigma_st
                    elif (v,u) in G.edges():
                        bns[(v,u)] += 1 / sigma_st


    print("Edge Between-ness of graph")
    for i in bns.keys():
        print(f"{i} : {round(bns[i],2)}")
    print()
