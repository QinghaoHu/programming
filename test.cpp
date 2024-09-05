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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

struct Exlucas {
    ll M, phipe;
    ll a, b, m;
    vector<pair<int, int> > prime;
    vector<ll> fac, pr;

    ll cnts = 0, cntp = 0;

    ll powmod(ll a, ll b, ll p) {
        ll res = 1;
        for (; b; b >>= 1) {
            if (b & 1) {
                res = res * a % p;
            }
            a = a * a % p;
        }
        return res;
    }

    ll exgcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }

    ll calc(ll a, int p, int pe, int w) {
        ll val = 1;
        while (a) {
            cntp += (a / p) * w;
            cnts += (a / pe) * w;
            val = val * fac[a % pe] % pe;
            a /= p;
        }
        return val;
    }

    ll binom(ll a, ll b, int p, int pe) {
        cntp = 0, cnts = 0;
        ll f1 = calc(a, p, pe, 1);
        ll f2 = calc(b, p, pe, -1);
        ll f3 = calc(a - b, p, pe, -1);
        ll v1 = f1 * powmod(f2 * f3 % pe, phipe - 1, pe) % pe;
        ll v2 = powmod(p, cntp, pe);
        ll v3 = powmod(fac[pe], cnts, pe);
        return v1 * v2 % pe * v3 % pe;
    }

    ll solve(ll x, ll y, ll ps) {
        a = x, b = y, m = ps;
        M = m;

        for (int i = 2; i * i <= m; i++) {
            if (m % i == 0) {
                int p = i, pe = 1;
                while (m % i == 0) {
                    m /= i;
                    pe *= i;
                }
                prime.push_back({p, pe});  // Fix here to use pe instead of ps
            }
        }
        if (m > 1) {
            prime.push_back({m, m});
        }

        pr.resize((int)prime.size(), 0);
        for (int i = 0; i < (int)prime.size(); i++) {
            ll pe = prime[i].second;
            ll x, y;
            ll d = exgcd((M / pe), pe, x, y);
            pr[i] = x * (M / pe);
        }

        ll ans = 0;
        for (int i = 0; i < (int)prime.size(); i++) {
            int p = prime[i].first, pe = prime[i].second;
            fac.resize(pe + 1, 0);
            fac[0] = 1; // Initialize fac[0] to 1
            for (int j = 1; j <= pe; j++) {
                if (j % p == 0) {
                    fac[j] = fac[j - 1];
                } else {
                    fac[j] = fac[j - 1] * j % pe;
                }
            }
            phipe = pe / p * (p - 1);
            ans = (ans + binom(a, b, p, pe) * pr[i]) % M;
        }
        return (ans % M + M) % M;
    }
};

int main() {
    int a, b, p;
    scanf("%d%d%d", &a, &b, &p);
    Exlucas z;  // No constructor arguments are provided
    cout << z.solve(a, b, p) << "\n";

    return 0;
}