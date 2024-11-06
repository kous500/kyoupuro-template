# [index](index.md) > 動的計画法

## 汎用DP

```cpp
template<class A, class R> struct Dp {
    map<A, R> mp;
    function<R(A, function<R(A)>)> f;

    Dp(function<R(A, function<R(A)>)> f) : f(f) {}
    
    R get(A x) {
        if (mp.count(x)) return mp[x];
        return mp[x] = f(x, [this](A x) { return this->get(x); });
    }
};
```

## 1次元DP

```cpp
template<class T> struct Dp1d {
    V<T> dp;
    V<bool> done;
    function<T(int, function<T(int)>)> f;

    Dp1d(int size, function<T(int, function<T(int)>)> f) : dp(size), done(size), f(f) {}

    T get(int x1) {
        if (done[x1]) return dp[x1];
        done[x1] = true;
        return dp[x1] = f(x1, [this](int x1) { return this->get(x1); });
    }
};
```

## 2次元DP

```cpp
template<class T> struct Dp2d {
    VV<T> dp;
    VV<bool> done;
    function<T(int, int, function<T(int, int)>)> f;

    Dp2d(int size1, int size2, function<T(int, int, function<T(int, int)>)> f) : dp(size1, V<T>(size2)), done(size1, V<bool>(size2)), f(f) {}

    T get(int x1, int x2) {
        if (done[x1][x2]) return dp[x1][x2];
        done[x1][x2] = true;
        return dp[x1][x2] = f(x1, x2, [this](int x1, int x2) { return this->get(x1, x2); });
    }
};
```

## 3次元DP

```cpp
template<class T> struct Dp3d {
    VVV<T> dp;
    VVV<bool> done;
    function<T(int, int, int, function<T(int, int, int)>)> f;

    Dp3d(int size1, int size2, int size3, function<T(int, int, int, function<T(int, int, int)>)> f) : dp(size1, VV<T>(size2, V<T>(size3))), done(size1, VV<bool>(size2, V<bool>(size3))), f(f) {}

    T get(int x1, int x2, int x3) {
        if (done[x1][x2][x3]) return dp[x1][x2][x3];
        done[x1][x2][x3] = true;
        return dp[x1][x2][x3] = f(x1, x2, x3, [this](int x1, int x2, int x3) { return this->get(x1, x2, x3); });
    }
};
```