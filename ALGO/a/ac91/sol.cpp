#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>

using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > weight(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cin >> weight[i][j];
        }
    }
    int dp[1 << n][n];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i >> j & 1) {
                for (int k = 0; k < n; ++ k) {
                    if ((i - (1 << j)) >> k & 1) {
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
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
