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
	int d[15], f[15];
	d[1] = 1;
	for (int i = 2; i <= 12; ++ i) {
		d[i] = 2 * d[i - 1] + 1;
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= 12; ++ i) {
		for (int j = 0; j < i; ++ j) {
			f[i] = min (f[i], 2 * f[j] + d[i - j]);
		}
	}
	for (int i = 1; i <= 12; ++ i) {
		cout << f[i] << " ";
	}
	cout << endl;
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
