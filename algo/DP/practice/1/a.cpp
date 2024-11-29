#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

#define FOR(i, a, n) for(int i=a; i<n; i++) 
#define ROF(i, a, n) for(int i=n; i>=a; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n); FOR(i, 0, n) cin >> a[i];
    vector<int> b(5, 0); 
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        b[x]++;
    }

    int f[41][41][41][41] {};
    f[0][0][0][0] = a[0];
    FOR(i, 0, b[1] + 1) {
        FOR(j, 0, b[2] + 1) {
            FOR(k, 0, b[3] + 1) {
                FOR(l, 0, b[4] + 1) {
                    int len = i + 2 * j + 3 * k + 4 * l;
                    auto &ta = f[i][j][k][l];
                    int t = a[len];
                    if (i > 0) ta = max(ta, f[i - 1][j][k][l] + t);
                    if (j > 0) ta = max(ta, f[i][j - 1][k][l] + t);
                    if (k > 0) ta = max(ta, f[i][j][k - 1][l] + t);
                    if (l > 0) ta = max(ta, f[i][j][k][l - 1] + t);
                }
            }
        }
    }
    cout << f[b[1]][b[2]][b[3]][b[4]] << '\n';

    return 0;
}
