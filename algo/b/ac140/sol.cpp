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
const double eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int base = 131;

void solve() {
    string s;
    cin >> s;
    int len = SZ(s);
    vector<ull> a(len + 1, 0), p(len + 1, 1);
    vector<int> sa(len);
    iota(all(sa), 1);
    rep(i, 1, len + 1) {
        a[i] = a[i - 1] * base + s[i - 1] - 'a' + 1;
        p[i] = p[i - 1] * base;
    }
    auto getHash = [&](int l, int r) -> ull {
        return a[r] - a[l - 1] * p[r - l + 1];
    };
    auto get = [&](int a, int b) {
        int l = 0, r = min(len - a + 1, len - b + 1);
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (getHash(a, a + mid - 1) == getHash(b, b + mid - 1)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    };
    auto cmp = [&](int a, int b) -> bool {
        int l = get(a, b);
        int av = a + l > len ? -INF: s[a + l - 1];
        int bv = b + l > len ? -INF: s[b + l - 1];
        return av < bv;
    };
    sort(all(sa), cmp);
    for (int i : sa) cout << i - 1 << " ";
    cout << endl;
    rep(i, 1, len + 1) {
        if (i == 1) {
            cout << 0 << " ";
        } else {
            cout << get(sa[i - 1], sa[i - 2]) << " ";
        }
    }
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

