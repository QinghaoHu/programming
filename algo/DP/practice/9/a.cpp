#include <bits/stdc++.h>

using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vector<int> a(2 * N + 10, 0); for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) a[i + N] = a[i];

    long long f[210][210] {};
    for (int len = 3; len <= N + 1; len++) {
        for (int l = 1; l <= 2 * N - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, f[i][i + N]);
    }
    cout << ans << '\n';

    return 0;
}
