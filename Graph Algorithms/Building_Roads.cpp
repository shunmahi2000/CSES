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
typedef vector<char> vchar;
typedef vector<bool> vbool;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<vector<char>> vvchar;
typedef vector<vector<bool>> vvbool;
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
int find(int a, v32 &parent)
{
    if (parent[a] == a)
        return a;
    else
    {
        parent[a] = find(parent[a], parent);
        return parent[a];
    }
}
void union_do(int a, int b, v32 &parent, v32 &rank)
{
    int aP = find(a, parent);
    int bP = find(b, parent);
    if (aP == bP)
        return;
    int aR = rank[a];
    int bR = rank[b];
    if (aR <= bR)
    {
        parent[aP] = bP;
        rank[aP]++;
    }
    else
    {
        parent[bP] = aP;
        rank[bP]++;
    }
}
void union_check(int a, int b, v32 &parent, v32 &rank, int &ans, vv32 &res)
{
    int aP = find(a, parent);
    int bP = find(b, parent);
    if (aP == bP)
        return;
    int aR = rank[a];
    int bR = rank[b];
    ans++;
    res.pb({aP, bP});
    if (aR <= bR)
    {
        parent[aP] = bP;
        rank[aP]++;
    }
    else
    {
        parent[bP] = aP;
        rank[bP]++;
    }
}
int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    vv32 v;
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    v32 parent(n + 1), rank(n + 1);
    forn(i, n + 1) parent[i] = i;
    int ans = 0;
    forn(i, m)
    {
        union_do(v[i][0], v[i][1], parent, rank);
    }
    vector<vector<int>> res;
    for (int i = 1; i < n; i++)
    {
        union_check(i, i + 1, parent, rank, ans, res);
    }
    cout << ans << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}