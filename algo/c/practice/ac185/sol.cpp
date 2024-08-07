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
#define VI vector<int>
#define SZ(x) ((int)x.size()) 
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
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

struct p {
    int x, y, d;
}paths[5];

int n;
int g[5][7], bg[5][5][7];
int cnt[11], bcnt[5][11];
bool st[5][7];

void move(int a, int b, int c) {
    swap(g[a][b], g[c][b]);
    while (true) {
        bool flag = true;
        rep(x, 0, 5) {
            int z = 0;
            rep(y, 0, 7) {
                if (g[x][y]) {
                    g[x][z++] = g[x][y];
                }
            }
            while (z < 7) {
                g[x][z++] = 0;
            }
        }
        memset(st, 0, sizeof st);
        rep(x, 0, 5) {
            rep(y, 0, 7) {
                if (g[x][y]) {
                    int l = x, r = x;
                    while (l - 1 >= 0 && g[l - 1][y] == g[x][y]) {
                        l--;
                    }
                    while (r + 1 < 5 && g[r + 1][y] ==  g[x][y]) {
                        r++;
                    }
                    if (r - l + 1 >= 3) {
                        st[x][y] = true;
                        flag = false;
                    } else {
                        l = r = y;
                        while (l - 1 >= 0 && g[x][l - 1] == g[x][y]) {
                            l--;
                        }
                        while (r + 1 < 7 && g[x][r + 1] == g[x][y]) {
                            r++;
                        }
                        if (r - l + 1 >= 3) {
                            st[x][y] = true;
                            flag  = false;
                        }
                    }
                }
            }
        }
        if (flag)break;
        rep(i, 0, 5) {
            rep(j, 0, 7) {
                if (g[i][j]) {
                    if (st[i][j]) {
                        cnt[g[i][j]]--;
                        cnt[0]--;
                        g[i][j] = 0;
                    }
                }
            }
        }
    }
}

bool dfs(int u) {
    if (u == n) {
        return !cnt[0];
    }
    rep(i, 1, 11) {
        if (cnt[i] == 1 || cnt[i] == 2) {
            return false;
        }
    }
    memcpy(bg[u], g, sizeof g);
    memcpy(bcnt[u], cnt, sizeof cnt);
    rep(x, 0, 5) {
        rep(y, 0, 7) {
            if (g[x][y]) {
                int nx = x + 1;
                if (nx < 5) {
                    paths[u] = {x, y, 1};
                    move(x, y, nx);
                    if (dfs(u + 1)) {
                        return true;
                    }
                    memcpy(g, bg[u], sizeof g);
                    memcpy(cnt, bcnt[u], sizeof cnt);
                }
                nx = x - 1;
                if (nx >= 0 && !g[nx][y]) {
                    paths[u] = {x, y, -1};
                    move (x, y, nx);
                    if (dfs(u + 1)) {
                        return true;
                    }
                    memcpy(g, bg[u], sizeof g);
                    memcpy(cnt, bcnt[u], sizeof cnt);
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(x, 0, 5) {
        int t, y = 0;
        while (cin >> t, t) {
            cnt[t]++;
            g[x][y++] = t;
            cnt[0]++;
        }
    }
    if (dfs(0)) {
        rep(i, 0, n) {
            cout << paths[i].x << ' ' << paths[i].y << ' ' << paths[i].d << " \n";
        }
    } else {
        cout << -1 << " \n";
    }

    return 0;
}
