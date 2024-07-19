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

const int N = 9;

int row[N], col[N], cell[3][3];
char str[N][N];
int ones[1 << N], maps[1 << N];

inline int lowbit(int x) {
    return x & -x;
}

void init() {
    rep(i, 0, 9) {
        row[i] = col[i] = (1 << 9) - 1;
    }
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            cell[i][j] = (1 << 9) - 1;
        }
    }
}

inline int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (cnt == 0) {
        return true;
    }
    int minv = 10;
    int x = 0, y = 0;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (str[i][j] == '0') {
                int t = get(i, j);
                t = ones[t];
                if (t < minv) {
                    x = i;
                    y = j;
                    minv = t;
                }
            }
        }
    }
    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = lowbit(i);
        t = maps[t];
        str[x][y] = t + '1';
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        if (dfs(cnt - 1)) {
            return true;
        }
        str[x][y] = '0';
        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
    }
    return false;
}

void solve() {
    init();
    rep(i, 0, 1 << N) {
        int s = 0;
        for (int j = i; j; j -= lowbit(j)) {
            s++;
        }
        ones[i] = s;
    }
    rep(i, 0, N) {
        maps[1 << i] = i;
    }
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> str[i][j];
        }
    }
    int cnt = 0;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (str[i][j] != '0') {
                int t = str[i][j] - '1';
                row[i] -= 1 << t;
                col[j] -= 1 << t;
                cell[i / 3][j / 3] -= 1 << t;
            } else {
                cnt++;
            }
        }
    }
    dfs(cnt);
    rep(i, 0, N) {
        rep(j, 0, N) {
            cout << str[i][j];
        }
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    rep(i, 0, T) {
        solve();
    }

    return 0;
}
