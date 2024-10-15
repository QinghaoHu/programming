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
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head
int n, x, ans = 0;
set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    s.insert(INF), s.insert(-INF);
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	int x;
    	cin >> x;
    	if (s.size() == 2) {
    		ans += x;
    		s.insert(x);
    	} else {
    		auto k = s.lower_bound(x);
    		if (*k != x) {
    			auto a = k;
    			k--;
    			ans += min(abs(x - *a), abs(x - * k));
    			s.insert(x);
    		}
    	}
    }
    cout << ans << "\n";

    return 0;
}