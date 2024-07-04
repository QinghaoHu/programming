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

int trie[N][26];
int tot = 1, endts[N];

void solve() {
    int n, m;
    cin >> n >> m;
    auto insertT = [&](char *str) {
        int len = strlen(str), p = 1;
        rep(i, 0, len) {
            if (trie[p][str[i] - 'a'] == 0) {
                trie[p][str[i] - 'a'] = ++tot;
            }
            p = trie[p][str[i] - 'a'];
        }
        endts[p]++;
    };
    auto search = [&](char *str) -> int {
        int len = strlen(str), p = 1;
        int cnt = 0;
        rep(i, 0, len) {
            if (trie[p][str[i] - 'a'] == 0) {
                return cnt;
            } 
            cnt += endts[trie[p][str[i] - 'a']];
            p = trie[p][str[i] - 'a'];
        }
        return cnt;
    };
    rep(i, 0, n) {
        char s[N];
        cin >> s;
        insertT(s);
    }
    rep(i, 0, m) {
        char s[N];
        cin >> s;
        cout << search(s) << endl;
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


