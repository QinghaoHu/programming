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
#define f first
#define s second

using namespace std;
using ll = long long;

const int INF = -1e9;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return max(-1 * a.s, a.f - b.s) < max (-1 * b.s, b.f - a.s);
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for (auto &i : a) {
		cin >> i.f >> i.s;
	}
	sort(a.begin(), a.end(), cmp);
	int sum = 0, ans = INF;
	for (auto i : a) {
		ans = max(ans, sum - i.s);
		sum += i.f;
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