#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 50005;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> p[N];
    auto add = [&](int x, int y, int z) -> void {
        p[x].push_back({y, z});
    };

    for (int i = 1; i < N; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }

    for (int i = 1; i <= n; i++) {
        int a, b, c; 
        std::cin >> a >> b >> c;
        a++; b++;
        add(a - 1, b, c);
    }

    int dist[N] {};
    bool st[N] {};
    auto spfa = [&]() -> void {
        memset(dist, -0x3f, sizeof dist);
        dist[0] = 0;

        std::queue<int> q;
        q.push(0);
        st[0] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            st[x] = false;
            for (auto [y, z] : p[x]) {
                if (dist[y] < dist[x] + z) {
                    dist[y] = dist[x] + z;
                    if (!st[y]) {
                        st[y] = true;
                        q.push(y);
                    }
                }
            }
        }
    };

    spfa();

    std::cout << dist[50001] << '\n';
    
    return 0;
}