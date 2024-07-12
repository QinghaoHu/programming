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

const int N = 1010;

int n, m;
char s[N][N];
int h[N][N];

void solve() {
    cin >> n >> m;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            char c;
            cin >> c;
            s[i][j] = c;
            if (c == 'F') {
                h[i][j] = h[i - 1][j] + 1;
            }
        }
    }
    int res = 0;
    rep(i, 1, n + 1) {
        stack<int> st, w;
        rep(j, 1, m + 2) {
            int len = 0;
            while(!st.empty() && st.top() >= h[i][j]) {
                len += w.top(); res = max(res, len * st.top());
                st.pop(); w.pop();
            }
            st.push(h[i][j]); w.push(len + 1);
        }
    }
    cout << res * 3 << endl;
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
