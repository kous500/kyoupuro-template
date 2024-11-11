# [index](index.md) > 正規表現

```cpp
inline bool is_match(string s, string reg) {
    return regex_match(s, regex(reg));
}

inline bool is_match(char c, string reg) {
    return regex_match(string({c}), regex(s));
}
```