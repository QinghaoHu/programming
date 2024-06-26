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

int n;

void solve() {
    unordered_map<int, int> mp;
    vector<queue<int> > q(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            mp[y] = i;
        }
    }
    string str1;
    while(cin >> str1 && str1 != "STOP") {
        if (str1 == "ENQUEUE") {
            int t;
            cin >> t;
            if (q[mp[t]].empty()) {
                q[0].push(mp[t]);
            }
            q[mp[t]].push(t);
        } else if (str1 == "DEQUEUE") {
            int x = q[0].front();
            cout << q[x].front() << endl;
            q[x].pop();
            if (!SZ(q[x])) {
                q[0].pop();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (cin >> n && n) {
    	cout << "Scenario #" << T++ << endl;
        solve();
        cout << endl;
    }

    return 0;
}
/*
* Note is here:
* */
