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

const int N = 5010;

int grid[N][N];

void settarget(int x, int y) {
    grid[x][y] += grid[x - 1][y] + grid[x][y - 1] - grid[x - 1][y - 1];
}

void solve() {
    int n, r;
    cin >> n >> r;
    while(n --) {
        int x, y, w;
        cin >> x >> y >> w;
        x++; y++;
        grid[x][y] += w;
    }
    r = min(r, 5001);
    int res = INT_MIN;
    for (int i = 1; i <= 5001; ++ i) 
        for (int j = 1; j <= 5001; ++ j)
            settarget(i, j);
    for (int i = r; i <= 5001; ++ i) {
        for (int j = r; j <= 5001; ++ j) {
            res = max(res, grid[i][j] - grid[i - r][j] - grid[i][j - r] + grid[i - r][j - r]);
        }
    }
    cout << res << endl;
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
