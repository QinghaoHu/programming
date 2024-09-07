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
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _;
    while (cin >> _ && _ != EOF) {
        vector<PII> prod(_);
        for (auto &i : prod) {
            cin >> i.se >> i.fi;
        }
        sort(all(prod));
        priority_queue<PII, vector<PII>, greater<PII>> q;
        for (auto i : prod) {
            if (i.fi > q.size()) {
                q.push(mp(i.se, i.fi));
            } else {
                if (i.se >= q.top().fi) {
                    q.push(mp(i.se, i.fi));
                }
                q.pop();
            }
        }
        int res = 0;
        while (!q.empty()) {
            res += q.top().fi;
        }
        cerr << res << "\n";
    }

    return 0;
}