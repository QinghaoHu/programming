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
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1010, M = N * N, base = 131;

int n, m, a, b;
ull hashv[N][N], p[M];
char str[N];

void solve() {
    cin >> n >> m >> a >> b;
    p[0] = 1;
    rep(i, 1, n * m + 1) {
        p[i] = p[i - 1] * base;
    }
    rep(i, 1, n + 1) {
        cin >> str + 1;
        rep(j, 1, m + 1) {
            hashv[i][j] = hashv[i][j - 1] * base + str[j] - '0';
        }
    }
    unordered_set<ull> S;
    auto get = [&](ull *f, int l, int r) -> ull {
        return f[r] - f[l - 1] * p[r - l + 1];
    };
    rep(i, b, m + 1) {
        ull s = 0;
        int l = i - b + 1, r = i;
        rep(j, 1, n + 1) {
            s = s * p[b] + get(hashv[j], l, r);
            if (j > a) {
                s -= get(hashv[j - a], l, r) * p[a * b];
            }
            if (j >= a) S.insert(s);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        ull s = 0;
        rep(i, 0, a) {
            cin >> str;
            rep(j, 0, b) {
                s = s * base + str[j] - '0';
            }
        }
        cout << ((S.count(s)) ? 1 : 0) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
