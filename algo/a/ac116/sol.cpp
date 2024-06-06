#include <csignal>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#define f first
#define s second

using namespace std;
using ll = long long;

char g[4][4];
char test[4][4];

pair<int, int> get(int n) {
    return {n / 4, n % 4};
}

void t(int x, int y) {
    if (test[x][y] == '-') {
        test[x][y] = '+';
    } else {
        test[x][y] = '-';
    }
}

void change(int x, int y) {
    t(x, y);
    for (int i = 0; i < 4; i++) {
        if (i != y) 
            t(x, i);
        if (i != x) 
            t(i, y);
    }
}

void solve() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> g[i][j];
        }
    }
    vector<pair<int, int> > ans, tempt;
    for (int op = 0; op < 1 << 16; op++) {
        memcpy(test, g, sizeof g);
        for (int i = 0; i < 16; i++) {
            if (op >> i & 1) {
                auto pos = get(i);
                change(pos.f, pos.s);
                tempt.push_back({pos.f + 1, pos.s + 1});
            }
        }
        bool isT = true;
        for (int i = 0; i < 4 && isT; i++) {
            for (int j = 0; j < 4 && isT; j++) {
                if (test[i][j] == '+') {
                    isT = false;
                    break;
                }
            }
        }
        if (isT && (tempt.size() < ans.size() || ans.empty())) {
            ans = tempt;
        }
        tempt.clear();
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.f << " " << i.s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie (nullptr);

    int T = 1;
    //cin >> T;

    while(T --) {
        solve();
    }

    return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
