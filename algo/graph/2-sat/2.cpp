#include <bits/stdc++.h>

constexpr int N = 2010;

int n, m;
std::vector<int> e[N];

int idx, cnt, low[N];
int ins[N], dfn[N], bel[N];
std::stack<int> stk;
bool vis[N];

void dfs(int x) {
	dfn[x] = low[x] = ++idx;
	ins[x] = true;
	stk.push(x);

	for (auto u : e[x]) {
		if (!dfn[u]) {
			dfs(u);
			low[x] = std::min(low[u], low[x]);
		} else if (ins[u]) {
			low[x] = std::min(low[x], dfn[u]);
		}
	}

	if (low[x] == dfn[x]) {
		int y;
		++cnt;
		do {
			y = stk.top();
			stk.pop();
			ins[y] = false;
			bel[y] = cnt;
		} while (y != x);
	}
}

void dfs2(int u) {
	for (auto x : e[u]) {
		if (!vis[x]) {
			vis[x] = true;
			dfs2(x);
		}
	}
}

bool check(int a, int b) {
	for (int i = 0; i < N; i++) vis[i] = false;
	vis[a] = true;
	dfs2(a);
	return vis[b];
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		char tr1[2], tr2[2];
		std::cin >> u >> tr1 >> v >> tr2;
		u = u * 2 + (tr1[0] == 'Y');
		v = v * 2 + (tr2[0] == 'Y');
		e[u ^ 1].push_back(v);
		e[v ^ 1].push_back(u);
	}

	for (int i = 1; i <= 2 * n; i++) if (!dfn[i]) {
		dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (bel[i * 2] == bel[i * 2 + 1]) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	char ans[N] {};
	for (int i = 1; i <= n; i++) {
		if (check(i * 2, i * 2 + 1)) {
			ans[i] = 'Y';
		} else if (check(i * 2 + 1, i * 2)) {
			ans[i] = 'N';
		} else {
			ans[i] = '?';
		}
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i];
	}
	std::cout << '\n';
}
