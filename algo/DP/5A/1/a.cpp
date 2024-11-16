#include <bits/stdc++.h>
typedef long long ll;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)

int main() {
	using namespace std;
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, s; cin >> n >> s;
    vector<ll> t(n + 1, 0), c(n + 1, 0);

    for (int i = 1; i <= n; i++) {
    	cin >> t[i] >> c[i];
    }
    rep(i, 1, n + 1) {
    	t[i] = t[i] + t[i - 1];
    	c[i] = c[i] + c[i - 1];
    }

    const int N = 5010;
    ll f[N] {};
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    rep(i, 1, n + 1) {
    	rep(j, 0, i) {
    		f[i] = min(f[j] + t[i] * (c[i] - c[j]) + s * (c[n] - c[j]), f[i]);
    	}
    }
    cout << f[n] << '\n';

    return 0;
}
