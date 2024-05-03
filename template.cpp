#include<bits/stdc++.h>
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
using namespace atcoder;
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

const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

struct UnionFind {
    vector<int> par;
    
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

random_device rd;
mt19937 gen(rd());

template<class T> T rand_uniform(T n, T m) {
    uniform_int_distribution<T> distribution(n, m);
    return distribution(gen);
}

double rand_normal(double n, double m) {
    normal_distribution<> distribution(n, m);
    return distribution(gen);
}

template<class T> T three_part_search(T left, T right, function<T(T)> f) {
    while (abs(right - left) > 1e-9) {
        T mid1 = left + (right - left) / 3;
        T mid2 = right - (right - left) / 3;
        if (f(mid1) < f(mid2)) right = mid2;
        else left = mid1;
    }
    return left;
}

int binary_search(vector<int> a, int key) {
    int left = 0, right = (int)a.size() - 1; // 配列 a の左端と右端
    while (right >= left) {
        int mid = left + (right - left) / 2; // 区間の真ん中
        if (a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int lower_binary_search(vector<int> a, int key) {
    auto isOK = [](int index, int key) { return true; };

    int ng = -1, ok = (int)a.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

template<class T> vector<T> coordinate_compression(vector<T>& a) {
    vector<T> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<T> res(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    return res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void up_low_case(char c) {
    cout << static_cast<char>(tolower(c)); // 小文字に
    cout << static_cast<char>(toupper(c)); // 大文字に
}

int ceil_division(int a, int b) { return (a + b - 1) / b; }

vector<int> binary(int x) {
    vector<int> bit(30);
    for (int i = 0; i < 30; i++) {
        int Div = (1 << i);
        bit[i] = (x / Div) % 2;
    }
    return bit;
}

bool char_regex_match(char c, string s) {
    return regex_match(string({c}), regex(s));
}

int sum(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(15);
}