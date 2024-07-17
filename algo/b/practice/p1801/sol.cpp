#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 2e5 + 10;

int n, m;
int a[N], b[N];
priority_queue<int> down;
priority_queue<int, vector<int>, greater<int> > up;

void solve() {
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 1, m + 1) {
        cin >> b[i];
    }
    int j = 1;
    rep(i, 1, n + 1) {
        up.push(a[i]);
        while (up.size() && down.size() && up.top() < down.top()) {
            int t = up.top();
            up.pop();
            up.push(down.top());
            down.pop();
            down.push(t);
        }
        while(b[j] == i) {
            cout << up.top() << endl;
            down.push(up.top());
            up.pop();
            j++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    rep(i, 0, T) {
        solve();
    }

    return 0;
}
