# [index](index.md) > グラフ

```cpp
struct DirectedGraph {
    int n;
    VV<int> from, to;
    DirectedGraph(int n) : n(n), from(n), to(n) {}
    void add_edge(int a, int b) {
        from[b].push_back(a);
        to[a].push_back(b);
    }
};
```

## 無向グラフ距離計算

```cpp
    Vi dist(n, -1);
    queue<P<int>> q;
    q.push({0, 0});
    dist[0] = 0;
    while (!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (dist[u] != -1) continue;
            dist[u] = d + 1;
            q.push({u, d + 1});
        }
    }
```