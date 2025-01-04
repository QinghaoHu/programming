#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> E;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        E.push_back({v, u, w});
    }

    std::vector<int> d(n + 1, (1 << 30));
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        E.push_back({i, 0, 0});
    }

    for (int i = 0; i <= n; i++) {
        for (auto [u, v, w] : E) {
            d[u] = std::min(d[u], d[v] + w);
        }
    }

    for (auto [u, v, w] : E) {
        if (d[u] > d[v] + w) {
            std::cout << "NO\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << d[0] - d[i] << " \n"[i == n];
    }
    
    return 0;
}
