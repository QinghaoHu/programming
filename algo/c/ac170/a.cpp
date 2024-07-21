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

int n, d;
vector<int> a;

bool dfs(int u) {
    if (u == d) {
        return a[u - 1] == n;
    }
    for (int i = u - 1; i >= 0; i--) {
        int t = a[u - 1] + a[i];
        if (t > n) {
            continue;
        }
        a[u] = t;
        for (int j = u + 1; j <= d; j++) {
            t *= 2;
        }
        if (t < n) {
            return false;
        }
        if (dfs(u + 1)) {
            return true;
        }
    }
    return false;
}

void solve() {
    a.assign(n + 1, 0);
    a[0] = 1;
    d = 1;
    while (!dfs(1)) {
        d++;
    }
    rep(i, 0, d) {
        cout << a[i] << " \n"[i == d - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n, n) {
        solve();
    }

    return 0;
}