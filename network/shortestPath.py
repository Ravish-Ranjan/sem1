import heapq
import networkx as nx

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
            w = data.get("weight",1)
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
        return [] if givePaths else float("inf")
    
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
