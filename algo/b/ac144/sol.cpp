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

const int N = 1e5 + 10;

int n;
int x[N];
bool st[N];
int trie[N * 32][2];
vector<PII> path[N];

void dfs(int u) {
    for (auto i : path[u]) {
        if (!st[i.fi]) {
            st[i.fi] = 1;
            x[i.fi] = i.se ^ x[u];
            dfs(i.fi);
        }
    }
}

void solve() {
    cin >> n;
    int k = 0;
    rep(i, 0, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        path[u].eb(mp(v, w));
        path[v].eb(mp(u, w));
        k = u;
    }
    st[k] = 1;
    dfs(k);
    int tot = 0;
    auto insertt = [&](int a) {
        int p = 0;
        per(i, 31, 0) {
            int s = a >> i & 1;
            if (!trie[p][s]) {
                trie[p][s] = ++tot;
            }
            p = trie[p][s];
        }
    };
    auto search = [&](int a) {
        int ans = 0, t = 0;
        per(i, 31, 0) {
            int s = a >> i & 1;
            if (trie[t][!s] == 0) {
                t = trie[t][s];
            } else {
                ans += 1 << i;
                t = trie[t][!s];
            }
        }
        return ans;
    };
    rep(i, 1, n + 1) {
        insertt(x[i]);
    }
    int ans = 0;
    rep(i, 1, n + 1) {
        ans = max(ans, search(x[i]));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
