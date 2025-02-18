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
    int64_t n; std::cin >> n;

    auto check = [&](int64_t cur) -> bool {
        while (cur) {
            if (cur % 10 == 7) {
                return true;
            }
            cur /= 10;
        }
        return false;
    };

    if (check(n)) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = 9;
    for (int i = 1; i <= 9; i++) {
        int64_t x = n;
        for (int j = 1; j <= 9; j++) {
            x += pow(10, i) - 1;
            if (check(x)) {
                ans = std::min(ans, j);
                break;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
