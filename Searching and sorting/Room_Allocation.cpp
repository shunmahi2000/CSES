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

bool compare(pair<int, char> a, pair<int, char> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<pair<int, char>> v;
    vector<pair<int, int>> arr;
    multimap<int, int> mp2, departure;
    map<int, int> mp3;
    forn(i, n)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 'a'});
        v.push_back({b, 'd'});
        mp2.insert({a, b});
        arr.push_back({a, b});
        departure.insert({b, a});
    }

    sort(v.begin(), v.end(), compare);
    int room = 0;
    int resRoom = 0;
    multimap<pair<int, int>, int> mp;
    list<int> q;
    forn(i, 2 * n)
    {
        cout << v[i].first << " " << v[i].second << endl;
        if (v[i].second == 'a')
        {
            room++;
            if (room > resRoom)
            {
                q.push_back(room);
                auto it = mp2.find(v[i].first);
                mp3[it->first] = room;
                mp.insert({{it->first, it->second}, room});
                mp2.erase(mp2.find(v[i].first));
            }
            else
            {

                mp3[v[i].first] = q.back();
                auto it = mp2.find(v[i].first);
                mp.insert({{it->first, it->second}, q.back()});
                mp2.erase(mp2.find(v[i].first));
                //q.push_back( q.back());
            }
        }
        else
        {
            room--;
            auto val = departure.find(v[i].first);
            departure.erase(departure.find(v[i].first));
            int roomAlloted = mp3[val->second];
            q.remove(roomAlloted);
            q.push_back(roomAlloted);
        }
        resRoom = max(resRoom, room);
    }
    cout << resRoom << endl;
    for (int i = 0; i < n; i++)
    {
        auto it = mp.find(arr[i]);
        cout << it->second << " ";
        mp.erase(mp.find(arr[i]));
    }
    return 0;
}