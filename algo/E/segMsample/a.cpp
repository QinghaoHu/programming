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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int N = 201000;
int a[N];

struct node {
	int minv;
} seg[N * 4];

void update(int id) {
	seg[id].minv = min(seg[id * 2].minv, seg[id * 2 + 1].minv);
}

void build(int id, int l, int r) {
	if (l == r) {
		seg[id].minv = a[l];
	} else {
		int mid = (l + r) >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		update(id);
	}
}

void change(int id, int l, int r, int pos, int val) {
	if (l == r) {
		seg[id].minv = val;
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

int query(int id, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) {
		return seg[id].minv;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) {
		return query(id * 2, l, mid, ql, qr);
	} else if (ql > mid) {
		return query(id * 2 + 1, mid + 1, r, ql, qr);
	} else {
		return min(query(id * 2, l, mid, ql, mid), query(id * 2 + 1, mid + 1, r, mid + 1, qr));
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build(1, 1, n);

    return 0;
}