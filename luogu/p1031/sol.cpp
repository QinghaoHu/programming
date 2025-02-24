#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int avg = 0, n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    for (int i = 0; i < n; i++) {
        a[i] -= avg;
    }
    int js = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        a[i + 1] += a[i];
        js++;
    }
    cout << js << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    //cin >> T;

    while(T --) {
        solve();
    }

    return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
