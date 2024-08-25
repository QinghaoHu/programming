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
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int B = 60;

struct linear_basis {
    ll num[B + 1] {};
    bool insert(ll x) {
        for (int i = B - 1; i >= 0; i--) {
            if (x & (1ll << i)) {
                if (num[i] == 0) {
                    num[i] = x;
                    return true;
                } else {
                    x ^= num[i];
                }
            }
        }
        return false;
    }

    ll queryMin(ll x) {
        for (int i = 59; i >= 0; i--) {
            x = min(x, x ^ num[i]);
        }
        return x;
    }

    ll queryMax(ll x) {
        for (int i = 59; i >= 0; i--) {
            x = max(x, x ^ num[i]);
        }
        return x;
    }
};

int main() {
    int n;
    ll k;
    cin >> n >> k;
    int zero = 0;
    linear_basis T;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (!T.insert(x)) {
            zero++;
        }
    }
    k >>= zero;
    vector<ll> num;
    for (int i = 0; i <= B - 1; i++) {
        if (T.num[i] != 0) {
            num.push_back(T.num[i]);
        }
    }
    int m = num.size();
    ll x = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (k & (1ll << i)) {
            x = max(x, x ^ num[i]);
        } else {
            x = min(x, x ^ num[i]);
        }
    }
    cout << x << "\n";
}