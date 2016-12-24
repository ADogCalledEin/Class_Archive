## Directed Graphs

We have an algorithm that has an error in it. We're gonna find the error.

| **City/City**  | Providence | Westerly | New London  | Norwich |
| --- |
| **Providence**  |  - | 53  | 54  | 48  |
| **Westerly**  | 53  | -  | 18  | 101  |
| **New London**  | 54  | 18  | -  | 12  |
| **Norwich**  | 48  | 101  | 12  | -  |

_See graph in notebook_

The error is that Norwich to Westerly is 101, when we can clearly see that a non-direct path through New London is much shorter.

Properties of Directed Graphs
---
1. All paths are directed, ergo any shortest path algorithm must respect the path direction.
2. Weights are generalized values.
3. Not all vertices need to be reachable.
4. Negative edge weights: allowed, however, introduces complexity.
5. Simple: Ignore 0 edge weights that form cycles.
6. Parallel edges and self loops OK (that we won't directly address).
7. Shortest paths are not necessarily unique.

Shortest Path Tree
---
Rooted at S, every path in the tree is a shortest path within the directed graph.



- Let G be and edge-weighted digraph w/source vertex S
- define d[] as a vertex-indexed array of path lengths
  in a such that if a vertex, v, is reachable from s, then d[v] is the length
  of some path from s to v.
- Let d[v] be &infin; for any vertex not reachable from S.

Claim: The values in d[] are shortest path length if and only if d[w]&le;d[v]+e<sub>vw</sub> for all edges from v to w.

1. Proof by contradiction: if d[w]>d[v]+e<sub>vw</sub> then w would give a path from S to W (via V) thats shorter than d[w].
2. Supposed that w is reachable from S & via some path S&rarr;v<sub>0</sub>&rarr;v<sub>1</sub>...&rarr;w and this is the shortest OPT<sub>sw</sub>.
Let E be the set of edges { e<sub>i</sub> | 1&le;i&le;w, e<sub>i</sub> is the directed edge from v<sub>i-1</sub>&rarr;v<sub>i</sub>}

Dijkstra's Shortest Path Algorithm
---
1. Initialize dist[s] to 0. Every other entry is infinite (or a large value for a computer cuz they have no real concept of infinity)
2. Repeatably relax edges and add to the tree a non-tree vertex w/ the lowest distance/path weight.
3. Stop when all vertices add to the tree or no non-tree vertex has a finite distance.

Implementation:

1. distTo[] array
2. edgeTo[] array
3. P.Q. w/ distance (path) as key vertex as value.
