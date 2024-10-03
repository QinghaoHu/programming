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

const int N = 2e4 + 10, M = 1e5 + 10;
int n, m;
int p[N], d[N];

struct node {
	int a, b, c;
	bool operator < (const node & _) const {
		return c > _.c;
	}
} seg[M];

int find(int x) {
	if (p[x] != x) {
		int t = find(p[x]);
		d[x] += d[p[x]] % 2;
		p[x] = t;
	}
	return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rep(i, 0, N) {
    	p[i] = i;
    }
    cin >> n >> m;
    rep(i, 0, m) {
    	cin >> seg[i].a >> seg[i].b >> seg[i].c;
    }

    sort(seg, seg + m);

    int ans = 0;
    rep(i, 0, m) {
    	int x = seg[i].a, y = seg[i].b, z = seg[i].c;
    	int pa = find(x), pb = find(y);
    	if (find(x) == find(y) && d[x] % 2 == d[y] % 2) {
    		cout << seg[i].c << "\n";
    		return 0;
    	} else {
    		p[pa] = pb;
    		d[pa] = ((d[x] - d[y] + 1) % 2 + 2) % 2;
    	}
    }
    cout << 0 << "\n";

    return 0;
}