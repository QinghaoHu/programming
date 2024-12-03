#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

#define _print(x) cerr << x << ' ';
#define _println(x) cerr << x << '\n';

void __print(bool x) {cerr << (!x ? "false" : "true") << " ";}
template<typename T>
void __print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
T gcd(T a, T b) {return !b ? a : gcd(b,a%b);}
template<typename T>
T lcm(T a, T b) {return a/gcd<T>(a, b)*b;}
template<typename T>
T powmod(T a, T b, T p) {T res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}


const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

const int T = 10000;
bool s[105] {};
vector<int> a(106, 0);
bool f[105][20005] {}, g[105][20005] {};

void sign(int i, int j) {
    if (i == 2) {s[1] = false; s[2] = true; return;}
    s[i] = g[i][j + T];
    if (s[i]) sign(i - 1, j + a[i]);
    else sign(i - 1, j - a[i]);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, t; cin >> n >> t;
    FOR(i, 1, n + 1) cin >> a[i];

    auto valid = [&](int x) -> bool {
        return x >= -T && x <= T;
    };
    
    f[2][a[1] - a[2] + T] = true;
    FOR(i, 2, n) {
        FOR(j, -T, T + 1) {
            if (f[i][j + T]) {
                if (valid(j - a[i + 1])) {
                    f[i + 1][j - a[i + 1] + T] = true;
                    g[i + 1][j - a[i + 1] + T] = true;
                }
                if (valid(j + a[i + 1])) {
                    f[i + 1][j + a[i + 1] + T] = true;
                    g[i + 1][j + a[i + 1] + T] = false;
                }
            }
        }
    }

    sign(n, t);

    int merged = 0;
    FOR(i, 2, n + 1) {
        if (!s[i]) {
            cout << i - 1 - merged << '\n';
            merged++;
        }
    }
    FOR(i, 2, n + 1) {
        if (s[i]) cout << 1 << '\n';
    }

    return 0;
}
