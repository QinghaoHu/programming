#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	if (n == 1) {
		std::cout << 1 << '\n';
	} else {
		int res = 2, t = 4;
		while (t < n) {
			res++;
			t += (t + 2);
			std::cerr << t << '\n';
		}
		std::cout << res << '\n';
	}
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