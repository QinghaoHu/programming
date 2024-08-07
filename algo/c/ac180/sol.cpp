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

const int N = 20;
int n, dep;
int q[N], w[5][N];

int f() {
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (q[i + 1] != q[i] + 1) {
            res++;
        }
    }
    return (res + 2) / 3;
}

bool check() {
    rep(i, 0, n) {
        if (q[i] != i + 1) {
            return false;
        }
    }
    return true;
}

bool dfs(int now) {
    if (now + f() > dep) {
        return false;
    }
    if (check()) {
        return true;
    }
    rep(l, 0, n) {
        rep(r, l, n) {
            rep(k, r + 1, n) {
                memcpy(w[now], q, sizeof q);
                int x, y;
                for (x = r + 1, y = l; x <= k; x++, y++) {
                    q[y] = w[now][x];
                }
                for (x = l; x <= r; x++, y++) {
                    q[y] = w[now][x];
                }
                if (dfs(now + 1)) {
                    return true;
                }
                memcpy(q, w[now], sizeof q);
            }
        }
    }
    return false;
}

void solve() {
    cin >> n;
    rep(i, 0, n) {
        cin >> q[i];
    }
    int res = -1;
    for (dep = 0; dep < 5; dep++) {
        if (dfs(0)) {
            res = dep;
            break;
        }
    }
    if (res != -1) {
        cout << dep << " \n";
    } else {
        cout << "5 or more\n";
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
