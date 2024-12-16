#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a; i<n; i++)
#define per(i,a,n) for (int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) (int)((x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
const ll INF = 1 << 29;
ll powmod(ll a,ll b) {ll res = 1; for (; b; b>>=1){if (b&1) res=res*a; a=a*a;}return res;}
ll gcd(ll a,ll b) { return !b ? a : gcd(b, a%b); }
//head
const int N = 155, M = 15;
bool st[N][M];
int f[2][60000], n, m, k;
int pre[M], now[M];
int pow3[M] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};

int three_ten(int a[]) {
    int res = 0;
    rep(i, 0, m) res += a[i] * pow3[i];
    return res;
}

void ten_three(int x, int (&a)[M]) {
    rep(i, 0, m) {
        a[i] = x % 3;
        x /= 3;
    }
}

void dfs(int i, int j, int last, int state) {
    f[i & 1][state] = max(f[i & 1][state], last);
    if (j >= m) return;
    if (j + 1 < m && !pre[j] && !pre[j + 1] && !now[j] && !now[j + 1]) {
        now[j] = now[j + 1] = 2;
        dfs(i, j + 2, last + 1, three_ten(now));
        now[j] = now[j + 1] = 0;
    }

    if (j + 2 < m && !now[j] && !now[j + 1] && !now[j + 2]) {
        now[j] = now[j + 1] = now[j + 2] = 2;
        dfs(i, j + 3, last + 1, three_ten(now));
        now[j] = now[j + 1] = now[j + 2] = 0;
    }

    dfs(i, j + 1, last, state);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int _; cin >> _;
    rep(tt, 0, _) {
        cin >> n >> m >> k;
        memset(st, 0, sizeof st);
        rep(i, 0, k) {
            int x, y; cin >> x >> y;
            st[x][y - 1] = true;
        }
        memset(f[1 & 1], -1, sizeof f[1 & 1]);
        rep(i, 0, m) pre[i] = st[1][i] ? 2 : 1;
        int temp = three_ten(pre);
        f[1 & 1][temp] = 0;
        rep(i, 2, n + 1) {
            memset(f[i & 1], -1, sizeof f[i & 1]);
            rep(j, 0, pow3[m] + 1) {
                if (f[(i - 1) & 1][j] == -1) continue;
                ten_three(j, pre);
                rep(k, 0, m) {
                    if (st[i][k]) now[k] = 2;
                    else now[k] = pre[k] ? pre[k] - 1 : 0;
                }
                temp = three_ten(now);
                dfs(i & 1, 0, f[(i - 1) & 1][j], temp);
            }
        }
        int res = 0;
        rep(i, 0, pow3[m]) res = max(res, f[n & 1][i]);
        cout << res << '\n';
    }
    return 0;
}