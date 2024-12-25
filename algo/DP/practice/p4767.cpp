#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

template<typename T>
void _print(T x) {cerr << x << ' ';}
template<typename T>
void _println(T x) {cerr << x << '\n';}
void _print(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _println(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void _print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
void _println(vector<T> u) {for(auto i : u)_print(i); cerr << '\n';}

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int v, p; cin >> v >> p;
    vector<int> a(v + 1); FOR(i, 1, v + 1) cin >> a[i];
    sort(a.begin() + 1, a.end());

    int dist[3010][3010] {}, d[3010][310] {}, dp[3010][310] {};
    auto init = [&]() {
        for (int l = 1; l <= v; l++) {
            for (int r = l + 1; r <= v; r++) {
                dist[l][r] = dist[l][r - 1] + a[r] - a[l + r >> 1];
            }
        }
    };

    init();
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int j = 1; j <= p; j++) {
        d[v + 1][j] = v;
        for (int i = v; i >= 1; i--) {
            int minn = INF, mind;
            for (int k = d[i][j - 1]; k <= d[i + 1][j]; k++) {
                if (dp[k][j - 1] + dist[k + 1][i] < minn) {
                    minn = dp[k][j - 1] + dist[k + 1][i];
                    mind = k;
                }
            }
            dp[i][j] = minn;
            d[i][j] = mind;
        }
    }
    cout << dp[v][p] << '\n';

    return 0;
}
