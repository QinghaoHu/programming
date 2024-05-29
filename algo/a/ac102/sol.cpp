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

const double eps = 1e-5;

int n, f;

bool check(double mid, vector<double> a) {
	vector<double> b(n + 1, 0);
	for (int i = 1; i <= n; i++) 
		b[i] = b[i - 1] + a[i] - mid;
	double mins = 0;
	for (int k = f; k <= n; k++) {
		mins = min(mins, b[k - f]);
		if (b[k] >= mins) return true;
	}
	return false;
}

void solve() {
	cin >> n >> f;
	vector<double> a(n + 1, 0);
	double l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r = max (r, a[i]);
	}
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if (check(mid, a)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << (int) (r * 1000) << endl;
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
