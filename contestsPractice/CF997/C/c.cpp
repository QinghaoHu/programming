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
    std::cout << 1 << ' ';
    for (int i = 0; i < n - 3; i++) {
        std::cout << i  + 1 << ' ';
    } 
    std::cout << "1 2\n";
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
