#include <bits/stdc++.h>
#include <string>
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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

void solve() {
    string result = "12345678x";
    string start, seq;
    rep(i, 0, 9) {
        char n;
        cin >> n;
        start.pb(n);
        if (n != 'x') {
            seq.pb(n);
        }
    }
    int cnt = 0;
    rep(i, 0, SZ(seq)) {
        rep(j, i, 8) {
            if (seq[i] > seq[j]) {
                cnt++;
            }
        }
    }
    auto f = [&](string state) {
        int res = 0;
        rep(i, 0, SZ(state)) {
            if (state[i] != 'x') {
                int t = state[i] - '1';
                res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
            }
        }
        return res;
    };
    auto bfs = [&](string start) -> string {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;
        unordered_map<string, int> dist;
        unordered_map<string, pair<string, char> > prev;
        heap.push(mp(f(start), start));
        arr<PII, 4> d {{mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)}};
        arr<char, 4> op{{'u', 'r', 'd', 'l'}};
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            string state = t.se;
            if (state == result) {
                break;
            }
            int x, y;
            rep(i, 0, SZ(state)) {
                if (state[i] == 'x') {
                    x = i / 3, y = i % 3;
                    break;
                }
            }
            string source = state;
            rep(i, 0, 4) {
                int a = x + d[i].fi, b = y + d[i].se;
                if (a < 0 || a > 2 || b < 0 || b > 2) {
                    continue;
                }
                swap(state[x * 3 + y], state[a * 3 + b]);
                if (dist.find(state) == dist.end() || dist[state] > dist[source] + 1) {
                    dist[state] = dist[source] + 1;
                    heap.push(mp(dist[state] + f(state), state));
                    prev[state] = mp(source, op[i]);
                }
                state = source;
            }
        }
        string res = "";
        while (result != start) {
            res.pb(prev[result].se);
            result = prev[result].fi;
        }
        reverse(all(res));
        return res;
    };
    if (cnt & 1) {
        cout << "unsolvable\n";
    } else {
        cout << bfs(start) << " \n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}
