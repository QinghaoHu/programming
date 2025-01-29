#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int N, M; std::cin >> N >> M;

    constexpr int T = 210;
    int g[T][T] {}, st[T] {}, match[T] {};
    for (int i = 0; i < M; i++) {
        int x, y; std::cin >> x >> y;
        g[x][y] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                g[i][j] |= g[i][k] & g[k][j];
            }
        }
    }

    std::function<bool(int)> find = [&](int x) {
        for (int i = 1; i <= N; i++) {
            if (g[x][i] && !st[i]) {
                st[i] = true;
                int t = match[i];
                if (t == 0 || find(t)) {
                    match[i] = x;
                    return true;
                }
            }
        }
        return false;
    };

    int res = 0;
    for (int i = 1; i <= N; i++) {
        memset(st, 0, sizeof st);
        if (find(i)) res++;
    }
    std::cout << N - res << '\n';
} // This is the last question I wrote for the Algo practice
