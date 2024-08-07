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

const int N = 55;

int n;
int h[N];
int down[N], up[N];

bool dfs(int depth, int u, int su, int sd) {
    if (su + sd > depth) {
        return false;
    }
    if (u == n) {
        return true;
    }
    bool flag = false;
    rep(i, 1, su + 1) {
        if (up[i] < h[u]) {
            int t = up[i];
            up[i] = h[u];
            if (dfs(depth, u + 1, su, sd)) {
                return true;
            }
            up[i] = t;
            flag = true;
            break;
        }
    }
    if (!flag) {
        up[su + 1] = h[u];
        if (dfs(depth, u + 1, su + 1, sd)) {
            return true;
        }
    }
    flag = false;
    rep(i, 1, sd + 1) {
        if (down[i] > h[u]) {
            int t = down[i];
            down[i] = h[u];
            if (dfs(depth, u + 1, su, sd)) {
                return true;
            }
            down[i] = t;
            flag = true;
            break;
        }
    }
    if (!flag) {
        down[sd + 1] = h[u];
        if (dfs(depth, u + 1, su, sd + 1)) {
            return true;
        }
    }
    return false;
}

void solve() {
    rep(i, 0, n) {
        cin >> h[i];
    }
    int depth = 0;
    while (!dfs(depth, 0, 0, 0)) {
        depth++;
    }
    cout << depth << " \n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        solve();
    }

    return 0;
}