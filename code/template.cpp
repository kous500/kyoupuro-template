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
#define VVI(v, n, m) V<Vi> v(n, Vi(m)); input(v)
#define VVL(v, n, m) V<Vl> v(n, Vl(m)); input(v)
#define VVS(v, n, m) V<Vs> v(n, Vs(m)); input(v)
#define VVC(v, n, m) V<Vc> v(n, Vc(m)); input(v)
#define VVB(v, n, m) V<Vb> v(n, Vb(m)); input(v)
#define VVD(v, n, m) V<Vd> v(n, Vd(m)); input(v)

#define all(i) begin(i),end(i)
#define rall(i) rbegin(i),rend(i)
#define REF [&]

using namespace std;
using namespace atcoder;

template<class T> using Pque = priority_queue<T>;
template<class T> using Pqueg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using P = pair<T, T>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = V<V<V<T>>>;
using ll = long long;
using Vi = V<int>;
using Vl = V<ll>;
using Vs = V<string>;
using Vc = V<char>;
using Vb = V<bool>;
using Vd = V<double>;

const int INF = 1e9;
const ll INF_l = 1e18;

template<typename T> std::istream& operator>>(istream& is, vector<T>& v) { for (T& in : v) is >> in; return is; }
template<typename F, typename S> std::istream& operator>>(istream& is, pair<F, S>& p) { is >> p.first >> p.second; return is; }
template<class... T> void input(T&... a) { (cin >> ... >> a); }

template<typename T> std::ostream& operator<<(ostream& os, vector<T> v) { rep(i, v.size()) { os << v[i]; if (i < (int)v.size() - 1) os << ' '; }; return os; }
template<typename F, typename S> std::ostream& operator<<(ostream& os, pair<F, S> p) { os << p.first << ' ' << p.second; return os; }
void print() { cout << '\n'; }
template<class T> void print(T a) { cout << a << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); print(); }
void fprint(double a) { cout << fixed << setprecision(15) << a << '\n'; }
void yesno(bool a) { cout << (string)(a ? "Yes\n" : "No\n"); }

template<class... T> constexpr auto MIN(T... a) { return min(initializer_list{a...}); }
template<class... T> constexpr auto MAX(T... a) { return max(initializer_list{a...}); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> ll sum(V<T> &v) { return accumulate(all(v), 0LL); }

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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    using mint = modint1000000007;

    INT(n);
    LL(k);
    VV<mint> a(n);
    

    auto ak = matrixpow(a, k);
    mint ans = 0;
    rep(i, n) rep(j, n) ans += ak[i][j];
    print(ans.val());
}