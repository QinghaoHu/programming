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

const int N = 1e5 + 10, M = 1e4 + 10;
int n, m;
int a[N];
vector<int> nums;

struct node {
	int lc, rc;
	int cnt;
} seg[N * 4 + N * 17];
int root[N], idx;

int find(int x) {
	return lower_bound(all(nums), x) - nums.begin();
}

int insert(int u, int l, int r, int x) {
	int p = ++idx;
	seg[p] = seg[u];
	if (l == r) {
		seg[p].cnt += 1;
		return p;
	}
	int mid = l + r >> 1;
	if (x <= mid) {
		seg[p].lc = insert(seg[u].lc, l, mid, x);
	} else {
		seg[p].rc = insert(seg[u].rc, mid + 1, r, x);
	}
	seg[p].cnt = seg[seg[p].lc].cnt + seg[seg[p].rc].cnt;
	return p;
}

int build(int l, int r) {
	int p = ++idx;
	if (l == r) {
		return p;
	}
	int mid = l + r >> 1;
	seg[p].lc = build(l, mid);
	seg[p].rc = build(mid + 1, r);
	return p;
}

int query(int q, int p, int l, int r, int k) {
	if (l == r) return r;
	int cnt = seg[seg[q].lc].cnt - seg[seg[p].lc].cnt;
	int mid = l + r >> 1;
	if (k <= cnt) return query(seg[q].lc, seg[p].lc, l, mid, k);
	else return query(seg[q].rc, seg[p].rc, mid + 1, r, k - cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 1, n + 1) {
    	cin >> a[i];
    	nums.push_back(a[i]);
    }
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());

    root[0] = build(0, nums.size() - 1);
    for (int i = 1; i <= n; i++) {
    	root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));
    }

    while (m--) {
    	int l, r, k;
    	cin >> l >> r >> k;
    	cout << nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)] << "\n";
    }

    return 0;
}