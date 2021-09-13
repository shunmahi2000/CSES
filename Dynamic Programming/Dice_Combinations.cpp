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
ll mod = 1000000007;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
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
cout<<*arr.find_by_order(k)<<endl;->(k+1)Th largerst element (0-based Indexing) 1 2 5 ->if9 (2)--> 5
cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
Time Complexity ->O(logn)
*/
vector<int> mp;
ll solve(ll n)
{
    if (mp[n] != -1)
    {
        return mp[n];
    }
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
        return 0;
    ll temp = 0;
    for (int i = 1; i <= 6; i++)
    {
        temp = (temp + solve(n - i)) % mod;
    }
    mp[n] = temp;
    return temp;
}
int main()
{
    fast_cin();
    ll n;
    mp.resize(1000001, -1);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i <= 6)
        {
            mp[i] = sum + 1;
            sum += mp[i];
        }
        else
        {
            mp[i] = sum;
            sum = (sum + mp[i]) % mod;
            sum = (sum - mp[i - 6]) % mod;
        }
    }
    cout << mp[n] << endl;
    return 0;
}
/*
https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array#:~:text=3%20Answers&text=You%20can%20store%20as%20many,cannot%20do%20it%20like%20that.
If we use recursion stack becomes full and our program crashes abruptly
vector->dynamic allocation means heap allocation
stack size <<<< heap size
*/