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

int calc(int bit, int now, vector<pair<string, int> > door) {
    for (int i = 0; i < door.size(); ++ i) {
        int x = door[i].second >> bit & 1;
        if (door[i].first == "AND") now &= x;
        else if (door[i].first == "XOR") now ^= x;
        else now |= x;

    }
    return now;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int> > door(n);
    for (int i = 0; i < n; ++ i) {
        string str; 
        int x;
        cin >> str >> x;
        door[i] = {str, x};
    }
    int val = 0, ans = 0;
    for (int bit = 29; bit >= 0; --bit) {
        int res0 = calc(bit, 0, door);
        int res1 = calc(bit, 1, door);
        if (val + (1 << bit) <= m && res0 < res1) {
            val += (1 << bit);
            ans += res1 << bit;
        }   else {
            ans += res0 << bit;
        }
    }
    cout << ans << endl;

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
