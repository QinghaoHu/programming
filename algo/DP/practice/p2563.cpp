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

    int n, m, w; cin >> n >> m >> w;
    int f[2001][2001] {};
    memset(f, -0x3f, sizeof(f));

    FOR(i, 1, n + 1) {
        int ap, bp, as, bs; cin >> ap >> bp >> as >> bs;
        for (int j = 0; j <= as; j++) f[i][j] = -1 * j * ap; // Case 1, buy from 0 shares
        for (int j = 0; j <= m; j++) f[i][j] = max(f[i][j], f[i - 1][j]);

        if (i <= w) continue;
        int l = 1, r = 0;
        int q[2010] {};
        for (int j = 0; j <= m; j++) {
            while (l <= r && q[l] < j - as) {
                l++;
            }
            while (l <= r && f[i - w - 1][q[r]] + q[r] * ap <= f[i - w - 1][j] + j * ap) r--;
            q[++r] = j;
            if (l <= r) {
                f[i][j] = max(f[i][j], f[i - w - 1][q[l]]  + q[l] * ap - j * ap);
            }
        }
        
        l = 1, r = 0;
        memset(q, 0, sizeof q);
        ROF(j, 0, m) {
            while (l <= r && q[l] > j + bs) l++;
            while (l <= r && f[i - w - 1][q[r]] + q[r] * bp <= f[i - w - 1][j] + j * bp) r--;
            q[++r] = j;
            if (l <= r) {
                f[i][j] = max(f[i][j], f[i - w - 1][q[l]] + q[l] * bp - j * bp);
            }
        }
    }

    int ans = 0;
    FOR(i, 0, m + 1) {
        ans = max(f[n][i], ans);
    }
    cout << ans << '\n';

    return 0;
}
