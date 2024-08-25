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
const int mod = 999971;
const db eps = 1e-5;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

struct node {
    double z[510];
    int c;
    bool operator < (const node &b) const {
        return c < b.c;
    }
}a[510];
int p[510];
int n, m;
int ans, cnt;

void gauss() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (fabs(a[i].z[j]) > eps) {
                if (!p[j]) {
                    p[j] = i;
                    ans += a[i].c;
                    cnt++;
                    break;
                } else {
                    double delta = a[i].z[j] / a[p[j]].z[j];
                    for (int k = j; k <= m; k++) {
                        a[i].z[k] -= a[p[j]].z[k] * delta;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i].z[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c;
    }
    sort(a + 1, a + n + 1);
    gauss();
    cout << cnt << " " << ans << "\n";

    return 0;
}