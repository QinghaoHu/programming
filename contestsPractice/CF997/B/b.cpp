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
    std::vector g(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j] - '0';
        }
    }
    
    std::vector<int> b1(n, 0), c0(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (g[i][j] == 1) b1[i]++;
        }
        for (int j = i + 1; j < n; j++) {
            if (g[i][j] == 0) c0[i]++;
        }
    }

    std::vector<int> vis(n, false);
    for (int _ = 0; _ < n; _++) {
        int t = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (vis[i]) continue;
            if (b1[i] == 0 && c0[i] == 0) t = i;
        }
        std::cout << t + 1 << ' ';
        vis[t] = true;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) continue;
            if (g[i][t] == 1 && t < i) b1[i]--;
            if (g[i][t] == 0 && t > i) c0[i]--;
        }
    }
    std::cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
