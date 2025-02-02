#include <bits/stdc++.h>

constexpr int N = 200010;

void solve() {
    int n; std::cin >> n;
    
    std::vector<std::vector<int>> d(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; std::cin >> x >> y;
        x--; y--;
        d[x].push_back(y);
        d[y].push_back(x);
    }

    if (n == 2) {
        std::cout << 0 << '\n';
        return;
    }

    std::multiset<int> c;
    int res = 0;
    std::function<void(int, int)> dfs = [&](int cur, int fa) {
        if (fa != -1) {
            res = std::max(res, (int)(d[fa].size() + d[cur].size() - 2));
        }

        for (int x : d[cur]) {
            if (x == fa) continue;
            dfs(x, cur);
        }

        c.erase(c.find(d[cur].size()));
        for (int x : d[cur]) {
            c.erase(c.find(d[x].size()));
        }

        if (!c.empty()) {
            res = std::max(res, (int)(d[cur].size() + *c.rbegin() - 1));
        }

        c.insert(d[cur].size());
        for (auto x : d[cur]) {
            c.insert(d[x].size());
        }
    };

    for (int i = 0; i < n; i++) {
        c.insert((int)d[i].size());
    }

    dfs(0, -1);
    std::cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) solve();

    return 0;
}
