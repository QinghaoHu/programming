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
void dbgl(std::vector<T> u) {for(auto i : u) {dbg(i);} cerr << '\n';}

void solve() {
    int n;  std::cin >> n;

    std::vector<int> a(n); for (auto &i : a) std::cin >> i;
    std::vector<int> b(n); for (auto &i : b) std::cin >> i;
    std::vector<int> choice(n, 0);

    int res = 0, bMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            res += a[i];
            choice[i] = 0;
            bMax = std::max(bMax, b[i]);
        } else if (a[i] == b[i]) {
            res += a[i];
            choice[i] = 2;
            bMax = std::max(bMax, b[i]);
        } else {
            res += b[i];
            choice[i] = 1;
            bMax = std::max(bMax, a[i]);
        }
    }
    std::cout << res + bMax << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T;
    std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
