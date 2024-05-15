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

int qmi(int a, int b, int m) {
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = (ll)(ans * a) % m;
        }
        a = (ll)(a * a) % m;
    }
    return ans;
}

void solve() {
    int m, n;
    cin >> m >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++ i) {
        int a, b;
        cin >> a >> b;
        ans = (ll)(ans + qmi(a, b, m)) % m;
        cout << "->" << qmi(a, b, 1000) << endl;
    }
    cout << ans % m<< endl;
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

