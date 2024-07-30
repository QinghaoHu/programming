#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int) x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

arr<char, 4> A {{'N', 'S', 'W', 'E'}};
arr<char, 4> a {{'n', 's', 'w', 'e'}};
int r, c, num = 0;
arr<arr<int, 2>, 4> d {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
arr<arr<char, 30>, 30> s;
string temp;

struct P {
    int x, y, px, py;
    string ans;
};

bool pd(int x, int y) {

}

string bfs1() {
    P st;
    st.x = st.y = st.py = 1;
    st.ans = " ";

}

void Pushing_Boxes() {
    rep(i, 1, r + 1) {
        rep(j, 1, c + 1) {
            cin >> s[i][j];
        }
    }
    cout << "Maze #" << ++num << "\n" << bfs1() << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> r >> c, r || c) {
        Pushing_Boxes();
    }

    return 0;
}