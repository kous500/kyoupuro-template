# [index](index.md) > UnionFind

```cpp
struct UnionFind {
    vector<int> par;
    
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
```