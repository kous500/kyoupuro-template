# [index](index.md) > 指数・対数

## IntegerCalculator \<LV\>

- 64bit整数用の指数対数計算クラスです。
- 指数テーブルの前計算を行うことで、関数を高速に計算します。

```cpp
template<unsigned LV = 4> class IntegerCalculator {
public:
    typedef long long I_t;
    typedef unsigned long long UI_t;

    IntegerCalculator() {
        static_assert(4 <= LV && LV <= 6, "LV must be in [4, 6]");
        _precompute_pow();
    }

    UI_t root_floor(const UI_t &value, const UI_t &degree = 2) const {
        assert(0 < degree);
        if (value == 0) return 0;
        UI_t l, r;
        if (degree == 1) return value;
        else if (degree == 2) l = static_cast<UI_t>(std::sqrt(value)) - 1, r = l + 2;
        else if (degree == 3) l = static_cast<UI_t>(std::cbrt(value)) - 1, r = l + 3;
        else l = 1ULL << log2_floor(value) / degree, r = l << 1;
        while (r - l > 1) {
            UI_t m = (l + r) / 2;
            if (ui_pow(m, degree) <= std::min(value, _UI_MAX - 1)) l = m;
            else r = m;
        }
        return l;
    }

    unsigned log_floor(const UI_t &base, const UI_t &value) const {
        assert(1 < base);
        assert(0 < value);
        unsigned l = 0, r = log2_floor(value) + 1;
        while (r - l > 1) {
            unsigned m = (l + r) / 2;
            if (ui_pow(base, m) <= std::min(value, _UI_MAX - 1)) l = m;
            else r = m;
        }
        return l;
    }

    I_t i_pow(const I_t &base, const UI_t &exp) const {
        const UI_t power = ui_pow(static_cast<UI_t>(std::abs(base)), exp);
        const bool neg = exp & 1 && base < 0;
        if (power > _I_MAX) return neg ? _I_MIN : _I_MAX;
        return neg ? -power : power;
    }

    UI_t ui_pow(const UI_t &base, const UI_t &exp) const {
        if (LV <= exp) {
            const unsigned safe_exp = std::min(static_cast<UI_t>(_BITS), exp);
            return base < _pow_table[safe_exp].size() ? _pow_table[safe_exp][base] : _UI_MAX;
        }
        UI_t power = 1;
        for (UI_t i = 0; i < exp; ++i) {
            if (base > _UI_MAX / power) return _UI_MAX;
            power *= base;
        }
        return power;
    }

    static constexpr unsigned log2_floor(const UI_t &v) { return 63 - __builtin_clzll(v); }

private:
    static constexpr size_t _BITS = std::numeric_limits<UI_t>::digits;
    static constexpr I_t _I_MAX = std::numeric_limits<I_t>::max(), _I_MIN = std::numeric_limits<I_t>::min();
    static constexpr UI_t _UI_MAX = std::numeric_limits<UI_t>::max();
    std::vector<std::vector<UI_t>> _pow_table;
    
    void _precompute_pow() {
        _pow_table.resize(_BITS + 1);
        for (size_t base = 0; base < 1U << (_BITS + LV - 1) / LV; ++base) {
            UI_t power = 1;
            for (size_t exp = 0; exp <= _BITS; ++exp) {
                if (exp >= LV) _pow_table[exp].push_back(power);
                if (base != 0 && power > _UI_MAX / base) break;
                power *= base;
            }
        }
    }
};
```

### 整数パラメータ $LV$
- $a^b$ を $LV \leq b \leq 64$ の範囲で前計算します。
- $LV$ が大きいほど前計算時間とメモリ使用量は減少しますが、一部のケースでの関数実行時間は増加します。
- 制約: $4 \leq LV \leq 6$
- $LV=4$ の場合、コンストラクタの平均実行時間は `数ミリ秒` です。 (デフォルト値)
- $LV=5$ の場合、コンストラクタの平均実行時間は `1ミリ秒以下` です。(4乗根などの計算時間が倍程度増加します)
- $LV=6$ の場合、コンストラクタの平均実行時間は `非常に短い` です。(4~5乗根などの計算時間が倍程度増加します)

### i_pow($BASE$, $EXP$)

- ${BASE}^{EXP}$ を求めます。
- 結果が `符号あり64bit整数` の範囲を超える場合は、範囲内で最も近い値を返します。
- $0^0$ の場合は $1$ を返します。
- 計算量: $O(1)$
- 制約: $BASE$ は `符号あり64bit整数` かつ $EXP$ は `符号なし64bit整数`
- 厳格な制約: ${BASE}^{EXP}$ が $0^0$ 以外かつ、 `符号あり64bit整数` の範囲内

### ui_pow($BASE$, $EXP$)

