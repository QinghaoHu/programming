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

const int mod = 9901;

int qmi (int a, int k) {
    int ans = 1; a %= mod;
    for (; k; k >>= 1) {
        if (k & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
    }
    return ans;
}

int sum (int p, int k) {
    if (k == 0) return 1;
    if (k % 2 == 0) return (p % mod * sum(p, k - 1) % mod + 1) % mod;
    return sum(p, k / 2) % mod * (1 + qmi(p, k / 2 + 1)) % mod;
}


void solve() {
    int A, B;
    cin >> A >> B;

    int res = 1;
    for (int i = 2; i <= A; i ++ )
    {
        int s = 0;
        while (A % i == 0)
        {
            s ++ ;
            A /= i;
        }

        if (s) res = res * sum(i, s * B) % mod;
    }

    if (!A) res = 0;
    cout << res << endl;
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
