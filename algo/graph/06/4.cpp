#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 200010;

int n, R, C;
int x[N], y[N], tr[N];
std::map<std::pair<int, int>, int> id;
std::vector<int> r[N], c[N];
std::unordered_map<int, int> rid, cid;
int dp[N], ans;

int low[N], ins[N], dfn[N], bel[N];
int idx, cnt;
std::stack<int> stk;
std::vector<int> scc[N];
std::vector<int> e[N];

void dfs(int x) {
	low[x] = dfn[x] = ++idx;
	ins[x] = true;
	stk.push(x);

	for (auto v : e[x]) {
		if (!dfn[v]) dfs(v);
		if (ins[v]) low[x] = std::min(low[x], low[v]);
	}

	if (dfn[x] == low[x]) {
		++cnt;
		int sz = 0;
		while (true) {
			int v = stk.top();
			stk.pop();
			sz += (v <= n);
			bel[v] = cnt;
			ins[v] = false;
			for (auto id : e[v]) if (bel[id] != 0 && bel[id] != cnt) {
				dp[cnt] = std::max(dp[cnt], dp[bel[id]]);
			}
			if (v == x) {
				break;
			}
		}
		dp[cnt] += sz;
		ans = std::max(dp[cnt], ans);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> R >> C;

	for (int i = 1; i <= n; i++) {
		std::cin >> x[i] >> y[i] >> tr[i];
		id[std::make_pair(x[i], y[i])] = i;
		r[x[i]].push_back(i);
		c[y[i]].push_back(i);
	}

	int tot = n;
	for (int i = 1; i <= n; i++) {
		if (tr[i] == 1) {
			if (!rid.count(x[i])) {
				rid[x[i]] = ++tot;
				for (auto id : r[x[i]]) e[tot].push_back(id);
			}
			e[i].push_back(rid[x[i]]);
		} else if (tr[i] == 2) {
			if (!cid.count(y[i])) {
				cid[y[i]] = ++tot;
				for (auto id : c[y[i]]) e[tot].push_back(id);
			}
			e[i].push_back(cid[y[i]]);
		} else {
			for (int dx = -1; dx <= 1; dx++) 
				for (int dy = -1; dy <= 1; dy++) {
					if (dx == 0 && dy == 0) continue;
					if (!id.count(std::make_pair(x[i] + dx, y[i] + dy))) continue;
					e[i].push_back(id[std::make_pair(x[i] + dx, y[i] + dy)]);
				}
		}
	}

	for (int i = 1; i <= tot; i++) if (!dfn[i]) {
		dfs(i);
	}

	std::cout << ans << '\n';

	return 0;
}
