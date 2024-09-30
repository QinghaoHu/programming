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

const int N = 201000;

struct BST {
	int l, r;
	int val;
} a[N];
int tot, root, INF = 1 << 30;

int new(int val) {
	a[++tot].val = val;
	return tot;
}

void build() {
	New(-INF), New(INF);
	root = 1, a[1].r = 2;
}

int get(int p, int val) {
	if (p == 0) return p;
	if (val == a[p].val) {
		return p;
	}
	return val < a[p].val ? Get(a[p].l, val) : Get(a[p].r, val);
}

void insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return;
	}
	if (val == a[p].val) {
		return;
	}
	if (val < a[p].val) {
		Insert(a[p].l, val);
	} else {
		Insert(a[p].r, val);
	}
}

int getNext(int val) {
	int ans = 2;
	int p = root;
	while (p) {
		if (val == a[p].val) {
			if (a[p].r > 0) {
				p = a[p].r;
				while (a[p].l > 0) {
					p = a[p].l;
				}
				ans = p;
			}
			break;
		}
		if (a[p].val > val && a[p].val < a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
	return ans;
}

int getPre(int val) {
	int ans = 1;
	int p = root;
	while (p) {
		if (val == a[p].val) {
			if (a[p].l > 0) {
				p = a[p].l;
				while (a[p].r > 0) {
					p = a[p].r;
				}
				ans = p;
			}
			break;
		}
		if (a[p].val < val && a[p].val > a[ans].val) ans = p;
		p = val < a[p].val ? a[p].l : a[p].r;
	}
}

void remove(int &p, int val) {
	if (p == 0) return;
	if (val == a[p].val) {
		if (a[p].l == 0) {
			p = a[p].r;
		} else if (a[p].r == 0) {
			a[p].l;
		} else {
			int next = a[p].r;
			while (a[p].l > 0) {
				next = a[next].l;
			}
			remove(a[p].r, a[next].val);
			a[next].l = a[p].l, a[next].r = a[p].r;
			p = next;
		}
		return;
	}
	if (val < a[p].val) {
		remove(a[p].l, val);
	} else {
		remove(a[p].r, val);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}