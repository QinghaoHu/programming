#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a; i<n; i++)
#define per(i,a,n) for (int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) (int)((x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f;
ll powmod(ll a,ll b) {ll res = 1; for (; b; b>>=1){if (b&1) res=res*a; a=a*a;}return res;}
ll gcd(ll a,ll b) { return !b ? a : gcd(b, a%b); }
//head
const int N = 2010;
int n, k;
ll f[N][26], a[N];
ll cost[N][N];

void solve() {
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) {
        priority_queue<int, vector<int>, greater<int>> mins;
        priority_queue<int, vector<int>, less<int>> maxs;
        int suml = 0, sumr = 0;
        rep(j, i, n + 1) {
            maxs.push(a[j]); suml += a[j];
            while (maxs.size() > (j - i + 1) / 2 + 1) {
                sumr += maxs.top(); suml -= maxs.top();
                mins.push(maxs.top());
                maxs.pop();
            }
            while (!mins.empty() && mins.top() < maxs.top()) {
                int a = mins.top(), b = maxs.top();
                suml -= maxs.top(), suml += mins.top();
                sumr -= mins.top(), sumr += maxs.top();
                mins.push(b), maxs.push(a);
            }
            int mid = maxs.top();
            cost[i][j] = (maxs.size() * mid - suml) + (sumr - mins.size() * mid);
        }
    }
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    rep(p, 1, k + 1) {
        rep(i, 1, n + 1) {
            rep(j, 0, i) {
                f[i][p] = min(f[i][p], f[j][p - 1] + cost[j + 1][i]);
            }
        }
    }
    cout << f[n][k] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while (cin >> n >> k, n != 0 || k != 0) {
        solve();
    }
    return 0;
}
