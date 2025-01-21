# [index](index.md) > セグ木

## テンプレート

```cpp
ll op_min(ll a, ll b) { return min(a, b); }
ll op_max(ll a, ll b) { return max(a, b); }
ll op_sum(ll a, ll b) { return a + b; }
ll op_mul(ll a, ll b) { return a * b; }
ll e_inf() { return INF_l; }
ll e_minf() { return -INF_l; }
ll e_0() { return 0LL; }
ll e_1() { return 1LL; }
using segtree_min = segtree<ll, op_min, e_inf>;
using segtree_max = segtree<ll, op_max, e_minf>;
using segtree_sum = segtree<ll, op_sum, e_0>;
using segtree_mul = segtree<ll, op_sum, e_1>;

// 区間Max 区間加算
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF_l; }
ll mapping(ll f, ll x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }
using lseg = lazy_segtree<ll, op, e, ll, mapping, composition, id>;

// 区間Max 区間更新
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF_l; }
ll mapping(ll f, ll x) { return f != -INF_l ? f : x; }
ll composition(ll f, ll g) { return g != -INF_l ? g : f }; 
ll id() { return -INF_l; }
using lseg = lazy_segtree<ll, op, e, ll, mapping, composition, id>;

// 区間Min 区間加算
ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF_l; }
ll mapping(ll f, ll x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }
using lseg = lazy_segtree<ll, op, e, ll, mapping, composition, id>;

// 区間Min 区間更新
ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF_l; }
ll mapping(ll f, ll x) { return f != -INF_l ? f : x; }
ll composition(ll f, ll g) { return g != -INF_l ? g : f }; 
ll id() { return -INF_l; }
using lseg = lazy_segtree<ll, op, e, ll, mapping, composition, id>;

// 区間和 区間加算
// S: {Value, Range}, {0, 1} で初期化必須
pair<ll, int> op(pair<ll, int> a, pair<ll, int> b) { return {a.first + b.first, a.second + b.second}; }
pair<ll, int> e() { return {0, 0}; }
pair<ll, int> mapping(ll f, pair<ll, int> x) { return {x.first + f * x.second, x.second}; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }
using lseg = lazy_segtree<pair<ll, int>, op, e, ll, mapping, composition, id>;

// 区間和 区間更新
// S: {Value, Range}, {0, 1} で初期化必須
pair<ll, int> op(pair<ll, int> a, pair<ll, int> b) { return {a.first + b.first, a.second + b.second}; }
pair<ll, int> e() { return {0, 0}; }
pair<ll, int> mapping(ll f, pair<ll, int> x) { return {f != -INF_l ? f * x.second : x.first, x.second}; }
ll composition(ll f, ll g) { return g != -INF_l ? g : f; }
ll id() { return -INF_l; }
using lseg = lazy_segtree<pair<ll, int>, op, e, ll, mapping, composition, id>;
```

# Segtree

[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) $(S, \cdot: S \times S \to S, e \in S)$、つまり

- 結合律: $(a \cdot b) \cdot c$ = $a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e$ = $e \cdot a$ = $a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です。

