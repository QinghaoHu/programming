#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	int _; std::cin >> _;
	
	for (int T = 0; T < _; T++) {
		int x, y; std::cin >> x >> y;
		if (x == 1 && y == 1) std::cout << 1 << '\n';
		else std::cout << y - x << '\n';
	}
}