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

const int N = 1e5 + 10;
int n, m;
int a[N];
ll tr1[N], tr2[N];

int lowbit(int x) {
	return x & -x;
}

void modify(ll tr[], int x, ll c) {
	for(; x <= n; x += lowbit(x)) {
		tr[x] += c;
	}
}

ll query(ll tr[], int x) {
	ll s = 0;
	for (; x; x -= lowbit(x)) {
		s += tr[x];
	}
	return s;
}

ll prefix_sum(int x) {
	return (x + 1) * query(tr1, x) - query(tr2, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 1, n + 1) {
    	cin >> a[i];
    }
    rep(i, 1, n + 1) {
    	modify(tr1, i, a[i] - a[i - 1]);
    	modify(tr2, i, (ll)i * (a[i] - a[i - 1]));
    }

    while (m--) {
    	int op;
    	int l, r, d;
    	cin >> op >> l >> r;
    	if (op == 2) {
    		cout << prefix_sum(r) - prefix_sum(l - 1) << "\n";
    	}	else {
    		cin >> d;
    		modify(tr1, l, d); modify(tr2, l, l * d);
    		modify(tr1, r + 1, -1 * d); modify(tr2, r + 1, (r + 1) * d * -1);
    	}
    }

    return 0;
}