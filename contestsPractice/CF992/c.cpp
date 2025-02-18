#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
	int n;
	i64 k;	
	std::cin >> n >> k;
	k--;

	if (n <= 60 && k >= (1LL << (n - 1))) {
		std::cout << -1 << '\n';
		return;
	}

	std::vector<int> p(n);
	int l = 0, r = n - 1;
	for (int i = 1; i < n; i++) {
		if (n - 1 - i > 60 || k < (1LL << (n - 1 - i))) {
			p[l++] = i;
		} else {
			p[r--] = i;
			k -= (1LL << (n - 1 - i));
		}
	}

	p[l] = n;

	for (int i = 0; i < n; i++) {
		std::cout << p[i] << " \n"[i == n - 1];
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