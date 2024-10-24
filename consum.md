# [index](index) > 累積和

```cpp
template<class T> struct Consum {
    V<T> sum;
        
    Consum(V<T> &v) : sum(v.size() + 1) {
        rep(i, v.size()) sum[i + 1] = sum[i] + v[i];
    }

    T opensum(int l, int r) {
        return sum[r + 1] - sum[l];
    }

    T halfsum(int l, int r) {
        return sum[r] - sum[l];
    }
};
```

入力配列を受け取り、累積和を計算して初期化します。

- **T opensum(int l, int r)**: 閉区間 **[l, r]** の和を返します。インデックス `l` から `r` までの要素の和を計算します。
- **T halfsum(int l, int r)**: 半開区間 **[l, r)** の和を返します。インデックス `l` から `r-1` までの要素の和を計算します。