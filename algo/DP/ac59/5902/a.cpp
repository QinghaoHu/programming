#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			cout << -1 << '\n';
			exit(0);
		}
	}
	assert(a[1] == 0);
	vector<int> c(n + 1, 0);
	ll sum = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		sum += a[i];
		while (sum > m) {
			sum -= a[j + 1];
			j++;
		}
		c[i] = j;
	}
	multiset<ll> q;
	int dq[100006] {};
	int l = 1, r = 0;
	ll f[100006] {};
	for (int i = 1; i <= n; i++) {
		while (l <= r && dq[l] <= c[i]) {
			q.erase(f[dq[l]] + a[dq[l + 1]]);
			l++;
		}
		while (l <= r && a[dq[r]] <= a[i]) {
			q.erase(f[dq[r - 1]] + a[dq[r]]);
			r--;
		}
		if (l <= r) {
			q.insert(f[dq[r]] + a[i]);
		}
		dq[++r] = i;
		f[i] = f[c[i]] + a[dq[l]];
		if (f[i] == 0) {
		    cerr << i << ' ' << a[dq[l]] << '\n';
		}
		if (!q.empty()) {
			f[i] = min(f[i], *q.begin());
		}
	}
	cout << f[n] << '\n';
    return 0;
}
