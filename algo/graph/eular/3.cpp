#include <bits/stdc++.h>

constexpr int N = 2010;

int g[N][N], d[N];
int n = 0, m;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; std::cin >> a >> b;
		n = std::max(n, std::max(a, b));
		// std::cerr << n << "-> \n";
		g[a][b]++, g[b][a]++;
		d[a]++, d[b]++;
	}

	int start = 1;
	while (!d[start]) start++;
	for (int i = 1; i <= n; i++) if (d[i] % 2) {
		start = i;
		break;
	}

	int ans[N] {}, cnt = 0;
	std::function<void(int)> dfs = [&](int u) {
		for (int i = 1; i <= n; i++) {
			if (g[u][i]) {
				g[i][u]--, g[u][i]--;
				dfs(i);
			}
		}
		ans[++cnt] = u;
	};

	dfs(start);

	for (int i = cnt; i; i--) std::cout << ans[i] << '\n';
}