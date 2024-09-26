#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;

const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

const int N = 101000;
int n, sz[N], maxs[N], L;
vector<pair<int, int>> e[N];
bool del[N];
ll ans = 0;

void solve(int u, int s) {
	int ms = s, root = -1;

	function<void(int, int)> dfs1 = [&](int u, int per) {
		sz[u] = 1;
		maxs[u] = 0;
		for (auto [v, w] : e[u]) {
			if (del[v] || v == per) {
				continue;
			}
			dfs1(v, u);
			sz[u] += sz[v];
			maxs[u] = max(maxs[u], sz[v]);
		}
		maxs[u] = max(maxs[u], s - maxs[u]);
		if (maxs[u] < ms) {
			ms = maxs[u];
			root = u;
		}
	};

	dfs1(u, -1);
	vector<int> d1, d2;
	d1.push_back(0);

	auto calc = [&](vector<int> &d) -> ll {
		sort(all(d));
		int m = SZ(d);
		int r = m - 1;
		ll ans = 0;
		for (int i = 0; i < m; i++) {
			while (r > 0 && d[i] + d[r] > L) {
				r--;
			}
			if (i < r) {
				ans += r - i;
			}
		}
		return ans;
	};

	for (auto [v, w] : e[root]) {
		if (del[v]) continue;
		d2.clear();

		function<void(int, int, int)> dfs2 = [&](int u, int par, int dep) {
			sz[u] = 1;
			d1.push_back(dep);
			d2.push_back(dep);
			for (auto [v, w] : e[u]) {
				if (del[v] || v == par) {
					continue;
				}
				dfs2(v, u, dep + w);
			}
		};
		sz[u] += sz[v];
		dfs2(v, root, w);
		ans -= calc(d2);
	}
	ans += calc(d1);
	del[root] = true;
	for (auto [v, w] : e[root]) {
		if (!del[v]) solve(v, sz[v]);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> L, n != 0 || L != 0) {
        memset(del, 0, sizeof del);
        memset(sz, 0, sizeof sz);
        memset(maxs, 0, sizeof maxs);
        rep(i, 0, N) {
            e[i].clear();
        }
        ans = 0;
    	rep(i, 1, n) {
    		int u, v, w;
    		cin >> u >> v >> w;
    		e[u].push_back({v, w});
    		e[v].push_back({u, w});
    	}
    	solve(1, n);
    	cout << ans << "\n";
    }

    return 0;
}