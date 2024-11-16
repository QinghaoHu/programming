#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define SZ(x) ((int)x.size())

typedef long long ll;

const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    const int N = 2e4 + 10;

    ll f[N] {}, g[N] {}, q[N] {};
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);
        for (int r = 0; r < v; r++) {
            int hh = 1, tt = 0;
            for (int k = r; k <= m; k += v) {
                if (hh <= tt && q[hh] < k - s * v) {
                    hh++;
                }
                if (hh <= tt) f[k] = max(g[k], g[q[hh]] + (k - q[hh]) / v * w);
                while (hh <= tt && g[k] >= g[q[tt]] + (k - q[tt]) / v * w) {
                    --tt;
                } 
                q[++tt] = k;
            }
        }
    }
    cout << f[m] << '\n';
    return 0;
}
