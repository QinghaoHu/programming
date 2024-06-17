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

const int N = 1e6 + 10;

int a[N], s[N], len;
stack<int> r, l;

void solve() {
    char com;
    cin >> com;
    a[0] = -1e9;
    auto ins = [&] (int x) -> void {
        len++;
        r.push(x);
        s[len] = s[len - 1] + x;
        a[len] = max(a[len - 1], s[len]);
    };
    auto del = [&] () -> void {
        if (!r.empty()) {
            r.pop();
            len--;
        }
    };
    auto left = [&] () -> void {
		if (!r.empty()) {
			int t = r.top();
			r.pop();
			l.push(t);
			len --;
		}
    };
    auto right = [&] () -> void {
        if (!l.empty()) {
 			int t = l.top();
			l.pop();
			ins(t);
		}
    };
    auto ques = [&] (int k) {
        return a[k];
    };
    if (com == 'I') {
        int x;
        cin >> x;
        ins(x);
    } else if (com == 'L') {
		left();
	} else if (com == 'R') {
		right();
	} else if (com == 'D') {
		del();
	} else if (com == 'Q') {
		int x;
		cin >> x;
		cout << ques(x) << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T --) {
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
