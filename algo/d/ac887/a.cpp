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
ll powmod(ll a, ll b, ll p){ ll res = 1; for(; b; b >>= 1) { if (b & 1) { res = res * a % p; } a = a * a % p; } return res; }

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

void solve() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> fac(p + 1, 0), inv(p + 1, 0);

    fac[0] = 1;
    rep(i, 1, p) {
        fac[i] = fac[i - 1] * i % p;
    }

    inv[p - 1] = powmod(fac[p - 1], p - 2, p);
    for (ll i = p - 1; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % p;
    }

    auto binom = [&](ll a, ll b) -> ll {
        if (b < 0 || b > a) {
            return 0;
        }
        return fac[a] * inv[b] % p * inv[a - b] % p;
    };

    ll res = 1;
    while (n > 0 || m > 0) {
        res = res * binom(n % p, m % p) % p;
        n /= p; m /= p;
    }

    cerr << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}