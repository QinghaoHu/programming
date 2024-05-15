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

char backup[5][5], g[5][5];

void turn(int x, int y) {
	if (g[x][y] == '1') {
		g[x][y] = '0';
	} else {
		g[x][y] = '1';
	}
}

void trn(int x, int y) {
	int vx[5] = {0, 1, 0, -1, 0}, vy[5] = {0, 0, 1, 0, -1};
	for (int i = 0; i < 5; ++ i) {
		int ax = x + vx[i], ay = y + vy[i];
		
		if (ax < 0 || ax > 4 || ay < 0 || ay > 4) continue;
		turn(ax, ay);
	}
}

void solve() {
    for (int i = 0; i < 5; ++ i) 
		for (int j = 0; j < 5; ++ j)
			cin >> backup[i][j];
	int ans = INT_MAX;
	for (int n = 0; n < 1 << 5; ++ n) {
		int res = 0;
		memcpy (g, backup, sizeof backup);
		for (int i = 0; i < 5; ++ i) {
			if (n >> i & 1) {
				trn(0, i);
				++ res;
			}
		}
		for (int i = 0; i < 4; ++ i) {
			for (int j = 0; j < 5; ++ j) {
				if (g[i][j] == '0') {
					trn(i + 1, j);
					++ res;
				}
			}
		}
		bool isA = true;
		for (int i = 0; i < 5; ++ i) {
			if (g[4][i] == '0') {
				isA = false; 
				break;
			}
		}
		if (isA) ans = min (ans, res);
	}
	if (ans > 6) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    cin >> T;

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
