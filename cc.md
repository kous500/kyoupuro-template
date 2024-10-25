# [index](index) > 座標圧縮

```cpp
template<class T> vector<T> coordinate_compression(vector<T>& a) {
    vector<T> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<T> res(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    return res;
}
```