#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
/*
pbds arr;
pbds.insert(value);
cout<<*arr.find_by_order(k)<<endl;->(k+1)Th largerst element (0-based Indexing) 1 2 5 -> (2)--> 5
cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
Time Complexity ->O(logn)
*/

void solve()
{
}
/*
dp[i][j]-->represents     (array of size i in which last element is j) ---> dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
*/
int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    v32 arr(n);
    forn(i, n) cin >> arr[i];
    vv32 dp(n, v32(m + 1, 0));
    if (arr[0] == 0)
    {
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;
    }
    else
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j - 1 > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        else
        {
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % MOD;
            if (arr[i] - 1 > 0)
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % MOD;
            if (arr[i] + 1 <= m)
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans = (ans % MOD + dp[n - 1][j] % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}