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
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	} 

	if (n == k) {
		int t = 1;
		for (int i = 1; i < k; i += 2) {
			if (a[i] != t) {
				std::cout << t << '\n';
				return;
			} else {
				t++;
			}
		} 
		std::cout << k / 2 + 1 << '\n';
		return;
	} else {
		for (int i = 1; i < n - k + 2; i++) {
			if (a[i] != 1) {
				std::cout << 1 << '\n';
				return;
			}
		}
	}
	std::cout << 2 << '\n';
	return;
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
