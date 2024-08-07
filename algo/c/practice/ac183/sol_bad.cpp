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

const int N = 9, M = 1 << 9;
arr<arr<int, 9>, 9> score {{
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9, 10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
}};
arr<int, M> ones{}, nums{};
// ones refer to the number, nums refer to the amount of numbers that can be chose
arr<int, 9> rows{}, col{}, paw{};
arr<arr<int, 9>, 9> grid{};
int max_sco = -INF;
int sco = 0;
int min_sco = 0;

int lowbit(int x) {
    return x & -x;
}

int prob(int x, int y) {
    return rows[x] & col[y] & paw[grid[x][y] - 6];
}

bool dfs(int u) {
    if (u == 0) {
        max_sco = max(sco, max_sco);
        return true;
    }
    int minv = 10;
    int x, y;
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            if (!grid[i][j]) {
                if (nums[prob(i, j)] < minv) {
                    x = i, y = j;
                    break;
                }
            }
        }
    }
    for (int j = prob(x, y); j; j -= lowbit(j)) {
        int t = ones[lowbit(j)];
        grid[x][y] = t;
        rows[x] -= (1 << (t - 1));
        col[y] -= (1 << (t - 1));
        int s = score[x][y];
        paw[s - 6] -= (1 << (t - 1));
        sco += s * t;
        if (dfs(u - 1)) {
            return true;
        }
        grid[x][y] = 0;
        rows[x] += (1 << (t - 1));
        col[y] += (1 << (t - 1));
        paw[s - 6] += (1 << (t - 1));
        sco -= s * t;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rep(i, 0, 9) {
        ones[1 << i] = i;
    }
    rep(i, 0, M) {
        int s = 0;
        for (int j = i;j; j -= lowbit(j)) {
            s++;
        }
        nums[i] = s;
    }
    rep(i, 0, 9) {
        rows[i] = col[i] = (1 << N) - 1;
    }
    rep(i, 0, 5) {
        paw[i] = (1 << N) - 1;
    }
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            cin >> grid[i][j];
            int c = grid[i][j];
            rows[i] -= 1 << (c - 1);
            col[j] -= 1 << (c - 1);
            paw[score[i][j] - 6] -= 1 << (c - 1);
            min_sco += score[i][j] * c;
        }
    }
    int cnt = 0;
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            if (!grid[i][j]) {
                cnt++;
            }
        }
    }
    if (dfs(cnt)) {
        cout << max_sco << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}

