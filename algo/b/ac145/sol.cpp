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

template <typename T>
class binTree {
public:
    int t;
    vector<T> heap;
    binTree(int n) {
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

    void insert(T val) {
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

    void remove(int k) {
        heap[k] = heap[t--];
        up(k), down(k);
    }

    int size() {
        return t;
    }
};

int n;

void solve() {
    binTree<int> tree(n + 5);
    vector<PII> a;
    auto cmp = [&](PII a, PII b) {
        return a.se < b.se;
    };
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        a.pb(mp(x, y));
    }
    sort(all(a), cmp);
    for (auto i : a) {
        int x = i.fi, y = i.se;
        if (y < tree.size()) {
            tree.insert(x);
        } else {
            while(tree.size() >= y && tree.top() < x) {
                tree.pop();
            }
            if (y > tree.size()) {
                tree.insert(x);
            }
        }
    }
    int ans = 0;
    while(tree.size()) {
        ans += tree.top();
        tree.pop();
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n && n != EOF)
        solve();

    return 0;
}
