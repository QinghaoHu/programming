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

using namespace std;
using ll = long long;

int num(char s) {
    string str1 = "A234567890JQK";
    return str1.find(s) + 1;
}

void solve() {
    vector<char> card[14], back[14];
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 4; j++) {
            char s;
            cin >> s;
            back[i].push_back(s);
        }
        reverse(back[i].begin(), back[i].end());
    }
    //From bottom to height
    for (int i = 0; i < 4; i++) {
        char c = back[13].back();
        back[13].pop_back();
        while(c != 'K') {
            int pos = num(c);
            card[pos].push_back(c);
            if (back[pos].size() == 0) {
                c = card[pos][0];
                card[pos].erase(card[pos].begin());
            } else {
                c = back[pos][0];
                back[pos].erase(back[pos].begin());
            }
        }
    }
    vector<int> cnt(14, 0);
    for (auto i : card) {
        for (auto j : i) {
            cnt[num(j)]++;
        }
    }
    int ans = 0;
    for (int i : cnt) {
        if (i >= 4) ans++;
    }
    cout << ans << endl;
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
