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

const ll mod = 11380;
const double eps = 1e-9;
const int INF = 1061109567;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int L1, L2, L3, D; cin >> L1 >> L2 >> L3 >> D;
    int f[31][11][11][11] {};
    for (int i = 0; i <= D; i++) f[i][0][0][0] = 1;
    for (int i = 1; i <= D; i++) {
        for (int j = 0; j <= L1; j++) {
            for (int k = 0; k <= L2; k++) {
                for (int l = 0; l <= L3; l++) {
                    if (j > 0) {
                        for (int p = 1; p <= j; p++) {
                            for (int q = 0; q <= k; q++) {
                                for (int r = 0; r <= l; r++) {
                                    f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][p - 1][q][r] * f[i][j - p][k - q][l - r]) % mod;
                                }
                            }
                        }
                    }

                    if (k > 0) {
                        for (int q = 1; q <= k; q++) {
                            for (int r = 0; r <= l; r++) {
                                f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][0][q - 1][r] * f[i][j][k - q][l - r]) % mod;
                            }
                        }
                    }

                    if (l > 0) {
                        for (int r = 1; r <= l; r++) {
                            f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][0][0][r - 1] * f[i][j][k][l - r]) % mod;
                        }
                    }
                }
            }
        }
    }

    cout << (f[D][L1][L2][L3] - (D ? f[D - 1][L1][L2][L3] : 0) + mod) % mod << '\n';

    return 0;
}
