# [index](index.md) > 指数・対数

```cpp
constexpr int floor_log2(const unsigned long long &a) { return 63 - std::countl_zero(a); }

inline long long safe_pow(const long long &a, unsigned b) {
    const bool is_negative = a < 0 && (b & 1);
    unsigned long long res = 1, p = std::abs(a);
    while (b > 0) {
        if (floor_log2(res) + floor_log2(p) > 62) return is_negative ? LONG_LONG_MIN : LONG_LONG_MAX;
        if (b & 1) res *= p;
        if (p > 3037000499ULL && b >> 1) return is_negative ? LONG_LONG_MIN : LONG_LONG_MAX;
        p *= p;
        b >>= 1;
    }
    if (res > LONG_LONG_MAX) return is_negative ? LONG_LONG_MIN : LONG_LONG_MAX;
    return is_negative ? -res : res;
}

inline long long floor_sqrt(const long long &a, const int &b = 2) {
    assert(0 <= a && a < LONG_LONG_MAX);
    assert(1 <= b);
    
    unsigned long long l = 0, r = a + 1;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (safe_pow(m, b) <= a) l = m;
        else r = m;
    }
    return l;
}
```

### floor_log2($a$)

- $\lfloor \log_2 a \rfloor$ を求めます。
- ただし、$a = 0$ の場合は $-1$ を返します。
- 計算量: $ O(\log {\log a})$
- 制約: $0 \leq a \leq 2^{64}-1$

### safe_pow($a$, $b$)

- $a^b$ を求めます。
- 結果が符号付き64bit整数の範囲を超える場合は、範囲内で最も近い値を返します。
- $0^0$ の場合は $1$ を返します。
- 計算量: $ O(\log b)$
- 制約: $-2^{63} \leq a \leq 2^{63}-1$ かつ $0 \leq b \leq 2^{32}-1$

### floor_sqrt($a$, $b$)

- $\lfloor \sqrt[a]{b} \rfloor$ を求めます。
- 計算量: $ O(\log a \log b)$
- 制約: $0 \leq a < 2^{63}-1$ かつ $1 \leq b \leq 2^{31}-1$

---

```cpp
inline int floor_log(const unsigned long long &a, unsigned long long x) {
    if (x <= 0) return INT_MIN;
    if (a <= 1) return INT_MAX;

    int res = 0;
    while (x >= a) {
        x /= a;
        res++;
    }
    return res;
}
```

### floor_log($a$, $x$)

- $\lfloor \log_a x \rfloor$ を求めます。
- ただし、$x \leq 0$ の場合は $-2^{31}$ を、 $a \leq 1$ の場合は $2^{31}-1$ を返します。
- 計算量: $ O(\log x)$