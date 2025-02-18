#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        a[x]++;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] >= 2) {
            a[i + 1] += a[i] - 2;
            a[i] = 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
}

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    for (int it = 0; it < tt; it++) {
        solve();
    }

    return 0;
}