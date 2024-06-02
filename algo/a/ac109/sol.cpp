#pragma GCC optimize (2)
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

int n, m;
ll t, value = 0;

ll sq (ll x) {
    return x * x;
}

vector<ll> check(vector<ll> a, vector<ll> b) {
    int i = 0, j = 0;
    vector<ll> c;
    sort(b.begin(), b.end());
    while(i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j++]);
        }
    }
    while(i != a.size()) {
        c.push_back(a[i++]);
    }
    while (j != b.size()) {
        c.push_back(b[j++]);
    }
    value = 0;
    for (int i = 0, j = c.size() - 1; i < m; i++, j--) {
        if (i >= j) break;
        value += sq(c[j] - c[i]);
    }
    return c;
}

void solve() {
    cin >> n >> m >> t;
    vector<int> w(n, 0);
    for (int &i : w) {
        cin >> i;
    }
    int len = 1;
    int start = 0;
    int ans = 1;
    while(start < n) {
        len = 1;
        vector<ll> general;
        int end = start;
        while(len) {
            vector<ll> local;
            if (end + len <= n) {
                for (int i = end; i < end + len; i++) {
                    local.push_back(w[i]);
                }
                auto abc = check(general, local);
                if (value <= t) {
                    end += len; len <<= 1;
                    if (end >= n) break;
                    general = abc;
                } else {
                    len >>= 1;
                }
            } else {
                len >>= 1;
            }
            if (len == 0) break;
        }
        start = end;
        ans ++;
    }
    cout << ans << endl;
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
