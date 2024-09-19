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

const int N = 500010;
int n, q, m;
vector<int> vx;
vector<arr<int, 4>> event;
ll c[N], ans[N];

ll query(int x) {
	ll s = 0;
	for (; x; x -= x & (-x)) {
		s += c[x];
	}
	return s;
}

void modify(int x, ll s) {
	for (; x <= m; x += x & (-x)) {
		c[x] += s;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    rep(i, 1, n + 1) {
    	int x, y;
    	cin >> x >> y;
    	vx.pb(x);
    	event.pb({y, 0, x});
    }
    rep(i, 1, q + 1) {
    	int x1, x2, y1, y2;
    	cin >> x1 >> x2 >> y1 >> y2;
    	event.push_back({y2, 2, x2, i});
    	event.push_back({y1 - 1, 2, x1 - 1, i});
    	event.push_back({y2, 1, x1 - 1, i});
    	event.push_back({y1 - 1, 1, x2 , i});
    }
    sort(event.begin(), event.end());
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    m = (int)vx.size();
    for (auto evt : event) {
    	if (evt[1] == 0) {
    		int y = lower_bound(vx.begin(), vx.end(), evt[2]) - vx.begin() + 1;
    		modify(y, 1);
    	} else {
    		int y = upper_bound(vx.begin(), vx.end(), evt[2]) - vx.begin();
    		int tmp = query(y);
    		if (evt[1] == 1) {
    			ans[evt[3]] -= tmp;
    		} else {
    			ans[evt[3]] += tmp;
    		}
    	}
    }
    for (int i = 1; i <= q; i++) {
    	cout << ans[i] << "\n";
    }

    return 0;
}