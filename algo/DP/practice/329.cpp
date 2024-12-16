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
const int N = 1e5 + 10, M = 1e5;
int n, s;
int l[N], r[N];
int f[N][2]; // 0 means left, 1 means right
struct node {
    int x;
    int t;
} seg[N * 8];

void build(int id, int l, int r) {
    seg[id].t = -1;
    if (l == r) {
        seg[id].x = 0; return;
    }
    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void pushdown(int id) {
    if (seg[id].t != -1) {
        int s = seg[id].x;
        seg[id * 2].x = s, seg[id * 2].t = seg[id].t;
        seg[id * 2 + 1].x = s, seg[id * 2 + 1].t = seg[id].x;
        seg[id].t = -1;
    }
}

void modify(int id, int l, int r, int ql, int qr, int t) {
    if (l == ql && r == qr) {
        seg[id].x = t;
        seg[id].t = t;
        return;
    }
    pushdown(id);
    int mid = l + r >> 1;
    if (qr <= mid) {
        modify(id * 2, l, mid, ql, qr, t);
    }  else if (ql > mid) {
        modify(id * 2 + 1, mid + 1, r, ql, qr, t);
    } else {
        modify(id * 2, l, mid, ql, mid, t);
        modify(id * 2 + 1, mid + 1, r, mid + 1, qr, t);
    }
}

int query(int id, int l, int r, int target) {
    if (l == r) {
        return seg[id].x;
    }
    pushdown(id);
    int mid = l + r >> 1;
    if (target <= mid) {
        return query(id * 2, l, mid, target);
    } else {
        return query(id * 2 + 1, mid + 1, r, target);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    rep(i, 1, n + 1) {
        cin >> l[i] >> r[i];
        l[i] += M, r[i] += M;
    }
    l[n + 1] = r[n + 1] = s + M;
    l[0] = r[0] = M;
    build(1, 0, 2 * N);
    memset(f, 0x3f, sizeof f);
    f[0][0] = f[0][1] = 0;
    rep(i, 1, n + 2) {
        int j = query(1, 0, 2 * N, l[i]);
        f[i][0] = min(f[j][0] + abs(l[i] - l[j]), f[j][1] + abs(l[i] - r[j]));
        j = query(1, 0, 2 * N, r[i]);
        f[i][1] = min(f[j][0] + abs(r[i] - l[j]), f[j][1] + abs(r[i] - r[j]));
        modify(1, 0, 2 * N, l[i], r[i], i);
    }
    cout << min(f[n + 1][0], f[n + 1][1]) << '\n';
    return 0;
}