#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    char a[105] {};
    cin >> a + 1;
    int n = strlen(a + 1);
    int f[105][105] {}, p[105][105] {};
    memset(f, 0x3f, sizeof(f));

    auto equals = [&](int r, int ed, int len) -> bool {
        for (int i = 0; i < len; i++) {
            if (a[r - i] != a[ed - i]) return false;
        }
        return true;
    };

    function<void(int, int)> print = [&](int l, int r) {
        if (!p[l][r]) {
            for (int i = l; i <= r; i++) cout << a[i];
            return;
        }
        if (p[l][r] > 0) {
            print(l, p[l][r]);
            print(p[l][r] + 1, r);
        } else {
            int len = -p[l][r];
            cout << (r - l + 1) / len << "(";
            print(l, l + len - 1);
            cout << ")";
        }
    };
    
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            if (len == 1) f[l][r] = 1;
            else {
                for (int k = l; k < r; k++) {
                    if (f[l][k] + f[k + 1][r] < f[l][r]) {
                        f[l][r] = f[l][k] + f[k + 1][r];
                        p[l][r] = k;
                    }
                }
            }
            for (int ed = r + len, cnt = 2; ed <= n && equals(r, ed, len); ed += len, cnt++) {
                if (f[l][r] + 2 + std::to_string(cnt).length() < f[l][ed]) {
                    f[l][ed] = f[l][r] + 2 + std::to_string(cnt).length();
                    p[l][ed] = -len;
                }
            }
        }
    }

    print(1, n);

    return 0;
}
