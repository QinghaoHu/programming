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
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

const int N = 1e5 + 10, T = 2006;
int n, m, cc;
int a[N], b[N];
int L[N], R[N];
bool v[N];
int pos[N];
int f[T][T], c[N];
vector<int> e[N];

int ask(int l, int r) {
    int p = pos[l], q = pos[r], cnt = 0;
    memset(v, 0, sizeof v);

    function<int(int, int, int)> find = [&](int x, int l, int r) {
        return upper_bound(e[x].begin(), e[x].end(), r) - lower_bound(e[x].begin(), e[x].end(), l);
    };

    function<bool(int)> pd = [&](int x) {
        return x && !(x & 1);
    };

    if (p == q) {
        for (int i = l; i <= r; i++) {
            if (v[a[i]]) continue;
            v[a[i]] = true;
            int w = find(a[i], l, r);
            if (pd(w)) ++cnt;
        }
        return cnt;
    }
    int x = 0, y = 0;
    if (p + 1 <= q - 1) {
        x = p + 1;
        y = q - 1;
    }
    cnt = f[x][y];
    for (int i = l; i <= R[p]; i++) {
        if (v[a[i]]) continue;
        v[a[i]] = true;
        int c1 = find(a[i], l, r), c2 = find(a[i], L[x], R[y]);
        if (!pd(c1) && pd(c2)) {
            cnt--;
        } else if (pd(c1) && !pd(c2)) {
            cnt++;
        }
    }
    for (int i = L[q]; i <= r; i++) {
        if (v[a[i]]) continue;
        v[a[i]] = true;
        int c1 = find(a[i], l, r), c2 = find(a[i], L[x], R[y]);
        if (!pd(c1) && pd(c2)) {
            cnt--;
        } else if (pd(c1) && !pd(c2)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> cc >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    memcpy(b, a, sizeof b);
    sort(b + 1, b + n + 1);
    int tot = unique(b + 1, b + n + 1) - (b + 1);
    rep(i, 1, n + 1) {
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        e[a[i]].push_back(i);
    }
    int t = sqrt(n);
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
        int cnt = 0;
        for (int j = L[i]; j <= n; j++) {
            if (++c[a[j]] > 1) {
                if (c[a[j]] & 1) cnt--;
                else cnt++;
            }
            f[i][pos[j]] = cnt;
        }
    }
    int x = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l = (l + x) % n + 1;
        r = (r + x) % n + 1;
        if (l > r) swap(l, r);
        x = ask(l, r);
        cout << x << "\n";
    }

    return 0;
}