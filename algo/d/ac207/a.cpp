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

struct Gauss {
    int n;
    vector<vector<double>> a;
    vector<double> b, ans;
    int st = 0;

    Gauss(int ns) {
        a.resize(ns + 1, vector<double>(ns + 1, 0));
        b.resize(ns + 1, 0);
        n = ns;
    }

    void solve() {
        int l = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = l; j <= n; j++) {
                if (fabs(a[j][i]) > fabs(a[l][i])) {
                    swap(a[l], a[j]);
                    swap(b[l], b[j]);
                }
            }
            if (fabs(a[l][i]) < eps) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (j != l && fabs(a[j][i]) > eps) {
                    double delta = a[j][i] / a[l][i];
                    for (int k = i; k <= n; k++) {
                        a[j][k] -= a[l][k] * delta;
                    }
                    b[j] -= b[l] * delta;
                }
            }
            ++l;
        }
        for (int i = l; i <= n; i++) {
            if (fabs(b[i]) > eps) {
                st = -1;
                return;
            }
        }
        if (l <= n) {
            st = -2;
        } else {
            ans.resize(n + 1);
            for (int i = 1; i <= n; i++) {
                ans[i] = b[i] / a[i][i];
            }
            st = 0;
        }
    }

    vector<double> getAns() {
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    Gauss z(n);
    vector a(n + 2, vector<double>(n + 1, 0));

    rep(i, 1, n + 2) {
        rep(j, 1, n + 1) {
            cin >> a[i][j];
        }
    }
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            z.a[i][j] = 2 * (a[i][j] - a[i + 1][j]);
            z.b[i] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
        }
    }

    z.solve();
    auto d = z.getAns();
    rep(i, 1, SZ(d)) {
        cout << fixed << setprecision(3) << d[i] << " \n"[i == SZ(d)];
    }

    return 0;
}