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
    int n, m; std::cin >> n >> m;
    int64_t res = m * 4;
    int a, b;

    auto minus = [&](int x1, int y1, int x2, int y2) -> int64_t {
        int r1 = std::abs(x1 - x2);
        int r2 = std::abs(y2 - y1);
        return int64_t(2 * (r1 + r2));
    };

    std::cin >> a >> b;

    for (int i = 0; i < n - 1; i++) {
        int x, y; std::cin >> x >> y;
        int a2 = a + x, b2 = b + y;
        res += m * 4;
        res -= minus(a + m, b + m, a2, b2);
        a = a2, b = b2;
        dbg(a), dbg(' '), dbgl(b);
    }
    std::cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
