# [index](index.md) > LIS

```cpp
template<class T> std::vector<T> LIS(const std::vector<T> &v, bool broadly = false) {
    const int n = v.size();
    const std::pair<bool, T> inf = std::make_pair(true, T());

    std::vector<std::pair<bool, T>> dp(n, inf);
    std::vector<int> id(n, -1), pre(n);
    for (int i = 0; i < n; ++i) {
        int j = broadly
                ? (std::upper_bound(dp.begin(), dp.end(), std::make_pair(false, v[i])) - dp.begin())
                : (std::lower_bound(dp.begin(), dp.end(), std::make_pair(false, v[i])) - dp.begin());
        dp[j] = std::make_pair(false, v[i]);
        id[j] = i;
        pre[i] = j ? id[j - 1] : -1;
    }

    std::vector<T> res;
    int l = std::lower_bound(dp.begin(), dp.end(), inf) - dp.begin() - 1;
    if (l < 0) return res;

    for (int i = id[l]; i != -1; i = pre[i]) res.push_back(v[i]);
    std::reverse(res.begin(), res.end());
    return res;
}
```

- **LIS(v)**: vの狭義単調増加となる最長の部分列の１つを求めます。
- **LIS(v, true)**: vの広義単調増加となる最長の部分列の１つを求めます。