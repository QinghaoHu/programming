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

template<typename T> 
struct BIT {
	int n;
	vector<T> a;
	
	BIT(): n(100007), a(100007, 0) {}
	BIT(int t): n(t), a(t + 1, 0) {}
	
	void modify(int x, T s) {
		for (int i = x; i <= n; i += (i & -i)) {
			a[i] = (a[i] + s) % mod;
		}
	}
	
	T query(int x) {
		T ans{};
		for (int i = x; i; i -= (i & -i)) {
			ans = (ans + a[i]) % mod;
		}
		return ans;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int tt;
	cin >> tt;
	for (int _ = 1; _ <= tt; _++) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<int> b;
		b.assign(a.begin(), a.end());
		sort(b.begin() + 1, b.end());
		for (int i = 1; i <= n; i++) {
			a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin() + 1;
		}
		//~for (int i = 1; i <= n; i++) {
			//~cerr << a[i] << ' ';
		//~}
		//~cerr << '\n';
		int f[1086][1086] {};
		a[0] = f[0][0] = 1;
		for (int i = 1; i <= m; i++) {
			BIT<int> c(n + 1);
			c.modify(1, f[i - 1][0]);
			for (int j = 1; j <= n; j++) {
				f[i][j] += c.query(a[j] - 1);
				c.modify(a[j], f[i - 1][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = (ans + f[m][i]) % mod;
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
    return 0;
}
