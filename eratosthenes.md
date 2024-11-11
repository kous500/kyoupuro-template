# [intdex](index.md) > エラトステネスの篩

```cpp
inline Vb eratosthenes(int n) {
    Vb is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    rep(i, 2, n + 1) if (is_prime[i]) for (int j = i * 2; j <= n; j += i) is_prime[j] = false;
    return is_prime;
}
```