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

const int N = 1005;

int n, r;
int t = 0, res = 0;
vector<int> g[N];
vector<int> weight(N, 0);
vector<pair<int, int>  > cod(N);
priority_queue<pair<float, int>, vector<pair<float, int> > , less<pair<float, int> > > sq;

pair<int, int> build(int n) {
    int sum = weight[n - 1]; int cnt = 1;
    for (auto i : g[n]) {
        auto p = build(i);
        sum += p.f, cnt += p.s;
    }
    return cod[n] = {sum, cnt};
}

void print(int n) {
    t++;
    res += t * weight[n - 1];
    cout << n << endl;
    if (n != r)
        sq.pop();
    for (int i = 0; i < g[n].size(); i++) {
        sq.push({(float)cod[g[n][i]].f / cod[g[n][i]].s, g[n][i]});
    }
}

void solve() {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    build(r);
    print(r);
    while(!sq.empty()) {
        print(sq.top().s);
    }
    cout << res << endl;
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
