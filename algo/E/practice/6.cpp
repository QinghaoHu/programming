#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

const int N = 200010;
int n, L, ans, maxv[N], sz[N];;
bool del[N];
vector<pair<int, int>> e[N];

void solve(int u, int size) {
    int ms = size + 1, root = -1;
    int v, w;

    function<void(int, int)> dfs1 = [&](int u, int par) {
        sz[u] = 1;
        maxv[u] = 0;
        for (auto [v, w] : e[u]) {
            if (v == par || del[v]) continue;
            dfs1(v, u);
            maxv[u] = max(maxv[u], sz[v]);
            sz[u] += sz[v];
        }
        maxv[u] = max(maxv[u], size - sz[u]);
        if (maxv[u] < ms) {
            ms = maxv[u], root = u;
        }
    };

    dfs1(u, -1);
    unordered_map<ll, int> dis;
    dis[0] = 0;

    for (auto [v, w] : e[root]) {
        if (del[v]) continue;
        vector<pair<ll, int>> d;

        function<void(int, int, int, int)> dfs2 = [&](int u, int par, ll dep, int d2) {
            sz[u] = 1;
            d.push_back({dep, d2});
            for (auto [v, w] : e[u]) {
                if (del[v] || v == par) continue;
                dfs2(v, u, dep + w, d2 + 1);
                sz[u] += sz[v];
            }
        };

        dfs2(v, root, w, 1);

        for (auto [d1, d2] : d) {
            if (dis.count(L - d1)) {
                ans = min(ans, dis[L - d1] + d2);
            }
        }

        for (auto [d1, d2] : d) {
            if (!dis.count(d1)) {
                dis[d1] = d2;
            } else {
                dis[d1] = min(d2, dis[d1]);
            }
        }
    }

    del[root] = true;

    for (auto [v, w] : e[root]) {
        if (!del[v]) solve(v, sz[v]);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L;
    rep(i, 0, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u++; v++;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    ans = n + 1;

    solve(1, n);

    if (ans == n + 1) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}