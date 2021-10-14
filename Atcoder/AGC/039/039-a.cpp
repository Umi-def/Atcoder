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

ll fact_mod(ll n, ll mod)
{
    ll f = 1;
    for (ll i = 2; i <= n; i++)
        f = f * (i % mod) % mod;
    return f;
}
ll modpow(ll x, ll n, ll mod)
{
    if (n == 0)
        return 1;
    ll res = modpow((x * x) % mod, n / 2, mod);
    if (n & 1)
        res = (res * x) % mod;
    return res;
}
ll modncr(ll n, ll r, ll mod)
{
    if (r > n - r)
        r = n - r;
    if (r == 0)
        return 1;
    ll a = 1;
    rep(i, r) a = a * ((n - i) % mod) % mod;
    ll b = modpow(fact_mod(r, mod), mod - 2, mod);
    return (a % mod) * (b % mod) % mod;
}
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll nlcm(vector<ll> numbers)
{
    ll res;
    res = numbers[0];
    for (ll i = 1; i < (ll)numbers.size(); i++)
    {
        res = lcm(res, numbers[i]);
    }
    return res;
}

uintmax_t ncr(unsigned int n, unsigned int r)
{
    if (r * 2 > n)
        r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor = 1;
    for (unsigned int i = 1; i <= r; ++i)
    {
        dividend *= (n - i + 1);
        divisor *= i;
    }
    return dividend / divisor;
}

signed main(void)
{

    string s, s1;
    ll k, f = 0, m = 0, e = 0;
    cin >> s >> k;
    s1 = s;
    rrep(i, s.size() - 1)
    {
        if (s[i - 1] == s[i])
        {
            if (s[0] == s[i] && s[i + 1] != s[0])
                e = i;
            m++;
            s[i] = 'W';
        }
    }

    if (s[0] == s[s.size() - 1] && e % 2 == 0)
        f = m + 1;
    else
        f = m;
    Sort(s1);
    //debug(s.size(), k, (s.size() * k), (s.size() * k) / 2);
    //debug(s1[0], s1[s.size() - 1]);
    if (s1[0] == s1[s.size() - 1])
    {
        mes((s.size() * k) / 2);
        re0;
    }

    if (s.size() == 1)
    {
        mes(k / 2);
        re0;
    }
    mes(f * (k - 1) + m * 1);
}
