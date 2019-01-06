/*
Written from competetive programmer's handbook

A path cover is a set of path in a graph such that each node of the graph belongs to at least one path. It turns out that in directed, acyclic graph, we can reduce the problem of finding a minimum path cover to the problem of finding a maximum flow in another graph.


In a node disjoint path cover each node belongs to exactly one path. We can find it by constructing a bi partile graph of 2 set of the same nodes. There will be an edge from left node to right node if there is an edge in the original graph.

A general path cover is a path cover where a node can belong to more than one path. A general path cover may be smaller than a disjoint path cover. It can be solved almost similarly. The difference together with the edges we also insert some new edges. If there is a path from a to b we insert the edge.

*/