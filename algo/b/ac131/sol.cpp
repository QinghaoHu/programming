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
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st, w;
    ll ans = 0;
    int sum;
    for (int i = 0; i < n + 1; i++) {
        sum = 0;
        while(!st.empty() && a[i] <= st.top()) {
            sum += w.top(), ans = max(ans, (ll)st.top() * sum);
            st.pop(); w.pop();
        }
        st.push(a[i]), w.push(sum + 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (cin >> n && n) {
        solve();
    }

    return 0;
}
/*
* Note is here:
* */
