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

struct points {
    int s, e, d;
};

ll get_sum(int x, vector<points> a) {
    int ans = 0;
    for (auto p : a) {
        if (x >= p.s) 
            ans += (min(p.e, x) - p.s) / p.d + 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<points> p(n);
    int l = 0, r = 0;
    for (auto &i : p) {
        cin >> i.s >> i.e >> i.d;
        r = max(r, i.e);
    }
    while(l < r) {
        int mid = (ll)l + r >> 1;
        if (get_sum(mid, p) & 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int ans = get_sum(l, p) - get_sum(l - 1, p);
    if (ans % 2 == 0) 
        cout << "There's no weakness." << endl;
    else 
        cout << r << " " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    cin >> T;

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
