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

const int N = 100010;

int n;
int snows[N][6], idx[N];

void get_min(int *a) {
    int b[12];
    rep(i, 0, 12) {
        b[i] = a[i % 6];
    }
    int i = 0, j = 1, k;
    int ans = 0;
    while(i < 6 && j < 6) {
        for (k = 0; k < 6 && b[i + k] == b[j + k]; k++);
            if (k == 6) break;
        if (b[i + k] > b[j + k]) {
            i += k + 1;
            if (i == j) j++;
        } else if (b[i + k] < b[j + k]) {
            j += k + 1;
            if (i == j) j++;
        }
    }
    ans = min(i, j);
    rep(i, 0, 6) {
        a[i] = b[ans + i];
    }
}

bool cmp(int a, int b) {
    rep(i, 0, 6) {
        if (snows[a][i] > snows[b][i]) {
            return false;
        } else if (snows[a][i] < snows[b][i]) {
            return true;
        }
    }
    return false;
}

bool cmp_array(int *a, int *b) {
    rep(i, 0, 6) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    int snow[6], resnow[6];
    rep(i, 0, n) {
        rep(j, 0, 6) {
            cin >> snow[j];
        }
        rep(j, 0, 6) {
            resnow[5 - j] = snow[j];
        }
        get_min(snow);
        get_min(resnow);
        if (cmp_array(snow, resnow))
            memcpy(snows[i], snow, sizeof snow);
        else
            memcpy(snows[i], resnow, sizeof resnow);
        idx[i] = i;
    }
    sort(idx, idx + n, cmp);
    bool duplicate = false;
    rep(i, 1, n) {
        if (!cmp(idx[i], idx[i - 1]) && !cmp(idx[i - 1], idx[i])) {
            duplicate = true;
            break;
        }
    }
    cout << (duplicate ? "Twin snowflakes found." : "No two snowflakes are alike.") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
