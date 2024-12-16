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

void solve() {
    int n, k; cin >> n >> k;
    k--;
    ll a[500010]{}, s[500010] {}, dp[500010] {};
    FOR(i, 1, n + 1) {
        cin >> a[i]; 
        s[i] = s[i - 1] + a[i];
    }

    auto getY = [&](int y) -> ll {
        return dp[y] - s[y] + y * a[y + 1];
    };
    auto getX = [&](int y) -> ll {
        return a[y + 1];
    };

    int l = 1, r = 1, q[500010] {};
    for (int i = 1; i <= n; i++) {
        if (i <= k) {dp[i] = INF; continue;}
        while (l < r && getY(q[l + 1]) - getY(q[l]) <= i * (getX(q[l + 1]) - getX(q[l]))) l++;
        dp[i] = dp[q[l]] + s[i] - s[q[l]] - (i - q[l]) * a[q[l] + 1];
        while (l < r && (getY(q[r]) - getY(q[r - 1])) * (getX(i - k) - getX(q[r])) >= (getY(i - k) - getY(q[r])) * (getX(q[r]) - getX(q[r - 1]))) r--;
        q[++r] = i - k;
    }
    cout << dp[n] << '\n';
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
