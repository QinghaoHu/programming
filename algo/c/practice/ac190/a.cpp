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

string A, B;
vector<pair<string, string>> roleA, roleB;

int extend(queue<string> &q, unordered_map<string, int> &da, unordered_map<string, int> &db, vector<pair<string, string>> rule) {
    int d = da[q.front()];
    while (!q.empty() && da[q.front()] == d) {
        auto t = q.front();
        q.pop();
        rep(i, 0, SZ(t)) {
            for (auto j : rule) {
                if (i + SZ(j.fi) <= SZ(t) && t.substr(i, SZ(j.fi)) == j.fi) {
                    string state = t.substr(0, i) + j.se + t.substr(i + j.fi.size());
                    if (db.count(state)) {
                        return db[state] + da[t] + 1;
                    } else if (da.count(state)) {
                        continue;
                    }
                    da[state] = da[t] + 1;
                    q.push(state);
                }
            }
        }
    }
    return 11;
}

int bfs() {
    if (A == B) return 0;
    queue<string> qa, qb;
    unordered_map<string, int> da, db;
    da[A] = 0, db[B] = 0;
    qa.push(A), qb.push(B);
    int step = 0;
    while (!qa.empty() && !qb.empty()) {
        int t = 0;
        if (qa.size() <= qb.size()) {
            t = extend(qa, da, db, roleA);
        } else {
            t = extend(qb, db, da, roleB);
        }
        if (t <= 10) {
            return t;
        }
        if(++step == 10) return 11;
    }
    return 11;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B;
    string a, b;
    while (cin >> a >> b) {
        roleA.pb(mp(a, b));
        roleB.pb(mp(b, a));
    }
    int t = bfs();
    if (t > 10) {
        cout << "NO ANSWER!\n";
    } else {
        cout << t << " \n";
    }

    return 0;
}