#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> ver(n << 1 | 1), head(n + 1), nxt(n << 1 | 1);
	int tot = 0;
    auto add = [&](int x, int y) -> void {
		ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
	};
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	vector<pair<int, int>> a(m + 1, {0, 0});
	vector<pair<int, int>> query[n + 1];
	vector<int> lca(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first == a[i].second) {lca[i] = a[i].first; continue;}
		query[a[i].first].push_back({a[i].second, i});
		query[a[i].second].push_back({a[i].first, i});
	}
	vector<int> fa(n + 1);
	iota(fa.begin(), fa.end(), 0);
	vector<int> v(n + 1, 0);
	function<int(int)> get = [&](int x) {
		return fa[x] ==  x ? x : (fa[x] = get(fa[x]));
	};
	function<void(int)> tarjan = [&](int x) {
		v[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (!v[y]) {
				tarjan(y);
				fa[y] = x;
			}
		}
		for (int i = 0; i < (int)query[x].size(); i++) {
			if (v[query[x][i].first] == 2) {
				lca[query[x][i].second] = get(query[x][i].first);
			}
		}
		v[x] = 2;
	};
	tarjan(1);
	vector<int> f(n + 1, 0);
	for (int i = 1; i <= m; i++) {
		f[a[i].first]++, f[a[i].second]++;
		f[lca[i]] -= 2;
	}
	fill(v.begin(), v.end(), 0);
	function<void(int)> dfs = [&](int x) {
		v[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (v[y]) continue;
			dfs(y);
			f[x] += f[y];
		}
	};
	dfs(1);
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) ans += m;
		else if (f[i] == 1) ans++;
	}
	cout << ans << '\n';
    return 0;
}
