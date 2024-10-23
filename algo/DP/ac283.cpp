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
int n, m;

void solve() {
	vector<pair<int, int>> g(n + 1, make_pair(0, 0));
	for (int i = 1; i <= n; i++) cin >> g[i].first;
	for (int i = 1; i <= n; i++) cin >> g[i].second;
	
	int f[100010] {}, gs[100010] {};
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		memset(gs, 0, sizeof gs);
		for (int j = g[i].first; j <= m; j++) {
			if (!f[j] && f[j - g[i].first] && gs[j - g[i].first] < g[i].second) {
				f[j] = 1;
				gs[j] = gs[j - g[i].first] + 1;
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= m; i++) {
		res += f[i];
	}
	cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> n >> m, n || m) {
		solve();
	}
	
    return 0;
}
