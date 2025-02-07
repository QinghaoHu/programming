#include <bits/stdc++.h>

using std::cerr;

template<typename T>
void dbg(T x) {cerr << x << ' ';}
template<typename T>
void dbgl(T x) {cerr << x << '\n';}
void dbg(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void dbgl(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void dbg(std::vector<T> u) {for(auto i : u) dbg(i);}
template<typename T>
void dbgl(std::vector<T> u) {for(auto i : u) dbgl(i); cerr << '\n';}

void solve() {
	int n, X, Y;
	std::cin >> n >> X >> Y;
	X--, Y--;

	int m;
	std::cin >> m;

	std::vector<std::pair<int, int>> edge1(m);
	std::vector<std::vector<int>> E1(n);
	for (auto &[u, v] : edge1) {
		std::cin >> u >> v;
		u--, v--;
		E1[u].push_back(v);
		E1[v].push_back(u);
	}

	std::cin >> m;

	std::vector<std::pair<int, int>> edge2(m);
	std::vector<std::vector<int>> E2(n);
	for (auto &[u, v] : edge2) {
		std::cin >> u >> v;
		u--, v--;
		E2[u].push_back(v);
		E2[v].push_back(u);
	}

	std::priority_queue<std::tuple<int64_t, int, int>, std::vector<std::tuple<int64_t, int, int>>, std::greater<>> Q;
	for (auto [u1, v1] : edge1) {
		for (auto [u2, v2] : edge2) {
			if (u1 == u2 && v1 == v2) {
				Q.push({0, u1, u1});
			}

			if (u1 == v2 && u2 == v1) {
				Q.push({0, u1, u1});
			}
		}
	}

	// dbg(Q.size());

	std::vector vis(n, std::vector<int64_t>(n));
	int64_t res = -1;
	while (!Q.empty()) {
		auto [d, u1, u2] = Q.top();
		Q.pop();

		if (vis[u1][u2] == true) continue;
		vis[u1][u2] = true;

		if (u1 == X && u2 == Y) {
			res = d;
			break;
		}

		d += abs(u1 - u2);

		for (auto v1 : E1[u1]) {
			for (auto v2 : E2[u2]) {
				Q.push({d, v1, v2});
			}
		}
	}

	std::cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		solve();
	}

    return 0;
}
