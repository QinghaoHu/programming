#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &i : a) {
        std::cin >> i;
    }

    int r = (a[0] != 0);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 0 && a[i] != 0) {
            r++;
        }
    }

    if (r == 0) std::cout << 0 << '\n';
    else {
        std::cout << (r < 2 ? 1 : 2) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}