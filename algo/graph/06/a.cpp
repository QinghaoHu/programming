#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 500005;

int n, m;
i64 w[N];
int bar[N];
std::vector<int> p[N];
i64 dp[N];

int low[N], dfn[N], ins[N], bel[N], siz;
int idx, cnt;
std::vector<int> scc[N];
std::stack<int> stk;

void dfs(int x) {
	low[x] = dfn[x] = ++idx;
	ins[x] = true;
	stk.push(x);

	for (auto v : p[x]) {
		if (!dfn[v]) dfs(v);
		if (ins[v]) low[x] = std::min(low[x], low[v]);
	}

	if (dfn[x] == low[x]) {
		++cnt;
		i64 sval = 0; 
		int sbar = 0;
		dp[cnt] = -(1ll << 60);
		while (true) {
			int v = stk.top();
			stk.pop();
			scc[cnt].push_back(v);
			sval += w[v];
			sbar |= bar[v];
			bel[v] = cnt;
			for (auto w : p[v]) if (bel[w] != cnt && bel[w]) {
				dp[cnt] = std::max(dp[cnt], dp[bel[w]]);
			}
			ins[v] = false;
			if (v == x) {
				break;
			}
		}
		if (sbar) dp[cnt] = std::max(0ll, dp[cnt]);
		dp[cnt] += sval;
	}
}
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		p[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}

	int s, p;
	std::cin >> s >> p;

	for (int i = 0; i < p; i++) {
		int x;
		std::cin >> x;
		bar[x] = 1;
	}

	dfs(s);

	std::cout << dp[bel[s]] << '\n';
	
	return 0;
}
