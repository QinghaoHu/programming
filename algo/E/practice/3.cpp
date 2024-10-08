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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

const int N = 50010;
int n, m;
struct node {
    int l, r;
    int d, ld, rd;
    int tag;
} seg[N * 4];

node operator + (node a, node b) {
    node res;
    res.l = a.l, res.r = b.r;
    res.ld = a.ld;
    if (a.d == a.r - a.l + 1)  {
        res.ld = a.d + b.ld;
    }
    res.rd = b.rd;
    if (b.d == b.r - b.l + 1) {
        res.rd = b.d + a.rd;
    }
    res.d = max(max(a.d, b.d), a.rd + b.ld);
    return res;
}

void update(int u) {
    seg[u] = seg[u * 2] + seg[u * 2 + 1];
}

void build(int u, int l, int r) {
    if (l == r) {
        seg[u] = {l, r, 1, 1, 1, 0};
        return;
    }
    seg[u].l = l, seg[u].r = r;
    int mid = l + r >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    update(u);
}

void settag(int u, int tag) {
    seg[u].tag = tag;
    if (tag == 1) {
        seg[u].d = seg[u].ld = seg[u].rd = 0;
    } else if (tag == -1) {
        seg[u].d = seg[u].ld = seg[u].rd = seg[u].r - seg[u].l + 1;
    }
}

void pushdown(int u) {
    if (seg[u].tag != 0) {
        settag(u * 2, seg[u].tag);
        settag(u * 2 + 1, seg[u].tag);
    }
    seg[u].tag = 0;
}

void modify(int u, int ql, int qr, int tag) {
    int l = seg[u].l, r = seg[u].r;
    if (l == ql && r == qr) {
        settag(u, tag);
        return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (qr <= mid) {
        modify(u * 2, ql, qr, tag);
    } else if (ql > mid) {
        modify(u * 2 + 1, ql, qr, tag);
    } else {
        modify(u * 2, ql, mid, tag);
        modify(u * 2 + 1, mid + 1, qr, tag);
    }
    update(u);
}

int query(int u, int d) {
    int l = seg[u].l, r = seg[u].r;
    if (l == r) {
        if (seg[u].d) return l;
        return 0;
    }
    pushdown(u);
    if (seg[u * 2].d >= d) {
        return query(u * 2, d);
    }
    if (seg[u * 2].rd + seg[u * 2 + 1].ld >= d) {
        return seg[u * 2].r - seg[u * 2].rd + 1;
    }
    if (seg[u * 2 + 1].d >= d) {
        return query(u * 2 + 1, d);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    build(1, 1, n);
    rep(i, 0, m) {
        int op, x, len;
        cin >> op;
        if (op == 1) {
            cin >> len;
            x = query(1, len);
            cout << x << "\n";
            if (x) modify(1, x, x + len - 1, 1);
        } else if (op == 2) {
            cin >> x >> len;
            modify(1, x, x + len - 1, -1);
        }
    }

    return 0;
}