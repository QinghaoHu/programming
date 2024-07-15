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
typedef pair<ll, int> PLI;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

string minp(string str) {
    string a;
    a.assign(all(str));
    a += str;
    int i = 0, j = 1, k;
    int n = SZ(str);
    while (i < n && j < n) {
        for (k = 0; a[i + k] == a[j + k]; k++);
        if (k == n) {
            break;
        }
        if (a[i + k] > a[j + k]) {
            i = i + k + 1;
        } else if (a[i + k] < a[j + k]) {
            j = j + k + 1;
        }
        if (i == j) {
            j += 1;
        }
    }
    int s = min(i, j);
    rep(i, 0, n) {
        str[i] = a[s + i];
    }
    return str;
}

void solve() {
    string a, b;
    cin >> a >> b;
    a = minp(a), b = minp(b);
    if (a == b) {
        cout << "Yes" << endl;
        cout << a << endl;
    } else {
        cout << "No" << endl;
    }
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
