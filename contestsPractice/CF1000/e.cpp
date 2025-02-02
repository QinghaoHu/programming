#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
	int n; std::cin >> n;

	std::vector<std::vector<int>> e(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	std::vector<int> d(n), s(n), l(n + 1, 0);
	auto dfs = [&](this auto &&self, int cur, int fa = -1, int dep = 0) -> void {
		s[cur] = 1;
		d[cur] = dep;
		l[dep]++;
		for (auto x : e[cur]) {
			if (x == fa) continue;
			self(x, cur, dep + 1);
			s[cur] += s[x];
		}
	};

	dfs(0);
	std::vector<i64> ls(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		ls[i] = ls[i + 1] + l[i];
	}

	i64 res = 0;
	for (int i = 1; i < n; i++) {
		res += d[i] * (ls[d[i] + 1] - s[i] + 1);
	}
	for (int i = 1; i < n; i++) {
		res += i64(l[i]) * (l[i] - 1) / 2 * i;
	}

	i64 res1 = 0;
	auto dfs2 = [&](this auto &&self, int cur, int fa = -1) -> void {
		for (int x : e[cur]) {
			if (fa == x) continue;
			self(x, cur);
			res1 += d[cur] * i64(s[cur] - 1 - s[x]) * s[x];
		}
	};
	dfs2(0);
	res -= res1 / 2;
	res *= 2;
	res -= i64(n) * (n - 1) / 2;
	for (int x : s) res += x - 1;
	std::cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

	for (int _ = 0; _ < T; _++) {
		solve();
	}

    return 0;
}
