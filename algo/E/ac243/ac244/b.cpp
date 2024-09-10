#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i >= n; i--)
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
ll powmod(ll a, ll b, ll p) { ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 1e5 + 10;
int n;
int a[N], c[N], height[N];

int lowbit(int x) {
	return x & -x;
}

int query(int x) {
	int s = 0;
	for (; x; x -= lowbit(x)) {
		s += c[x];
	}
	return s;
}

void modify(int x, int s) {
	for (; x <= n; x += lowbit(x)) {
		c[x] += s;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    modify(1, 1);
    rep(i, 2, n + 1) {
    	cin >> a[i];
    	modify(i, 1);
    }

    rep(i, 1, n + 1) {
    	cout << height[i] << "\n";
    }
    
    return 0;
}
