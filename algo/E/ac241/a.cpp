#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
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

int n;
vector<int> y;
vector<ll> c, great, les;

ll query(int x) {
    ll s = 0;
    for (int i = x; i; i -= (i & -i)) {
        s += c[i];
    }
    return s;
}

void modify(int x, ll s) {
    for (int i = x; i <= n; i += (i & -i)) {
        c[i] += s;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    y.assign(n + 1, 0), c.assign(n + 1, 0);
    great.assign(n + 1, 0), les.assign(n + 1, 0);

    rep(i, 1, n + 1) {
        cin >> y[i];
    }

    per(i, n, 1) {
        great[i] = query(n) - query(y[i]);
        les[i] = query(y[i] - 1);
        modify(y[i], 1);
    }

    c.assign(n + 1, 0);

    ll res1 = 0, res2 = 0;
    rep(i, 1, n + 1) {
        res1 += great[i] * (query(n) - query(y[i]));
        res2 += les[i] * query(y[i] - 1);
        modify(y[i], 1);
    }

    cout << res1 << " " << res2 << "\n";


    return 0;
}