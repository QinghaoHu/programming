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
    int p;
    cin >> p;
    while(p--) {
        int x, m;
        cin >> x >> m;
        priority_queue<int, vector<int>, less<int> > maxq;
        priority_queue<int, vector<int>, greater<int> > minq;
        cout << x << " " << m / 2 + 1 << endl;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            maxq.push(t);
            if (i % 2 == 0) {
                while((int)maxq.size() > i / 2 + 1) {
                    minq.push(maxq.top());
                    maxq.pop();
                }
                if (minq.size() >= 1) {
                    while(maxq.top() > minq.top()) {
                        maxq.push(minq.top());
                        minq.push(maxq.top());
                        minq.pop(), maxq.pop();
                    }
                }
                cout << maxq.top() << " ";
                cnt++;
                if (cnt % 10 == 0 && i != m - 1) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
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
