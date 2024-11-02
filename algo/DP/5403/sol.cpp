#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll powmod(ll a, ll b, ll p) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
    }
    return res;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// head

void solve() {
    int n;
    cin >> n;

    const int N = 200010;
    vector<pair<int, int>> son[N * 2];
    vector<int> deg(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        son[x].push_back({y, z});
        son[y].push_back({x, z});
        deg[x]++;
        deg[y]++;
    }

    vector<int> f(n + 1, 0), v(n + 1, 0), d(n + 1, 0);
    function<void(int)> dp = [&](int x) {
        v[x] = 1;
        d[x] = 0;
        for (auto [y, w] : son[x]) {
            if (v[y]) continue;
            dp(y);
            if (deg[y] == 1) {
                d[x] += w;
            } else {
                d[x] += min(w, d[y]);
            }
        }
        v[x] = 0;
    };

    function<void(int)> dfs = [&](int x) {
        v[x] = 1;
        for (auto [y, w] : son[x]) {
            if (v[y]) continue;
            f[y] = d[y];
            if (deg[x] > 1 && deg[y] > 1) {
                f[y] += min(f[x] - min(w, d[y]), w);
            } else if (deg[x] > 1 && deg[y] == 1) {
                f[y] += min(f[x] - w, w);
            } else if (deg[x] == 1) {
                f[y] += w;
            }
            dfs(y);
        }
        v[x] = 0;
    };

    dp(1);
    f[1] = d[1];
    dfs(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
