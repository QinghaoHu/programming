#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1010;

int t = 0;
int m, n, cur, cnt, low[N], dfn[N], cut[N];
std::vector<int> adj[N];
std::vector<int> cc[N];
std::stack<int> stk;

void dfs(int u, int f) {
	low[u] = dfn[u] = ++cur;
	stk.push(u);
	
	int ch = 0;
	for (auto v : adj[u]) {
		if (!dfn[v]) {
			dfs(v, u);
			ch++;
			low[u] = std::min(low[u], low[v]);
			
			if (low[v] >= dfn[u]) {
				cut[u] = 1;
				++cnt;
				cc[cnt].push_back(u);
				int y;
				do {
					y = stk.top();
					cc[cnt].push_back(y);
					stk.pop();
				} while (y != v);
			}
		} else if (v != f) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if (u == 1 && ch <= 1) cut[u] = 0;
}

void solve() {
	for (int i = 0; i < m; i++) {
		int s, t;
		std::cin >> s >> t;
		n = std::max(n, std::max(s, t));
		adj[s].push_back(t);
		adj[t].push_back(s);
	}

	for (int i = 1; i <= n; i++) if (!dfn[i]) {
		dfs(i, 0);
	}

	if (cnt == 1) {
		std::cout << "Case " << ++t << ": " << 2 << ' ' << n * (n - 1) / 2 << '\n';
	} else {
		int ans1 = 0;
		i64 ans2 = 1;
		for (int i = 1; i <= cnt; i++) {
			int nleaf = 0;
			for (auto v : cc[i]) {
				nleaf += cut[v];
			}
			if (nleaf == 1) {
				ans1 += 1;
				ans2 *= cc[i].size() - 1;
			}
		}
		std::cout << "Case " << ++ t << ": " << ans1 << ' ' << ans2 << '\n';
	}
	// std::cerr << m << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (std::cin >> m, m) {
		cur = cnt = n = 0;
		for (int i = 1; i < N; i++) {
			low[i] = dfn[i] = cut[i] = 0;
			cc[i].clear();
			adj[i].clear();
		}
		while (!stk.empty()) stk.pop();

		solve();
	}

	return 0;
}