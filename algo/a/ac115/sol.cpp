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

const int N = 1010;

int n, root;
struct Node {
    int father, size, sum;
    double avg;
} tree[N];

int find() {
    double avg = 0;
    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (i != root && avg < tree[i].avg) {
            avg = tree[i].avg;
            res = i;
        }
    }
    return res;
}

void solve() {
    cin >> n >> root;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        auto &nd = tree[i];
        cin >> nd.sum;
        nd.size = 1;
        nd.avg = nd.sum;
        ans += nd.sum;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[b].father = a;
    }
    for (int i = 0; i < n - 1; i++) {
        int p = find();
        int father = tree[p].father;
        ans += tree[father].size * tree[p].sum;
        tree[p].avg = -1;
        for (int j = 1; j <= n; j++) {
            if (tree[j].father == p) {
                tree[j].father = father;
            }
        }
        tree[father].sum += tree[p].sum;
        tree[father].size += tree[p].size;
        tree[father].avg = (double)tree[father].sum / tree[father].size;
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
