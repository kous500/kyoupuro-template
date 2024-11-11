# [index](index.md) > 時間計測

```cpp
struct Timer {
    const chrono::system_clock::time_point start;
    Timer() : start(chrono::system_clock::now()) {}
    double get() const {
        chrono::system_clock::time_point end = chrono::system_clock::now();
        chrono::duration<double> sec = end - start;
        return sec.count();
    }
};
```

- **get()**: `Timer()` コンストラクタが実行されてからの経過時間（秒）を取得します。