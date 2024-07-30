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

void solve() {
    int n, m;
    cin >> n >> m;
    array<array<char, 200>, 200> g;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> g[i][j];
        }
    }
    vector<vector<int> > dist(n, vector<int> (m, INF));
    auto bfs = [&]() -> void {
        queue<PII> heap;
        rep(i, 0, n) {
            rep(j, 0, m) {
                if (g[i][j] == '1') {
                    dist[i][j] = 0;
                    heap.push(mp(i, j));
                }
            }
        }
        array<array<int, 2>, 4> d = {{{1, 0}, {0, -1}, {-1, 0}, {0, 1}}};
        while (!heap.empty()) {
            auto t = heap.front();
            heap.pop();
            rep(i, 0, 4) {
                int x = t.fi + d[i][0], y = t.se + d[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                int val = dist[t.fi][t.se] + 1;
                if (dist[x][y] == INF) {
                    dist[x][y] = val;
                    heap.push(mp(x, y));
                }
            }
        }
    };
    bfs();
    rep(i, 0, n) {
        rep(j, 0, m) {
            cout << dist[i][j] << " \n"[j == m - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}