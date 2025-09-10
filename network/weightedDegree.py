import networkx as nx

def calcWeightedDegree(G:nx.Graph):
    A = nx.adjacency_matrix(G).todense()
    nodes = list(G.nodes())
    print("Weighted degree of graph nodes")
    for i in range(len(nodes)):
        print(f"{nodes[i]} : {round(int(sum(A[i])),2)}")
    print()