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

int n, m, ans = INF;
vector<int> minv, mins, R, H;

void dfs(int u, int v, int s) {
    if (u == 0) {
        if (v == n)
            ans = min(ans, s);
        return;
    }
    if (v + minv[u] > n) return;
    if (s + mins[u] >= ans) return;
    if (s + 2 * (n - v) / R[u + 1] >= ans) {
        return;
    }
    for (int r = min(R[u + 1] - 1, (int)sqrt(n - v)); r >= u; r--) {
        for (int h = min(H[u + 1] - 1, (int)(n - v) / (r * r)); h >= u; h--) {
            R[u] = r;
            H[u] = h;
            dfs(u - 1, v + r * r * h, s + 2 * r * h + (u == m ? r * r : 0));
        }
    }
}

void solve() {
    cin >> n >> m;
    minv.assign(m + 2, 0);
    mins.assign(m + 2, 0);
    R.assign(m + 2, 0);
    H.assign(m + 2, 0);
    rep(i, 1, m + 1) {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }
    R[m + 1] = H[m + 1] = INF;
    dfs(m, 0, 0);
    if (ans == INF) {
        ans = 0;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    rep(i, 0, T) {
        solve();
    }

    return 0;
}
