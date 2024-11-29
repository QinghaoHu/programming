#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    ll jc[200006] {}, jcv[200006] {};
    jc[0] = 1, jcv[0] = 1;
    for (int i = 1; i < 200006; i++) {
        jc[i] = i * jc[i - 1] % mod;
        ll x = 0, y = 0;
        exgcd(jc[i], mod, x, y);
        jcv[i] = x;
    }

    int h, w, n; cin >> h >> w >> n;
    vector<pair<int, int>> a(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    a.push_back({h, w});
    
    auto C = [&](int a, int b) {
        return jc[a] * jcv[b] % mod * jcv[a - b] % mod;
    };

    int f[2010] {};
    for (int i = 1; i <= n + 1; i++) {
        f[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
        for (int j = 1; j < i; j++) {
            if (a[j].first > a[i].first || a[j].second > a[i].second) continue;
            f[i] = (f[i] - (ll)f[j] * C(a[i].first + a[i].second - a[j].first - a[j].second, a[i].first - a[j].first)) % mod;
        }
    }
    cout << (f[n + 1] + mod) % mod << '\n';

    return 0;
}
