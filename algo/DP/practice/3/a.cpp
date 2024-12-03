#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vector<int> a(N + 1, 0); FOR(i, 1, N + 1) cin >> a[i];
    a[0] = INT_MAX;
    
    vector<int> c(N + 1, 0), f(N + 1, 0);
    c[0] = 1;
    FOR(i, 1, N + 1) {
        FOR(j, 0, i) {
            if (a[j] > a[i]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1, c[i] = c[j];
                } else if (f[i] == f[j] + 1) {
                    c[i] += c[j];
                }
            } else if (a[i] == a[j]) {
                c[j] = 0;
            }
        }
    }

    int ans = 0, tot = 0;
    FOR(i, 1, N + 1) {
        if (f[i] > ans) ans = f[i], tot = c[i];
        else if (f[i] == ans) tot += c[i];
    }
    cout << ans << ' ' << tot << '\n';

    return 0;
}
