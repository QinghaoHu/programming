#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s2, s1;
    int n2, n1;
    while (cin >> s2 >> n2 >> s1 >> n1) {
		ll f[105][31] {};
		for (int i = 0; i < s1.size(); i++) {
			int pos = i;
			for (int j = 0; j < s2.size(); j++) {
				int cnt = 0;
				while (s1[pos] != s2[j]) {
					pos = (pos + 1) % s1.size();
					if (++cnt >= s1.size()) {
						cout << 0 << '\n';
						return;
					}
				}
				pos = (pos + 1) % s1.size();
				f[i][0] += cnt + 1;
			}
		}
		for (int j = 1; j <= 30; j++) {
			for (int i = 0; i < s1.size(); i++) {
				f[i][j] = f[i][j - 1] + f[(i + f[i][j - 1]) % s1.size()][j - 1];
			}
		}
		ll m = 0;
		for (int st = 0; st < s1.size(); st++) {
			ll x = st, ans = 0;
			for (int k = 30; k >= 0; k--) {	
				if (x + f[x % s1.size()][k] <= s1.size() * n1) {
					x += f[x % s1.size()][k];
					ans += 1 << k;
				}
			}
			m = max(m, ans);
		}
		cout << m / n2 << '\n';
	}
	
    return 0;
}
