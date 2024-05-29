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
    vector<ll> a(n, 0);
    for (auto &i : a) {
        cin >> i;
    }
    for (int i = a.size() - 1; i > 0; i--) {
        a[i] = a[i] - a[i - 1];
    }
    ll pos = 0, neg = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < 0) 
            neg += abs(a[i]);
        else if (a[i] > 0) 
            pos += abs(a[i]);
    }
    cout << min (pos, neg) + abs(pos - neg) << endl;
    cout << abs(pos - neg) + 1 << endl;
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
