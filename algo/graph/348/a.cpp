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
// head
const int N = 1006;
const double eps = 1e-6;
struct P {
    int x, y, z;
} p[N];
int n;
double a[N][N], c[N][N], b[N][N], d[N];
bool v[N];
double ans;

inline double s(int i, int j) {
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}

double work(double k) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j) c[i][j] = 1e9;
            else c[i][j] = c[j][i] = a[i][j] - k * b[i][j];
        }
    }
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n; i++) d[i] = 1e9;
    d[1] = 0;
    double ans = 0;
    while (1) {
        int x = 0;
        for (int i = 1; i <= n; i++) {
            if (!v[i] && (x == 0 || d[i] < d[x])) x = i;
        }
        if (!x) break;
        v[x] = 1;
        ans += d[x];
        for (int i = 1; i <= n; i++) d[i] = min(d[i], c[x][i]);
    }
    return ans;
}

int main(){
    while (scanf("%d", &n), n) {
        rep(i, 1, n + 1) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        }
        double num = 0;
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                num += (a[i][j] = a[j][i] = abs(p[i].z - p[j].z));
                b[i][j] = b[j][i] = s(i, j);
            }
        }
        double l = 0, r = num;
        while (l + eps <= r) {
            double mid = (l + r) / 2;
            if (work(mid) >= 0) l = mid;
            else r = mid;
        }
        printf("%.3f\n", l);
    }
}