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

const int N = 4e5 + 10;

int n, m, q;
string a, b;
int z[N];

void solve() {
    cin >> n >> m >> q;
    cin >> a >> b;
    string c = " " + b + "#" + a;
    auto exkmp = [&](string s, int n) -> void {
        int l = 1, r = 0;
        z[1] = 0;
        rep(i, 2, n + 1) {
            if (i > r) {
                z[i] = 0;
            } else {
                z[i] = min(z[i - l + 1], r - i + 1);
            }
            while (i + z[i] <= n && s[z[i] + 1] == s[z[i] + i]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i, r = i + z[i] - 1;
            }
        }
    };
    exkmp(c, n + m + 1);
    rep(i, m + 2, m + n + 2) {
        cerr << z[i] << " ";
    }
    cerr << endl;
    unordered_map<int, int> mp;
    rep(i, m + 2, n + m + 2) {
        if (mp.find(z[i]) == mp.end()) {
            mp[z[i]] = 1;
        } else {
            mp[z[i]]++;
        }
    }
    while(q--) {
        int a;
        cin >> a;
        cout << ((mp.find(a) == mp.end()) ? 0 : mp[a]) << endl;
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
