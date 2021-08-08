#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

//#define ACL
#ifdef ACL
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#if __has_include("acl-all.h")
#include "acl-all.h" //on Wandbox
using namespace atcoder;
#endif
#endif //#ifdef ACL

typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef pair<ll, ll> pll;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rrep(i, n) for (int i = 1; i <= int(n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = int(n) - 1; i >= 0; --i)

#define MES(a) MES2 a
#define MES2(a0, a1, a2, a3, a4, x, ...) x
#define mes_1(x1) cout << x1 << endl
#define mes_2(x1, x2) cout << x1 << " " << x2 << endl
#define mes_3(x1, x2, x3) cout << x1 << " " << x2 << " " << x3 << endl
#define mes_4(x1, x2, x3, x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl
#define mes_5(x1, x2, x3, x4, x5) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << endl
#define mes(...)                                                \
    CHOOSE((__VA_ARGS__, mes_5, mes_4, mes_3, mes_2, mes_1, ~)) \
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
#define re0 return 0
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define rSort(a) sort(a.rbegin(), a.rend())
#define Rev(a) reverse(a.begin(), a.end())

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

signed main()
{
    string s;
    cin >> s;
    int i = s.size() - 1;
    while (s[i] == '0')
    {
        i--;
    }

    bool flg = true;
    drep(j, i + 1)
    {
        if (s[j] != s[i - j])
            flg = false;
    }

    Ynmes(flg);
}
