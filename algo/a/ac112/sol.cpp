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
#define f first
#define s second

using namespace std;
using ll = long long;

const double eps = 1e-8;

void solve() {
    int n; double d;
    cin >> n >> d;
    vector<pair<double, double> > pos(n);
    for (auto &s : pos) {
        double x, y;
        cin >> x >> y;
        double len = sqrt(d * d - y * y);
        if (y > d) {
            cout << -1 << endl;
            exit(0);
        }
        s = {x + len, x - len};
    }
    sort(pos.begin(), pos.end());
    int ans = 0; double last = -1500;

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
