# [index](index.md) > 最大公約数・最小公倍数

```cpp
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return a / d * b;
}
```
- **ll gcd(ll a, ll b)**: `a`, `b` の最大公約数を求めます。
- **ll lcm(ll a, ll b)**: `a`, `b` の最小公倍数を求めます。