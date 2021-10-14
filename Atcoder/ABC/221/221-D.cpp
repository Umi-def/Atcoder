#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

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
typedef vector<vector<bool>> vvb;

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

#define ynmes(a) (a) ? mes("Yes") : mes("No")
#define YNmes(a) (a) ? mes("YES") : mes("NO")
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

ll modpow(ll x, ll y)
{
    if (y == 1)
    {
        return x;
    }
    ll ans;
    if (y % 2 == 1)
    {
        ll r = modpow(x, (y - 1) / 2);
        ans = r * r % MOD;
        ans = ans * x % MOD;
    }
    else
    {
        ll r = modpow(x, y / 2);
        ans = r * r % MOD;
    }
    return ans;
}

ll modncr(ll N, ll K)
{
    ll res = 1;
    ll p = 1;
    for (ll n = 0; n < K; ++n)
    {
        res = (res * (N - n)) % MOD;
        p = (p * (n + 1)) % MOD;
    }
    return (res * modpow(p, MOD - 2)) % MOD;
}

signed main()
{
    ll n;
    cin >> n;
    vll a(n), b(n);

    vll r(n + 1, 0);
    map<ll, ll> mp;
    rep(i, n)
    {
        cin >> a[i] >> b[i];
        mp[a[i]] += 1;
        mp[a[i] + b[i]] -= 1;
    }

    vll rs((ll)mp.size() + 1, 0);
    ll cur = 0;

    vll list;

    for (auto i : mp)
    {
        rs[cur + 1] = rs[cur] + i.second;
        cur++;
        list.pb(i.first);
    }

    rep(i, (ll)mp.size())
    {
        r[rs[i]] += list[i] - list[i - 1];
    }
    rrep(i, n)
    {
        cout << r[i] << " ";
    }
}
