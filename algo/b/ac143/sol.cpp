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
const double eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 3 * 1e6 + 10, M = 2 * 31; 

int trie[N][2], tot = 0;
int ab[1000010];

void solve() {
    int n;
    cin >> n;
    auto insertt = [&](int a) -> void {
        int p = 0;
        per(i, 30, 0) {
            int t = a >> i & 1;
            if (trie[p][t] == 0) {
                trie[p][t] = ++tot;
            }
            p = trie[p][t];
        }
    };
    auto maxn = [&](int a) -> int {
        int t = 0;
        int ans = 0;
        per(i, 30, 0) {
            int s = (a >> i) & 1;
            if (trie[t][!s] == 0) {
                t = trie[t][s];
            } else {
                ans += 1 << i;
                t = trie[t][!s];
            }
        }
        return ans;
    };
    rep(i, 0, n) {
        int a;
        cin >> a;
        ab[i] = a;
        insertt(a);
    }
    int res = -INF;
    rep(i, 0, n) {
        res = max(res, maxn(ab[i]));
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    
    rep(t, 0, T) {
        solve();
    }

    return 0;
}
