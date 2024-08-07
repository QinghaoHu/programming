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
typedef long double ld; typedef pair<int, int> PII;
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

const int L = 1e6 + 10, M = 46350;

unsigned int l, r;
arr<int, L> v;
vector<int> p, ans;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto get_prime = [&](int n) -> VI {
        vector<int> prime;
        fill(all(v), 0);
        for (int i = 2; i <= n; i++) {
            if (v[i] == 0) {
                v[i] = i;
                prime.pb(i);
            }
            for (auto j : prime) {
                if (j > v[i] || j > n / i) {
                    break;
                }
                v[i * j] = j;
            }
        }
        return prime;
    };
    p = get_prime(M);
    while (cin >> l >> r) {
        solve();
    }

    return 0;
}
