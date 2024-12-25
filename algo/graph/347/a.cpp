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
ll powmod(ll a, ll b) {ll res = 1; for (; b; b>>=1){if (b&1) res=res*a; a=a*a;}return res;}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a%b); }
// head
const int N = 32;
int n, m, s;
int p, deg;
int d[N], ver[N], a[N][N], conn[N];
bool v[N];
int ans;
int tree[N][N];

void prim(int root) {
    d[root] = 0;
    rep(i, 1, p + 1) {
        int x = 0;
        rep(j, 1, p + 1) {
            if (!v[ver[j]] && (x == 0 || d[ver[j]] < d[x])) x = ver[j];
        }
        v[x] = true;
        rep(j, 1, p + 1) {
            if (!v[ver[j]] && d[ver[j]] > a[x][ver[j]]) {
                d[ver[j]] = a[x][ver[j]];
                d[ver[j]] = a[x][ver[j]], conn[ver[j]] = x;
            }
        }
    }
    int closet = root;
    rep(i, 1, p + 1) {
        int x = ver[i];
        if (root == x) continue;
        ans += d[x];
        tree[conn[x]][x] = tree[x][conn[x]] = d[x];
        if (a[1][x] < a[1][closet]) closet = x;
    }
    deg++;
    tree[closet][1] = tree[1][closet] = a[1][closet];
    ans += a[1][closet];
}

void dfs(int x) {
    c[x] = true;
    ver[++p] = x;
    rep(i, 1, n + 1) {
        if (a[x][i] != 0x3f3f3f && !c[i]) {
            dfs(i);
        }
    }
}

void prima() {
    memset(d, 0x3f, sizeof d);
    memset(v, 0, sizeof v);
    memset(tree, 0x3f, sizeof tree);
    c[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!c[i]) {
            p = 0;
            dfs(i);
            prim(i);
        }
    }
}

void dp(int x) {
    v[x] = true;
    rep(y, 2, n + 1) {
        if (tree[x][y] != 0x3f3f3f3f && !v[y]) {
            if (f[x] > tree[x][y]) {
                f[y] = f[x];
                fx[y] = fx[x], 
            }
        }
    }
}

int main(){
    scanf("%d", &m);
    map<string, int> h;
    h["Park"] = 1, n = 1;
    rep(i, 1, m + 1) {
        int x, y, z;
        char sx[12], sy[12];
        scanf("%s%s%d", sx, sy, &z);
        if (!h.count(sx)) h[sx] = ++n;
        if (!h.count(sy)) h[sy] = ++n;
        x = h[sx], y = h[sy];
        a[x][y] = a[y][x] = min(a[x][y], z);
    }
    scanf("%d", &s);

}