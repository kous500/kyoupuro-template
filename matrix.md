# [index](index) > 行列

## 行列累乗

```cpp
template<class T> VV<T> matrixmul(VV<T> &a, VV<T> &b) {
    VV<T> res(a.size(), V<T>(b[0].size()));
    rep(a.size()) rep(j, b[0].size()) rep(k, b.size()) res[i][j] += a[i][k] * b[k][j];
    return res;
}

template<class T> VV<T> matrixpow(VV<T> a, ll n) {
    VV<T> res(a.size(), V<T>(a.size()));
    rep(a.size()) res[i][i] = 1;
    while (n > 0) {
        if (n & 1) res = matrixmul(res, a);
        a = matrixmul(a, a);
        n >>= 1;
    }
    return res;
}
```

- **VV<T> matrixmul(VV<T> &a, VV<T> &b)**: 行列 `a`, `b` の積を求めます。
- **VV<T> matrixpow(VV<T> a, ll n)**: 行列 `a` の `n` 乗を求めます。

## 基礎知識

次のような2次の漸化式を考えます。

$
\quad x_{n+1}=ax_n+bx_n\\
\quad y_{n+1}=ay_n+by_n\\
$

このときの状態ベクトル $v_n$ を次のように定義します。

$
\quad v_n=
\begin{pmatrix}
x_n \\
y_n
\end{pmatrix}
$

行列 $A$ を $A=
\begin{pmatrix}
a & b \\
c & d
\end{pmatrix}
$ とすると、漸化式を$v_{n+1}=Av_n$で表現できます。

よって、初期状態を $v_0$ とすると $v_n=A^nv_0$ が成り立ちます。

$A^n$ を繰り返し２乗法で求めることで、$v_n$ を高速に計算することができます。