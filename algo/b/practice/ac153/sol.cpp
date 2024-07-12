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

const int N = 1010;

int n;
int s[N];
stack<int> a, b;
vector<int> r;

void solve() {
    cin >> n;
    rep(i, 0, n) {
        cin >> s[i];
    }
    a.push(s[0]);
    rep(i, 0, n) {
        int t = s[i];
        if (t > a.top() && b.empty()) {
            b.push(t);
        } else if (t > a.top() && t <= b.top()) {
            b.push(t);
        } else if (t <= a.top() && t <= b.top()) {
            int c = a.top() - t, d = b.top() - t;
            if (c <= d) {
                a.push(t);
            } else if (c > d) {
                b.push(t);
            }
        } else if (t > a.top() && t > b.top()) {
            while(!a.empty() && !b.empty()) {
                if (a.top() <= b.top()) {
                    r.pb(a.top());
                    a.pop();
                } else {
                    r.pb(b.top());
                    b.pop();
                }
                if (a.empty() || a.top() >= t) {
                    a.push(t);
                    break;
                }
                if (b.empty() || b.top() >= t) {
                    b.push(t);
                    break;
                }
            }
        }
    }
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
