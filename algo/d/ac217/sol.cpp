#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int N = 1e5 + 10, M = 2 * N;
int n, m;
vector<pair<int, int>> g[M];

double dp(int u) {
    if (u == n) {
        return 0;
    }
    db val = 0;
    int k = SZ(g[u]);
    for (auto [i, j] : g[u]) {
        val += (j + dp(i)) / k;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(mp(b, c));
    }

    cout << fixed << setprecision(2) << dp(1) << "\n";

    return 0;
}