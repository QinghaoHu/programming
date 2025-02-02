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

	int64_t ans = 0;
	for (int x = 1; x <= 10; x++) {
		std::vector<int> b(n);
		for (int i = 0; i < n; i++) {
			b[i] = (a[i] > x ? 1 : -1);
		}

		int sum = n;
		std::vector<int> pref(n);
		for (int i = 0; i < n; i++) {
			pref[i] = sum;
			sum += b[i];
		}

		std::vector<int> cnt(2 * n + 1, 0);
		sum = n;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == x) {
				while (j <= i) {
					cnt[pref[j]]++;
					j++;
				}
			}
			sum += b[i];
			ans += cnt[sum];
			if (cnt[sum] > 0) {
				dbg(i), dbg(' '), dbgl(cnt[sum]);
			}
		}
	}
	// dbg(ans);
	ans = 1ll * n * (n + 1) / 2 - ans;
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

	while (T--) {
		solve();
	}

    return 0;
}
