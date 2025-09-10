import networkx as nx
from matplotlib import pyplot as plt
import heapq

def calcWeightedDegree(G:nx.Graph):
    A = nx.adjacency_matrix(G).todense()
    nodes = list(G.nodes())
    print("Weighted degree of graph nodes")
    for i in range(len(nodes)):
        print(f"{nodes[i]} : {round(int(sum(A[i])),2)}")
    print()

def shortestPaths(G:nx.Graph,src,dest):
    dist = {node:float("inf") for node in G.nodes()}
    dist[src] = 0
    pq = [(0,src)]

    while pq:
        d,u = heapq.heappop(pq)
        if(d > dist[u]):
            continue
        for v in G.neighbors(u):
            w = G[u][v]["weight"]
            if(dist[v] > dist[u] + w):
                dist[v] = dist[u] + w
                heapq.heappush(pq,(dist[v],v))

    shortest = dist[dest]
    if(shortest == float("inf")):
        return []
    
    paths = []
    def backtrack(node,path,curDist):
        if(node == dest):
            if(curDist == shortest):
                paths.append(path[:])
            return
        for neighbor in G.neighbors(node):
            w = G[node][neighbor]["weight"]
            if dist[neighbor] == dist[node] + w:
                backtrack(neighbor, path + [neighbor], curDist + w)

    backtrack(src,[src],0)
    return paths

def shortestPathsNeg(G:nx.Graph,src,dest,givePaths = True):
    dist = {node:float("inf") for node in G.nodes()}
    pred = {node:[] for node in G.nodes()}
    dist[src] = 0

    for _ in range(len(G.nodes()) - 1):
        for u,v,data in G.edges(data=True):
            w = data["weight"]
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                pred[v] = [u]
            elif dist[u] + w == dist[v]:
                pred[v].append(u)

    for u,v,data in G.edges(data=True):
        w = data["weight"]
        if dist[u] + w < dist[v]:
            raise ValueError("Graph has a cycle with negative weight")
        
    if dist[dest] == float("inf"):
        return []
    
    if givePaths:
        paths = []
        def backtrack(node,path):
            if(node == src):
                paths.append(path[:])
                return
            for p in pred[node]:
                backtrack(p,path + [node])
    
        backtrack(dest,[])
        return paths
    if not givePaths:
        return dist[dest]

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

def calcCloseness(G:nx.Graph):
    nodes = G.nodes()
    cln = {node:0 for node in nodes}

    for u in nodes:
        sumOfDist = 0
        reachable = 0
        for v in nodes:
            if (u != v):
                shortestDist = shortestPathsNeg(G,u,v,False)
                if (type(shortestDist) == int):
                    print(u,v,shortestDist)
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


if __name__ == "__main__":
    G = nx.Graph()
    # G.add_nodes_from("ABCD")
    G.add_nodes_from("ABCDEFGH")
    
    # G.add_edge("A","B",weight=1)
    # G.add_edge("B","C",weight=1)
    # G.add_edge("C","D",weight=1)
    
    G.add_edge("A","B",weight=3)
    G.add_edge("C","D",weight=1)
    G.add_edge("A","D",weight=2)
    G.add_edge("B","F",weight=4)
    G.add_edge("G","H",weight=2)
    G.add_edge("A","G",weight=5)
    G.add_edge("C","F",weight=6)
    G.add_edge("E","F",weight=3)
    G.add_edge("B","G",weight=1)
    G.add_edge("E","H",weight=3)
    G.add_edge("C","H",weight=5)

    # calcEdgeBetweenness(G)
    # calcNodeBetweenness(G)
    calcCloseness(G)
    
    # pos = nx.spring_layout(G,seed=7)
    # nx.draw(G, pos, with_labels=True, node_color="lightblue", node_size=1000, font_size=10)
    
    # # Draw edge labels (weights)
    # labels = nx.get_edge_attributes(G, 'weight')
    # nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
    
    plt.show()