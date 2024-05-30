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

int res = 0;

void mergeSort(int l, int s, vector<int> &arr) {
    if (l >= s) return;
    int mid = (l + s) >> 1;
    mergeSort(l, mid, arr);
    mergeSort(mid + 1, s, arr);
    int i = l, j = mid + 1;
    int cnt = 0; 
    vector<int> c(s - l + 1, 0);
    while(i <= mid && j <= s) {
        if (arr[i] <= arr[j]) {
            c[cnt++] = arr[i++];
        } else {
            c[cnt++] = arr[j++];
            res += (mid - i + 1);
        }
    }
    while(j <= s) {
        c[cnt++] = arr[j++];
    }
    while(i <= mid) {
        c[cnt++] = arr[i++];
    }
    for (int i = 0; i < cnt; i++) {
        arr[l + i] = c[i];
    }
}

void solve() {
    int n;
    while(cin >> n && n) {
        int s = n * n;
        vector<int> sam(s - 1, 0);
        vector<int> tar(s - 1, 0);
        int x = 0, y = 0;
        for (int i = 0; i < s; i++) {
            int t;
            cin >> t;
            if (!t)
                continue;
            sam[x++] = t;
        }
        for (int i = 0; i < s; i++) {
            int t;
            cin >> t;
            if (!t)
                continue;
            tar[y++] = t;
        }
        mergeSort(0, s - 2, sam);
        int k = res; res = 0;
        mergeSort(0, s - 2, tar);
        int kj = res; res = 0;
        // cout << k << " " << kj << endl;
        if (abs(k - kj) % 2 == 0)
            cout << "TAK" << endl;
        else 
            cout << "NIE" << endl;
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
