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
bool isValid(int a, int b, int n, int m)
{
    return a >= 0 && b >= 0 && a < n && b < m;
}
int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    int sx, sy, ex, ey;
    vvchar v(n, vchar(m));
    forn(i, n)
    {
        forn(j, m)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (v[i][j] == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }
    vvbool vis(n, vbool(m, false));
    queue<pair<pair<int, int>, string>> q;
    q.push({{sx, sy}, ""});
    bool f = false;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, 1, -1, 0};
    vector<char> dc = {'U', 'R', 'L', 'D'};
    int steps = 0;
    string ans = "";
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            pair<pair<int, int>, string> p = q.front();
            q.pop();
            vis[p.first.first][p.first.second] = true;
            if (p.first.first == ex && p.first.second == ey)
            {
                ans = p.second;
                f = true;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = p.first.first + dx[i];
                int ny = p.first.second + dy[i];
                if (isValid(nx, ny, n, m) && (v[nx][ny] == '.' || v[nx][ny] == 'B') && vis[nx][ny] == false)
                {
                    q.push({{nx, ny}, p.second + dc[i]});
                }
            }
        }
        if (f)
            break;
        steps++;
    }
    if (f)
    {
        cout << "YES" << endl;
        cout << steps << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}