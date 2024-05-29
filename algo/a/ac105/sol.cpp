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

ll work(int n, vector<int> s, int t) {
    if (t % n != 0) {
        return -1;
    }
    vector<int> c(n, 0);
    int avg = t / n;
    c[0] = s[0];
    for (int i = 1; i < n; i++) {
        c[i] = c[i - 1] + s[i] - avg;
    }
    sort(c.begin(), c.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(c[i] - c[n / 2]);
    }
    return res;
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> row(m, 0), col(n, 0);
    int k = t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        col[x]++, row[y]++;
    }
    t = k;
    ll r = work(m, row, t);
    ll l = work(n, col, t);
    if (r == -1 && l == -1) {
        cout << "impossible" << endl;
    } else if (r != -1 && l != -1) {
        cout << "both " << r + l << endl;
    }  else if (r != -1) {
        cout << "column " << r << endl;
    } else {
        cout << "row " << l << endl;
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
