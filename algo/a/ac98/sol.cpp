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
using PII = pair<ll, ll>;

PII get(ll n, ll a) {
    if (n == 0) return {0, 0};
    ll block = 1ll << n * 2 - 2, len = 1ll << n - 1;
    auto p = get(n - 1, a % block);
    int z = a / block;
    ll x = p.first, y = p.second;
    if (z == 0) return {y, x};
    if (z == 1) return {x, y + len};
    if (z == 2) return {x + len, y + len};
    return {len * 2 - 1 - y, len -1 - x};
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    auto pa = get(n, a - 1);
    auto pb = get(n, b - 1);
    double dx = pa.first - pb.first;
    double dy = pa.second - pb.second;
    cout << sqrt(dx * dx + dy * dy) * 10 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    cin >> T;

    while(T --) {
        cout << fixed << setprecision(0);
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
