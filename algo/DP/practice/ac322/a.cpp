#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n, m = 0; cin >> n;
        int a[205] {}, b[205] {};
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x == a[m]) {
                b[m]++;
            } else {
                a[++m] = x;
                b[m] = 1;
            }
        }
        int f[205][205][205] {};
        memset(f, 0xcc, sizeof(f));
        for (int i = 1; i <= m; i++) {
            f[i][i][0] = b[i] * b[i];
            f[i][i][b[i]] = 0;
        }
        for (int len = 2; len <= m; len++) {
            for (int l = 1; l <= m - len + 1; l++) {
                int r = l + len - 1;
                for (int k = l; k < r; k++) {
                    f[l][r][0] = max(f[l][r][0], f[l][k][0] + f[k + 1][r][0]);
                }
                if (a[l] != a[r]) continue;
                int tot = b[l] + b[r];
                for (int k = l + 1; k < r; k++) {
                    if (a[k] == a[r]) tot += b[k];
                }
                for (int cnt = b[l] + b[r]; cnt <= tot; cnt++) {
                    for (int k = l + 1; k <= r; k++) {
                        if (a[l] == a[k]) {
                            f[l][r][cnt] = max(f[l][r][cnt], f[l + 1][k - 1][0] + f[k][r][cnt - b[l]]);
                        }
                    }
                    f[l][r][0] = max(f[l][r][0], f[l][r][cnt] + cnt * cnt);
                }
            }
        }
        cout << "Case " << _ << ": " << f[1][m][0] << '\n';
    }

    return 0;
}
