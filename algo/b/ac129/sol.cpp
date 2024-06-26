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

int n, cnt;
vector<int> s;
stack<int> a;
int num = 1;

void dfs() {
    if (s.size() == n) {
        for (int i : s) {
            cout << i;
        }
        cout << endl;
        cnt++;
        if (cnt == 20) 
            exit(0);
    }
    if (!a.empty()) {
        s.push_back(a.top());
        a.pop();
        dfs();
        a.push(s.back());
        s.pop_back();
    }
    if (num <= n) {
        a.push(num++);
        dfs();
        a.pop();
        num--;
    }
}

void solve() {
    cin >> n;
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
