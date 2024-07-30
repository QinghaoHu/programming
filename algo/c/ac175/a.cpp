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

int r, c;
char g[510][510];
int d[510][510];

int bfs() {
    memset(d, 0x3f, sizeof d);
    deque<PII> dq;
    dq.push_front(mp(0, 0));
    d[0][0] = 0;
    arr<int, 4> dx{{-1, -1, 1, 1}}, dy{{-1, 1, 1, -1}};
    arr<int, 4> ix{{-1, -1, 0, 0}}, iy{{-1, 0, 0, -1}};
    arr<char, 4> cs{{'\\', '/', '\\', '/'}};
    while (SZ(dq)) {
        auto t = dq.front();
        dq.pop_front();
        int x = t.fi, y = t.se;
        rep(i, 0, 4) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a <= r && b >= 0 && b <= c) {
                int w = 0;
                int j = x + ix[i], k = y + iy[i];
                if (g[j][k] != cs[i]) {
                    w++;
                }
                if (d[a][b] > d[x][y] + w) {
                    d[a][b] = d[x][y] + w;
                    if (w) {
                        dq.push_back({a, b});
                    } else {
                        dq.push_front(mp(a, b));
                    }
                }
            }
        }
    }
    if (d[r][c] == INF) {
        return -1;
    }
    return d[r][c];
}

void solve() {
    cin >> r >> c;
    rep(i, 0, r) {
        rep(j, 0, c) {
            cin >> g[i][j];
        }
    }
    int t = bfs();
    if (t == -1) {
        cout << "NO SOLUTION\n";
    } else {
        cout << t << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
