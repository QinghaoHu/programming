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
const ll INF = 1 << 29;
ll powmod(ll a, ll b) {ll res = 1; for (; b; b>>=1){if (b&1) res=res*a; a=a*a;}return res;}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a%b); }

const int N = 14;
int T, n, m, r[N][N];
pair<ll, ll> f[1 << N][N][N];
int a[N];
pair<ll, ll> ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
    	cin >> n >> m;
    	int sum = 0;
    	rep(i, 0, n) {
    		cin >> a[i];
    		sum += a[i];
    	}
    	memset(r, 0, sizeof r);
    	rep(i, 0, m) {
    		int x, y; cin >> x >> y;
    		x--; y--;
    		r[x][y] = r[y][x] = a[x] * a[y];
    	}
    	ans = mp(0, 0);
    	memset(f, 0x8c, sizeof f);
    	rep(i, 0, n) {
    		f[1 << i][i][n] = mp(0, 1);
    	}
        rep(i, 0, (1 << n)) {
            for (int j = 0; j < n; j++) {
                if (!(i >> j & 1)) continue;
                int ij = i ^ (1 << j);
                for (int k = 0; k < n; k++) {
                    if (!r[k][j]) continue;
                    if (!(ij >> k & 1)) continue;
                    int ijk = ij ^ (1 << k) ^ (1 << n);
                    rep(l, 0, n + 1) {
                        if (!(ijk >> l & 1)) continue;
                        int tmp = f[ij][k][l].first + r[k][j] + (r[j][l] ? r[j][l] * a[k] : 0);
                        if (f[i][j][k].first < tmp) {
                            f[i][j][k].first = tmp;
                            f[i][j][k].second = f[ij][k][l].second;
                        } else if (f[i][j][k].first == tmp) {
                            f[i][j][k].second += f[ij][k][l].second;
                        }
                    }
                }
            }
        }
        rep(j, 0, n) {
            rep(k, 0, n) {
                if (ans.first < f[(1 << n) - 1][j][k].first) {
                    ans = f[(1 << n) - 1][j][k];
                } else if (ans.first == f[(1 << n) - 1][j][k].first) {
                    ans.second += f[(1 << n) - 1][j][k].second;
                }
                // cerr << ans.second << ' ';
            }
            // cerr << '\n';
        }
        if (ans.second == 0) {
            cout << "0 0" << '\n';
            continue;
        }
        cout << ans.first + sum << ' ' << ans.second / 2 << '\n';
    }
    return 0;
}
