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

const int N = 250006;
vector<array<int, 5>> stone;
queue<array<int, 5>> que;
int n, L[N], R[N], M[N];
bool st[N];

bool cmp(array<int, 5> a, array<int, 5> b) {
	return a[2] < b[2];
}

ll getDis(int x, int y) {
	auto t = stone[0];
	ll dx = x - t[0], dy = y - t[1];
	return dx * dx + dy * dy;
}

bool cmpd(array<int, 5> a, array<int, 5> b) {
	return getDis(a[0], a[1]) < getDis(b[0], b[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, m, p, r;
    cin >> x >> y >> p >> r >> n;
    que.push({x, y, 0, p, r});
    stone.push_back({x, y, 0, p, r});
   	rep(i, 1, n + 1) {
   		cin >> x >> y >> m >> p >> r;
   		stone.push_back({x, y, m, p, r});
   	}
   	sort(stone.begin() + 1, stone.end(), cmp);
   	int t = sqrt(n);
   	int len = t ? n / t : n;
   	rep(i, 1, t + 1) {
   		L[i] = (i - 1) * len + 1;
   		R[i] = i * len;
   		M[i] = stone[R[i]][2];
   		sort(stone.begin() + L[i], stone.begin() + R[i] + 1, cmpd);
   	}
   	if (R[t] < n) {
   		L[t + 1] = R[t] + 1;
   		R[++t] = n;
   		M[t] = stone[R[t]][2];
   		sort(stone.begin() + L[t], stone.begin() + R[t] + 1,  cmpd);
   	}
   	int cnt = 0;
   	while (!que.empty()) {
   		auto qt = que.front();
   		que.pop();
   		int k = 0;
   		rep(i, 1, t + 1) {
   			if (M[i] <= qt[3]) {
   				k++;
   			} else {
   				break;
   			}
   		}
   		rep(i, 1, k + 1) {
   			for (int j = L[i]; j <= R[i]; j++) {
	   			if (L[i] <= R[i] && getDis(stone[j][0], stone[j][1]) <= (ll)qt[4] * qt[4]) {
	   				if (!st[L[i]]) {
	   					st[L[i]] = 1;
	   					que.push(stone[L[i]]);
	   					cnt++;
	   				}
	   				L[i]++;
	   			}
	   		}
   		}
   		if (++k <= t) {
   			for (int i = L[k]; i <= R[k]; i++) {
   				if (!st[i] && stone[i][2] <= qt[3] && getDis(stone[i][0], stone[i][1]) <= (ll)qt[4] * qt[4]) {
   					que.push(stone[i]);
   					cnt++;
   					st[i] = true;
   				}
   			}
   		}
   	}
   	cout << cnt << "\n";

    return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */