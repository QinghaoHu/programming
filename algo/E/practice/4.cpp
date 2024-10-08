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
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//header

const int N = 5010;
int n;

struct node {
	PII a, b;
} rect[N];

int get_range_len(int a, int b) {
    vector<PII> q;
    for (int i = 0; i < n; i++) {
        auto &r = rect[i];
        if (r.a.fi <= a && r.b.fi >= b) {
            q.push_back({r.a.se, r.b.se});
        }
    }
    if (q.empty()) {
        return 0;
    }
    sort(q.begin(), q.end());
    int res = 0, st = q[0].fi, ed = q[0].se;
    for (int i = 1; i < q.size(); i++) {
        if (q[i].fi <= ed) {
            ed = max(ed, q[i].se);
        } else {
            res += (b - a) * 2;
            st = q[i].fi, ed = q[i].se;
        }
    }
    res += (b - a) * 2;
    return res;
}

int get_len() {
	vector<int> xs;
	int res = 0;
	for (int i = 0; i < n; i++) {
		xs.push_back(rect[i].a.fi);
        xs.push_back(rect[i].b.fi);
	}
    sort(xs.begin(), xs.end());
    for (int i = 0; i + 1 < xs.size(); i++) {
        if (xs[i] != xs[i + 1]) {
            res += get_range_len(xs[i], xs[i + 1]);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, 0, n) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	rect[i] = {{x1, y1}, {x2, y2}};
    }
    int ans = get_len();
    rep(i, 0, n) {
    	swap(rect[i].a.fi, rect[i].a.se);
    	swap(rect[i].b.fi, rect[i].b.se);
    }
    cout << ans + get_len() << "\n";

    return 0;
}