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

const int N = 1e5 + 10;
int n, m;
vector<array<int, 3>> query;
VI a, d, fa;

void read_discerete() {
    cin >> n >> m;
    rep(i, 0, m) {
        int l, r;
        string str;
        cin >> l >> r >> str;
        int ans = (str[0] == 'o' ? 1 : 0);
        query.pb({l, r, ans});
        a.pb(l - 1); a.pb(r);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

int get(int x) {
    if (x != fa[x])
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    read_discerete();
    fa.assign(n + 1, 0); d.assign(n + 1, 0);
    iota(all(fa), 0);
    int i = 1;
    iota(all(fa), 0);
    for (auto t : query) {
        int p = get(t[0]), q = get(t[1]);
        if (p == q) {
            if ((d[t[0]] ^ d[t[1]]) != t[2]) {
                cout << i - 1 << " \n";
                return 0;
            }
        } else {

        }
    }

    return 0;
}