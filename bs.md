# [index](index.md) > ２分探索

## 整数の２分探索

```cpp
inline ll ibs(ll min_ng, ll max_ok, function<bool(ll)> is_ok) {
    while (abs(max_ok - min_ng) > 1) {
        ll mid = (max_ok + min_ng) / 2;
        if (is_ok(mid)) max_ok = mid;
        else min_ng = mid;
    }
    return max_ok;
}

```
条件を満たす最大の整数値を返します。

- **min_ng**: 条件を満たさない最小の値
- **max_ok**: 条件を満たす最大の値
- **is_ok**: 条件を判定する関数（true：条件を満たす、false：条件を満たさない）

## 実数の2分探索

```cpp
inline double fbs(double left, double right, function<bool(double)> is_ok) {
    while (abs(right - left) > 1e-9) {
        double mid = (right + left) / 2;
        if (is_ok(mid)) right = mid;
        else left = mid;
    }
    return left;
}
```

条件を満たす最大の実数値を返します。

- **left**: 条件を満たさない最小の値
- **right**: 条件を満たす最大の値
- **is_ok**: 条件を判定する関数（true：条件を満たす、false：条件を満たさない）

## 3分探索

```cpp
template<class T> inline T three_part_search(T left, T right, function<T(T)> is_ok) {
    while (abs(right - left) > 1e-9) {
        T mid1 = left + (right - left) / 3;
        T mid2 = right - (right - left) / 3;
        if (is_ok(mid1) < is_ok(mid2)) right = mid2;
        else left = mid1;
    }
    return left;
}
```