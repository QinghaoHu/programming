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

char g[1000][1000];

void b(int n, int x, int y) {
    if (n == 1) {
        g[x][y] = 'X';
        return;
    }
    int len = (int)pow(3, n - 2);
    b(n - 1, x, y);
    b(n - 1, x + 2 * len, y);
    b(n - 1, x + len, y + len);
    b(n - 1, x, y + 2 * len);
    b(n - 1, x + 2 * len, y + 2 * len);
}

void solve() {
    int t;
    while(cin >> t && t != -1) {
        memset(g, ' ', sizeof g);
        b(t, 0, 0);
        int len = (int)pow(3, t - 1);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    // cin >> T;

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
