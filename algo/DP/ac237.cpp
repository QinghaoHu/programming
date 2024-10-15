#include <bits/stdc++.h>
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
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    rep(i, 1, n + 1) {
    	std::cin >> a[i];
    }

    auto dp = [&]() -> int {
    	std::vector<int> b(n + 1, 0);
    	b.assign(all(a));
    	std::sort(all(b));

    	std::vector f(n + 1, std::vector<int>(n + 1, 0));
    	rep(i, 1, n + 1) {
    		int minv = INF;
    		rep(j, 1, n + 1) {
    			minv = std::min(minv, f[i - 1][j]);
    			f[i][j] = minv + std::abs(b[j] - a[i]);
    		}
    	}

    	int res = INF;
    	rep(i, 1, n + 1) {
    		res = std::min(res, f[n][i]);
    	}
    	return res; 
    };

    int res = dp();
    std::reverse(a.begin() + 1, a.end());
    res = std::min(res, dp());

    std::cout << res << "\n";

    return 0;
}	