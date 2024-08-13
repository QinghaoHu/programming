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
#define arr array
#define VI vector<int>
#define SZ(x) ((int) x.size())
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

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1010;

int n;

void solve() {
    cin >> n;
    auto get_phi = [&](int n) -> int {
        VI v(n + 1, 0), prime, phi(n + 1, 0);
        phi[1] = 1;
        rep(i, 2, n + 1) {
            if (!v[i]) {
                v[i] = i;
                prime.pb(i);
                phi[i] = i - 1;
            }
            for (auto j : prime) {
                if (j > v[i] || j > n / i) {
                    break;
                }
                v[i * j] = j;
                phi[i * j] = (i % j == 0 ? j * phi[i] : (j - 1) * phi[i]);
            }
        }
        int res = 0;
        for (auto ph : phi) {
            cout << ph << " ";
        }
        cerr << "\n";

        return res;
    };
    int k = get_phi(n);
    cout << k << " \n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
