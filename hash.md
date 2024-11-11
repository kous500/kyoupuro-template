# [index](index.md) > ハッシュ

## ローリングハッシュ

```cpp
template<unsigned mod> struct RollingHash {
    std::vector<unsigned> hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const {
        unsigned long long x = (unsigned long long) a * b;
        unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
        asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
        return m;
    }

    RollingHash(const std::string &s, unsigned base = 10007) {
        int sz = (int) s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    unsigned get(int l, int r) const {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned connect(unsigned h1, int h2, int h2len) const {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};

using RH = RollingHash<1000000007>;
```

- RollingHash($s$ , $base$): 文字列 $s$ のハッシュテーブルを構築する。
- get($l$, $r$): 区間 $[l, r)$ のハッシュ値を求める。
- connect($h1$, $h2$, $h2len$): ハッシュ値 $h1$ と, 長さ $h2len$ のハッシュ値 $h2$ を結合する。
- LCP($b$, $l1$, $r1$, $l2$, $r2$): 区間 $[l1, r1)$ と, ハッシュテーブルが $b$ からなる区間 $[l2, r2)$ の文字列の最長共通接頭辞の長さを求める。

### 計算量

- 構築 $O(N)$
- get, connect $O(1)$
- LCP $O(logN)$

## ハッシュリスト作成

```cpp
inline std::vector<long long> get_hashlist(int size, long long mod) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(1, mod - 1);
    std::vector<long long> hash(size);
    for (int i = 0; i < size; i++) hash[i] = dis(gen);
    return hash;
}
```

## 標準のmod

```cpp
constexpr ll mod = (1LL << 61) - 1;
```