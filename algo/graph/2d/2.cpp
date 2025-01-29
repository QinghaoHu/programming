#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;

	const int N = 110;
	bool g[N][N] {}, st[N][N] {};
	std::pair<int, int> match[N][N];

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		g[a][b] = true;
	}

	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	std::function<bool(int, int)> find = [&](int x, int y) {
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if (a && a <= n && b && b <= n && !g[a][b] && !st[a][b]) {
				st[a][b] = true;
				std::pair<int, int> t = match[a][b];
				if (t.first == -1 || find(t.first, t.second)) {
					match[a][b] = std::make_pair(x, y);
					return true;
				}
			}
		}
		return false;
	};

	memset(match, -1, sizeof match);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i + j) % 2 && !g[i][j]) {
				memset(st, 0, sizeof st);
				if (find(i, j)) res++;
			}
		}
	}
	std::cout << res << '\n';
}