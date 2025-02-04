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

	int t1 = 0, t2 = 0;
	std::unordered_map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		int x; 
		std::cin >> x;

		if (!mp.count(x)) {
			mp[x] = true;
			t1++;
		}
	}

	mp.clear();

	for (int i = 0; i < n; i++) {
		int x; 
		std::cin >> x;

		if (!mp.count(x)) {
			mp[x] = true;
			t2++;
		}
	}

	if (std::max(t1, t2) >= 3 || (t1 == 2 && t2 == 2)) {
		std::cout << "YES\n"; 
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

	while (T--) {
		solve();
	}

    return 0;
}
