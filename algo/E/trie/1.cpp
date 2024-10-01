#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;

const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

const int N = 600010, M = N * 25;
int n, m, idx;
int s[N], root[N];
int tr[M][2], max_id[M];

int query(int root, int c, int l) {
    int p = root;
    for (int i = 23; i >= 0; i--) {
        int v = c >> i & 1;
        if (max_id[tr[p][v ^ 1]] >= l) {
            p = tr[p][v ^ 1];
        } else {
            p = tr[p][v];
        }
    }
    return c ^ s[max_id[p]];
}

void insert(int i, int k, int p, int q) {
    if (k < 0) {
        max_id[q] = i;
        return;
    }
    int v = s[i] >> k & 1;
    if (p) {
        tr[q][v ^ 1] = tr[p][v ^ 1];
    }
    tr[q][v] = ++idx;
    insert(i, k - 1, tr[p][v], tr[q][v]);
    max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);
    rep(i, 1, n + 1) {
        int x;
        cin >> x;
        s[i] = s[i - 1] ^ x;
        root[i] = ++idx;
        insert(i, 23, root[i - 1], root[i]);
    }
    while (m--) {
        int l, r, x;
        char op;
        cin >> op;
        if (op == 'A') {
            cin >> x;
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(n, 23, root[n - 1], root[n]);
        } else {
            cin >> l >> r >> x;
            cout << query(root[r - 1], s[n] ^ x, l - 1) << "\n";
        }
    }

    return 0;
}