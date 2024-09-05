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
    vector<int> f;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.assign(n + 1, 1);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool comp(int a, int b) {
        return find(a) == find(b);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }
};

const int N = 2e5 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c, _;
    cin >> _;
    rep(tt, 0, _) {
        int n;
        cin >> n;
        unordered_map<int, int> md;
        vector<pair<int, int>> equ, dis;

        int cnt = 0;
        rep(j, 0, n) {
            cin >> a >> b >> c;
            if (!md.count(a)) {
                md[a] = ++cnt;
            }
            if (!md.count(b)) {
                md[b] = ++cnt;
            }

            if (c == 1) {
                equ.eb(mp(md[a], md[b]));
            } else {
                dis.eb(mp(md[a], md[b]));
            }
        }

        DSU d(N);
        for (auto [i, j] : equ) {
            d.merge(i, j);
        }

        bool isA = true;
        for (auto [i, j] : dis) {
            if (d.comp(i, j)) {
                isA = false;
                break;
            }
        }

        cout << (isA ? "YES" : "NO") << "\n";

    }

    return 0;
}