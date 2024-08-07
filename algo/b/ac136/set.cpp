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
typedef pair<double, double> PDD;
const ll mod = 1e9 + 7;
const db eps = 1e-9;
const int INF = 0x3f3f3f3f;

void solve() {
    set<PII> s;
    int n, a;
    cin >> n >> a;
    s.insert(mp(a, 1));
    for (int i = 2; i <= n; i++) {
        cin >> a;
        s.insert(mp(a, i));
        auto t = s.find(mp(a, i));
        PII ans;
        ans.first = 1e9;
        if (++t != s.end()) {
            ans = mp(t->f - a, t->s);
        }
        t--;
        if (t-- != s.begin() && ans.first >= a - t->f) {
            ans = mp(a - t->f, t->s);
        }
        cout << ans.f << " " << ans.s << endl;
    }
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
