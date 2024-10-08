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

const int N = 50000;

int n, a, b, c, d;
VI p;
vector<PII> divd;
VI num;

void get_primes(int n) {
    VI v(n + 1, 0);
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
}

void dfs(int u, int s) {
    if (u >= SZ(divd)) {
        num.pb(s);
        return;
    }
    for (int i = 0; i <= divd[u].se; i++) {
        dfs(u + 1, s);
        s *= divd[u].fi;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    get_primes(N);
    cin >> n;
    while (n--) {
        divd.clear();
        num.clear();
        cin >> a >> b >> c >> d;
        int cd = d;
        for (int i : p) {
            int s = 0;
            if (i > cd) {
                break;
            }
            while (cd % i == 0) {
                s++;
                cd /= i;
            }
            if (s) {
                divd.eb(mp(i, s));
            }
        }
        if (cd > 1) {
            divd.eb(mp(cd, 1));
        }
        dfs(0, 1);
        int res = 0;
        for (auto i : num) {
            if (__gcd(a, i) == b && c / __gcd(c, i) * i == d) {
                res++;
            }
        }
        cout << res << " \n";
    }

    return 0;
}
