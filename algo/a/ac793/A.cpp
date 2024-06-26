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
const ll mod = 1e9 + 7;
const db eps = 1e-9;
const int INF = 0x3f3f3f3f;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < SZ(A); i++) {
        if (i < SZ(A)) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while(t) {
        C.pb(t % 10);
        t /= 10;
    }
    while(SZ(C) > 1 && C.back() == 0) C.pop_back();

    return C;
}

void solve() {
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = SZ(a) - 1; i >= 0; i--) {
        A.pb(a[i] - '0');
    }
    auto C = mul(A, b);
    reverse(all(C));
    for (int i : C) {
        cout << i;
    }
    cout << endl;
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
