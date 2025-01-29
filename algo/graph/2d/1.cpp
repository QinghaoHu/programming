#include <bits/stdc++.h>

constexpr int N = 200010;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;
    
    int head[N] {}, nxt[N] {}, ver[N] {}, weight[N] {};
    int idx = 0;
    auto addEdge = [&](int a, int b, int c) {
        ver[++idx] = b, weight[idx] = c, nxt[idx] = head[a], head[a] = idx;
    };

    for (int i = 0; i < m; i++) {
        int a, b, c; 
        std::cin >> a >> b >> c;
        addEdge(a, b, c), addEdge(b, a, c);
    }

    std::vector<int> colors(n + 1, 0);
    std::function<bool(int, int, int)> dfs = [&](int u, int c, int mid) {
        colors[u] = c;
        for (int i = head[u]; i; i = nxt[i]) {
            int y = ver[i];
            if (weight[i] <= mid) continue;
            else if (colors[y]) {
                if (colors[y] == c) return false;
            } else if (!dfs(y, 3 - c, mid)) {
                return false;
            }
        }
        return true;
    };

    auto check = [&](int mid) -> bool {
        colors.assign(colors.size(), 0);
        for (int i = 1; i <= n; i++) if (colors[i] == 0) {
            if (!dfs(i, 1, mid)) return false;
        }
        return true;
    };

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    std::cout << r << '\n';

    return 0;
}
