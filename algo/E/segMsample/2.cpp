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

const int N = 201000, M = 100, MlogN = M * log2(N);

struct node {
    int lc, rc;
    int dat;
} seg[MlogN];

int tot, root[M];
int n, a[N];

int build(int l, int r) {
    int p = ++tot;
    if (l == r) {
        seg[l].dat = a[l];
        return p;
    }
    int mid = (l + r) >> 1;
    seg[p].lc = build(l, mid);
    seg[p].rc = build(mid + 1, r);
    seg[p].data = max(seg[seg[p].lc].dat, seg[seg[p].rc].dat);
    return p;
}

int insert(int now, int l, int r, int x, int val) {
    int p = ++tot;
    seg[p] = seg[now];
    if (l == r) {
        seg[p].dat = val;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        seg[p].lc = insert(seg[now].lc, l, mid, x, val);
    } else {
        seg[p].rc = insert(seg[now].rc, mid + 1, r, x, val);
    }
    seg[p].dat = max(seg[seg[p].lc].dat, seg[seg[p].rc].dat);
    return p;
}

// root[i] = insert(root[i - 1], 1, n, ni, vali);