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
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    set <pair<int, int> > myset;
    vector<int> a(n + 1, 0);

    while(m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (!myset.count({x, y})) {
            a[x + 1]--;
            a[y]++;
            myset.insert({x, y});
        }
    }
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + a[i];
        cout << h + d[i] << endl;
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
