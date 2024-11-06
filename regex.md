# [index](index.md) > 正規表現

```cpp
bool is_match(string s, string reg) {
    return regex_match(s, regex(reg));
}

bool is_match(char c, string reg) {
    return regex_match(string({c}), regex(s));
}
```