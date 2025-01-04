#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5010;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::pair<int, int>> p[N];
    auto add = [&](int a, int b, int c) -> void {
        p[b].push_back(std::make_pair(a, c));
    };

    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(b, a, c);
    }

    for (int i = 1; i <= n; i++) {
        add(i, 0, 0);
    }

    std::vector<int> d(n + 1, 1 << 30);
    d[0] = 0;

    std::queue<int> q;
    q.push(0);

    int st[N] {}, cnt[N] {};
    st[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        st[x] = false;
        for (auto [y, z] : p[x]) {
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n + 1) {
                    std::cout << "NO\n";
                    return 0;
                }
                if (!st[y]) {
                    st[y] = true;
                    q.push(y);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << d[0] - d[i] << " \n"[i == n];
    }

    return 0;
}
