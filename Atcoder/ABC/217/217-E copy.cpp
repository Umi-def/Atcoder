#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#include <limits>
#include <math.h>
#pragma GCC optimize("Ofast")
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;

typedef cpp_int BigNum;
typedef cpp_dec_float_100 PreciseFloat;
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;

#define rep(i, n) for (int i = 0; i < (ll)(n); ++i)
#define rrep(i, n) for (int i = 1; i <= (ll)(n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define CHOOSE3(a) CHOOSE4 a
#define CHOOSE4(a0, a1, a2, x, ...) x
#define mes_1(a) cout << (a) << endl
#define mes_2(a, b) cout << (a) << " " << (b) << endl
#define mes_3(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define mes(...)                                   \
    CHOOSE3((__VA_ARGS__, mes_3, mes_2, mes_1, ~)) \
    (__VA_ARGS__)
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cout << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << endl
#define debug_4(x1, x2, x3, x4) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define debug(...)                                                        \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)

#define Ynmes(a) (a) ? mes("Yes") : mes("No")
#define YNmes(a) (a) ? mes("YES") : mes("NO")
#define ynmes(a) (a) ? mes("yes") : mes("no")
#define re0 return 0
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define rSort(a) sort(a.rbegin(), a.rend())
#define Rev(a) reverse(a.begin(), a.end())
#define MATHPI acos(-1)
#define itn int;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
struct io
{
    io()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const ll MAX = 200000;
// ll a[200000];          // キューを表す配列
// ll tail = 0, head = 0; // キューの要素区間を表す変数

// // キューを初期化する
// void init()
// {
//     head = tail = 0;
// }

// // キューが空かどうかを判定する
// bool isEmpty()
// {
//     return (head == tail);
// }

// // スタックが満杯かどうかを判定する
// bool isFull()
// {
//     return (head == (tail + 1) % MAX);
// }

// // enqueue (tail に要素を格納してインクリメント)
// void enqueue(ll v)
// {
//     if (isFull())
//     {
//         cout << "error: queue is full." << endl;
//         return;
//     }
//     a[tail++] = v;
//     if (tail == MAX)
//         tail = 0; // リングバッファの終端に来たら 0 に
// }

// // dequeue (head にある要素を返して head をインクリメント)
// ll dequeue()
// {
//     if (isEmpty())
//     {
//         cout << "error: stack is empty." << endl;
//         return -1;
//     }
//     ll res = a[head];
//     ++head;
//     if (head == MAX)
//         head = 0;
//     return res;
// }
signed main(void)
{
    priority_queue<ll, vector<ll>, greater<ll>> sa;

    queue<ll> a;

    ll q, x = 0;
    cin >> q;
    bool f = 0;
    vll sx;
    ll n = 0;
    rep(i, q)
    {
        ll c;

        cin >> c;
        if (c == 1)
        {
            cin >> x;
            sx[n] = x;
            a.push(x);

            n++;
            debug(n);
        }
        else if (c == 2)
        {
            if (f == 1)
            {
                mes(sa.top());
                sa.pop();
            }
            else
            {
                mes(a.front());
                a.pop();
            }
        }
        else if (c == 3)
        {
            rep(k, n)
            {
                sa.push(sx[k]);
            }
            n = 0;
            f = 1;
        }
    }
}
