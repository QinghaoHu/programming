#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#if !defined(ONLINE_JUDGE) && defined(LOCAL)
#include "helper.h"
#else
#define dbg(...) ;
#define local_go_m(x) int c;cin>>c;while(c--)x()
#endif

template<typename T>
bool cmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template<typename T>
bool cmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

void go() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int K = 0;
    if (n > m) {
        swap(n, m);
        swap(a, b);
    }
    dbg(a);
    dbg(b);
    if (n * 2 < m) K = n;
    else K = (n + m) / 3;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    vector<i64> as(1, 0), bs(1, 0);
    for (int i = 0; i < n; i++) {
        if (i < n - 1 - i) {
            as.push_back(a[n - 1 - i] - a[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (i < m - 1 - i) {
            bs.push_back(b[m - 1 - i] - b[i]);
        }
    }
    vector<i64> asp(as.size(), 0), bsp(bs.size(), 0);
    for (int i = 1; i < as.size(); i++) {
        asp[i] = asp[i - 1] + as[i];
    }
    for (int i = 1; i < bs.size(); i++) {
        bsp[i] = bsp[i - 1] + bs[i];
    }
    dbg(as);
    dbg(bs);
    int ai = 0, bi = 0;
    auto calc = [&](int la, int lb, int tot) -> i64 {
        dbg(la, lb, tot);
        ai = min(la, ai);
        bi = min(lb, bi);
//        dbg(ai, bi);
        while (ai + bi < tot) {
            if (ai == la || ai + 1 >= as.size()) bi++;
            else if (bi == lb || bi + 1 >= bs.size()) ai++;
            else {
                if (as[ai + 1] > bs[bi + 1]) ai++;
                else bi++;
            }
        }
//        dbg(ai, bi);
        while (ai + bi > tot) {
            if (ai == 0) bi--;
            else if (bi == 0) ai--;
            else {
                if (as[ai] > bs[bi]) bi--;
                else ai--;
            }
        }
//        dbg(ai, bi);
        return asp[ai] + bsp[bi];
    };
    vector<i64> ans(K);
    for (int i = 1; i <= K; i++) {
        if (i * 2 <= n) {
            ans[i - 1] = calc(i, i, i);
        } else {
            ans[i - 1] = calc(n - i, min(m - i, m / 2), i);
        }
    }
    cout << K << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    local_go_m(go);
    return 0;
}