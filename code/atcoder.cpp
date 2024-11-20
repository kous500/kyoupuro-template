#include <bits/stdc++.h>
#include<atcoder/all>
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
#define IN(T, ...) T __VA_ARGS__; input(__VA_ARGS__)
#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; input(__VA_ARGS__)
#define VI(v, n) Vi v(n); input(v)
#define VL(v, n) Vl v(n); input(v)
#define VS(v, n) Vs v(n); input(v)
#define VC(v, n) Vc v(n); input(v)
#define VB(v, n) Vb v(n); input(v)
#define VD(v, n) Vd v(n); input(v)
#define VVI(v, n, m) VVi v(n, Vi(m)); input(v)
#define VVL(v, n, m) VVl v(n, Vl(m)); input(v)
#define VVS(v, n, m) VVs v(n, Vs(m)); input(v)
#define VVC(v, n, m) VVc v(n, Vc(m)); input(v)
#define VVB(v, n, m) VVb v(n, Vb(m)); input(v)
#define VVD(v, n, m) VVd v(n, Vd(m)); input(v)

#define all(i) begin(i),end(i)
#define rall(i) rbegin(i),rend(i)
#define REF [&]

using namespace std;
using namespace atcoder;

using ll = long long;
template<class T> using Pque = priority_queue<T>;
template<class T> using Pqueg = priority_queue<T, vector<T>, greater<T>>;
template<class F, class S> using P = pair<F, S>;
using Pi = P<int, int>;
using Pl = P<ll, ll>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = V<V<V<T>>>;
using Vi = V<int>; using VVi = VV<int>; using VVVi = VVV<int>;
using Vl = V<ll>; using VVl = VV<ll>; using VVVl = VVV<ll>;
using Vs = V<string>; using VVs = VV<string>; using VVVs = VVV<string>;
using Vc = V<char>; using VVc = VV<char>; using VVVc = VVV<char>;
using Vb = V<bool>; using VVb = VV<bool>; using VVVb = VVV<bool>;
using Vd = V<double>; using VVd = VV<double>; using VVVd = VVV<double>;

constexpr int INF = 1e9;
constexpr ll INF_l = 2e18;

template<typename T> inline std::istream& operator>>(istream& is, vector<T>& v) { for (T& in : v) is >> in; return is; }
template<typename F, typename S> inline std::istream& operator>>(istream& is, pair<F, S>& p) { is >> p.first >> p.second; return is; }
template<class... T> inline void input(T&... a) { (cin >> ... >> a); }

template<typename T> inline std::ostream& operator<<(ostream& os, vector<T> v) { rep(i, v.size()) { os << v[i]; if (i < (int)v.size() - 1) os << ' '; }; return os; }
template<typename F, typename S> inline std::ostream& operator<<(ostream& os, pair<F, S> p) { os << '[' << p.first << ' ' << p.second << ']'; return os; }
inline void print() { cout << '\n'; }
template<class T> inline void print(T a) { cout << a << '\n'; }
template<class T, class... Ts> inline void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); print(); }
inline void fprint(double a) { cout << fixed << setprecision(15) << a << '\n'; }
template<class T> inline void debug2d(VV<T> &v) { for (auto &r : v) rep(i, r.size()) cout << r[i] << (i == (int)r.size() - 1 ? "\n" : ", "); }
inline void yesno(bool a) { cout << (string)(a ? "Yes\n" : "No\n"); }

template<class... T> constexpr auto MIN(T... a) { return min(initializer_list{a...}); }
template<class... T> constexpr auto MAX(T... a) { return max(initializer_list{a...}); }
template<class T> constexpr bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> constexpr bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> constexpr ll sum(V<T> &v) { return accumulate(all(v), 0LL); }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

}