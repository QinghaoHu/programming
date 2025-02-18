#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (auto &i : a) {
		std::cin >> i;
	}

	for (int i = 0; i < n; i++) {
		bool willWin = true;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (abs(a[i] - a[j]) % k == 0) {
				willWin = false;
				break;
			}
		}
		if (willWin) {
			std::cout << "YES\n" << i + 1 << '\n';
			return;
		}
	}
	std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int tt; 
	std::cin >> tt;

	while (tt--) {
		solve();
	}

	return 0;
}