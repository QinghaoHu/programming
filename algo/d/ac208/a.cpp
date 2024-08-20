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
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

struct xorGauss {
    int n, st = 0;
    vector<int> b;
    vector<vector<int> > a;

    xorGauss(int ns) : n(ns), st(0), b(ns + 1), a(ns + 1, vector<int>(ns + 1, 0)) {}

    int solve() {
        int l = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = l; j <= n; j++) {
                if (a[j][i] != 0) {
                    swap(a[j], a[l]);
                    swap(b[j], b[l]);
                    break;
                }
            }
            if (a[l][i] == 0) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (j != l && a[j][i] != 0) {
                    for (int k = l; k <= n; k++) {
                        a[j][k] ^= a[l][k];
                    }
                    b[j] ^= b[l];
                }
            }
            ++ l;
        }
        for (int i = l; i <= n; i++) {
            if (b[i] != 0) {
                st = -1;
                return -1;
            }
        }
        if (l < n) {
            st = -2;
            return (n - l + 1);
        }
        st = 0;
        return 0;
    }

    vector<int> getAns() {
        return b;
    }
};

void solve() {
    int n;
    cin >> n;

    xorGauss z(n);
    for (int i = 1; i <= n; i++) {
        cin >> z.b[i];
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        z.b[i] ^= c;
        z.a[i][i] = 1;
    }

    int x, y;
    while (cin >> x >> y, x || y) {
        z.a[y][x] = 1;
    }
    int t = z.solve();
    if (t == -1) {
        cout << "Oh,it's impossible~!!\n";
    } else {
        ll res = 1;
        for (int i = 1; i <= t; i++) {
            res *= 2;
        }
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}