長さ $N$ の $S$ の配列に対し、

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log N)$ で行うことが出来ます。詳細な要件は [Appendix](https://atcoder.github.io/ac-library/master/document_ja/appendix.html) を参照してください。

また、このライブラリはオラクルとして`op, e`の2種類を使用しますが、これらが定数時間で動くものと仮定したときの計算量を記述します。オラクル内部の計算量が $O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となります。

## コンストラクタ

```cpp
(1) segtree<S, op, e> seg(int n)
(2) segtree<S, op, e> seg(vector<S> v)
```

- 型 `S`
- 二項演算 `S op(S a, S b)`
- 単位元 `S e()`

を定義する必要があります。例として、Range Min Queryならば

```cpp
int op(int a, int b) {
    return min(a, b);
}

int e() {
    return (int)(1e9);
}

segtree<int, op, e> seg(10);
```

のようになります。

- (1): 長さ `n` の数列 `a` を作ります。初期値は全部`e()`です。
- (2): 長さ `n = v.size()` の数列 `a` を作ります。`v` の内容が初期値となります。

詳しくは、使用例や [こちら](https://atcoder.jp/contests/practice2/editorial) も参照してください。

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n)$

## set

```cpp
void seg.set(int p, S x)
```

`a[p]` に `x` を代入します。

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

## get

```cpp
S seg.get(int p)
```

`a[p]` を返します。

**制約**

- $0 \leq p < n$

**計算量**

- $O(1)$

## prod

```cpp
S seg.prod(int l, int r)
```

`op(a[l], ..., a[r - 1])` を、モノイドの性質を満たしていると仮定して計算します。$l = r$ のときは `e()` を返します。

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## all_prod

```cpp
S seg.all_prod()
```

`op(a[0], ..., a[n - 1])` を計算します。$n = 0$ のときは `e()` を返します。

**計算量**

- $O(1)$

## max_right

```cpp
(1) int seg.max_right<f>(int l)
(2💻) int seg.max_right<F>(int l, F f)
```

- (1): 関数 `bool f(S x)` を定義する必要があります。segtreeの上で二分探索をします。  
- (2): `S`を引数にとり`bool`を返す関数オブジェクトを渡して使用します。  

以下の条件を両方満たす `r` を(いずれか一つ)返します。

- `r = l` もしくは `f(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = n` もしくは `f(op(a[l], a[l + 1], ..., a[r])) = false`

`f`が単調だとすれば、`f(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最大の `r`、と解釈することが可能です。

**制約**

- `f`を同じ引数で呼んだ時、返り値は等しい(=副作用はない)
- `f(e()) = true`
- $0 \leq l \leq n$

**計算量**

- $O(\log n)$

## min_left

```cpp
(1) int seg.min_left<f>(int r)
(2💻) int seg.min_left<F>(int r, F f)
```

- (1): 関数 `bool f(S x)` を定義する必要があります。segtreeの上で二分探索をします。  
- (2): `S`を引数にとり`bool`を返す関数オブジェクトを渡して使用します。  

以下の条件を両方満たす `l` を(いずれか一つ)返します。

- `l = r` もしくは `f(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` もしくは `f(op(a[l - 1], a[l], ..., a[r - 1])) = false`

`f`が単調だとすれば、`f(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最小の `l`、と解釈することが可能です。

**制約**

- `f`を同じ引数で呼んだ時、返り値は等しい(=副作用はない)
- `f(e()) = true`
- $0 \leq r \leq n$

# Lazy Segtree

[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) $(S, \cdot: S \times S \to S, e \in S)$と、$S$ から $S$ への写像の集合 $F$ であって、以下の条件を満たすようなものについて使用できるデータ構造です。

- $F$ は恒等写像 $\mathrm{id}$ を含む。つまり、任意の $x \in S$ に対し $\mathrm{id}(x) = x$ をみたす。
- $F$ は写像の合成について閉じている。つまり、任意の $f, g \in F$ に対し $f \circ g \in F$ である。
- 任意の $f \in F, x, y \in S$ に対し $f(x \cdot y) = f(x) \cdot f(y)$ をみたす。

長さ $N$ の $S$ の配列に対し、

- 区間の要素に一括で $F$ の要素 $f$ を作用($x = f(x)$ )
- 区間の要素の総積の取得

を $O(\log N)$ で行うことが出来ます。詳細な要件は [Appendix](https://atcoder.github.io/ac-library/master/document_ja/appendix.html) を参照してください。

また、このライブラリはオラクルとして`op, e, mapping, composition, id`を使用しますが、これらが定数時間で動くものと仮定したときの計算量を記述します。オラクル内部の計算量が $O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となります。

## コンストラクタ

```cpp
(1) lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
(2) lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<S> v);
```

- モノイドの型 `S`
- $\cdot: S \times S \to S$ を計算する関数 `S op(S a, S b)`
- $e$ を返す関数 `S e()`
- 写像の型 `F`
- $f(x)$ を返す関数 `S mapping(F f, S x)`
- $f \circ g$ を返す関数 `F composition(F f, F g)`
- $id$ を返す関数 `F id()`

を定義する必要があります。
詳しくは、使用例や [こちら](https://atcoder.jp/contests/practice2/editorial) も参照してください。

- (1): 長さ `n` の数列 `a` を作ります。初期値は全部`e()`です。
- (2): 長さ `n = v.size()` の数列 `a` を作ります。`v` の内容が初期値となります。

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n)$

## set

```cpp
void seg.set(int p, S x)
```

`a[p] = x`

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

## get

```cpp
S seg.get(int p)
```

`a[p]` を返します。

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

## prod

```cpp
S seg.prod(int l, int r)
```

`op(a[l], ..., a[r - 1])` を、モノイドの性質を満たしていると仮定して計算します。$l = r$ のときは `e()` を返します。

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## all_prod

```cpp
S seg.all_prod()
```

`op(a[0], ..., a[n-1])` を計算します。$n = 0$ のときは `e()` を返します。

**計算量**

- $O(1)$

## apply

```cpp
(1) void seg.apply(int p, F f)
(2) void seg.apply(int l, int r, F f)
```

- (1) `a[p] = f(a[p])`
- (2) `i = l..r-1`について`a[i] = f(a[i])`

**制約**

- (1) $0 \leq p < n$
- (2) $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## max_right

```cpp
(1) int seg.max_right<g>(int l)
(2💻) int seg.max_right<G>(int l, G g)
```

- (1): 関数 `bool g(S x)` を定義する必要があります。segtreeの上で二分探索をします。  
- (2): `S`を引数にとり`bool`を返す関数オブジェクトを渡して使用します。  

以下の条件を両方満たす `r` を(いずれか一つ)返します。

- `r = l` もしくは `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = n` もしくは `g(op(a[l], a[l + 1], ..., a[r])) = false`

`g`が単調だとすれば、`g(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最大の `r`、と解釈することが可能です。

**制約**

- `g`を同じ引数で呼んだ時、返り値は等しい(=副作用はない)
- `g(e()) = true`
- $0 \leq l \leq n$

**計算量**

- $O(\log n)$

## min_left

```cpp
(1) int seg.min_left<g>(int r)
(2💻) int seg.min_left<G>(int r, G g)
```

- (1): 関数 `bool g(S x)` を定義する必要があります。segtreeの上で二分探索をします。  
- (2): `S`を引数にとり`bool`を返す関数オブジェクトを渡して使用します。  

以下の条件を両方満たす `l` を(いずれか一つ)返します。

- `l = r` もしくは `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` もしくは `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

`g`が単調だとすれば、`g(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最小の `l`、と解釈することが可能です。

**制約**

- `g`を同じ引数で呼んだ時、返り値は等しい(=副作用はない)
- `g(e()) = true`
- $0 \leq r \leq n$

**計算量**

- $O(\log n)$