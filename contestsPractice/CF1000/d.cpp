#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, m; std::cin >> n >> m;
    
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];

    int K = 0;
    if (n > m) {
        std::swap(n, m);
        std::swap(a, b);
    }
    if (2 * n < m) K = n;
    else K = (n + m) / 3;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<i64> as(1, 0), bs(1, 0);
    for (int i = 0; i < n; i++) {
        if (i < n - i - 1) {
            as.push_back(a[n - i - 1] - a[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (i < m - i - 1) {
            bs.push_back(b[m - i - 1] - b[i]);
        }
    }

    std::vector<i64> asp(as.size(), 0), bsp(bs.size(), 0);
    for (int i = 1; i < as.size(); i++) {
        asp[i] = asp[i - 1] + as[i];
    }
    for (int i = 1; i < bs.size(); i++) {
        bsp[i] = bsp[i - 1] + bs[i];
    }

    int ai = 0, bi = 0;
    auto calc = [&](int la, int lb, int tot) -> i64 {
        ai = std::min(la, ai);
        bi = std::min(lb, bi);

        while (ai + bi < tot) {
            if (ai == la || ai + 1 >= as.size()) bi++;
            else if (bi == lb || bi + 1 >= bs.size()) ai++;
            else {
                if (as[ai + 1] > bs[bi + 1]) ai++;
                else bi++;
            }
        }

        while (ai + bi > tot) {
            if (ai == 0) bi--;
            else if (bi == 0) ai--;
            else {
                if (as[ai] > bs[bi]) bi--;
                else ai--;
            }
        }
        return asp[ai] + bsp[bi];
    };

    std::vector<i64> ans(K);
    for (int i = 1; i <= K; i++) {
        if (i * 2 <= n) {
            ans[i - 1] = calc(i, i, i);
        } else {
            ans[i - 1] = calc(n - i, std::min(m - i, m / 2), i);
        }
    }   

    std::cout << K << '\n';
    for (auto x : ans) std::cout << x << ' ';
    std::cout << '\n';
    
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--)
		solve();
    
    return 0;
}
