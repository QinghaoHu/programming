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

void solve() {
    int rl[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> rl[i][j];
        }
    }
    int n;
    cin >> n;
    while(n --) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        for (int i = 0; i < 4; i++) {
            if (rl[x][i] == 0) {
                rl[x][i] = 1;
            } else {
                rl[x][i] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (i == x) continue;
            if (rl[i][y] == 0) {
                rl[i][y] = 1;
            } else {
                rl[i][y] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << rl[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
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
