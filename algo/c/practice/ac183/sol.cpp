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
typedef pair<double, double> PDD; typedef pair<string, int> PSI; const int mod = 999971; const db eps = 1e-9; const db PI = acos(-1.0);
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
arr<int, 9> row{}, col{};
arr<arr<int, 3>, 3> cell{};
arr<arr<int, 9>, 9> grid{};
int max_sco = -INF;
int sco = 0;
int min_sco = 0;

int lowbit(int x) {
    return x & -x;
}

int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

void init() {
    rep(i, 0, N) {
        ones[1 << i] = i;
    }
    rep(i, 0, M) {
        int s = 0;
        for (auto j = i; j; j -= lowbit(j)) {
            s++;
        }
        nums[i] = s;
    }
    rep(i, 0, 9) {
        row[i] = col[i] = (1 << N) - 1;
    }
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            cell[i][j] = (1 << N) - 1;
        }
    }
}

void dfs(int u) {
    if (u == 0) {
        max_sco = max(sco, max_sco);
        return;
    }
    int minv = 10;
    int x, y;
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            if (grid[i][j] == 0) {
                if (nums[get(i, j)] < minv) {
                    x = i, y = j;
                    minv = nums[get(i, j)];
                }
            }
        }
    }
    for (auto i = get(x, y); i; i -= lowbit(i)) {
        auto k = lowbit(i);
        int t = ones[k];
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        grid[x][y] = t + 1;
        sco += (t + 1) * score[x][y];
        dfs(u - 1);
        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
        grid[x][y] = 0;
        sco -= (t + 1) * score[x][y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int cnt = 0;
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            int c;
            cin >> c;
            if (c != 0) {
                row[i] -= 1 << (c - 1);
                col[j] -= 1 << (c - 1);
                cell[i / 3][j / 3] -= 1 << (c - 1);
                min_sco += c * score[i][j];
                grid[i][j] = c;
            } else {
                cnt++;
            }
        }
    }
    dfs(cnt);
    if (max_sco == -INF) {
        cout << -1 << " \n";
    } else {
        rep(i, 0, 9) {
            rep(j, 0, 9) {
                cerr << grid[i][j] << " ";
            }
            cerr << "\n";
        }
        cout << max_sco + min_sco << " \n";
    }

    return 0;
}

