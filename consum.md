# [index](index) > 累積和

```cpp
template<class T> class CumulativeSum {
  public:
    CumulativeSum() : _sum(1) {}
    CumulativeSum(std::vector<T> &v) : _sum(v.size() + 1) {
        for (int i = 0; i < v.size(); i++) {
            _sum[i + 1] = _sum[i] + v[i];
        }
    }

    //get sum of [l, r]
    long long sum(int l, int r) {
        assert(l <= r + 1);
        assert(0 <= l && r + 1 < _sum.size());
        return _sum[r + 1] - _sum[l];
    }

    //get sum of [l, r)
    long long halfsum(int l, int r) {
        assert(l <= r);
        assert(0 <= l && r < _sum.size());
        return _sum[r] - _sum[l];
    }

  private:
    std::vector<long long> _sum;
};
```

### CumulativeSum

入力配列を受け取り、その累積和をあらかじめ計算します。

- **sum(int l, int r)**: 閉区間 `[l, r]` （インデックス `l` から `r` まで）の要素の和を計算します。
- **halfsum(int l, int r)**: 半開区間 `[l, r)` （インデックス `l` から `r-1` まで）の要素の和を計算します。