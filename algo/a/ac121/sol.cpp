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

const int N = 1010;

int c, n;
int g[N][N];
unordered_map<int, int> mymap;
vector<int> sit;

int get(int x1, int y1, int x2, int y2) {
    return g[x2][y2] - g[x2][y1 - 1] - g[x1 - 1][y2] + g[x1 - 1][y1 - 1];
}

bool check(int len, vector<pair<int, int> > p) {
    for (auto i : p) {
        int j = 0, k = mymap[i.f];
        int t = k;
        while(j < len) {
            j = sit[t++] - sit[k];
        }
        t--;
        if (get(mymap[i.f], mymap[i.s], mymap[i.f] + t, mymap[i.s] + t) < c) {
            continue;
        }
        return true;
    }
    return false;
}

void solve() {
    cin >> c >> n;
    vector<pair<int, int> >points(n);
    for (auto &i : points) {
        cin >> i.first >> i.second;
        sit.push_back(i.first);
        sit.push_back(i.second);
    }
    sit.push_back(0);
    //Set discrete map
    sort(sit.begin(), sit.end());
    sit.erase(unique(sit.begin(), sit.end()), sit.end());
    for (int i = 1; i < sit.size(); i++) {
        mymap[sit[i]] = i;
    }
    //Record the map
    for (auto i : points) {
        g[mymap[i.f]][mymap[i.s]]++;
    }
    auto settle  = [&](int x, int y) {
        g[x][y] = g[x - 1][y] + g[x][y - 1] - g[x - 1][y - 1];
    };
    for (int i = 1; i < 1010; i++) {
        for (int j = 1; j < 1010; j++) {
            settle(i, j);
        }
    }
    int l = 0, r = 10010;
    while(l < r) {
        int mid = l + r >> 1;
        if (check(mid, points)) {
            r = l;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
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
