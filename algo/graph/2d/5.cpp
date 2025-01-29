#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    constexpr int N = 110;
    int g[N][N] {}, match[N] {}, st[N] {};
    int res = 0;

    g[1][2] = 1, g[2][3] = 1, g[3][4] = 1;
    std::function<bool(int)> find = [&](int x) {
        for (int i = 1; i < N; i++) {
            if (st[i] || !g[x][i]) continue;
            st[i] = true;
            if (match[i] == 0 || find(match[i])) {
                match[i] = x;
                return true;
            }
        }
        return false;
    };

    for (int i = 0; i < N; i++) {
        memset(st, 0, sizeof st);
        if (find(i)) res++;
    }
    std::cout << res << '\n';
}
