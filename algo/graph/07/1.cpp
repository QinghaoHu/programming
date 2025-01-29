#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5010;

int n, m;
std::vector<std::pair<int, int>> adj[N];
int bel[N] {}, cur, cnt;
std::stack<int> stk;
int ins[N], dfn[N], low[N];
std::vector<int> cc[N];

void dfs(int u, int id) {
	low[u] = dfn[u] = ++cur;
	ins[u] = true;
	stk.push(u);

	for (auto [v, id2] : adj[u]) {
		if (!dfn[v]) {
			dfs(v, id2);
			low[u] = std::min(low[v], low[u]);
		} else if (id != id2) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}

	if (low[u] == dfn[u]) {
		int y;
		++cnt;
		do {
			y = stk.top();
			stk.pop();
			cc[cnt].push_back(y);
			bel[y] = cnt;
		} while (y != u);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x].push_back(std::make_pair(y, i));
		adj[y].push_back(std::make_pair(x, i));
	}

	dfs(1, -1);

	int nleaf = 0;
	for (int i = 1; i <= cnt; i++) {
		int sz = 0;
		for (auto j : cc[i]) {
			for (auto [v, id2] : adj[j]) {
				sz += (bel[j] != bel[v]);
			}
		}
		nleaf += (sz == 1);
	}

	std::cout << (nleaf + 1) / 2 << '\n';

	return 0;
}
