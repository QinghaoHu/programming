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

VI d, fa;

int find(int x) {
    if (x != fa[x]) {
        int root = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = root;
    }
    return fa[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int res = 0, n, k;
    cin >> n >> k;
    d.assign(n + 1, 0);
    fa.assign(n + 1, 0);
    iota(all(fa), 0);
    rep(i, 0, k) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n || y > n) {
            res++;
            continue;
        }
        int p = find(x), q = find(y);
        if (t == 1) {
            if (p == q && (d[x] - d[y]) % 3) {
                res++;
                continue;
            } else if (p != q) {
                fa[p] = q;
                d[p] = d[y] - d[x];
            }
        } else {
            if (x == y) {
                res++;
                continue;
            }
            if (p == q && (d[x] - d[y] - 1) % 3) {
                res++;
                continue;
            } else if (p != q) {
                fa[p] = q;
                d[p] = d[y] + 1 - d[x];
            }
        }
    }

    cout << res << "\n";

    return 0;
}
