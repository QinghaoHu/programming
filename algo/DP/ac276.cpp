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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector w(n + 1, vector<int>(m + 1, 0));
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            cin >> w[i][j];
        }
    }

    const int N = 16;
    int f[N][N * N][N][N][2][2];
    memset(f, -0x3f, sizeof f);
    struct State {
        int i, j, l, r, x, y;
    } g[N][N * N][N][N][2][2];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 1; l <= m; l++) {
                for (int r = l; r <= m; r++) {
                    if (j < r - l + 1) continue;

                    {
                        auto &vf = f[i][j][l][r][1][0];
                        auto &vg = g[i][j][l][r][1][0];
                        if (j == r - l + 1) {
                            vf = 0;
                        }
                        for (int p = l; p <= r; p++) {
                            for (int q = l; q <= r; q++) {
                                int val = f[i - 1][j - (r - l + 1)][p][q][1][0];
                                if (val > vf) {
                                    vf = val;
                                    vg = {i - 1, j - r + l - 1, p, q, 1, 0};
                                }
                            }
                        }
                        for (int u = l; u <= r; u++) {
                            vf += w[i][u];
                        }
                    }

                    {
                        auto &vf = f[i][j][l][r][0][1];
                        auto &vg = g[i][j][l][r][0][1];
                        if (j == r - l + 1) {
                            vf = 0;
                        }
                        for (int p = 1; p <= l; p++) {
                            for (int q = r; q <= m; q++) {
                                for (int y = 0; y <= 1; y++) {
                                    for (int x = 0; x <= 1; x++) {
                                        int val = f[i - 1][j - (r - l + 1)][p][q][x][y];
                                        if (val > vf) {
                                            vf = val;
                                            vg = {i - 1, j - r + l - 1, p, q, x, y};
                                        }
                                    }
                                }
                            }
                        }
                        for (int u = l; u <= r; u++) {
                            vf += w[i][u];
                        }
                    }

                    {
                        auto &vf = f[i][j][l][r][1][1];
                        auto &vg = g[i][j][l][r][1][1];
                        if (j == r - l + 1) {
                            vf = 0;
                        }
                        for (int p = l; p <= r; p++) {
                            for (int q = r; q <= m; q++) {
                                for (int y = 0; y <= 1; y++) {
                                    int val = f[i - 1][j - (r - l + 1)][p][q][1][y];
                                    if (val > vf) {
                                        vf = val;
                                        vg = {i - 1, j - r + l - 1, p, q, 1, y};
                                    }
                                }
                            }
                        }
                        for (int u = l; u <= r; u++) {
                            vf += w[i][u];
                        }
                    }

                    {
                        auto &vf = f[i][j][l][r][0][0];
                        auto &vg = g[i][j][l][r][0][0];
                        if (j == r - l + 1) {
                            vf = 0;
                        }
                        for (int p = 1; p <= l; p++) {
                            for (int q = l; q <= r; q++) {
                                for (int y = 0; y <= 1; y++) {
                                    int val = f[i - 1][j - (r - l + 1)][p][q][y][0];
                                    if (val > vf) {
                                        vf = val;
                                        vg = {i - 1, j - r + l - 1, p, q, y, 0};
                                    }
                                }
                            }
                        }
                        for (int u = l; u <= r; u++) {
                            vf += w[i][u];
                        }
                    }

                }
            }
        }
    }

    int res = 0;
    State state;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            for (int r = 1; r <= m; r++) {
                for (int x = 0; x <= 1; x++) {
                    for (int y = 0; y <= 1; y++) {
                        if (f[i][k][l][r][x][y] > res) {
                            res = f[i][k][l][r][x][y];
                            state = {i, k, l, r, x, y};
                        }
                    }
                }
            }
        }
    }

    cout << "Oil : " << res << "\n";

    while (state.j) {
        for (int i = state.l; i <= state.r; i++) {
            cout << state.i << " " << i << "\n";
        }
        state = g[state.i][state.j][state.l][state.r][state.x][state.y];
    }

    return 0;
}