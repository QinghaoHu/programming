#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int w = (int)log2(n);
    vector<int> h(n + 1, 0);
    for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int x0, m;
	cin >> x0 >> m;
	vector<int> s(m + 1, 0), x(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> x[i];
	}
	multiset<pair<int, int>> st;
	st.insert({INF, 0});
	st.insert({INF, 0});
	st.insert({-INF, 0});
	st.insert({-INF, 0});
	vector<int> ga(n + 1, 0), gb(n + 1, 0);
	for (int i = n; i; i--) {
		st.insert({h[i], i});
		auto it = st.find({h[i], i});
		auto it1 = (++it);
		auto it2 = (++it);
		auto it3 = (--(--(--it)));
		auto it4 = (--it);
		int a = (*it3).first != -INF ? h[i] - (*it3).first : INF;
		int b = (*it1).first != INF ? (*it1).first - h[i] : INF;
		if (a <= b) {
			gb[i] = (*it3).second;
			a = (*it4).first != -INF ? h[i] - (*it4).first : INF;
			ga[i] = (a <= b ? (*it4).second : (*it1).second);
		} else {
			gb[i] = (*it1).second;
			b = (*it2).first != INF ? (*it2).first - h[i] : INF;
			ga[i] = (a <= b ? (*it3).second : (*it2).second);
		}
	}
	const int N = 1e5 + 6;
	int f[18][N][2] {};
	for (int i = 1; i <= n; i++) {
		f[0][i][0] = ga[i];
		f[0][i][1] = gb[i];
	}
	for (int i = 1; i <= n; i++) {
		f[1][i][1] = f[0][f[0][i][1]][0];
		f[1][i][0] = f[0][f[0][i][0]][1];
	}
	for (int i = 2; i < w; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j][0] = f[i - 1][f[i - 1][j][0]][0];
			f[i][j][1] = f[i - 1][f[i - 1][j][1]][1];
		}
	}
	int da[18][N][2], db[18][N][2];
	for (int i = 1; i <= n; i++) {
		da[0][i][0] = abs(h[i] - h[ga[i]]);
		db[0][i][1] = abs(h[i] - h[gb[i]]);
		da[0][i][1] = db[0][i][0] = 0;
	}
	for (int i = 1; i <= n; i++) {
		da[1][i][0] = da[0][i][0];
        da[1][i][1] = da[0][f[0][i][1]][0];
        db[1][i][0] = db[0][f[0][i][0]][1];
        db[1][i][1] = db[0][i][1];
	}
	for (int i = 2; i < w; i++) {
		for (int j = 1; j <= n; j++) {
			da[i][j][0] = da[i - 1][j][0] + da[i - 1][f[i - 1][j][0]][0];
			da[i][j][1] = da[i - 1][j][1] + da[i - 1][f[i - 1][j][1]][1];
			db[i][j][0] = db[i - 1][j][0] + db[i - 1][f[i - 1][j][0]][0];
			db[i][j][1] = db[i - 1][j][1] + db[i - 1][f[i - 1][j][1]][1];
		}
	}
	
	int la, lb;
	auto calc = [&](int s, int x) {
		la = lb = 0;
		int p = s;
		for (int i = w; i >= 0; i--) {
			if (f[i][p][0] && la + lb + da[i][p][0] + db[i][p][0] <= x) {
				la += da[i][p][0];
				lb += db[i][p][0];
				p = f[i][p][0];
			}
		}
	};
	
	calc(1, x0);
	double ans0[2] = {1, (lb ? (double)la / lb : INF)};
	for (int i = 2; i <= n; i++) {
		calc(i, x0);
		if ((double)la / lb < ans0[1] || ((double)la / lb == ans0[1] && h[i] > h[(int)ans0[0]])) {
			ans0[0] = i;
			ans0[1] = (double)la / lb;
		}
	}
	cout << ans0[0] << '\n';
	for (int i = 1; i <= m; i++) {
		calc(s[i], x[i]);
		cout << la << ' ' << lb << '\n';
	}
	
    return 0;
}
