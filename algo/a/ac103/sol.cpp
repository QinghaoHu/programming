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
	int n, m;
	cin >> n;
	unordered_map<int, int> lang, subt;
	while(n--) {
		int a;
		cin >> a;
		if (lang.find(a) == lang.end()) {
			lang[a] = 1;
		} else {
			lang
			if (s > mlike) {
				pos = i;
				mlike = s;
			}
		}
	}
	cout << pos + 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while(T--) {
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
