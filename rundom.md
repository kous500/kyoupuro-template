# [index](index.md) > 乱数生成

```cpp
random_device rd;
mt19937 gen(rd());

template<class T> T rand_uniform(T mn, T mx) {
    uniform_int_distribution<T> distribution(mn, mx);
    return distribution(gen);
}

double rand_normal(double mn, double mx) {
    normal_distribution<> distribution(mn, mx);
    return distribution(gen);
}
```
- **gen**: シード値
- **T rand_uniform(T mn, T mx)**: 範囲 `[mn, mx]` 上の離散ランダム分布で乱数を生成します。
- **double rand_normal(double n, double m)**: 範囲 `[mn, mx]` 上の正規連続分布で乱数を生成します。