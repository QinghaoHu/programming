#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
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
vector<int> sit;
unordered_map<int, int> mymap;
vector<pair<int, int> > points;
int g[N][N];

bool get(int len) {
   for (int x1 = 0, x2 = 1; x2 < sit.size(); x2++) {
        while(sit[x2] - sit[x1 + 1] + 1 > len) x1++;
        for (int y1 = 0, y2 = 1; y2 < sit.size(); y2++) {
            while(sit[y2] - sit[y1 + 1] + 1 > len) y1++;
            if (g[x2][y2] - g[x1][y2] - g[x2][y1] + g[x1][y1] >= c) {
                return true;
            }
        }
   }
   return false;
}

void solve() {
	cin >> c >> n;
    points.resize(n);
	for (auto &i : points) {
		cin >> i.first >> i.second;
		sit.push_back(i.first), sit.push_back(i.second);
	}
    sit.push_back(0);
	sort(sit.begin(), sit.end());
    sit.erase(unique(sit.begin(), sit.end()), sit.end());
    for (int i = 1; i < (int)sit.size(); i++) {
        mymap[sit[i]] = i;
    }
    for (auto i : points) {
        g[mymap[i.f]][mymap[i.s]]++;
    }
    for (int i = 1; i < sit.size(); i++) {
        for (int j = 1; j < sit.size(); j++) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    int l = 1, r = 10000;
    while(l < r) {
        int mid = l + r >> 1;
        if (get(mid)) {
            r = mid;
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