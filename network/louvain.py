from networkx.algorithms.community import louvain_communities
import networkx as nx

def louvainComms(G:nx.Graph):
    return louvain_communities(G)

