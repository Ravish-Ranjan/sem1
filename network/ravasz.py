import networkx as nx
import pandas as pd
import numpy as np
 
def ravaszSimilarityCalc(G:nx.Graph,u,v):
    u_neigh = set(G.neighbors(u))
    v_neigh = set(G.neighbors(v))
    comm_neigh = len(u_neigh.intersection(v_neigh))
    print(f"from {u} to {v}")
    print(f"n of {u}",set(G.neighbors(u)))
    print(f"n of {v}",set(G.neighbors(v)))
    print(u_neigh.intersection(v_neigh))
    direct = 1 if (u,v) in G.edges() else 0
    min_deg = min(G.degree[u],G.degree[v])
    return (comm_neigh + direct )/ (min_deg + 1)

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
    # np.fill_diagonal(df.values,-1)
    maxi = getMaxSim(df)
    newName = f"{maxi["col"]}{maxi["row"]}"
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
    
    print("--- Initial Matrix ---")
    print(sim)
    
    # FIX: Loop n-1 times to get to a single cluster
    for i in range(n-1):
        print(f"\n--- Step {i+1} (Merging {n-i} clusters) ---")
        
        # Check if there's anything left to merge
        if sim.shape[0] <= 1:
            print("Clustering complete.")
            break
            
        sim = combineMax(sim)
        print(sim.to_markdown(floatfmt=".3f")) # .to_markdown() is easier to read

    print("\n--- Final Cluster ---")
    print(sim.index[0])        