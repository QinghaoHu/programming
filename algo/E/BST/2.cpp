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

const int N = 100010;

struct node {
	int l, r;
	int val, dat;
	int cnt, size;
} tr[N];

int tot, root, n;

int newNode(int val) {
	tr[++tot].val = val;
	tr[tot].dat = rand();
	tr[tot].cnt = tr[tot].size = 1;
	return tot;
}

void update(int p) {
	tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

void build() {
	newNode(-INF), newNode(INF);
	root = 1, tr[root].r = 2;
	update(root);
}

int getRankByVal(int p, int val) {
	if (p == 0) {
		return 0;
	}
	if (val == tr[p].val) return tr[tr[p].l].size + 1;
	if (val < tr[p].val) {
		return getRankByVal(tr[p].l, val);
	}
	return getRankByVal(tr[p].r, val) + tr[tr[p].l].size + tr[p].cnt;
}

int getValByRank(int p, int rank) {
	if (p == 0) return INF;
	if (tr[tr[p].l].size >= rank) return getValByRank(tr[p].l, rank);
	if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].val;
	return getValByRank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}

void zig(int &p) {
	int q = tr[p].l;
	tr[p].l = tr[q].r, tr[q].r = p, p = q;
	update(tr[p].r); update(p);
}

void zag(int &p) {
	int q = tr[p].r;
	tr[p].r = tr[q].l, tr[q].l = p, p = q;
	update(tr[p].l); update(p);
}

void insert(int &p, int val) {
	if (p == 0) {
		p = newNode(val);
		return;
	}
	if (val == tr[p].val) {
		tr[p].cnt++;
		update(p);
		return;
	}
	if (val < tr[p].val) {
		insert(tr[p].l, val);
		if (tr[p].dat < tr[tr[p].l].dat) {
			zig(p);
		}
	}
	if (val > tr[p].val) {
		insert(tr[p].r, val);
		if (tr[tr[p].r].dat > tr[p].dat) {
			zag(p);
		}
	}
	update(p);
}

int getPre(int val) {
	int ans = 1;
	int p = root;
	while (p) {
		if (tr[p].val == val) {
			if (tr[p].l > 0) {
				p = tr[p].l;
				while (tr[p].r > 0) {
					p = tr[p].r;
				}
				ans = p;
			}
			break;
		}
		if (tr[p].val > tr[ans].val && tr[p].val < val) {
			ans = p;
		}
		p = val < tr[p].val ? tr[p].l : tr[p].r;
	}
	return tr[ans].val;
}

int getNext(int val) {
	int p = root;
	int ans = 2;
	while (p) {
		if (tr[p].val == val) {
			if (tr[p].r > 0) {
				p = tr[p].r;
				while (tr[p].l > 0) {
					p = tr[p].l;
				}
				ans = p;
			}
			break;
		}
		if (tr[p].val > val && tr[p].val < tr[ans].val) {
			ans = p;
		}
		p = tr[p].val > val ? tr[p].l : tr[p].r;
	}
	return tr[ans].val;
}

void remove(int &p, int val) {
	if (p == 0) {
		return;
	}
	if (val == tr[p].val) {
		if (tr[p].cnt > 1) {
			tr[p].cnt--, update(p);
			return;
		}
		if (tr[p].l || tr[p].r) {
			if (tr[p].r == 0 || tr[tr[p].l].dat > tr[tr[p].r].dat) {
				zig(p); remove(tr[p].r, val);
			} else {
				zag(p); remove(tr[p].l, val);
			}
			update(p);
		} else {
			p = 0;
			return;
		}
	}
	val < tr[p].val ? remove(tr[p].l, val) : remove(tr[p].r, val);
	update(p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build();
    cin >> n;
    while (n--) {
    	int op, x;
    	cin >> op >> x;
    	switch (op) {
    	case 1:
    		insert(root, x);
    		break;
    	case 2:
    		remove(root, x);
    		break;
    	case 3:
    		cout << getRankByVal(root, x) - 1 << "\n";
    		break;
    	case 4:
    		cout << getValByRank(root, x + 1) << "\n";
    		break;
    	case 5:
    		cout << getPre(x) << "\n";
    		break;
    	case 6:
    		cout << getNext(x) << "\n";
    		break;
    	}
    }

    return 0;
}