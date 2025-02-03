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
	int n; std::cin >> n;
	std::vector<int> a(n); for (auto &i : a) std::cin >> i;
	std::vector<int> b(n); for (auto &i : b) std::cin >> i;

	bool reject = 0;
	int gap = 0, minU = (int)2e9;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			if (reject) {
				std::cout << "No\n";
				return;
			}
			gap = b[i] - a[i];
			reject = true;
		} else {
			minU = std::min(a[i] - b[i], minU);
		}
	}
	std::cout << (minU < gap ? "No" : "Yes") << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

	while (T--) {
		solve();
	}

    return 0;
}
