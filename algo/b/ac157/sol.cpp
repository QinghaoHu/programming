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

string dfs(string &seq, int &u) {
    u++;
    vector<string> seqs;
    while (seq[u] == '0') {
        seqs.push_back(dfs(seq, u));
    }
    u++;
    sort(all(seqs));
    string res = "0";
    for (string i : seqs) {
        res += i;
    }
    res += '1';
    return res;
}

void solve() {
    string a, b;
    cin >> a >> b;
    a = '0' + a + '1';
    b = '0' + b + '1';
    int ua = 0, ub = 0;
    string ra = dfs(a, ua), rb = dfs(b, ub);
    cout << (ra == rb ? "same" : "different") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
