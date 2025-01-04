#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 100010;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> p[N];

    auto add = [&](int a, int b, int z) -> void {
        p[a].push_back(std::make_pair(b, z));
    };

    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> w >> u >> v;
        if (w == 1) {
            add(u, v, 0);
            add(v, u, 0); 
        } else if (w == 2) {
            add(u, v, -1);
        } else if (w == 3) {
            add(v, u, 0);
        } else if (w == 4) {
            add(v, u, -1);
        } else {
            add(u, v, 0);
        }
    }

    std::vector<int> d(n + 1, (1 << 30));
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        add(0, i, -1);
    }

    auto spfa = [&]() -> bool {
        std::vector<int> st(n + 1, 0), cnt(n + 1, 0);

        std::queue<int> q;
        q.push(0);

        st[0] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            st[x] = false;
            for (auto [y, z] : p[x]) {
                if (d[y] > d[x] + z) {
                    d[y] = d[x] + z;
                    cnt[y] = cnt[x] + 1;
                    if (cnt[y] >= n + 1) return false;
                    if (!st[y]) {
                        q.push(y);
                        st[y] = true;
                    }
                }
            }
        }
        return true;
    };

    if (!spfa()) {
        std::cout << -1 << '\n';
        return 0;
    }

    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        res += d[0] - d[i];
    }
    std::cout << res << '\n';
    
    return 0;
}