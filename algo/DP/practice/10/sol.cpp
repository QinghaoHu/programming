#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

template<typename T>
void _print(T x) {cerr << x << ' ';}
template<typename T>
void _println(T x) {cerr << x << '\n';}
void _print(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _println(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void _print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
void _println(vector<T>u) {for(auto i : u) _print(i); cerr << '\n';}

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

ll sqr(ll x) {
    return x * x;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int a[9][9] {}, sum[9][9] {};
    FOR(i, 1, 9) {
        FOR(j, 1, 9) {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
        }
    }

    auto rect_sum = [&](int u, int d, int l, int r) -> int {
        return sum[d][r] - sum[u - 1][r] - sum[d][l - 1] + sum[u - 1][l - 1];
    };

    ll f[9][9][9][9][16] {}; // {up, down, left, right}
    memset(f, 0x3f, sizeof(f));
    for (int len_row = 1; len_row <= 8; len_row++) {
        for (int len_col = 1; len_col <= 8; len_col++) {
            for (int u = 1; u <= 8 - len_row + 1; u++) {
                for (int l = 1; l <= 8 - len_col + 1; l++) {
                    int d = u + len_row - 1;
                    int r = l + len_col - 1;
                    f[u][d][l][r][1] = sqr(n * rect_sum(u, d, l, r) - sum[8][8]);
                    for (int cnt = 2; cnt <= n; cnt++) {
                        for (int mid = u; mid < d; mid++) {
                            f[u][d][l][r][cnt] = min(min(f[u][mid][l][r][1] + f[mid + 1][d][l][r][cnt - 1], 
                                        f[u][mid][l][r][cnt - 1] + f[mid + 1][d][l][r][1]), f[u][d][l][r][cnt]);
                        }
                        for (int mid = l; mid < r; mid++) {
                            f[u][d][l][r][cnt] = min(min(f[u][d][l][mid][1] + f[u][d][mid + 1][r][cnt - 1],
                                        f[u][d][l][mid][cnt - 1] + f[u][d][mid + 1][r][1]), f[u][d][l][r][cnt]);
                        }
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(3) << sqrt(f[1][8][1][8][n] * 1.0 / (n * n * n)) << '\n';

    return 0;
}
