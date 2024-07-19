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

const int N = 30010;

int n, m;
vector<int> path[N];
int deg[N], seq[N];
bitset<N> f[N];

void topsort() {
    int cnt = 0;
    queue<int> q;
    rep(i, 1, n + 1) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int k = q.front();
        q.pop();
        seq[cnt++] = k;
        for (auto s : path[k]) {
            if (--deg[s] == 0) {
                q.push(s);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        path[a].pb(b);
        deg[b]++;
    }
    topsort();
    per(i, n - 1, 0) {
        int j = seq[i];
        f[j][j] = 1;
        for (auto s : path[j]) {
            f[j] |= f[s];
        }
    }
    rep(i, 1, n + 1) {
        cout << f[i].count() << endl;
    }
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