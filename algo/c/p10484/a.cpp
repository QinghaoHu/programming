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

struct State {
    int x, y, lie;
};

const int N = 510;

int n, m;
char g[N][N];
int dist[N][N][3];



void solve() {
    while (cin >> n >> m, n || m) {
        rep(i, 0, n) {
            rep(j, 0, m) {
                cin >> g[i][j];
            }
        }
        State start = {-1}, end;
        rep(i, 0, n) {
            rep(j, 0, m) {
                if (g[i][j] == 'X' && start.x == -1) {
                    if (g[i + 1][j] == 'X') {
                        start = {i, j, 2};
                    } else if (g[i][j + 1] == 'X') {
                        start = {i, j, 1};
                    } else {
                        start = {i, j, 0};
                    }
                } else if (g[i][j] == 'O') {
                    end = {i, j, 0};
                }
            }
        }
        auto check = [&](int x, int y) -> bool{
            if (x < 0 || x >= n || y < 0 || y >= m) {
                return false;
            }
            return g[x][y] != '#';
        };
        auto bfs = [&](State start, State end) -> int{
            queue<State> q;
            memset(dist, -1, sizeof dist);
            dist[start.x][start.y][start.lie] = 0;
            q.push(start);
            int d[3][4][3] = {
                {{-2, 0, 2}, {0, 1, 1}, {1, 0, 2}, {0, -2, 1}},
                {{-1, 0, 1}, {0, 2, 0}, {1, 0, 1}, {0, -1, 0}},
                {{-1, 0, 0}, {0, 1, 2}, {2, 0, 0}, {0, -1, 2}}
            };
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                rep(i, 0, 4) {
                    State next = {t.x + d[t.lie][i][0], t.y + d[t.lie][i][1], d[t.lie][i][2]};
                    int x = next.x, y = next.y;
                    if (!check(x, y)) {
                        continue;
                    }
                    if (next.lie == 0) {
                        if (g[x][y] == 'E') {
                            continue;
                        }
                    } else if (next.lie == 1) {
                        if (!check(x, y + 1)) {
                            continue;
                        }
                    } else {
                        if (!check(x + 1, y)) {
                            continue;
                        }
                    }
                    if (dist[next.x][next.y][next.lie] == -1) {
                        dist[next.x][next.y][next.lie] = dist[t.x][t.y][t.lie] + 1;
                        q.push(next);
                    }
                 }
            }
            return dist[end.x][end.y][end.lie];
        };
        int res = bfs(start, end);
        if (res == -1) {
            cout << "Impossible\n";
        } else {
            cout << res << "\n";
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