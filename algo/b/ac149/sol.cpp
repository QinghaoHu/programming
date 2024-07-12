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
typedef pair<ll, int> PLI;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<PLI, vector<PLI>, greater<PLI> > heap;
    rep(i, 0, n) {
        ll x;
        cin >> x;
        heap.push(mp(x, 0));
    }
    while((n - 1) % (k - 1)) {
        heap.push(mp(0, 0));
        n++;
    }
    ll res = 0;
    int depth = 0;
    while(heap.size() > 1) {
        ll sum = 0;
        rep(i, 0, k) {
            auto s = heap.top();
            sum += s.fi;
            depth = max(depth, s.se);
            heap.pop();
        }
        res += sum;
        heap.push(mp(sum, depth + 1));
    }
    cout << res << endl;
    cout << heap.top().se << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    
    rep(t, 0, T) {
        solve();
    }

    return 0;
}
