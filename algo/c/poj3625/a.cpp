#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int) x.size())
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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1010, C = 110;

int n, m, d[N][C];
bool v[N][C];
arr<int, N> p {};
vector<PII> e[N];
priority_queue<pair<int, pair<int, int>>> q;

void tank() {
    int c, st, ed;
    cin >> c >> st >> ed;
    priority_queue<pair<int, pair<int, int>>> empty;
    swap(q, empty);
    memset(d, 0x3f, sizeof d);
    q.push({0, {st, 0}});
    d[st][0] = 0;
    memset(v, 0, sizeof v);
    while (q.size()) {
        int city = q.top().se.fi;
        int fuel = q.top().se.se;
        q.pop();
        if (city == ed) {
            cout << d[city][fuel] << "\n";
            return;
        }
        if (v[city][fuel]) continue;
        v[city][fuel] = 1;
        if (fuel < c && d[city][fuel + 1] > d[city][fuel] + p[city]) {
            d[city][fuel + 1] = d[city][fuel] + p[city];
            q.push(mp(-d[city][fuel] - p[city], mp(city, fuel + 1)));
        }
        for (auto i : e[city]) {
            int y = i.fi, z = i.se;
            if (z <= fuel && d[y][fuel - z] > d[city][fuel]) {
                d[y][fuel - z] = d[city][fuel];
                q.push(mp(-d[city][fuel], mp(y, fuel - z)));
            }
        }
    }
    cout << "impossible\n";
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> p[i];
    }
    rep(i, 0, m) {
        int u, v, d;
        cin >> u >> v >> d;
        e[u].pb(mp(v, d));
        e[v].pb(mp(u, d));
    }
    int q; cin >> q;
    while (q--) {
        tank();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}