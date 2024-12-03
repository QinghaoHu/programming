#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

char ans[82] {};
int f[82][82] {};
vector<char> last[82][82];
int preA[82][26] {}, preB[82][26] {};

void print(int i, int j, int len) {
    if (f[i][j] == 1) {
        ans[len] = 0;
        int k = strlen(ans);
        FOR(i, 0, k) {
            cout << ans[i];
        }
        cout << '\n';
        return;
    }
    for (int k = 0; k < last[i][j].size(); k++) {
        char ck = last[i][j][k];
        ans[len] = ck;
        print(preA[i - 1][ck - 'a'], preB[j - 1][ck - 'a'], len + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string as, bs; cin >> as >> bs;
    string a = " " + as, b = " " + bs;
    int n = as.length(), m = bs.length();
    reverse(a.begin() + 1, a.end());
    reverse(b.begin() + 1, b.end());
    
    FOR(i, 1, n + 1) {
        for (int ch = 0; ch < 26; ch++) preA[i][ch] = preA[i - 1][ch];
        preA[i][a[i] - 'a'] = i;
    }
    FOR(i, 1, m + 1) {
        for (int ch = 0; ch < 26; ch++) preB[i][ch] = preB[i - 1][ch];
        preB[i][b[i] - 'a'] = i;
    }
    a.push_back('~'); n++;
    b.push_back('~'); m++;

    memset(f, 0xcc, sizeof f);
    f[0][0] = 0;
    FOR(i, 1, n + 1) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                for (int ch = 'a'; ch <= 'z'; ch++) {
                    int pa = preA[i - 1][ch - 'a'];
                    int pb = preB[j - 1][ch - 'a'];
                    if (f[pa][pb] + 1 > f[i][j]) {
                        f[i][j] = f[pa][pb] + 1;
                        last[i][j].clear();
                        last[i][j].push_back(ch);
                    } else if (f[pa][pb] + 1 == f[i][j]) {
                        last[i][j].push_back(ch);
                    }
                }
            }
        }
    }

    cerr << 1 << '\n';

    print(n, m, 0);

    return 0;
}
