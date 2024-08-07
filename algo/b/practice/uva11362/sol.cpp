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

const int N = 1e5 + 10;

int n, idx;
int trie[N][15];
bool st[N];

bool insertt(string str) {
    int p = 0;
    int len = SZ(str);
    bool isN = false;
    bool isF = false;
    rep(i, 0, len) {
        int ch = str[i] - '0';
        if (!trie[p][ch]) {
            trie[p][ch] = ++idx;
            isN = true;
        }
        p = trie[p][ch];
        if (st[p]) isF = true;
    }
    st[p] = true;
    return isN && !isF;
}

void solve() {
    memset(trie, 0, sizeof trie);
    memset(st, false, sizeof st);
    cin >> n;
    idx = 0;
    bool res = true;
    string str;
    rep(i, 0, n) {
        cin >> str;
        if (!insertt(str)) {
            res = false;
        }
    }
    cout << ((!res) ? "NO" : "YES") << endl;
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
