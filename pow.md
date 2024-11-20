# [index](index.md) > 指数・対数

```cpp
inline long long fast_pow(long long base, unsigned exp) {
    if (base != 0 && std::log2(std::abs(base)) * exp >= 63) {
        return (base < 0 && (exp & 1)) ? LONG_LONG_MIN : LONG_LONG_MAX;
    }
    long long result = 1;
    while (exp != 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

inline long long root_floor(const long long &value, const unsigned &degree = 2) {
    unsigned long long l = 0, r = 1ULL << (62 / std::max(1U, degree) + 1);
    while (r - l > 1) {
        unsigned long long m = (l + r) / 2;
        if (fast_pow(m, degree) <= value) l = m;
        else r = m;
    }
    return l;
}
```

### fast_pow($BASE$, $EXP$)

- ${BASE}^{EXP}$ を求めます。
- 結果が `符号あり64bit整数` の範囲を超える場合は、範囲内で最も近い値を返します。
- $0^0$ の場合は $1$ を返します。
- 計算量: $ O(\log EXP)$
- 安全な制約: $BASE$ は `符号あり64bit整数` かつ $EXP$ は `符号なし32bit整数`
- 厳格な制約: ${BASE}^{EXP}$ が $0^0$ 以外かつ、 `符号あり64bit整数` の範囲内

### root_floor($VALUE$, $DEGREE$)

- $\lfloor \sqrt[DEGREE]{VALUE} \rfloor$ を求めます。
- $VALUE < 0$ の場合は $0$ 、 $DEGREE = 0$ の場合は $0$ または $2^{63}-1$ を返します。
- 計算量: $ O(\log VALUE \times \log DEGREE)$
- 安全な制約: $BASE$ は `符号あり64bit整数` かつ $EXP$ は `符号なし32bit整数`
- 厳格な制約: $0 \leq BASE$ かつ $1 \leq DEGREE$

---

```cpp
constexpr int log2_floor(const unsigned long long &value) { return 63 - std::countl_zero(value); }

inline int log_floor(const unsigned &base, unsigned long long value) {
    assert(1 < base);

    int res = 0;
    while (value >= base) {
        value /= base;
        res++;
    }
    return res;
}
```

### log2_floor($VALUE$)

- $\lfloor \log_2 VALUE \rfloor$ を求めます。
- ただし、$VALUE = 0$ の場合は未定義です。
- 計算量: $ O(\log {\log VALUE})$
- 安全な制約: $VALUE$ は $1$ 以上の `符号あり64bit整数`

### log_floor($BASE$, $VALUE$)

- $\lfloor \log_{BASE} VALUE \rfloor$ を求めます。
- ただし、$VALUE = 0$ の場合は $0$ を返します。
- $BASE \leq 1$ の場合はエラーです。
- 計算量: $ O(\log VALUE)$
- 安全な制約: $BASE$ は $1$ より大きい `符号なし32bit整数` かつ $VALUE$ は $1$ 以上の `符号なし64bit整数`