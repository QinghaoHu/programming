#include <bits/stdc++.h>

constexpr int N = 210;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	int N, M, K;
	bool st[N];
	int match[N];
	std::vector<int> e[N];

	std::function<bool(int)> find = [&](int x) {
		for (auto p : e[x]) {
			if (!st[p]) {
				st[p] = true;
				if (match[p] == -1 || find(match[p])) {
					match[p] = x;
					return true;
				}
			}
		}
		return false;
	};
	
	while (std::cin >> N, N) {
		std::cin >> M >> K;

		memset(match, -1, sizeof match);
		for (int i = 0; i < N; i++) {
			e[i].clear();
		}
		
		for (int i = 0; i < K; i++) {
			int t, a, b;
			std::cin >> t >> a >> b;
			if (!a || !b) continue;
			e[a].push_back(b + 100);
		}

		int res = 0;
		for (int i = 0; i < 101; i++) {
			memset(st, 0, sizeof st);
			if (find(i)) res++;
		}
		std::cout << res << '\n';
	}
}
