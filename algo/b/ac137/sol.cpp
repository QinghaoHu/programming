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
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;
typedef pair<double, double> PDD;
const ll mod = 99991;
const db eps = 1e-9;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

struct node {
    int s[6];
};

int n;

vector<node> nodes[N];

int H(int *a) {
    int sum = 0, mul = 1;
    for (int i = 0; i < 6; i++) {
        sum = (sum + a[i]) % mod;
        mul = (ll)mul * a[i] % mod;
    }
    return (sum + mul) % mod;
}

bool equal(int *a, int *b) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            bool eq = 1;
            for (int k = 0; k < 6; k++) {
                if (a[(i + k) % 6] != b[(j + k) % 6]) {
                    eq = 0;
                    break;
                }
            }
            if (eq) return 1;
            eq = 1;
            for (int k = 0; k < 6; k++) {
                if (a[(i + k) % 6] != b[(j - k + 6) % 6]) {
                    eq = 0;
                    break;
                }
            }
            if (eq == 1) return 1;
        }
    }
    return 0;
}

bool insert(int *a) {
    int val = H(a);
    for (auto i : nodes[val]) {
        if (equal(i.s, a)) {
            return 1;
        }
    }
    node t;
    memcpy(t.s, a, 6 * sizeof(int));
    nodes[val].pb(t);
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a[6];
        for (int j = 0; j < 6; j++) {
            cin >> a[j];
        }
        if (insert(a)) {
            cout << "Twin snowflakes found." << endl;
            exit(0);
        }
    }
    cout << "No two snowflakes are alike." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (T --) {
        solve();
    }

    return 0;
}
/*
* Note is here:
* */
