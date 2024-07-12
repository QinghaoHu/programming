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
class binlTree {
public:
    int t;
    vector<T> heap;

    binlTree(int n) : t(0), heap(n) {}

    void up(int p) {
        while (p > 1 && heap[p] < heap[p / 2]) {
            swap(heap[p], heap[p / 2]);
            p /= 2;
        }
    }

    void push(T val) {
        heap[++t] = val;
        up(t);
    }

    T top() const {
        return heap[1];
    }

    void down(int p) {
        int s = p * 2;
        while (s <= t) {
            if (s < t && heap[s] > heap[s + 1]) s++;
            if (heap[s] < heap[p]) {
                swap(heap[s], heap[p]);
                p = s;
                s = p * 2;
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
        up(k);
        down(k);
    }

    int size() {
        return t;
    }
};

const int N = 10010;

int n;
int a[N];
ll res;

void solve() {
    cin >> n;
    binlTree<int> b(N);
    rep(i, 0, n) {
        cin >> a[i];
        b.push(a[i]);
    }
    while(b.size() != 1) {
        auto c = b.top(); b.pop();
        auto d = b.top(); b.pop();
        res += c + d;
        b.push(c + d);
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    rep(t, 0, T) {
        solve();
    }

    return 0;
}
