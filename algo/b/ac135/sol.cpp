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
const int INF = INT_MIN;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0), s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    deque<int> que;
    que.push_back(0);
    int res = -INF;
    for (int i = 1; i <= n; i++) {
        if (que.front() < i - m) {
            que.pop_front();
        }
        res = max(res, s[i] - s[que.front()]);
        while(SZ(que) && s[que.back()] >= s[i]) {
            que.pop_back();
        }
        que.push_back(i);
    }
    cout << res << endl;
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
