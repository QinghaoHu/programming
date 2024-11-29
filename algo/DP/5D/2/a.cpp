#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const double eps = 1e-9;
const int INF = 1061109567;

#define rep(i, a, n) for (int i = a; i < n; i++) 
#define per(i, a, n) for (int i = n; i >= a; i--)

int mod(int x, int k) {
    return (x % k + k) % k;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int f[12][83][83][83] {}, pwr[12][83] {};
    for (int k = 1; k <= 82; k++) {
        pwr[0][k] = 1 % k;
        for (int i = 1; i <= 10; i++) pwr[i][k] = pwr[i - 1][k] * 10 % k;
        f[0][0][k][0] = 1;
        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j <= 82; j++) {
                for (int l = 0; l < k; l++) {
                    for (int p = 0; p <= 9; p++) {
                        if (j - p < 0) break;
                        f[i][j][k][l] += f[i - 1][j - p][k][mod(l - p * pwr[i - 1][k], k)];
                    }
                }
            }
        }
    }

    auto cnt = [&](int R) -> int {
        int a[11] {}, n;
        for(n = 0; R; R /= 10) a[++n] = R % 10;
        int ans = 0;
        for (int sum = 1; sum <= 82; sum++) {
            int t = 0, q = 0; //t: the pre-sum, q: the rest
            for (int i = n; i; i--) {
                for (int p = 0; p < a[i]; p++) {
                    if (sum - t - p < 0) break;
                    ans += f[i - 1][sum - t - p][sum][mod(0 - q - p * pwr[i - 1][sum], sum)];
                }
                t += a[i];
                q = (q + a[i] * pwr[i - 1][sum]) % sum;
            }
            if (t == sum && q == 0) ans++;
        }
        return ans;
    };

    int R, L; cin >> L >> R;
    cout << cnt(R) - cnt(L - 1) << '\n';

    return 0;
}
