#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(2 * n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[n + i] = a[i];
	}
	deque<int> q;
	a[0] = -INF;
	q.push_back(0);
	int ans = 0;
	for (int i = 1; i <= n * 2; i++) {
		while (q.size() && q.front() < i - n / 2) {
			q.pop_front();
		}
		ans = max(ans, a[i] + i - q.front() + a[q.front()]);
		while (q.size() && a[i] - i >= a[q.back()] - q.back()) {
			q.pop_back();
		}
		q.push_back(i);
	}
	cout << ans << '\n';
	
	return 0;
}
