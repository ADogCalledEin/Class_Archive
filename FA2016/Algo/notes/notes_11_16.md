## Graph Algorithms
```
public class Graph
------------------
- Graph (int V)
- int V()     \____ size
- int E()     /
- void addEdge(int V)
- Iterable<Integer> adj(int v)
```
PseudoCode for getting the maximum degree of G - an integer:

```
GetMaxDegree(G)
  Input: G - a graph
  Output: max. degree of G, an integer

  max <- 0
  for i <- 0 to G.V()-1 do:
    degree <- 0
    edges <- G.adj(i)
    while edges.hasNext() do:
      edges.next()
      degree <- degree + 1
      if degree > max then
        max <- degree
  return max
```

## Searching in a graph
- from some source (vertex) give me the connected vertices

API might look something liek dis:
```
SearchGraph
-----------
- SearchGraph(G,s)
- int count()
- boolean isConnected(int V) (book calls it marked)
```

#### Depth First Search

It turns out that we can modify the above to answer a lot of questions about a graph. The general approach is to visit a vertex, then recursively visit all unvisited adjacent vertices. PseudoCode below.

```
dfs(V, marked, G)
  Input: V - vertex to visit (integer)
         marked - array designating visited vertices (boolean array)
         G - our graph
  Output: map of connected vertices (marked array)

  marked[V] <- true
  edges <- G.adj(V)
  while edges.hasNext() do:
    w <- edges.next()
    if marked[w] != true then
      dfs(w, marked, G)

```

The above gives us a path, but doesn't exactly give the shortest path. So we can alter it.

```
dfs(V, marked, G, edgeTo)
  Input: V - vertex to visit (integer)
         marked - array designating visited vertices (boolean array)
         edgeTo - array designating previous vertex (int array)
         G - our graph
  Output: map of connected vertices (marked array)

  marked[V] <- true
  edges <- G.adj(V)
  while edges.hasNext() do:
    w <- edges.next()
    if marked[w] != true then
      edgeTo[V] <- w
      dfs(w, marked, G, edgeTo)

```

While this still doesn't give us the shortest path, Depth First Search cannot give the shortest path in every instance due to the nature of the algorithm.

#### Breadth First Search
This algorithm makes use of the Queue in keeping track of what has been visited.
