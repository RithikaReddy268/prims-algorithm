# Prim's Algorithm in C

This repository contains an implementation of **Prim's Minimum Spanning Tree (MST) algorithm** in C.  

## Description
Prim's algorithm finds a subset of edges that forms a **tree including every vertex**, where the total weight of all the edges in the tree is minimized.

The code uses:
- An adjacency matrix (`cost[][]`) to represent the graph.
- A `near[]` array to track the closest vertex to the growing MST.
- Output: all edges in MST and the total minimum cost.

## How to Run
1. Clone the repository:
   ```bash
   git clone <your-repo-url>
   cd Prims-Algorithm
