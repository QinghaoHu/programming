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
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 70;

int n;
int a[N], v[N], len, cnt;

bool dfs(int stick, int cab, int last) {
    if (stick > cnt) {
        return true;
    }
    if (cab == len) {
        return dfs(stick + 1, 0, 1);
    }
    int fail = 0;
    rep(i, last, n + 1) {
        if (a[i] != fail && cab + a[i] <= len && !v[i]) {
            v[i] = 1;
            if (dfs(stick, cab + a[i], i + 1)) return true;
            fail = a[i];
            v[i] = 0;
            if (cab == 0 || cab + a[i] == len) {
                return false;
            }
        }
    }
    return false;
}

void solve() {
    memset(a, 0, sizeof a);
    memset(v, 0, sizeof v);
    int sum = 0, val = INT_MIN;
    rep(i, 1, n + 1) {
        cin >> a[i];
        sum += a[i], val = max(val, a[i]);
    }
    auto cmp = [&](int a, int b) -> bool {
        return a > b;
    };
    sort(a + 1, a + n + 1, cmp);
    for (len = val; len <= sum; len++) {
        if (sum % len) {
            continue;
        }
        cnt = sum / len;
        memset(v, 0, sizeof v);
        if (dfs(1, 0, 1)) break;
    }
    cout << len << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n, n) {
        solve();
    }

    return 0;
}
