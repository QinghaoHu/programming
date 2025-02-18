#include <bits/stdc++.h>

int mode(int x, int y) {
    return (x % y + y) % y;
}

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    x--, y--;
	
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = (i % 2 ? 0 : 1);
    }

    std::set<int> s;
    s.insert(mode(x - 1, n));
    s.insert(mode(x + 1, n));
    s.insert(res[y]);

    bool change = false;
    for (auto i : s) {
        if (i == res[x]) {
            change = true;
            break;
        }
    }

    if (change) {
        res[x] = 2;
    }

    for (auto i : res) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

    int T; 
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
