#include <bits/stdc++.h>

void solve() {
	int n; 
	std::cin >> n;

	std::vector<std::vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<int> a(n);
	int cur = 1;
	auto dfs = [&](this auto &&self, int x, int p = -1) -> void {
		a[x] = cur;
		bool first = true;
		for (auto y : adj[x]) {
			if (y == p) {
				continue;
			} else if (first) {
				first = false;
				cur++;
				self(y, x);
				cur++;
			} else {
				cur += 2;
				self(y, x);
			}
		}
	};
	dfs(0);

	for (auto i : a) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int tt; 
	std::cin >> tt;

	for (int it = 0; it < tt; it++) {
		solve();
	}

	return 0;
}