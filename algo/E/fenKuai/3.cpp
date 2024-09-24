#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;

const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

const int N = 40006, T = 806;
int a[N], b[N], c[N], L[N], R[N], pos[N], f[T][T];
vector<int> e[N];

int find(int x, int l, int r) {
    return upper_bound(e[x].begin(), e[x].end(), r) - lower_bound(e[x].begin(), e[x].end(), l);
}

void work(int x, int l, int r, int &ans, int &cnt) {
    int w = find(x, l, r);
    if (w > cnt || (w == cnt && x < ans)) {
        cnt = w;
        ans = x;
    }
}

int ask(int l, int r) {
    int p = pos[l], q = pos[r];
    int ans = 0, cnt = 0;
    if (p == q) {
        for (int i = l; i <= r; i++) {
            work(a[i], l, r, ans, cnt);

        }
        return b[ans];
    }
    int x = 0, y = 0;
    if (p + 1 <= q - 1) {
        x = p + 1;
        y = q - 1;
    }
    for (int i = l; i <= R[p]; i++) {
        work(a[i], l, r, ans, cnt);
    }
    for (int i = L[q]; i <= r; i++) {
        work(a[i], l, r, ans, cnt);
    }
    if (f[x][y]) {
        work(f[x][y], l, r, ans, cnt);
    }
    return b[ans];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    memcpy(b, a, sizeof b);
    sort(b + 1, b + n + 1);
    int tot = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        e[a[i]].push_back(i);
    }
    int t = sqrt(log(n) / log(2) * n);
    int len = t ? n / t : n;
    for (int i = 1; i <= t; i++) {
        L[i] = (i - 1) * len + 1;
        R[i] = i * len;
    }
    if (R[t] < n) {
        L[t + 1] = R[t] + 1;
        R[++t] = n;
    }
    for (int i = 1; i <= t; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            pos[j] = i;
        }
    }
    memset(f, 0, sizeof f);
    for (int i = 1; i <= t; i++) {
        memset(c, 0, sizeof c);
        int cnt = 0, ans = 0;
        for (int j = L[i]; j <= n; j++) {
            if (++c[a[j]] > cnt || (c[a[j]] == cnt && a[j] < ans)) {
                cnt = c[a[j]];
                ans = a[j];
            }
            f[i][pos[j]] = ans;
        }
    }
    int x = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l = (l + x - 1) % n + 1;
        r = (r + x - 1) % n + 1;
        if (l > r) {
            swap(l, r);
        }
        x = ask(l, r);
        cout << x << "\n";
    }

    return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */