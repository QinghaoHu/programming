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
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll powmod(ll a, ll b, ll p) { ll res = 1; for (; b; b >>= 1) { if (b & 1) { res = res * a % p; } a = a * a % p; } return res; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

const int N = 5e5 + 10;
int n, q;
int a[N];

struct info {
    ll mss, mpre, msuf, s;
    info() : mss(-INF), mpre(-INF), msuf(-INF), s(0) {} // Proper initialization
    info(int a) : mss(a), mpre(a), msuf(a), s(a) {}
};

// Merge function to combine two nodes
info operator + (const info& l, const info& r) {
    info res;
    res.mss = max({l.mss, r.mss, l.msuf + r.mpre});
    res.mpre = max(l.mpre, l.s + r.mpre);
    res.msuf = max(r.msuf, r.s + l.msuf);
    res.s = l.s + r.s;
    return res;
}

struct node {
    info val;
} seg[4 * N];

// Updates the segment tree node by combining its two children
void update(int id) {
    seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}

// Builds the segment tree
void build(int id, int l, int r) {
    if (l == r) {
        seg[id].val = info(a[l]);
    } else {
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

// Updates a specific position in the array
void change(int id, int l, int r, int pos, int val) {
    if (l == r) {
        seg[id].val = info(val); // Update the leaf node
    } else {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            change(id * 2, l, mid, pos, val);
        } else {
            change(id * 2 + 1, mid + 1, r, pos, val);
        }
        update(id);
    }
}

// Queries the maximum subarray sum in the range [ql, qr]
info query(int id, int l, int r, int ql, int qr) {
    if (ql > qr) return info(); // If the query range is invalid, return a neutral element
    if (l == ql && r == qr) {
        return seg[id].val;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(id * 2, l, mid, ql, qr);
    } else if (ql > mid) {
        return query(id * 2 + 1, mid + 1, r, ql, qr);
    } else {
        return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n); // Build the segment tree

    rep(i, 0, q) {
        int ty;
        cin >> ty;
        if (ty == 2) { // Update query
            int x, d;
            cin >> x >> d;
            change(1, 1, n, x, d); // Update element at position x to value d
        } else { // Range query
            int l, r;
            cin >> l >> r;
            auto res = query(1, 1, n, l, r); // Query the range [l, r]
            cout << res.mss << "\n"; // Output the maximum subarray sum in the range
        }
    }

    return 0;
}
