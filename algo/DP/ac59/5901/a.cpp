#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

struct rec {
	int l, p, s;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<rec> a(m + 1, rec{});
	for (int i = 1; i <= m; i++) {
		cin >> a[i].l >> a[i].p >> a[i].s;
	}
	sort(a.begin() + 1, a.end(), [&](rec a, rec b) {
		return a.s < b.s;
	});
	int f[110][16010] {};
	
	auto calc = [&](int i, int x) -> int {
		return f[i - 1][x] - x * a[i].p;
	};
	
	for (int i = 1; i <= m; i++) {
		deque<int> q;
		for (int k = max(0, a[i].s - a[i].l); k <= a[i].s - 1; k++) {
			while (!q.empty() && calc(i, q.back()) <= calc(i, k)) {
				q.pop_back();
			}
			q.push_back(k);
		}
		for (int j = 1; j <= n; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (j >= a[i].s) {
				while (q.size() && q.front() < j - a[i].l) {
					q.pop_front();
				}
				if (q.size()) {
					f[i][j] = max(f[i][j], calc(i, q.front()) + j * a[i].p);
				}
			}
		}
	}
	cout << f[m][n] << '\n';
    return 0;
}
