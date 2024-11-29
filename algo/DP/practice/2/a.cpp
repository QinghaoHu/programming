#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)
#define print(x) cerr << x << ' ';
#define println(x) cerr << x << '\n';

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int F, V; cin >> F >> V;
    int flow[110][110] {};
    FOR(i, 1, F + 1) {
        FOR(j, 1, V + 1) {
            cin >> flow[i][j];
        }
    }

    vector f(110, vector<ll> (110, INT_MIN));
    FOR(i, 1, V + 1) f[1][i] = flow[1][i];
    FOR(i, 2, F + 1) {
        FOR(j, 1, V + 1) {
            FOR(k, 1, j) {
                f[i][j] = max(f[i][j], f[i - 1][k] + flow[i][j]);
            }
        }
    }

    int ans = INT_MIN, pos = -1;
    FOR(i, 1, V + 1) {
        if (f[F][i] > ans) {
            ans = f[F][i];
            pos = i;
            print(pos);
        }
    }

    cout << ans << '\n';

    vector<int> res;
    res.push_back(pos);
    for (int i = F; i > 1; i--) {
        for (int j = 1; j < pos; j++) {
            if (f[i][pos] == f[i - 1][j] + flow[i][pos]) {
                res.push_back(j);
                pos = j;
                break;
            }
        }
    }

    reverse(res.begin(), res.end());
    for (auto i : res) cout << i << ' ';
    cout << "\n";

    return 0;
}
