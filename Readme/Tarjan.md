# Tarjan Algorithm

***

## What are SCCS

>**Strongly Connected Components** can be thought of self-connected cycles within a directed graph where every vertex in a given cycle can reach every other vertex in the same cycle.

```dot {engine="dot"}
digraph G {
    node [shape = circle, fontname = "Microsoft YaHei", fontsize = 12]
    size = "5.5, 8"
    rankdir=RL
    "Directed Graph" [ shape = plaintext ];
    a -> d
    c -> d
    f -> a
    f -> e
    h -> e
    i -> g
    i -> h
    subgraph cluster_0 {
        a -> b[dir="both"]
        b -> c[dir="both"]
    }

    subgraph cluster_1 {
        d -> e[dir="both"]
    }

    subgraph cluster_2 {
        f -> g[dir="both"]
        g -> h[dir="both"]
        h -> f[dir="both"]
    }

    subgraph cluster_3 {
        i -> i
    }
}
```

## Low-link Values

>The low-link values of a node is the smallest node id reachable from that node when doing a DFS (including itself).
