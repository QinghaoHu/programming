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
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

int n;
queue<PII> waits;
set<PII> runs;
priority_queue<PII, vector<PII>, greater<PII> > endts;
int mt, cnt;

bool give(int t, int m, int p) {
    for (auto it = runs.begin(); it != runs.end(); it++) {
        auto jt = it;
        jt++;
        if (jt != runs.end()) {
            if (m <= jt->first - (it->first + it->second - 1) - 1) {
                int start = it->first + it->second;
                runs.insert(mp(start, m));
                endts.push(mp(t + p, start));
                return true;
            }
        }
    }
    return false;
}

void finish(int t) {
    while(endts.size() && endts.top().first <= t) {
        int f = endts.top().fi;
        while(endts.size() && endts.top().fi == f) {
            auto top = endts.top();
            endts.pop();
            auto it = runs.lower_bound({top.se, 0});
            runs.erase(it);
        }

        mt = f;

        while(waits.size()) {
            auto front = waits.front();
            if (give(f, front.fi, front.se)) {
                waits.pop();
            } else {
                break;
            }
        }
    }
}

void solve() {
    cin >> n;
    int t, m, p;

    runs.insert(mp(-1, 1)), runs.insert({n, 1});

    while(cin >> t >> m >> p, t || m || p) {
        finish(t);
        if (!give(t, m, p)) {
            waits.push(mp(m, p));
            cnt ++;
        }
    }

    finish(2e9);

    cerr << mt << endl << cnt << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
