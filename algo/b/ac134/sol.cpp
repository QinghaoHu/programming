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
	int n;
    cin >> n;
    vector<int> D(n + 1, 0);
    unordered_map<int, PII> pm;
    //Left is the Minimum, right is the maximum
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
    }
    for (int i = 1; i <= n; i++) {
        if (pm.find(D[i]) == pm.end()) {
            pm[D[i]] = mp(i, i);
        } else {
            pm[D[i]].s = max(pm[D[i]].s, i);
        }
    }
    D.erase(D.begin());
    sort(all(D));
    D.erase(unique(all(D)), D.end());
    bool isA = false, isD = true;
    vector<int> a;
    for (int i = 1; i < SZ(D); i++) {
        if (isD) {
            if (pm[D[i - 1]].f < pm[D[i]].s || pm[D[i - 1]].f < pm[D[i]].f) {
                isD = false, isA = true;
                a.pb(1);
            }
        } else {
            if (pm[D[i - 1]].s > pm[D[i]].f || pm[D[i - 1]].s > pm[D[i]].s) {
                isD = true, isA = false;
                a.pb(-1);
            }
        }
    }
    if (SZ(a) == 0) {
        cout << 1 << endl;
    } else {
         cout << SZ(a) / 2 + 1 << endl;
    }
    for (int i : a) {
        cout << i << endl;
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
