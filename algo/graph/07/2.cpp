#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 101000;

int n, m;
int low[N],dfn[N], sz[N];
int cur;
std::vector<int> adj[N];
i64 ans[N];

void dfs(int u, int fa) {
	low[u] = dfn[u] = ++cur;
	ans[u] = n - 1;
	sz[u] = 1;
	int cut = n - 1;

	for (auto v : adj[u]) {
		if (!dfn[v]) {
			dfs(v, u);
			sz[u] += sz[v];
			low[u] = std::min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				ans[u] += (i64)sz[v] * (n - sz[v]);
				cut -= sz[v];
			}
		} else if (v != fa) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	ans[u] += (i64)cut * (n - cut);

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << '\n';
	}
	
	return 0;
}
