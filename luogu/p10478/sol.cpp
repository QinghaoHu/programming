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

const int N = 1e5 + 10;

int n, m;
ll a[N], l[N], r[N];
bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;

void solve() {
    cin >> n >> m;
    int k = 1;
    rep(i, 1, n + 1) {
        int x;
        cin >> x;
        if (a[k] * x < 0) {
            a[++k] = x;
        } else {
            a[k] += x;
        }
    }
    n = k;
    ll cnt = 0, res = 0;
    rep(i, 1, n + 1) {
        if (a[i] > 0) {
            cnt++;
            res += a[i];
        }
        l[i] = i - 1, r[i] = i + 1;
        heap.push(mp(abs(a[i]), i));
    }
    auto remove = [&](int p) -> void {
        l[r[p]] = l[p];
        r[l[p]] = r[p];
        st[p] = true;
    };
    while (cnt > m) {
        while (st[heap.top().se]) {
            heap.pop();
        }
        auto t = heap.top();
        heap.pop();
        int v = t.fi, p = t.se;
        if ((l[p] != 0 && r[p] != n + 1) || a[p] > 0) {
            cnt--;
            res -= v;
            int left = l[p], right = r[p];
            a[p] += a[left] + a[right];
            heap.push(mp(abs(a[p]), p));
            remove(left);
            remove(right);
        }
    }
    cout << res << endl;
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
