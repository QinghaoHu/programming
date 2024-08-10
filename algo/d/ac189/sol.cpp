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
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;

const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

int n;
arr<int, 9> pu{{2, 3, 5, 7, 11, 13, 17, 19, 23}};
int sum, minx;

void dfs(int u, int last, int p, int s) {
    if (u == 9) {
        return;
    }
    if (s > sum || (s == sum && p < minx)) {
        sum = s;
        minx = p;
    }
    rep(i, 1, last + 1) {
        if ((ll) p * pu[u] > n) {
            break;
        }
        p *= pu[u];
        dfs(u + 1, i, p, s * (i + 1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(0, 30, 1, 1);
    cout << minx << "\n";

    return 0;
}