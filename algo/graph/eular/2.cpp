#include <bits/stdc++.h>

constexpr int N = 200010;

int n, m, cnt;
int type;
int ver[N], head[N], nxt[N], used[N], ans[N];
int dout[N], din[N];
int idx = -1;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	std::cin >> type >> n >> m;
	memset(head, -1, sizeof head);

	for (int i = 0; i < m; i++) {
		int a, b; std::cin >> a >> b;
		auto addEdge = [&](int a, int b) {
			ver[++idx] = b, nxt[idx] = head[a], head[a] = idx;
		};
		addEdge(a, b);
		if (type == 1) addEdge(b, a);
		dout[a]++, din[b]++;
	}

	if (type == 1) {
		for (int i = 1; i <= n; i++) {
			if ((din[i] + dout[i]) & 1) {
				std::cout << "NO\n";
				return 0;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (din[i] != dout[i]) {
				std::cout << "NO\n";
				return 0;
			}
		}
	}

	std::function<void(int)> dfs = [&](int u) {
		for (int i = head[u]; ~i;) {
			if (used[i]) {
				i  = nxt[i];
				continue;
			}

			used[i] = true;
			if (type == 1) used[i ^ 1] = true;

			int t;

			if (type == 1) {
				t = i / 2 + 1;
				if (i & 1) t = -t;
			} else t = i + 1;

			int j = ver[i];
			i = nxt[i];
			dfs(j);

			ans[++cnt] = t;
		}
	};

	for (int i = 1; i <= n; i++) {
		if (head[i] != -1) {
			dfs(i);
		}
	}

	if (cnt < m) {
		std::cout << "NO\n";
		return 0;
	}

	std::cout << "YES\n";
	for (int i = cnt; i; i--) std::cout << ans[i] << ' ';
	std::cout << '\n';
}