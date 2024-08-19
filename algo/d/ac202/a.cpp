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
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef double db;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

ll n, tt = 0;

ll get_phi(ll s) {
    ll res = s;
    for (int i = 2; i * i <= s; i++) {
        if (s % i == 0) {
            res = res / i * (i - 1);
            while (s % i == 0) {
                s /= i;
            }
        }
    }
    if (s > 1) {
        res = res / s * (s - 1);
    }
    return res;
}

// 64-bit modular multiplication function
ll mul(ll x, ll y, ll c) {
    x %= c, y %= c;
    long long d = (long double)x * y / c;
    ll res = x * y - d * c;
    if (res < 0) res += c;
    else if (res >= c) res -= c;
    return res;
}

ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a, c);
        }
        b >>= 1;
        a = mul(a, a, c);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n, n) {
        cout << "Case " << ++tt << ": ";
        ll c = 9 * n / gcd(n, 8);  // Correct calculation for c
        if (gcd(c, 10) == 1) {  // Check if 10 and c are coprime
            ll s = get_phi(c);
            vector<ll> prime;
            for (int i = 1; i * i <= s; i++) {
                if (s % i == 0) {
                    prime.pb(i);
                    if (i != s / i) {
                        prime.pb(s / i);
                    }
                }
            }
            sort(all(prime));
            ll ans = 0;
            for (auto i : prime) {
                if (qmi(10, i, c) == 1) {
                    ans = i;
                    break;
                }
            }
            cout << ans << " \n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
