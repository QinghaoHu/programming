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
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<ll> s(n + 1, 0); FOR(i, 1, n + 1) cin >> s[i];
    FOR(i, 1, n + 1) s[i] += s[i - 1];

    array<ll, 1000010> q {}, f {};
    int h = 1, t = 1;
    auto getx = [&](int x) -> ll {
        return s[x];
    };
    auto gety = [&](int x) -> ll {
        return f[x] + a * s[x] * s[x] - b * s[x];
    };
    auto slope = [&](int x, int y) -> ld {
        return (ld)(gety(x) - gety(y)) / (getx(x) - getx(y));
    };
    for (int i = 1; i <= n; i++) {
        while (h < t && slope(q[h], q[h + 1]) >= (ld)2.0 * a * s[i]) h++;
        int j = q[h];
        f[i] = f[j] + a * s[j] * s[j] - b * s[j] + a * s[i] * s[i] + b * s[i] + c - 2 * a * s[i] * s[j];
        while (h < t && slope(q[t - 1], q[t]) <= slope(q[t], i)) t--;
        q[++t] = i;
    }
    cout << f[n] << '\n';

    return 0;
}
