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
typedef pair<int, int> p32;
typedef tree<p32, null_type, less<p32>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
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

int main()
{
    fast_cin();
    ll n, k;
    cin >> n >> k;
    v64 v(n);
    forn(i, n) cin >> v[i];
    map<int, int> mp;
    vector<int> ans;
    pbds p;
    int t;
    if (k % 2 == 0)
    {
        t = k / 2 - 1;
    }
    else
    {
        t = (k / 2);
    }
    forn(i, k)
    {
        mp[v[i]]++;
        p.insert({v[i], mp[v[i]]});
    }
    auto it = p.find_by_order(t);

    cout << it->first << " ";
    for (int i = k; i < n; i++)
    {
        p.erase(p.find({v[i - k], mp[v[i - k]]}));
        mp[v[i - k]]--;
        mp[v[i]]++;
        p.insert({v[i], mp[v[i]]});
        auto it = p.find_by_order(t);
        cout << it->first << " ";
    }

    return 0;
}