- ${BASE}^{EXP}$ を求めます。
- 結果が `符号なし64bit整数` の範囲を超える場合は、範囲内で最も近い値 ($2^{64}-1$) を返します。
- $0^0$ の場合は $1$ を返します。
- 計算量: $O(1)$
- 制約: $BASE$ は `符号なし64bit整数` かつ $EXP$ は `符号なし64bit整数`
- 厳格な制約: ${BASE}^{EXP}$ が $0^0$ 以外かつ、 `符号なし64bit整数` の範囲内

### root_floor($VALUE$, $DEGREE$)

- $\lfloor \sqrt[DEGREE]{VALUE} \rfloor$ を求めます。
- $DEGREE = 0$ の場合はエラーです。
- 計算量: 軽めの $O(\log VALUE)$
- 制約: $VALUE$ は `符号なし64bit整数` かつ $DEGREE$ は $1$ 以上の `符号なし64bit整数`

### log2_floor($VALUE$)

- $\lfloor \log_2 VALUE \rfloor$ を求めます。
- ただし、$VALUE = 0$ の場合は未定義です。
- 計算量: $O(1)$
- 制約: $VALUE$ は $1$ 以上の `符号なし64bit整数`

### log_floor($BASE$, $VALUE$)

- $\lfloor \log_{BASE} VALUE \rfloor$ を求めます。
- $BASE \leq 1$ または $VALUE = 0$ の場合はエラーです。
- 計算量: $O(\log \log VALUE)$
- 制約: $BASE$ は $2$ 以上の `符号なし64bit整数` かつ $VALUE$ は $1$ 以上の `符号なし64bit整数`

## テストコード

```cpp
template<unsigned LV> class IntegerCalculatorTester {
public:
    typedef long long I_t;
    typedef unsigned long long UI_t;

    IntegerCalculatorTester() : _ic() {
        std::cout << "@ IntegerCalculator <" << LV << ">" << std::endl;
        _test_root_floor();
        _test_log_floor();
    }

private:
    static constexpr I_t _I_MAX = std::numeric_limits<I_t>::max(), _I_MIN = std::numeric_limits<I_t>::min();
    static constexpr UI_t _UI_MAX = std::numeric_limits<UI_t>::max();
    const IntegerCalculator<LV> _ic;

    void _test_root_floor() {
        int failed = 0;

        // root_floor(a^b±1, b)
        for (UI_t i = 1; i <= 64; ++i) {
            for (UI_t j = 0; j < 1ULL << 22; j++) {
                UI_t pow = _safe_pow(j, i);
                if (pow == _UI_MAX) continue;
                failed += _require(_ic.root_floor(pow, i), j, i, "^/", pow);
                if (2 <= i && 0 < pow) {
                    failed += _require(_ic.root_floor(pow - 1, i), j - 1, i, "^/", pow - 1);
                    failed += _require(_ic.root_floor(pow + 1, i), j, i, "^/", pow);
                }
            }
        }

        // max cases
        failed += _require(_ic.root_floor(_safe_pow(1ULL << 30, 2), 2), 1ULL << 30, 2, "^/", _safe_pow(1ULL << 30, 2));
        failed += _require(_ic.root_floor(18446744073709551615ULL, 2), 4294967295ULL, 2, "^/", 18446744073709551615ULL);
        failed += _require(_ic.root_floor(18446744073709551615ULL, 3), 2642245ULL, 3, "^/", 18446744073709551615ULL);
        failed += _require(_ic.root_floor(18446744073709551615ULL, 4), 65535ULL, 4, "^/", 18446744073709551615ULL);
        failed += _require(_ic.root_floor(0, _UI_MAX), 0ULL, _UI_MAX, "^/", 0);
        failed += _require(_ic.root_floor(1, _UI_MAX), 1ULL, _UI_MAX, "^/", 1);
        failed += _require(_ic.root_floor(2, _UI_MAX), 1ULL, _UI_MAX, "^/", 2);
        failed += _require(_ic.root_floor(_UI_MAX, _UI_MAX), 1ULL, _UI_MAX, "^/", _UI_MAX);

        std::cout << "failed cases [root_floor]: " << failed << std::endl;
    }

    void _test_log_floor() {
        for (UI_t i = 2; i <= 1ULL << 32; i *= 2) {
            std::cout << "log_" << i << "(18446744073709551615ULL) = " << _ic.log_floor(i, 18446744073709551615ULL) << std::endl;
        }
    }

    template<class R, class... A> bool _require(const R &result, const R &expect, A... args) {
        if (result != expect) {
            std::cout << "Failed: " << result << " != " << expect;
            (std::cout << ... << (std::cout << ' ', args));
            std::cout << std::endl;
            return true;
        }
        return false;
    }

    UI_t _safe_pow(const UI_t &base, const UI_t &exp) {
        UI_t power = 1;
        for (UI_t i = 0; i < exp; ++i) {
            if (base != 0 && power > _UI_MAX / base) return _UI_MAX;
            power *= base;
        }
        return power;
    }
};
```