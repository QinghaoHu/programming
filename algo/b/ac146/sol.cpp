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
typedef double db; typedef long double ld;
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

template <typename T>
class binlTree {
public:
    int t;
    vector<T> heap;
    binlTree(int n) {
        heap.resize(n);
        t = 0;
    }

    void up(int p) {
        while(p > 1) {
            if (heap[p] < heap[p / 2]) {
                swap(heap[p], heap[p / 2]);
                p /= 2;
            } else {
                break;
            }
        }
    }

    void push(T val) {
        heap[++t] = val;
        up(t);
    }

    T top() {
        return heap[1];
    }

    void down(int p) {
        int s = p * 2;
        while(s <= t) {
            if (s < t && heap[s] > heap[s + 1]) s++;
            if (heap[s] < heap[p]) {
                swap(heap[s], heap[p]);
                p = s, s = p * 2;
            } else {
                break;
            }
        }
    }

    void pop() {
        heap[1] = heap[t--];
        down(1);
    }

    void erase(int k) {
        heap[k] = heap[t--];
        up(k), down(k);
    }
};

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> r(n, 0);
    for (auto &i : r) {
        cin >> i;
    }
    sort(all(r));
    rep(i, 1, m) {
        binlTree<PII> t(n * m);
        vector<int> b(n, 0);
        for (auto &j : b) {
            cin >> j;
        }
        for (auto j : b) {
            t.push(mp(r[0] + j, 0));
        }
        vector<int> c(n, 0);
        rep(j, 0, n) {
            auto s = t.top();
            t.pop();
            c[j] = s.fi;
            if (s.se < n - 1) {
                t.push(mp(s.fi - r[s.se] + r[s.se + 1], s.se + 1));
            }
        }
        r.assign(all(c));
    }
    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
