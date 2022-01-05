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
#define N 2e5 + 1
int depth[(int)N];
int dp[(int)N][21];
void dfs(int cur, int par, vv32 &v)
{
    depth[cur] = depth[par] + 1;
    dp[cur][0] = par;
    for (int j = 1; j < 20; j++)
    {
        dp[cur][j] = dp[dp[cur][j - 1]][j - 1];
    }
    for (auto it : v[cur])
    {
        if (it != par)
        {
            dfs(it, cur, v);
        }
    }
}
int distanceBtw(int a, int b)
{
    if (a == b)
        return 0;
    if (depth[a] < depth[b])
        swap(a, b);
    int diff = depth[a] - depth[b];
    int ans = 0;
    for (int j = 19; j >= 0; j--)
    {
        if ((diff >> j) & 1)
        {
            ans += pow(2, j);
            a = dp[a][j];
        }
    }
    if (a == b)
        return ans;
    for (int j = 19; j >= 0; j--)
    {
        if (dp[a][j] != dp[b][j])
        {
            a = dp[a][j];
            b = dp[b][j];
            ans += (2 * pow(2, j));
        }
    }
    ans += 2;
    return ans;
}
int main()
{
    fast_cin();
    int n, q;
    cin >> n >> q;
    vv32 v(n + 1);
    forsn(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, v);
    forn(i, q)
    {
        int a, b;
        cin >> a >> b;
        cout << distanceBtw(a, b) << endl;
    }
    return 0;
}