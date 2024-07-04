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
const ll mod = pow(2, 64);
const double eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1e6 + 10;
const int base = 131;

ull p[N];
string s;

int solve() {
    int ans = 0, len = SZ(s);
    vector<ull> a(len + 1, 0), b(len + 2, 0);
    rep(i, 1, len + 1) {
        a[i] = a[i - 1] * base + s[i - 1] - 'a' + 1;
        a[i] %= mod;
    }
    b[len + 1] = 0;
    per(i, len, 1) {
        b[i] = b[i + 1] * base + s[i - 1] - 'a' + 1;
        b[i] %= mod;
    }
    auto H1 = [&] (int l, int r) {
        return (ll)(a[r] - a[l - 1] * p[r - l + 1]) % mod;
    };
    auto H2 = [&] (int l, int r) {
        return (ll)(b[l] - b[r + 1] * p[r - l + 1]) % mod;
    };
    rep(i, 1, len) {
        int l = 0, r = min(i - 1, len - i);
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (H1(i - mid, i - 1) == H2(i + 1, i + mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(2 * l + 1, ans);
        l = 0, r = min(i - 1, len - i + 1);
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (H1(i - mid, i - 1) == H2(i, i + mid - 1)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(2 * l, ans);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> s;

    p[0] = 1;
    rep(i, 1, N) {
        p[i] = p[i - 1] * base;
    }

    while(s != "END") {
        cout << "Case " << T++ << ": " << solve() << endl;
        cin >> s;
    }

    return 0;
}
