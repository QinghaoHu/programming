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
	int n;
	cin >> n;
	int total = 0;
	vector<int> a(n, 0);
	for (int &i : a) {
		cin >> i;
		total += i;
	}
	int avg = total / n;
	for (int &i : a) {
		i -= avg;
	}
	vector<int> s(n, 0);
	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	sort(s.begin(), s.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs((s[i] - s[n / 2]));
	}
	cout << ans << endl;
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
