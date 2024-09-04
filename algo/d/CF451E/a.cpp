#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (long long i = a; i < n; i++)
#define per(i, a, n) for (long long i = a; i >= n; i--)
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
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> ab;
    rep(i, 0, n) {
        ll x;
        cin >> x;
        ab.pb(x);
    }

    auto C = [&](ll a, ll b) -> ll {
        if (b < 0 || b > a) {
            return 0;
        }
        ll up = 1, down = 1;
        per(i,a, a - b + 1) {
            up = i % mod * up % mod;
        }
        rep(i, 1, b + 1) {
            down = i % mod * down % mod;
        }
        down = powmod(down, mod - 2, mod);
        return up % mod * down % mod;
    };

    ll res = 0;
    for (ll i = 0; i < 1 << n; i++) {
        int sign = 1;
        ll a = n + m - 1, b = n - 1;
        rep(j, 0, n) {
            if (i >> j & 1) {
                sign *= -1;
                a -= ab[j] + 1;
            }
        }
        res = (res + C(a, b) * sign) % mod;
    }

    cout << (res % mod + mod) % mod << "\n";

    return 0;
}