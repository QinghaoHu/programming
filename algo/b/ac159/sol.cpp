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

const int N = 1e4 + 10;

int n, m;
string s[N], es[N];
int nxt[N];

void solve() {
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    nxt[1] = 0;
    int j = 0;
    rep(i, 2, n + 1) {
        while (j > 0 && s[j + 1] != s[i]) {
            j = nxt[j];
        }
        if (s[j + 1] == s[i]) {
            j++;
        }
        nxt[i] = j;
    }
    int k = n - nxt[n];
    rep(i, 1, m + 1) {
        rep(j, 1, k + 1) {
            es[i] += s[j][i];
        }
    }
    rep(i, 1, m + 1) {
        s[i] = es[i];
    }
    j = 0;
    memset(nxt, 0, sizeof nxt);
    rep(i, 2, m + 1) {
        while (j > 0 && s[j + 1] != s[i]) {
            j = nxt[j];
        }
        if (s[j + 1] == s[i]) {
            j++;
        }
        nxt[i] = j;
    }
    int ans = m - nxt[m];
    ans *= k;
    cout << ans << endl;
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
