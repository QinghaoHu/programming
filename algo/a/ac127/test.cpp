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
using PII = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<PII> mach(n), task(m);
	for (auto &[i, j] : mach) {
		cin >> i >> j;
	}
	for (auto &[i, j] : task) {
		cin >> i >> j;
	}
	auto cmp = [&](PII a, PII b) {
		return a.f > b.f;
	};
	sort(mach.begin(), mach.end());
	sort(task.begin(), task.end());
	ll ans = 0, cnt = 0;
	multiset<int> s;
	for (int i = m - 1, j = n - 1; i >= 0; i--) {
		while (mach[j].f >= task[i].f && j >= 0) {
			s.insert(mach[j--].s);
		}
		auto it = s.lower_bound(task[i].s);
		if (it != s.end()) {
			cnt++;
			ans += 500 * task[i].f + 2 * task[i].s;
			s.erase(it);
		}
	}
	cout << cnt << " " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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