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
    vector<ll> c(n + 1, 0), t(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        c[i] += c[i - 1];
        t[i] += t[i - 1];
    }

    int h = 1, tt = 1;
    vector<ll> q(n + 2, 0), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        while (h < tt && (f[q[h + 1]] - f[q[h]]) <= (t[i] + s) * (c[q[h + 1]] - c[q[h]])) {
            h++;
        }
        int j = q[h];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while (h < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]])) {
            tt--;
        }
        q[++tt] = i;
    }
    cout << f[n] << '\n';

    return 0;
}
