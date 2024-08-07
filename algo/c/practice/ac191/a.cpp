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

struct node {
    int day, x, y, s0, s1, s2, s3;
};

int n;
bool st[366][4][4][7][7][7][7];
int state[366][4][4];

int bfs() {
    memset(st, false, sizeof st);
    queue<node> q;
    auto s = state[1];
    if (s[1][1] || s[1][2] || s[2][2] || s[2][1]) {
        return 0;
    }
    st[1][1][1][1][1][1][1] = true;
    q.push({1, 1, 1, 1, 1, 1, 1});
    arr<int, 5> dx{{1, 0, -1, 0, 0}}, dy{{0, 1, 0, -1, 0}};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (t.day == n) {
            return 1;
        }
        for (int i = 0; i < 5; i++) {
            rep(j, 1, 3) {
                int x = t.x + dx[i] * j, y = t.y + dy[i] * j;
                if (x < 0 || x >= 3 || y < 0 || y >= 3) {
                    continue;
                }
                auto s = state[t.day + 1];
                if (s[x][y] || s[x][y + 1] || s[x + 1][y] || s[x + 1][y + 1]) {
                    continue;
                }
                int s0 = t.s0, s1 = t.s1, s2 = t.s2, s3 = t.s3;
                if (x == 0 && y == 0) {
                    s0 = 0;
                } else if (++s0 == 7) {
                    continue;
                }
                if (x == 0 && y == 2) {
                    s1 = 0;
                } else if (++s1 == 7) {
                    continue;
                }
                if (x == 2 && y == 0) {
                    s2 = 0;
                } else if (++s2 == 7) {
                    continue;
                }
                if (x == 2 && y == 2) {
                    s3 = 0;
                } else if (++s3 == 7) {
                    continue;
                }
                if (st[t.day + 1][x][y][s0][s1][s2][s3] == true) {
                    continue;
                }
                st[t.day + 1][x][y][s0][s1][s2][s3] = true;
                q.push({t.day + 1, x, y, s0, s1, s2, s3});
            }
        }
    }
    return 0;
}

void solve() {
    rep(i, 1, n + 1) {
        rep(j, 0, 4) {
            rep(k, 0, 4) {
                cin >> state[i][j][k];
            }
        }
    }
    cout << bfs() << " \n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        solve();
    }

    return 0;
}
