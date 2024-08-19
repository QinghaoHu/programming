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
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

ll f[70], d[70][70], e[70][70][70];
char b[20][20], s[100];
int n, m, t, act, p, a[20][20], c[20][20];

int num(int i, int j) {
    return (i - 1) * m + j;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> t >> act;
    for (int i = 1; i <= n; i++) {
        cin >> s + 1;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j] - '0' + 1;
        }
    }
    for (int i = 1; i <= act; i++) {
        cin >> b[i];
    }
    p = n * m + 1;
    for (int k = 1; k <= 60; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = a[i][j], y = c[i][j];
                if (b[x][y] >= '0' && b[x][y] <= '9') {

                }
            }
        }
    }

    return 0;
}