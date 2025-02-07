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
	int n;
	std::cin >> n;

	std::vector a(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<int> suffix(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] != 1) break;
			suffix[i]++;
		}
	}

	sort(suffix.begin(), suffix.end());

	int ans = 1;
	for (auto i : suffix) {
		if (i >= ans) {
			ans++;
		}
	}
	std::cout << std::min(ans, n) << '\n';
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
