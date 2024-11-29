#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define SZ(x) ((int)x.size())

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, s; cin >> n >> s;
    vector<ll> t(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }

    int h = 1, tt = 1;
    vector<int> q(n + 2, 0);
    vector<ll> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int l = h, r = tt;
        while (l < r) {
            int mid = l + r >> 1;
            if ((f[q[mid + 1]] -  f[q[mid]]) >= (t[i] + s) * (c[q[mid + 1]] - c[q[mid]])) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int j = q[r];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while (h < tt && (float)(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (float)(f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]])) tt -- ;
        q[ ++ tt] = i;
    }
    cout << f[n] << '\n';

    return 0;
}
