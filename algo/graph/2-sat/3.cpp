#include <bits/stdc++.h>

constexpr int N = 100010;

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int n, d; std::cin >> n >> d;
    std::string s; std::cin >> s;

    std::vector<int> X;
    for (int i = 0; i < (int)s.size(); i++) if (s[i] == 'x'){
        X.push_back(i);
    }

    int m; std::cin >> m;
    std::vector<std::array<int, 4>> cc;
    for (int i = 0; i < m; i++) {
        int u, v;
        char ty1, ty2;
        std::cin >> u >> ty1 >> v >> ty2;
        --u; --v;
        cc.push_back({u, ty1 - 'A', v, ty2 - 'A'});
    }

    std::vector<int> e[N];
    int dfn[N] {}, low[N] {}, ins[N] {}, bel[N] {};
    char ans[N];
    std::stack<int> stk;
    int idx, cnt;

    std::function<void(int)> dfs = [&](int u) {
        dfn[u] = low[u] = ++idx;
        ins[u] = true;
        stk.push(u);

        for (auto x : e[u]) {
            if (!dfn[x]) {
                dfs(x);
                low[u] = std::min(low[u], low[x]);
            } else if (ins[x]) {
                low[u] = std::min(low[u], dfn[x]);
            }
        }

        if (low[u] == dfn[u]) {
            ++cnt;
            int y;
            do {
                y = stk.top(); stk.pop();
                ins[y] = false;
                bel[y] = cnt;
            } while (y != u);
        }
    };

    auto getID = [&](int x, int y) -> int {
        if (s[x] == 'a' + y % 3) return -1;
        if (s[x] == 'a' + (y + 1) % 3) return 2 * x;
        if (s[x] == 'a' + (y + 2) % 3) return 2 * x + 1;
        assert(0);
        return -1;
    };

    auto check = [&]() -> bool {
        for (int i = 0; i < 2 * n; i++) {
            e[i].clear();
            dfn[i] = 0;
        }

        idx = cnt = 0;

        for (int i = 0; i < m; i++) {
            int f1 = getID(cc[i][0], cc[i][1]);
            int f2 = getID(cc[i][2], cc[i][3]);
            if (f1 != -1 && f2 != -1) {
                e[f1].push_back(f2);
                e[f2 ^ 1].push_back(f1 ^ 1);
            } else if (f1 != -1 && f2 == -1) {
                e[f1].push_back(f1 ^ 1);
            }
        }

        for (int i = 0; i < 2 * n; i++) if (!dfn[i]) {
            dfs(i);
        }

        for (int i = 0; i < n; i++) {
            if (bel[i * 2] == bel[i * 2 + 1]) return false;
        }

        for (int i = 0; i < n; i++) {
            if (bel[i * 2] < bel[i * 2 + 1]) {
                ans[i] = (s[i] - 'a' + 2) % 3 + 'A';
            } else {
                ans[i] = (s[i] - 'a' + 1) % 3 + 'A';
            }
        }
        return true;
    };

    while (clock() <= 1.9 * CLOCKS_PER_SEC) {
        for (int i = 0; i < d; i++) {
            s[X[i]] = "abc"[rand() % 3];
        }
        if (check()) {
            std::cout << ans << '\n';
            return 0;
        }
    }
    std::cout << -1 << '\n';

    return 0;
}
