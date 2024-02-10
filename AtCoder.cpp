#include<bits/stdc++.h>
//#include<atcoder/all>
#define overload4(a, b, c, d, e, ...) e
#define rep1(a) for (int i = 0; i < (int)(a); i++)
#define rep2(i, a) for (int i = 0; i < (int)(a); i++)
#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep4(i, a, b, c) for (int i = (int)(a); i < (int)(b); i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(a) for (int i = (int)(a); i--;)
#define rrep2(i, a) for (int i = (int)(a); i--;)
#define rrep3(i, a, b) for (int i = (int)(b); i-- > (int)(a);)
#define rrep4(i, a, b, c) for(int i = (int)(a) + ((int)(b) - (int)(a) - 1) / (int)(c) * (int)(c); i >= (int)(a); i -= (int)(c))
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define ll long long
#define V vector
#define VV(T) V<V<T>>
#define Vi V<int>
#define Vl V<ll>
#define Vs V<string>
#define Vc V<char>
#define Vb V<bool>
#define P(T) pair<T, T>
#define IN(T, ...) T __VA_ARGS__; input(__VA_ARGS__)
#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; input(__VA_ARGS__)
#define VIN(T, n, a) V(T) a(n); input(n, a)
#define VINT(n, a) VIN(int, n, a)
#define all(i) begin(i),end(i)
#define rall(i) rbegin(i),rend(i)

using namespace std;
//using namespace atcoder;
const int INF = 1e9;
const ll INF_l = 1e18;
template<class... T> void input(T&... a) { (cin >> ... >> a); }
template<class T> void input(int n, V<T>& a) { a = V<T>(n); rep(i, n) input(a[i]); }
template<class T> void input(V<T>& a) { input((int)a.size(), a); }
void print() { cout << '\n'; }
template<class T> void print(T a) { cout << a << '\n'; }
template<class T, class Ts> void print(T a, Ts b) { cout << a << ' ' << b << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    print();
}
template<class T> void print(const V<T>& a) {
    rep(i, a.size()) cout << (T)a[i] << (char)(i + 1 != (int)a.size() ? ' ' : '\n');
}
void yesno(bool a) { cout << (string)(a ? "Yes\n" : "No\n"); }
template<class... T> constexpr auto MIN(T... a) { return min(initializer_list{a...}); }
template<class... T> constexpr auto MAX(T... a) { return max(initializer_list{a...}); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    
}