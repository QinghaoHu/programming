#include <bits/stdc++.h>

constexpr int N = 100010;

int n, m;
int dfn[N];
std::vector<int> e[N];
int bel[N], ins[N], idx, cnt;
int low[N];
std::stack<int> stk;

void dfs(int x) {
	dfn[x] = low[x] = ++idx;
	ins[x] = true;
	stk.push(x);

	for (auto u : e[x]) {
		if (!dfn[u]) {
			dfs(u);
			low[x] = std::min(low[x], low[u]);
		} else if (ins[u]) {
			low[x] = std::min(low[x], dfn[u]);
		} 
	}

	if (dfn[x] == low[x]) {
		int y;
		++cnt;
		do {
			y = stk.top(); stk.pop();
			bel[y] = cnt;
			ins[y] = false;
		} while (y != x);
	}
}

void solve() {
	std::cin >> n >> m;
	for (int i = 0; i < 2 * n; i++) {
		dfn[i] = 0; e[i].clear();
	}

	idx = cnt = 0;

	for (int i = 0; i < m; i++) {
		char ty1, ty2;
		int u, v;
		std::cin >> ty1 >> u >> ty2 >> v;
		u--; v--;
		u = u * 2 + (ty1 == 'h');
		v = v * 2 + (ty2 == 'h');
		e[u ^ 1].push_back(v);
		e[v ^ 1].push_back(u);
	}

	for (int i = 0; i < 2 * n; i++) if (dfn[i] == 0) {
		dfs(i);
	}

	for (int i = 0; i < n; i++) {
		if (bel[i * 2] == bel[i * 2 + 1]) {
			std::cout << "BAD\n";
			return;
		}
	}
	std::cout << "GOOD\n";
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
