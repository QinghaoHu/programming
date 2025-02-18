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
	int x, y; std::cin >> x >> y;

    if (x == y || y - x > 1) {
        std::cout << "No\n";
        return;
    } 
    if (y - x == 1) {
        std::cout << "Yes\n";
        return;
    }
    if ((x - y + 1) % 9 == 0) {
        std::cout << "Yes\n";
        return;
    }
    std::cout << "No\n";
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
