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

    int n, p, m; cin >> n >> m >> p;
    vector<ll> d(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    
    vector<ll> a(m + 1, 0), t(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        int h;
        cin >> h >> t[i];
        a[i] = t[i] - d[h];
    }
    sort(a.begin() + 1, a.end());
    vector<ll> s(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        s[i] = s[i - 1] + a[i];
    }

    ll f[105][100006] {};
    memset(f, 0x3f, sizeof f);

    auto get_y = [&](int k, int j) -> ll {
        return f[j - 1][k] + s[k];
    };

    for (int i = 0; i <= p; i++) {
        f[i][0] = 0;
    }
    for (int j = 1; j <= p; j++) {
        int hh = 1, tt = 1;
        vector<int> q(m + 2, 0);
        for (int i = 1; i <= m; i++) {
            while (hh < tt && (get_y(q[hh + 1], j) - get_y(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh])) hh++;
            int k = q[hh];
            f[j][i] = f[j - 1][k] + a[i] * i - a[i] * k - s[i] + s[k];
            while (hh < tt && (get_y(q[tt], j) - get_y(q[tt - 1], j)) * (i - q[tt - 1]) >= (get_y(i, j) - get_y(q[tt - 1], j)) * (q[tt] - q[tt - 1])) tt--;
            q[++tt] = i;
        }
    }
    cout << f[p][m] << '\n';

    return 0;
}
