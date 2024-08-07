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
typedef long double ld; typedef pair<int, int> PII;
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

int dep;
int result[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1},
    {0, 0, -1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
};
int curr[5][5];

int f() {
    int res = 0;
    rep(i, 0, 5) {
        rep(j, 0, 5) {
            if (curr[i][j] != -1 && result[i][j] != curr[i][j]) {
                res++;
            }
        }
    }
    return res;
}

arr<int, 8> dx{{2, 2, -2, -2, 1, 1, -1, -1}}, dy{{1, -1, 1, -1, 2, -2, 2, -2}};

bool dfs(int u, int x, int y) {
    if (u + f() > dep) {
        return false;
    }
    if (!f()) {
        return true;
    }
    rep(i, 0, 8) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) {
            continue;
        }
        swap(curr[a][b], curr[x][y]);
        if (dfs(u + 1, a, b)) {
            return true;
        }
        swap(curr[a][b], curr[x][y]);
    }
    return false;
}

void solve() {
    int x = -1, y = -1;
    rep(i, 0, 5) {
        rep(j, 0, 5) {
            char c;
            cin >> c;
            if (c == '0') {
                curr[i][j] = 0;
            } else if (c == '1') {
                curr[i][j] = 1;
            } else {
                curr[i][j] = -1;
                x = i, y = j;
            }
        }
    }
    for (dep = 0; !dfs(0, x, y) && dep <= 15; dep++);
    cout << (dep <= 15 ? dep : -1) << " \n";
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

// Remainder: Never use two dimensional std::array in the competitive programming, even god and -O2 cannot save you when you use std::array. 
