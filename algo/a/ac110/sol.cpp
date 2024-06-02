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

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) 
        return a.second < b.second;
    else
        return a.first < b.first;
}

void solve() {
	int c, l;
    int ans = 0;
    cin >> c >> l;
    vector<pair<int, int> > spf(c, {0, 0});
    for (auto &i : spf) {
        cin >> i.first >> i.second;
    }
    sort(spf.begin(), spf.end(), cmp);
    vector<pair<int, int> > cover(l);
    for (auto &i : cover) {
        cin >> i.first >> i.second;
    }
    sort (cover.begin(), cover.end(), cmp);
    for (auto i : spf) {
        for (auto &j : cover) {
            if (j.first >= i.first && j.first <= i.second && j .second > 0) {
                ans++;
                j.second--;
            }
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
