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

const int N = 800010;
int n;
int L, ans[N] {};
array<int, 4> a[N], tmp[N];

template <typename T>
struct BIT {
    int size;
    std::vector<T> a;

    BIT(): size(N), a(N, 0) {}
    BIT(int x): size(x), a(x + 1, 0) {}

    void modify(int x, T s) {
        for (; x <= size; x += (x & -x)) {
            a[x] += s;
        }
    }

    T query(int x) {
        T s{};
        for (; x; x -= (x & -x)) {
            s += a[x];
        }
        return s;
    }

    T rangeSum(int x, int y) {
        return query(y) - query(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L;
    BIT<int> c(L);
    int q = 0, t = 0;

    function<void(int, int)> cdq = [&](int l, int r) {
        if (l == r) return;
        int mid = (l + r) >> 1;
        cdq(l, mid);
        cdq(mid + 1, r);
        int p1 = l, p2 = mid + 1;
        int p3 = 0;
        while (p1 <= mid || p2 <= r) {
            if (p2 > r || (p1 <= mid && mp(a[p1][0], a[p1][1]) <= mp(a[p2][0], a[p2][1]))) {
                if (a[p1][3] == 0) {
                    c.modify(a[p1][1], a[p1][2]);
                }
                tmp[p3++] = a[p1++];
            } else {
                if (a[p2][3] != 0) {
                    ans[a[p2][2]] += a[p2][3] * c.query(a[p2][1]);
                }
                tmp[p3++] = a[p2++];
            }
        }
        for (int i = l; i <= mid; i++) {
            if (a[i][3] == 0) {
                c.modify(a[i][1], -a[i][2]);
            }
        }
        rep(i, 0, p3) {
            a[l + i] = tmp[i];
        }
    };

    while (true) {
        int op;
        cin >> op;
        if (op == 3) break;
        if (op == 1) {
            int x, y, A;
            cin >> x >> y >> A;
            a[t++] = {x, y, A, 0};
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            a[t++] = {x2, y2, q, 1};
            a[t++] = {x1 - 1, y1 - 1, q, 1};
            a[t++] = {x2, y1 - 1, q, -1};
            a[t++] = {x1 - 1, y2, q, -1};
            q++;
        }
    }
    cdq(0, t - 1);
    rep(i, 0, q) {
        cout << ans[i] << "\n";
    }

    return 0;
}