#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> u(n + 1, 0);
	rep(i, 1, n + 1) {
		cin >> u[i];
	}
	int f[2][4000][2] {};
	if (m == 0) {
		cout << 0 << '\n';
		exit(0);
	}
	memset(f, -0x3f, sizeof f);
	f[1 & 1][0][0] = 0;
	f[1 & 1][1][1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= min(i, m); j++) {
			f[i & 1][j][0] = max(f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
			if (j - 1 >= 0) f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + u[i]);
		}
	}
	int ans = max(f[n & 1][m][0], f[n & 1][m][1]);
	memset(f, -0x3f, sizeof f);
	f[1 & 1][1][1] = u[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= min(i, m); j++) {
			f[i & 1][j][0] = max(f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
			if (j - 1 >= 0) f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + u[i]);
		}
	}
	ans = max(ans, f[n & 1][m][1]);
	cout << ans << '\n';
	
    return 0;
}
