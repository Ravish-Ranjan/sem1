import networkx as nx
import pandas as pd
import numpy as np
 
def ravaszSimilarityCalc(G:nx.Graph,u,v):
    Nu = set(G.neighbors(u))
    Nv = set(G.neighbors(v))
    
    intN = len(Nu.intersection(Nv))
    uniN = len(Nu.union(Nv))

    if (uniN == 0):
        return 0
    return intN/uniN

def similarityMatrix(G:nx.Graph):
    nodes = list(G.nodes())
    n = len(nodes)
    sim_matrix = pd.DataFrame(index=nodes, columns=nodes, dtype=float)

    sim_matrix.loc[nodes[0],nodes[0]] = 0
    for i in range(n):
        for j in range(1,n):
            u = nodes[i]
            v = nodes[j]
            sim = 0
            if u == v:
                sim = 0
            else :
                sim = ravaszSimilarityCalc(G,u,v)
            sim_matrix.loc[u, v] = sim
            sim_matrix.loc[v, u] = sim 
    return sim_matrix

def getMaxSim(matrix:pd.DataFrame):
    max_val = matrix.max().max()
    col_max_val = matrix.max().idxmax()
    row_max_val = matrix[col_max_val].idxmax()
    return {
        "row":row_max_val,
        "col":col_max_val,
        "value":float(max_val)
    }

def combineMax(sim:pd.DataFrame):
    df = sim.copy()
    np.fill_diagonal(df.values,-1)
    maxi = getMaxSim(df)
    newName = f"{maxi["row"]}{maxi["col"]}"
    newSims = (sim[maxi["row"]]+sim[maxi["col"]])/2
    df_updated = sim.drop(index=[maxi["row"], maxi["col"]], columns=[maxi["row"], maxi["col"]])
    df_updated.loc[newName] = newSims.drop([maxi["row"], maxi["col"]])
    df_updated[newName] = newSims.drop([maxi["row"], maxi["col"]])
    df_updated.loc[newName,newName] = 0
    return df_updated

def aglo(G:nx.Graph):
    sim = similarityMatrix(G)
    nodes = G.nodes()
    n = len(nodes)
   
    print(sim)
    for i in range(n-2):
        sim = combineMax(sim)
        print(sim)        


    
        
