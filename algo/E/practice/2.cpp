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

const int N = 510, M = 2010;
int n, m;
int p[N], d[N];
int f[N];

struct node {
	int a, b;
	char c;
} jud[M];

int find(int x) {
	if (x != p[x]) {
		int root = find(p[x]);
		d[x] = (d[x] + d[p[x]]) % 3;
		p[x] = root;
	}
	return p[x];
}

bool check(int j) {
	int a = jud[j].a, b = jud[j].b;
	int t = 1;
	if (jud[j].c == '=') {
		t = 0;
	} else if (jud[j].c == '>') {
		swap(a, b);
	}
	int pa = find(a), pb = find(b);
	if (pa == pb) {
		if (d[a] != (d[b] + t + 3) % 3) {
			return false;
		}
	} else {
		p[pa] = p[b];
		d[pa] = (d[b] - d[a] + t + 3) % 3;
	}
	return true;
}

void solve(int n, int m) {
	rep(i, 1, m + 1) {
		cin >> jud[i].a >> jud[i].c >> jud[i].b;
	}
	memset(f, 0, sizeof f);
	int cnt = 0, num = 0;
	rep(i, 0, n) {
		bool isC = true;
		rep(j, 0, n) {
			p[j] = j;
			d[j] = 0;
		}
		rep(j, 1, m + 1) {
			if (jud[j].a != i && jud[j].b != i && !check(j)) {
				f[i] = j;
				isC = false;
				break;
			}
		}
		if (isC) {
			cnt++;
			num = i;
		}
	}
	if (!cnt) {
		cout << "Impossible\n";
	} else if (cnt > 1) {
		cout << "Can not determine\n";
	} else {
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (i != num)
				res = max(res, f[i]);
		}
		cout << "Player " << num << " can be determined to be the judge after " << res << " lines\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
    	solve(n, m);
    }

    return 0;
}