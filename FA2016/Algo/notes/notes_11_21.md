## More Graph Algorithms

Assumptions
---
1. Connected Graph
2. Edge weights not equal to/not relevant to the notion of distance
3. Can be 0 or negative
4. Unique edge weights

Fun fact: Graphs without loops are called trees

Cut property
---
1. Add an Edge -> introducing a unique cycle
2. Remove and edge -> two disjoint subtrees

Spanning tree of G: Connected subgraph of G w/ all vertices in G and no cycles

Weight of a spanning subtree:

_Minimized_:
W<sub>s</sub> = <sub>i=1</sub><strong>&Sigma;</strong><sup>v-1</sup> E<sub>i</sub>

Prim's Algorithm
---
for graph G:
1. Define G<sub>r</sub> as an initially empty graph.
2. Add 1 vertex V&isin;G to G<sub>r</sub>.
3. While V &ne; V<sub>r</sub>, choose the minimal edge (v,w) where u&isin;V<sub>r</sub>, w&notin;V<sub>r</sub>

See Example in notebook/book.

Kruskal's Algorithms
---
1. Start w/ G<sub>r</sub> a _forest_ w/ V trees of size 1.
2. Add edge weights in sorted order connecting two disjoint trees ergo reducing forest size by 1
3. Repeat `V - 1` times


#### Digraph
