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

const int N = 50006;
int n, q, c[N], cnt[N];
array<int, 3> que[N];
ll ans[N], ans2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    rep(i, 1, n + 1) {
    	cin >> c[i];
    }
    rep(i, 1, q + 1) {
    	int l, r;
    	cin >> l >> r;
    	que[i] = {l, r, i};
    }
    int t = sqrt(q);
    sort(que + 1, que + q + 1, [&](array<int, 3> a, array<int, 3> b) {
    	if (a[2] / t != b[2] / t) {
    		return a[0] < b[0];
    	} 
    	return a[1] < b[1];
    });

    auto add = [&](int x) {
    	cnt[c[x]]++;
    	tmp += cnt[c[x]];
    };

    auto del = [&](int x) {
    	tmp -= cnt[c[x]];
    	cnt[c[x]]--;
    };

    int l = 1, r = 0;
    rep(i, 1, q + 1) {
    	while (l > que[i][0]) l--, add(l);
    	while (r < que[i][1]) r++, add(r);
    	while (l < que[i][1]) del(l), l++;
    	while (r > que[i][1]) del(r), r--;
    	ans[que[i][2]] = tmp;
    	
    }

    return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */