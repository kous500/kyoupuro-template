# [index](index.md) > ダブリング

```cpp
class Doubling {
  public:
    Doubling() = default;
    Doubling(std::vector<int> next, int log_max = 64) : _log_max(log_max), _doubling(log_max, std::vector<int>(next.size())) {
        assert(0 <= _log_max && _log_max <= 64);

        _doubling[0] = std::move(next);
        for (int i = 1; i < _log_max; i++) {
            for (int j = 0; j < next.size(); j++) {
                _doubling[i][j] = _doubling[i - 1][_doubling[i - 1][j]];
            }
        }
    }

    int query(int idx, unsigned long long k) const {
        assert(0 <= idx && idx < _doubling[0].size());
        assert(_log_max == 64 || k < (1ULL << _log_max));

        for (int i = 0; i < _log_max; i++) {
            if (k & (1ULL << i)) {
                idx = _doubling[i][idx];
            }
        }
        return idx;
    }

  private:
    const int _log_max;
    std::vector<std::vector<int>> _doubling;
};
```

```cpp
template<class T> class DoublingMap {
  public:
    DoublingMap() = default;
    DoublingMap(std::map<T, T> next, int log_max = 64) : _log_max(log_max), _doubling(log_max) {
        assert(0 <= _log_max && _log_max <= 64);

        _doubling[0] = std::move(next);
        for (int i = 1; i < _log_max; i++) {
            for (auto [key, val] : _doubling[i - 1]) {
                assert(_doubling[i - 1].count(val));
                _doubling[i][key] = _doubling[i - 1][val];
            }
        }
    }

    T query(T idx, unsigned long long k) const {
        assert(_doubling[0].count(idx));
        assert(_log_max == 64 || k < (1ULL << _log_max));

        for (int i = 0; i < _log_max; i++) {
            if (k & (1ULL << i)) {
                idx = _doubling[i][idx];
            }
        }
        return idx;
    }

  private:
    const int _log_max;
    std::vector<std::map<T, T>> _doubling;
};
```