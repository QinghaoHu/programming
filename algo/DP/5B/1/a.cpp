#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define SZ(x) ((int)x.size())

struct Node {
    int x, l, r;
};

void solve() {
    int n, l, p; cin >> n >> l >> p;
    vector<string> ad(n + 1);
    vector<ll> s(n + 1, 0);
    vector<Node> q(n + 2, Node{});
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        ad[i] = str;
        s[i] = str.length() + s[i - 1];
    }
    long double f[100006] {};
    int L = 1, R = 1;
    q[1].x = 0, q[1].l = 1, q[1].r = n;

    auto get = [&](int i, int l, int r) -> int {
        int ans = 0; 
        while (l <= r) {
            int mid = l + r >> 1;
            if (q[mid].l <= i && q[mid].r >= i) {
                ans = mid;
                break;
            }
            if (i >= q[mid].l) l = mid + 1;
            else r = mid - 1;
        }
        return q[ans].x;
    };

    auto calc = [&](int i, int j) -> long double {
        long double ans = 1, num = abs((long double)(s[i] - s[j] + i - j - 1 - l));
        for (int i = 1; i <= p; i++) ans *= num;
        return ans + f[j];
    };

    auto insert = [&](int i) -> void {
        int w = -1;
        while (L <= R) {
           if (calc(q[R].l, q[R].x) >= calc(q[R].l, i)) w = q[R--].l;
           else {
               if (calc(q[R].r, q[R].x) > calc(q[R].r, i)) {
                   int ls = q[R].l, rs = q[R].r;
                   while (ls < rs) {
                       int mid = ls + rs >> 1;
                       if (calc(mid, q[R].x) < calc(mid, i)) ls = mid + 1;
                       else rs = mid;
                   }
                   q[R].r = ls - 1;
                   w = ls;
               }
               break;
           }
        }
        if (w != -1) {
            q[++R].x = i;
            q[R].l = w;
            q[R].r = n;
        }
    };

    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int j = get(i, L, R);
        f[i] = calc(i, j);
        pos[i] = j;
        while (L <= R && q[L].r <= i) ++L;
        q[L].l = i + 1;
        insert(i);
    }
    if (f[n] > 1e18) cout << "Too hard to arrange" << '\n';
    else {
        cout << (ll)f[n] << '\n';
        int k = n;
        vector<string> ans;
        bool st = true;
        while (st) {
            string str = "";
            for (int i = pos[k] + 1; i <= k; i++) {
                str += ad[i];
                if (i != k) str += " ";
                if (i == 1) st = false;
            }
            k = pos[k];
            ans.push_back(str);
        }
        reverse(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << '\n';
        }
    }
    for (int i = 1; i <= 20; i++) {
        cout << '-';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
