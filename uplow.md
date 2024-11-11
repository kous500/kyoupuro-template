# [index](index.md) > 大文字小文字

## 小文字へ

```cpp
inline string to_lower(string s) {
    rep(i, s.size()) s[i] = tolower(s[i]);
    return s;
}
```

## 大文字へ

```cpp
inline string to_upper(string s) {
    rep(i, s.size()) s[i] = toupper(s[i]);
    return s;
}
```