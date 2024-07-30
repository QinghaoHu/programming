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

void solve() {
    const int N = 810;
    arr<arr<int, N>, N> st{};
    arr<arr<char, N>, N> g{};
    int n, m;
    PII boy, girl;
    vector<PII> ghosts;
    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> g[i][j];
            char c = g[i][j];
            if (c == 'M') {
                boy = mp(i, j);
            } else if (c == 'G') {
                girl = mp(i, j);
            } else if (c == 'Z') {
                ghosts.pb(mp(i, j));
            }
        }
    }
    auto distance = [&](int x, int y) -> int {
        int res = INF;
        for (auto r : ghosts) {
            res = min(res, abs(x - r.fi) + abs(y - r.se));
        }
        return res;
    };
    auto bfs = [&]() -> int {
        queue<PII> as, bs;
        st[boy.fi][boy.se] = 1;
        st[girl.fi][girl.se] = 2;
        as.push(boy), bs.push(girl);
        arr<PII, 4> change {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};
        int time = 0;
        while (!as.empty() || !bs.empty()) {
            ++time;
            rep(i, 0, 3) {
                int s = as.size();
                rep(j, 0, s) {
                    auto t = as.front();
                    as.pop();
                    for (auto row : change) {
                        int x = t.fi + row.fi, y = t.se + row.se;
                        if (x < 0 || x >= n || y < 0 || y >= m || st[x][y] == 1 || g[x][y] == 'X') {
                            continue;
                        }
                        if (distance(x, y) <= 2 * time) {
                            continue;
                        }
                        if (st[x][y] == 2) {
                            cerr << x << " " << y << "\n";
                            return time;
                        }
                        st[x][y] = 1;
                        as.push(mp(x, y));
                    }
                }
            }
            int s2 = bs.size();
            rep(i, 0, s2) {
                auto t = bs.front();
                bs.pop();
                for (auto row : change) {
                    int x = t.fi + row.fi, y = t.se + row.se;
                    if (x < 0 || x >= n || y < 0 || y >= m || st[x][y] == 2 || g[x][y] == 'X') {
                        continue;
                    }
                    if (distance(x, y) <= 2 * time) {
                        continue;
                    }
                    if (st[x][y] == 1) {
                        cerr << x << " " << y << "\n";
                        return time;
                    }
                    st[x][y] = 2;
                    bs.push(mp(x, y));
                }
            }
        }
        return -1;
    };
    cout << bfs() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}
