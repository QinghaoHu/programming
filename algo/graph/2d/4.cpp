#include <bits/stdc++.h>

int main() {
    using namespace std;
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;

	bool g[110][110] {};
	bool st[110][110] {};
	pair<int, int> match[110][110] {};

	for (int i = 0; i < K; i++) {
		int x, y; 
		cin >> x >> y;
		g[x][y] = true;
	}

	int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	std::function<bool(int, int)> find = [&](int x, int y) {
		for (int i = 0; i < 8; i++) {
			int a = x + dx[i], b = y + dy[i];
			if (a < 1 || a > N || b < 1 || b > M || g[a][b] || st[a][b]) continue;
			st[a][b] = true;
			auto t = match[a][b];

			if (t.first == 0 || find(t.first, t.second)) {
				match[a][b] = make_pair(x, y);
				return true;
			}
		}
		return false;
	};

	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (g[i][j] || (i + j) % 2) continue;
			memset(st, 0, sizeof st);
			if (find(i, j)) res++;
		}
	}
	cout << N * M - K - res << '\n';

    return 0;
}
