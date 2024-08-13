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
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1e6 + 10;

int n;
int phi[N];
VI prime;

void primes(int n) {
    VI v(n + 1, 0);
    rep(i, 2, n + 1) {
        if (!v[i]) {
            v[i] = i;
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (auto j : prime) {
            if (j > v[i] || j > n / i) {
                break;
            }
            v[i * j] = j;
            phi[i * j] = (i % j == 0 ? phi[i] * j : phi[i] * (j - 1));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    phi[1] = 1;
    primes(n);
    ll res = 0;
    rep(i, 1, n + 1) {
        res += (ll)phi[i];
    }
    cout << res << " \n";

    return 0;
}
