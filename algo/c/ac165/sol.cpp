#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 55;

int n, w, cnt;
ll a[N];
ll weight[N];

void dfs(int u, int sz) {
    if (sz >= cnt) {
        return;
    }
    if (u == n + 1) {
        cnt = min(cnt, sz);
        return;
    }
    int c = a[u];
    rep(i, 1, sz + 1) {
        if (weight[i] + c <= w) {
            weight[i] += c;
            dfs(u + 1, sz);
            weight[i] -= c;
        }
    }
    weight[sz + 1] = c;
    dfs(u + 1, sz + 1);
    weight[sz + 1] = 0;
}

void solve() {
    cin >> n >> w;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    auto cmp = [&](ll a, ll b) -> bool {
        return a > b;
    };
    sort(a + 1, a + n + 1, cmp);
    cnt = INF;
    dfs(1, 0);
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    rep(i, 0, T) {
        solve();
    }

    return 0;
}
