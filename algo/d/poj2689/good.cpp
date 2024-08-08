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

const int N = 1e5, M = 1e6 + 10;

int l, r;
arr<int, M> v{};
VI p, ans;

int main() {
    auto primes = [&](int n) -> void {
        fill(all(v), 0);
        for (int i = 2; i <= n; i++) {
            if (!v[i]) {
                v[i] = i;
                p.pb(i);
            }
            for (auto j : p) {
                if (j > v[i] || j > n / i) {
                    break;
                }
                v[i * j] = j;
            }
        }
    };
    primes(N);
    while (cin >> l >> r) {
        ans.clear();
        fill(all(v), 1);
        if (l == 1) {
            v[0] = 0;
        }
        for (auto primes : p) {
            for (int i = (l - 1) / primes + 1; i <= r / primes; i++) {
                if (i > 1) {
                    v[i * primes - l] = 0;
                }
            }
        }
        for (ll i = l; i <= r; i++) {
            if (v[i - l]) {
                ans.pb(i);
            }
        }
        int minv = INF, maxv = 0, x1, y1, x2, y2;
        for (int i = 0; i < (int)ans.size() - 1; i++) {
            int num = ans[i + 1] - ans[i];
            if (num < minv) {
                minv = num;
                x1 = ans[i], y1 = ans[i + 1];
            } 
            if (num > maxv) {
                maxv = num;
                x2 = ans[i], y2 = ans[i + 1];
            }
        }
        if (!maxv) {
            cout << "There are no adjacent primes.\n";
        } else {
            printf("%d,%d are closest, %d,%d are most distant.\n", x1, y1, x2, y2);
        }
    }

    return 0;
}
