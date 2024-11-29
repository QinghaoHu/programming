#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const double eps = 1e-9;
const ll mod = 1004535809;
const int INF = 0x3f3f3f3f;

ll powmod(ll a, ll b) {
	ll c = 1;
	for (; b; b >>= 1) {
		if (b & 1) c = (c * a) % mod;
		a = (a * a) % mod;
	}
	return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    ll fc[1010] {}, fcv[1010] {}, f[1010] {};
    fc[0] = 1, fcv[0] = 1;
    for (int i = 1; i < 1010; i++) {
    	fc[i] = fc[i - 1]  * i % mod; 
    	fcv[i] = powmod(fc[i], mod - 2) % mod;
    }

    auto getC = [&](int a, int b) -> int {
    	return fc[a] % mod * fcv[b] % mod * fcv[a - b] % mod; 
    };

    f[1] = 1;
    for (int i = 2; i <= n; i++) {
    	f[i] = powmod(2, i * (i - 1) / 2) % mod;
    	for (int j = 1; j <= i - 1; j++) {
    		f[i] =  (f[i] - f[j] * getC(i - 1, j - 1) % mod * powmod(2, (i - j) * (i - j - 1) / 2) % mod) % mod; 
    	}
    }
    cout << (f[n] + mod) % mod << '\n';

    return 0;
}
