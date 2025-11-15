import networkx as nx
from matplotlib import pyplot as plt

from betweenness import calcEdgeBetweenness,calcNodeBetweenness
from closeness import calcCloseness
from weightedDegree import calcWeightedDegree
from ravasz import similarityMatrix,aglo
from louvain import louvainComms

if __name__ == "__main__":
    G = nx.Graph()
    # G.add_nodes_from("ABCD")

    # G.add_edge("A","B",weight=1)
    # G.add_edge("B","C",weight=1)
    # G.add_edge("C","D",weight=1)

    # G.add_nodes_from("ABCDEFGHIJK")

    G.add_edge("A","B")
    G.add_edge("C","B")
    G.add_edge("C","A")
    G.add_edge("C","D")
    G.add_edge("E","D")
    G.add_edge("I","D")
    G.add_edge("F","G")
    G.add_edge("E","G")
    G.add_edge("E","F")
    G.add_edge("H","G")
    G.add_edge("H","I")
    G.add_edge("H","J")
    G.add_edge("I","J")
    G.add_edge("I","K")
    G.add_edge("K","J")

    # G.add_edge("A","B",weight=3)
    # G.add_edge("C","D",weight=1)
    # G.add_edge("A","D",weight=2)
    # G.add_edge("B","F",weight=4)
    # G.add_edge("G","H",weight=2)
    # G.add_edge("A","G",weight=5)
    # G.add_edge("C","F",weight=6)
    # G.add_edge("E","F",weight=3)
    # G.add_edge("B","G",weight=1)
    # G.add_edge("E","H",weight=3)
    # G.add_edge("C","H",weight=5)

    # calcWeightedDegree(G)
    # calcEdgeBetweenness(G)
    # calcNodeBetweenness(G)
    # calcCloseness(G)
    # aglo(G)
    # louvains
    comms = louvainComms(G)

    for comm in comms:
        print(comm)

    # barabasi
    G1 = nx.barabasi_albert_graph(n=10,m=2)




    # pos = nx.spring_layout(G1,seed=7)
    # nx.draw(G, pos, with_labels=True, node_color="lightblue", node_size=1000, font_size=10)
    
    # Draw edge labels (weights)
    # labels = nx.get_edge_attributes(G, 'weight')
    nx.draw(G1)
    
    plt.show()