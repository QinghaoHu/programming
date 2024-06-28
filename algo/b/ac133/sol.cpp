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
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;
typedef pair<ll, ll> PLL;
typedef pair<double, double> PDD;
const ll mod = 1e9 + 7;
const db eps = 1e-9;
const int INF = 0x3f3f3f3f;

void solve() {
    ll n, m, q, u, v, d;
    cin >> n >> m >> q >> u >> v >> d;
    double p = (double)u / v;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    auto cmp = [&](ll a, ll b) -> bool {
        return a > b;
    };
    sort(all(a), cmp);
    vector<queue<ll> > que(3);
    for (auto i : a) {
        que[0].push(i);
    }
    auto getMax = [&]() -> ll {
        ll x = -INF, pos = -1;
        for (int i = 0; i < 3; i++) {
            if (!que[i].empty()) {
                if (que[i].front() > x) {
                    x = que[i].front();
                    pos = i;
                }
            } 
        }
        que[pos].pop();
        return x;
    };
    ll dt = 0;
    for (int i = 1; i <= m; i++) {
        int t = getMax();
        t += dt;
        if (i % d == 0) {
            cout << t << " ";
        }
        ll bp = (ll) t * p, cp = t - bp;
        bp -= (q + dt), cp -= (q + dt);
        dt += q;
        que[1].push(bp); que[2].push(cp);
    }
    cout << endl;
    int cnt = SZ(que[0]) + SZ(que[1]) + SZ(que[2]);
    for (int i = 1; i <= cnt; i++) {
        ll td = getMax();
        if (i % d == 0) {
            cout << td + dt << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (T --) {
        solve();
    }

    return 0;
}
/*
* Note is here:
* */
