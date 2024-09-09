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

int n, m;
VI a, fa;
vector<arr<int, 3>> query;

int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int l, r;
        string str;
        cin >> l >> r >> str;
        int ans = (str[0] == 'o' ? 1 : 0);
        query.pb({l, r, ans});
        a.pb(l - 1);
        a.pb(r);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    for (int i : a) {
        cerr << i << " ";
    }
    cerr << "\n";

    n = SZ(a);
    fa.assign(2 * n + 1, 0);
    iota(all(fa), 0);

    cerr << n << "\n";
    rep(i, 0, m) {
        int x = lower_bound(all(a), query[i][0] - 1) - a.begin();
        int y = lower_bound(all(a), query[i][1]) - a.begin();
        int x_odd = x, x_even = x + n;
        int y_odd = y, y_even = y + n;
        if (query[i][2] == 0) {
            if (find(x_odd) == find(y_even)) {
                cout << i << " \n";
                return 0;
            }
            fa[find(x_odd)] = find(y_odd);
            fa[find(x_even)] = find(y_even);
        } else {
            if (find(x_odd) == find(y_odd)) {
                cout << i << "\n";
                return 0;
            }
            fa[find(x_odd)] = find(y_even);
            fa[find(x_even)] = find(y_odd);
        }
    }
    cout << m << "\n";

    return 0;
}