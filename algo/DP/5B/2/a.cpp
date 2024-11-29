#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

int main() {
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> a(n + 1, 0); for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];

    ll f[5006][5006] {}; int p[5006][5006] {};
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= n; i++) {
        f[i][i] = 0, p[i][i] = i;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            for (int j = p[l][r - 1]; j <= p[l + 1][r]; j++) {
                if (f[l][r] > f[l][j] + f[j + 1][r] + r - l + 1) {
                    f[l][r] = f[l][j] + f[j + 1][r] + r - l + 1;
                    p[l][r] = j;
                }
            }
        }
    }
    cout << f[1][n] << '\n';

    return 0;
}
