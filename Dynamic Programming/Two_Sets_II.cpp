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
int MOD = 1000000007;
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
//How to find Modular inverse of any Number???
//->Code
ll power(ll a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans % MOD * a % MOD) % MOD;
        a = (a % MOD * a % MOD) % MOD;
        b = b >> 1;
    }
    return ans % MOD;
}
int main()
{
    fast_cin();
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    //cout << sum << endl;
    if (sum % 2 != 0)
    {
        cout << "0" << endl;
    }
    else
    {
        int val = (sum / 2) + 1;
        vv64 dp(n + 1, v64(val, 0));
        forn(i, n + 1) dp[i][0] = 1;
        forsn(i, 1, n + 1)
        {
            forsn(j, 1, val)
            {
                if (i <= j)
                {
                    dp[i][j] = (dp[i - 1][j - i] + dp[i - 1][j]) % MOD;
                }
                else
                    dp[i][j] = (dp[i - 1][j]) % MOD;
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        cout << ((dp[n][val - 1] % MOD) * (500000004 % MOD)) % MOD << endl;
    }
}