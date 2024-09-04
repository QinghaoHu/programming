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
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int mod = 999911659;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    if (q % mod == 0) {
        cout << 0 << "\n";
        return 0;
    }
    int m = mod - 1;
    VI prime;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            prime.push_back(i);
            m /= i;
        }
    }
    if (m > 1) {
        prime.push_back(m);
    }

    arr<ll, 4> crt {};
    m = mod - 1;
    for (int i = 0; i < 4; i++) {
        int p = prime[i];
        ll x, y;
        ll d = exgcd((m / p), p, x, y);
        crt[i] = (m / p) * x;
        crt[i] = (crt[i] + m) % m;
    }

    vector<int> factor;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factor.pb(i);
            if (n / i != i) {
                factor.pb(n / i);
            }
        }
    }

    vector<ll> fac, fnv;
    auto binom = [&](int a, int b, int p) -> ll {
        if (b < 0 || b > a) {
            return 0;
        }
        return fac[a] * fnv[b] % p * fnv[a - b] % p;
    };

    auto lucas = [&](int a, int b, int p) -> ll {
        ll
         val = 1;
        while (a > 0 || b > 0) {
            val = val * binom(a % p, b % p, p) % p;
            a /= p, b /= p;
        }
        return val;
    };

    ll ans = 0;
    for (int i = 0; i < SZ(prime); i++) {
        int p = prime[i];
        fac.resize(p, 1); fnv.resize(p, 1);
        for (int j = 1; j < p; j++) {
            fac[j] = fac[j - 1] * j % p;
        }
        for (int j = 1; j < p; j++) {
            fnv[j] = powmod(fac[j], p - 2, p);
        }
        ll sum = 0;
        for (int j = 0; j < SZ(factor); j++) {
            sum = (sum + lucas(n, factor[j], p)) % p;
        }
        ans = (ans + sum * crt[i]) % (mod - 1);
    }
    cout << powmod(q, ans, mod);

    return 0;
}