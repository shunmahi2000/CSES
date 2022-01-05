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
#define mpp make_pair
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
map<pair<int, int>, vector<int>> mp;
vector<int> solve(int curInd, int sum, v32 &v)
{
    if (curInd == v.size() - 1)
    {
        vector<int> ans = {v[v.size() - 1] + sum, sum};
        return ans;
    }
    if (mp.find({curInd, sum}) != mp.end())
    {
        return mp[{curInd, sum}];
    }
    vector<int> a = solve(curInd + 1, sum, v);
    vector<int> b = solve(curInd + 1, sum + v[curInd], v);
    for (int i = 0; i < b.size(); i++)
        a.push_back(b[i]);
    mp[{curInd, sum}] = a;
    return a;
}
int main()
{
    fast_cin();
    int n;
    cin >> n;
    v32 v(n);
    int sum = 0;
    forn(i, n)
    {

        cin >> v[i];
        sum += v[i];
    }
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, sum + 1)
        {
            if (v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int count = 0;
    for (int j = 1; j <= sum; j++)
    {
        if (dp[n][j])
            count++;
    }
    cout << count << endl;
    forsn(j, 1, sum + 1)
    {
        if (dp[n][j])
            cout << j << " ";
    }
    return 0;
}