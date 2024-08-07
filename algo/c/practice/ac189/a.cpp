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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, mx, my;
    cin >> x >> y >> mx >> my;
    swap(x, y), swap(mx, my);
    vector g(x, vector<char>(y, ' '));
    for (auto &i : g) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    vector cnt(x, vector<int>(y, -1));
    queue<PII> q;
    cnt[x - mx][my - 1] = 0;
    arr<PII, 8> chan {{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
    }};
    q.push(mp(x - mx, my - 1));
    int ans = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (auto ch : chan) {
            int a = t.fi + ch.fi, b = t.se + ch.se;
            if (a < 0 || a >= x || b < 0 || b >= y || g[a][b] == '*' || cnt[a][b] != -1) {
                continue;
            }
            cnt[a][b] = cnt[t.fi][t.se] + 1;
            ans = max(ans, cnt[a][b]);
            q.push({a, b});
        }
    }
    for (auto i : cnt) {
        for (auto j : i) {
            cerr << j << " ";
        }
        cerr << "\n";
    }
    cout << ans << " \n";

    return 0;
}