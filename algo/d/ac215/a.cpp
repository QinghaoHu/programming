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

const int N = 5e4 + 10;
VI mobius(N, 0), sum(N, 0), st(N, 0);
VI prime;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, d, _;
    cin >> _;

    mobius[1] = 1;
    rep(i, 2, N) {
        if (!st[i]) {
            st[i] = 1;
            mobius[i] = -1;
            prime.pb(i);
        }
        for (int j = 0; j < SZ(prime) && prime[j] * i <= N; j++) {
            int t = prime[j] * i;
            st[t] = 1;
            if (i % prime[j] == 0) {
                mobius[t] = 0;
                break;
            } else {
                mobius[t] = mobius[i] * -1;
            }
        }
    }

    rep(i, 1, N) {
        sum[i] = sum[i - 1] + mobius[i];
    }

    rep(i, 0, _) {
        cin >> a >> b >> d;
        a /= d, b /= d;
        int n = min(a, b);
        ll ans = 0;
        for (int l = 1, r; l <= n; l++) {
            r = min(n, min(a / (a / l), b / (b /  l)));
            ans += (sum[r] - sum[l - 1]) * (ll)(a / l) * (b / l);
            l = r;
        }
        cout << ans << "\n";
    }

    return 0;
}