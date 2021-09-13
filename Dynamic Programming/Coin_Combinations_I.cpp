// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <complex>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <list>
// #include <chrono>
// #include <random>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <iomanip>
// #include <fstream>

// using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef long long ll;
// typedef long double ld;
// typedef pair<int, int> p32;
// typedef pair<ll, ll> p64;
// typedef pair<double, double> pdd;
// typedef vector<ll> v64;
// typedef vector<int> v32;
// typedef vector<vector<int>> vv32;
// typedef vector<vector<ll>> vv64;
// typedef vector<vector<p64>> vvp64;
// typedef vector<p64> vp64;
// typedef vector<p32> vp32;
// int MOD = 1000000007;
// double eps = 1e-12;
// #define forn(i, e) for (ll i = 0; i < e; i++)
// #define forsn(i, s, e) for (ll i = s; i < e; i++)
// #define rforn(i, s) for (ll i = s; i >= 0; i--)
// #define rforsn(i, s, e) for (ll i = s; i >= e; i--)
// #define ln "\n"
// #define dbg(x) cout << #x << " = " << x << ln
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
// #define fast_cin()                    \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())
// /*
// pbds arr;
// pbds.insert(value);
// cout<<*arr.find_by_order(k)<<endl;->(k+1)Th largerst element (0-based Indexing) 1 2 5 -> (2)--> 5
// cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
// Time Complexity ->O(logn)
// */

// void solve()
// {
// }
// int main()
// {
//     fast_cin();
//     ll n, sum;
//     cin >> n >> sum;
//     v32 arr(n);
//     forn(i, n) cin >> arr[i];
//     // vv32 dp(n + 1, v32(sum + 1));
//     // for (int i = 0; i <= n; i++)
//     //     dp[i][0] = 1;
//     // forsn(j, 1, sum + 1) dp[0][j] = 0;
//     v32 dp(sum + 1);
//     dp[0] = 1;
//     forsn(j, 1, sum + 1)
//     {
//         forsn(i, 1, n + 1)
//         {
//             if (arr[i - 1] <= j)
//                 dp[j] = (dp[j] % MOD + dp[j - arr[i - 1]] % MOD) % MOD;
//             // dp[i][j] = (dp[i][j - arr[i - 1]] + dp[i - 1][j]) % MOD;
//             //else
//             //dp[i][j] = (dp[i - 1][j]) % MOD;
//         }
//     }

//     //cout << dp[n][sum] % MOD << endl;
//     cout << dp[sum] % MOD << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "")
{ // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0); // see Fast Input & Output
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll dp[1000001];

const int MOD = (int)1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vi coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int weight = 0; weight <= x; weight++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (weight - coins[i - 1] >= 0)
            {
                dp[weight] += dp[weight - coins[i - 1]];
                dp[weight] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}