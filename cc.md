# [index](index) > 座標圧縮

```cpp
template<class T> class CoordinateCompression {
  public:
    CoordinateCompression(std::vector<T> v) : _id(v) {
        sort(all(_id));
        _id.erase(unique(all(_id)), _id.end());
        _v.resize(_id.size());
        for (int i = 0; i < _id.size(); i++) {
            _mp[_id[i]] = i;
            _v[i] = lower_bound(v.begin(), v.end(), _id[i]) - v.begin();
        }
    }

    int toId(T x) { return _mp[x]; }
    T toValue(int x) { return _id[x]; }
    std::vector<int> get() { return _v; }
    int size() { return _id.size(); }

  private:
    std::vector<T> _id;
    std::map<T, int> _mp;
    std::vector<int> _v;
};
```