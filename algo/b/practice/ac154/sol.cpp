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

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

void solve() {
    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    int front = 0, rear = -1;
    rep(i, 1, n + 1) {
        while (front <= rear && a[q[rear]] >= a[i]) {
            rear--;
        }
        q[++rear] = i;
        if (q[front] <= i - k) {
            front++;
        }
        if (i >= k) {
            cout << a[q[front]] << " ";
        }
    }
    cout << endl;
    front = 0, rear = -1;
    rep(i, 1, n + 1) {
        while (front <= rear && a[q[rear]] <= a[i]) {
            rear--;
        }
        q[++rear] = i;
        if (q[front] <= i - k) {
            front++;
        }
        if (i >= k) {
            cout << a[q[front]] << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
