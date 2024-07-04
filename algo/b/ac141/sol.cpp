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
const double eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1e6 + 10;

int s;

void solve() {
    char str[N];
    rep(i, 1, s + 1) {
        cin >> str[i];
    }
    int nxt[N];
    int j = 0; 
    rep(i, 2, s + 1) {
        while(j > 0 && str[j + 1] != str[i]) {
            j = nxt[j];
        }
        if (str[j + 1] == str[i]) {
            j++;
        }
        nxt[i] = j;
    }
    rep(i, 1, s + 1) {
        if (i % (i - nxt[i]) == 0 && i / (i - nxt[i]) > 1) {
            cout << i << " " << i / (i - nxt[i]) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while(cin >> s, s) {
        cout << "Test case #" << T++ << endl;
        solve();
        cout << endl;
    }

    return 0;
}
