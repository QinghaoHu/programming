#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

template<typename T>
void _print(T x) {cerr << x << ' ';}
template<typename T>
void _println(T x) {cerr << x << '\n';}
void _print(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _println(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void _print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
void _println(vector<T> u) {for(auto i : u)_print(i); cerr << '\n';}

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

const int N = 1000010;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<ll> x(n + 1, 0); FOR(i, 1, n + 1) cin >> x[i];
    vector<ll> s(n + 1, 0);
    FOR(i, 1, n + 1) s[i] = s[i - 1] + x[i];
    
    array<int, N> f{}, q{};
    int l = 0, r = -1;
    auto getx = [&](int x) -> ll {
        return s[x];
    };
    auto gety = [&](int x) -> ll {
        return f[x] + a * s[x] * s[x] - b * s[x];
    };
    auto slope = [&](int x, int y) -> double {
        return 1.0 * (gety(x) - gety(y)) / (getx(x) - getx(y));
    };
    FOR(i, 1, n + 1) {
        while (l < r && slope(q[l], q[l + 1]) > 2 * a * s[i]) l++;
        int j = q[l];
        f[i] = f[j] + a * s[i] * s[i] - 2 * a * s[i] * s[j] + a * s[j] * s[j] + b * s[i] - b * s[j] + c;
        while (l < r && slope(q[r - 1], q[r]) <= slope(q[r], i)) r--;
        q[++r] = i;
    }
    cout << f[n] << '\n';

    return 0;
}
