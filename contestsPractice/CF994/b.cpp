#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<char> s(n);
    for (auto &i : s) {
        std::cin >> i;
    }
    
    int sCnt = 0, pCnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's') {
            if (pCnt) {
                std::cout << "NO\n";
                return;
            }
            sCnt += (i != 0);
        } else if (s[i] == 'p') {
            if (sCnt && i != n - 1) {
                std::cout << "NO\n";
                return;
            }
            pCnt++;
        }
    }
    std::cout << "YES\n";
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
