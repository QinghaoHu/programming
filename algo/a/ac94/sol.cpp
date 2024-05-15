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

int n;
vector<int> ran;
vector<bool> isV;

void dfs() {
    if (ran.size() == n) {
        for (int i : ran) {
            cout << i << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++ i) {
        if (!isV[i]) {
            ran.push_back(i);
            isV[i] = true;
            dfs();
            ran.pop_back();
            isV[i] = false;
        }
    }
}

void solve() {
	cin >> n;
	isV.resize(n + 1, false);
    dfs();
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
