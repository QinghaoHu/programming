#include <bits/stdc++.h>

void solve() {
    int n, l, r; std::cin >> n >> l >> r;
    l--; r--;

    std::vector<int> a(n); for (auto &i : a) std::cin >> i;
    std::priority_queue<int, std::vector<int>, std::greater<int>> c;
    
    int64_t res = 0, cnt = 0;
    for (int i = 0; i <= r; i++) c.push(a[i]);
    while (!c.empty()) {
        res += c.top();
        c.pop();
        cnt++;
        if (cnt == r - l + 1) break;
    }

    while (!c.empty()) c.pop();
    int64_t res2 = 0;
    cnt = 0;
    for (int i = l; i < n; i++) c.push(a[i]);
    while (!c.empty()) {
        res2 += c.top();
        c.pop();
        ++cnt;
        if (cnt == r - l + 1) break;
    }
    std::cout << std::min(res, res2) << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        solve();
    }
}
