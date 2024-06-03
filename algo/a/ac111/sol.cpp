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

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int > > a(n);
    int cnt = 0;
    for (auto &i : a) {
        cin >> i.f.f >> i.f.s;
        i.s = cnt++;
    }
    vector<int> pos(n, 0);
    sort (a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > myq;
    for (auto s : a) {
        if (myq.empty() || myq.top().f >= s.f.f) {
            pos[s.s] = myq.size() + 1;
            myq.push({s.f.s, myq.size() + 1});
        } else {
            pos[s.s] = myq.top().s;
            myq.pop();
            myq.push({s.f.s, pos[s.s]});
        }
    }
    cout << myq.size() << endl;
    for (int i : pos) {
        cout << i << endl;
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
