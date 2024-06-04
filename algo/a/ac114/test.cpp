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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first * a.second < b.first * b.second;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int> > hands(n + 1);
	for (auto &i : hands) {
		cin >> i.first >> i.second;
	}
	sort(hands.begin() + 1, hands.end(), cmp);
	ll res = 0;
	ll cnt = hands[0].first;
	for (int i = 1; i <= n; i++) {
		res = max(res, cnt / hands[i].second);
		cnt *= hands[i].first;
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