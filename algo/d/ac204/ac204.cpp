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
#define arr array
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

struct CRT {
    vector<ll> as, bs;
    ll a = 0, b = 1;
    int sz = 0;

    CRT(int n) : sz(n), as(n), bs(n) {}

    ll exgcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }

    bool merge(ll &a, ll &b, ll c, ll d) {
        if (b == 0) {  // handle the case when 'b' is 0
            a = c;
            b = d;
            return true;
        }
        ll x, y;
        ll g = exgcd(b, d, x, y);
        if ((c - a) % g != 0) return false;
        d /= g;
        ll t0 = ((c - a) / g % d * x % d + d) % d;
        a += b * t0;
        b *= d;
        return true;
    }

    bool solve() {
        for (int i = 0; i < sz; i++) {
            if (!merge(a, b, as[i], bs[i])) {
                a = b = -1;
                return false;
            }
        }
        return true;
    }

    ll ans() const {
        return (a % b + b) % b;  // make sure the answer is non-negative
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    CRT z(n);
    rep(i, 0, n) {
        cin >> z.bs[i] >> z.as[i];
    }
    z.solve();
    cout << z.ans() << " \n";

    return 0;
}