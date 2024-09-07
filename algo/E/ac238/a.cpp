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

struct DSU {
    VI _f, _depth, _size;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        _f.resize(n + 1, 0);
        iota(_f.begin(), _f.end(), 0);
        _depth.assign(n + 1, 0);
        _size.assign(n + 1, 1);
    }

    int find(int x) {
        if (x != _f[x]) {
            int t = find(_f[x]);
            _depth[x] += _depth[_f[x]];
            _f[x] = t;
        }
        return _f[x];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    bool merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) {
            return false;
        }
        _depth[x] = _size[y];
        _size[y] += _size[x];
        _f[x] = y;
        return true;
    }
};

const int N = 3e4 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _;
    cin >> _;

    DSU d(N);

    rep(tt, 0, _) {
        char s;
        int a, b;
        cin >> s >> a >> b;

        if (s == 'M') {
            d.merge(a, b);
        } else {
            if (!d.same(a, b)) {
                cout << -1 << "\n";
            } else {
                cout << max(abs(d._depth[a] - d._depth[b]) - 1, 0) << " \n";
            }
        }
    }

    return 0;
}