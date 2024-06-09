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

const int N = 2 * 1e5 + 10;
const double INF = 1e10;
const double eps = 1e-12;

struct Point {
    double x, y;
    bool type;
    bool operator < (const Point &w) const {
        return x < w.x;
    } 
} points[N], tmp[N];

double dist (Point A, Point B) {
    if (A.type == B.type) return INF;
    double dx = A.x - B.x, dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

double dfs(int l, int r) {
    if (l >= r) return INF;
    int mid = l + r >> 1;
    int midx = points[mid].x;
    double res = min(dfs(l, mid), dfs(mid + 1, r));
    {
        int cnt = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (points[i].y < points[j].y) {
                tmp[cnt++] = points[i++];
            } else {
                tmp[cnt++] = points[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = points[i++];
        }
        while (j <= r) {
            tmp[cnt++] = points[j++];
        }
        for (int i = 0, j = l; i < cnt; i++, j++) {
            points[j] = tmp[i];
        }
    }
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (points[i].x <= midx + res && points[i].x >= midx - res) {
            tmp[cnt++] = points[i];
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = i - 1; j >= 0 && tmp[i].y - tmp[j].y < res; j--) {
            res = min(res, dist(tmp[i], tmp[j]));
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].type = 0;
    }
    for (int i = n; i < 2 * n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].type = 1;
    }
    random_shuffle(points, points + 2 * n);
    sort (points, points + 2 * n);
    cout << fixed << setprecision(3) << dfs(0, 2 * n - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    cin >> T;

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
