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
const int N = 1e5 + 10;

struct node {
    int val, pos;
    int prev, next;
} nodes[N];

int head, tail, tot;

void init() {
    head = 1, tail = 2;
    tot = 2;
    nodes[head].next = 2;
    nodes[tail].prev = 1;
}

void add(int p, int value, int pos) {
    nodes[++tot].val = value;
    nodes[tot].pos = pos;
    nodes[tot].next = nodes[p].next;
    nodes[nodes[p].next].prev = tot;
    nodes[p].next = tot;
    nodes[tot].prev = p;
}

void del(int p) {
    nodes[nodes[p].prev].next = nodes[p].next;
    nodes[nodes[p].next].prev = nodes[p].prev;
}

void clear() {
    memset(nodes, 0, sizeof nodes);
    head = tail = tot = 0;
}

void solve() {
    int n;
    cin >> n;
    init();
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f;
        a[i].s = i + 1;
    }
    int iToN[N];
    sort(all(a));
    for (int i = 0; i < n; i++) {
        add(nodes[tail].prev, a[i].f, a[i].s);
        iToN[a[i].s] = tot;
    }
    vector<PII> all_ans;
    for (int i = n; i > 1; i--) {
        int g = iToN[i];
        PII ans;
        ans.f = INF;
        if (nodes[g].next != tail) {
            ans = mp(nodes[nodes[g].next].val - nodes[g].val, nodes[nodes[g].next].pos);
        }
        if (nodes[g].prev != head && nodes[g].val - nodes[nodes[g].prev].val <= ans.f) {
            ans = mp(nodes[g].val - nodes[nodes[g].prev].val, nodes[nodes[g].prev].pos);
        }
        all_ans.pb(ans);
        del(g);
    }
    reverse(all(all_ans));
    for (auto i : all_ans) {
        cout << i.f << " " << i.s << endl;
    }
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
