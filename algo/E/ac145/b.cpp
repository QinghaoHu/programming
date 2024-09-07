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

const int N = 1e5 + 10;

struct DSU {
    vector<int> _f;

    DSU (int n) {
        init(n);
    }

    void init(int n) {
        _f.assign(n + 1, 0);
        iota(all(_f), 0);
    }

    int find(int x) {
        if (x != _f[x]) {
            _f[x] = find(_f[x]);
        }
        return _f[x];
    }

    bool merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) {
            return false;
        }
        _f[y] = _f[x];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while (cin >> N && n != EOF) {
        DSU d(N);
        vector<PII> prod(n);
        for (auto &i : prod) {
            cin >> i.fi >> i.se;
        }
        sort(all(prod), greater());
        int res = 0;
        for (auto i : prod) {
            int x = d.find(i.se);
            if (x > 0) {
                res += i.fi;
                d.merge(x - 1, x);
            }
        }
        cout << res << "\n";
    }

    return 0;
}
