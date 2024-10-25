# [index](index) > 大文字小文字

## 小文字へ

```cpp
string to_lower(string s) {
    rep(i, s.size()) s[i] = tolower(s[i]);
    return s;
}
```

## 大文字へ

```cpp
string to_upper(string s) {
    rep(i, s.size()) s[i] = toupper(s[i]);
    return s;
}
```