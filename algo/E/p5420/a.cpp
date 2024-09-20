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
ll lcm(ll a, ll b) {return a /gcd(a,b) *b;}

const int N = 100010;
int n, m;
ll ans = 0;
vector<int> vx;
vector<array<int, 4>> event;

struct info {
    int minv, mincnt;
};

info operator + (const info &l, const info &r) {
    info a;
    a.minv = min(l.minv, r.minv);
    if (l.minv == r.minv) {
        a.mincnt = l.mincnt + r.mincnt;
    } else if (l.minv < r.minv) {
        a.mincnt = l.mincnt;
    } else {
        a.mincnt = r.mincnt;
    }
    return a;
}

struct node {
    int t;
    info val;
} seg[8 * N];

void update(int id) {
    seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}

void settag(int id, int t) {
    seg[id].val.minv += t;
    seg[id].t += t;
}

void pushdown(int id) {
    if (seg[id].t != 0) {
        settag(id * 2, seg[id].t);
        settag(id * 2 + 1, seg[id].t);
        seg[id].t = 0;
    }
}

void modify(int id, int l, int r, int ql, int qr, int t) {
    if (l == ql && r == qr) {
        settag(id, t);
        return;
    }
    int mid = l + r >> 1;
    pushdown(id);
    if (qr <= mid) {
        modify(id * 2, l, mid, ql, qr, t);
    } else if (ql > mid) {
        modify(id * 2 + 1, mid + 1, r, ql, qr, t);
    } else {
        modify(id * 2, l, mid, ql, mid, t);
        modify(id * 2 + 1, mid + 1, r, mid + 1, qr, t);
    }
    update(id);
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id].val.minv = 0;
        seg[id].val.mincnt = vx[r] - vx[r - 1];
    } else {
        int mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, 1, n + 1) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vx.pb(x1);
        vx.pb(x2);
        event.pb({y1, 1, x1, x2});
        event.pb({y2, -1, x1, x2});
    }
    sort(event.begin(), event.end());
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    m = (int)vx.size() - 1;
    build(1, 1, m);
    int prey = 0;
    int totlen = seg[1].val.mincnt;
    for (auto evt : event) {
        int cov = totlen;
        if (seg[1].val.minv == 0) {
            cov = totlen - seg[1].val.mincnt;
        }
        ans += (ll)(evt[0] - prey) * cov;
        prey = evt[0];
        int x1 = lower_bound(vx.begin(), vx.end(), evt[2]) - vx.begin() + 1;
        int x2 = lower_bound(vx.begin(), vx.end(), evt[3]) - vx.begin();
        modify(1, 1, m, x1, x2, evt[1]);
    }
    cout << ans << "\n";

    return 0;
}