#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>

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
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector a(n + 1, std::vector<int>(m));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}

	int64_t dp[500][500] {};
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = 1e18;
		}
	}

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int shift = 0; shift < m; shift++) {
			std::vector<int64_t> tmp(m, 1e18);
			for (int j = 0; j < m; j++) {
				tmp[j] = dp[i - 1][j]  + a[i][(j + shift) % m] + k * 1LL * shift;
			}

			for (int j = 0; j < m; j++) tmp[j] = std::min(tmp[j], tmp[(j + m - 1) % m] + a[i][(j + shift) % m]);
			for (int j = 0; j < m; j++) {
				dp[i][j] = std::min(dp[i][j], tmp[j]);
			}
		}
	}

	std::cout << dp[n][m - 1] << '\n';
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
