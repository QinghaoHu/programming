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

vector<int> match;
vector<int> ran;

void dfs(int n, int m) {
    if (m == n) {
        for (int i : match) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    match.push_back(ran[m]);
    dfs(n, m + 1);
    match.pop_back();
    dfs(n, m + 1);
    
}

void solve() {
    int n;
    cin >> n;
    ran.resize(n);
    iota(ran.begin(), ran.end(), 1);
    dfs(n, 0);
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
