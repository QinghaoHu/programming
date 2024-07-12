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

const int N = 1000010;

ll d[N];
int l[N], r[N];

void solve() {
    int n, k;
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> d[i];
    }
    per(i, n - 1, 1) {
        d[i] -= d[i - 1];
    }
    set<pair<ll, int> > S;
    d[0] = d[n] = 1e15;
    rep(i, 0, n + 1) {
        l[i] = i - 1, r[i] = i + 1;
        S.insert(mp(d[i], i));
    }
    ll res = 0;
    auto del = [&](int p) {
        r[l[p]] = r[p];
        l[r[p]] = l[p];
    };
    while(k--) {
        auto it = S.begin();
        ll v = it->first;
        int p = it->second, left = l[p], right = r[p];
        S.erase(it);
        S.erase(mp(d[left], left)), S.erase(mp(d[right], right));
        del(left), del(right);
        res += v;
        d[p] = d[left] + d[right] - d[p];
        S.insert(mp(d[p], p));
    }
    cout << res << endl;
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
