# [index](index.md) > 指数・対数

## fast_pow($BASE$, $EXP$)

```cpp
constexpr long long fast_pow(long long base, unsigned exp) {
    const bool neg = base < 0 && (exp & 1);
    long long result = 1;
    if (base != 0 && (63 - std::countl_zero((unsigned long long)std::abs(base))) * exp >= 63) {
        return neg ? LONG_LONG_MIN : LONG_LONG_MAX;
    }
    while (exp != 0) {
        if (base != 0 && std::abs(result) > LONG_LONG_MAX / std::abs(base)) {
            return neg ? LONG_LONG_MIN : LONG_LONG_MAX;
        }
        if (exp & 1) result *= base;
        if (exp >>= 1) {
            if (base != 0 && std::abs(base) > LONG_LONG_MAX / std::abs(base)) {
                return neg ? LONG_LONG_MIN : LONG_LONG_MAX;
            }
            base *= base;
        }
    }
    return result;
}
```

- ${BASE}^{EXP}$ を求めます。
- 結果が `符号あり64bit整数` の範囲を超える場合は、範囲内で最も近い値を返します。
- $0^0$ の場合は $1$ を返します。
- 計算量: $ O(\log EXP)$
- 制約: $BASE$ は `符号あり64bit整数` かつ $EXP$ は `符号なし32bit整数`
- 厳格な制約: ${BASE}^{EXP}$ が $0^0$ 以外かつ、 `符号あり64bit整数` の範囲内

## root_floor($VALUE$, $DEGREE$)

```cpp
constexpr unsigned long long root_floor(const unsigned long long &value, const unsigned &degree = 2) {
    assert(0 < degree);
    if (degree == 1) return value;
    if (value == 0) return 0;

    unsigned long long l = 1ULL << (63 - std::countl_zero(value)) / degree, r = l << 1;
    while (r - l > 1) {
        unsigned long long m = (l + r) / 2;
        if (m != 0 && (63 - std::countl_zero(m)) * degree >= 64) {
            r = m;
            continue;
        }
        unsigned exp = degree;
        unsigned long long pow = 1, base = m;
        while (true) {
            if (exp & 1) {
                if (pow > value / base) {
                    r = m;
                    break;
                }
                pow *= base;
            }
            if (exp >>= 1) {
                if (base != 0 && base > value / base) {
                    r = m;
                    break;
                }
                base *= base;
            } else {
                if (pow <= value) l = m;
                else r = m;
                break;
            }
        }
    }
    return l;
}
```

- $\lfloor \sqrt[DEGREE]{VALUE} \rfloor$ を求めます。
- $DEGREE = 0$ の場合はエラーです。
- 計算量: $ O(\log DEGREE * \log VALUE)$
- 制約: $VALUE$ は `符号なし64bit整数` かつ $DEGREE$ は $1$ 以上の `符号なし32bit整数`

## log2_floor($VALUE$)

```cpp
constexpr int log2_floor(const unsigned long long &value) { return 63 - std::countl_zero(value); }
```

- $\lfloor \log_2 VALUE \rfloor$ を求めます。
- ただし、$VALUE = 0$ の場合は未定義です。
- 計算量: $ O(\log {\log VALUE})$
- 制約: $VALUE$ は $1$ 以上の `符号あり64bit整数`

## log_floor($BASE$, $VALUE$)

```cpp
constexpr int log_floor(const unsigned &base, unsigned long long value) {
    assert(1 < base);

    int res = 0;
    while (value >= base) {
        value /= base;
        res++;
    }
    return res;
}
```

- $\lfloor \log_{BASE} VALUE \rfloor$ を求めます。
- ただし、$VALUE = 0$ の場合は $0$ を返します。
- $BASE \leq 1$ の場合はエラーです。
- 計算量: $ O(\log VALUE)$
- 制約: $BASE$ は $2$ 以上の `符号なし32bit整数` かつ $VALUE$ は $1$ 以上の `符号なし64bit整数`