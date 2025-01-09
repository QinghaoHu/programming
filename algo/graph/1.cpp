#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 20010;

int n, m;
struct BCC {
	int n, cur, cnt;
	std::vector<std::vector<int>> adj;
	std::vector<int> cut;
	std::vector<int> dfn, low, bel;

	BCC(int n) {
		init(n);
	}

	void init(int n) {
		this -> n = n;
		adj.resize(n + 1, {});
		cut.resize(n + 1, 0);
		dfn.resize(n + 1, 0);
		low.resize(n + 1, 0);
		bel.resize(n + 1, 0);
		cur = cnt = 0;
	}

	void add_edge(int x, int y) {
		adj[x].push_back(y);
	}

	void dfs(int u, int f) {
		low[u] = dfn[u] = ++cur;
		int ch = 0;
		for (auto v : adj[u]) {
			if (!dfn[v]) {
				dfs(v, u);
				ch++;
				low[u] = std::min(low[v], low[u]);
				if (low[v] >= dfn[u]) cut[u] = 1; 
			} else if (f != v) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
		if (f == -1 && ch <= 1) cut[u] = 0;
	}

	void solve() {
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) dfs(i, -1);
		}
	}

	std::vector<int> work() {
		return cut;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;

	BCC tr(n);

	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		tr.add_edge(x, y);
		tr.add_edge(y, x);
	}

	tr.solve();

	auto cut = tr.work();

	int sz = 0;
	for (int i = 1; i <= n; i++) {
		sz += cut[i];
	}

	std::cout << sz << '\n';
	for (int i = 1; i <= n; i++) if (cut[i]) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	return 0;
}