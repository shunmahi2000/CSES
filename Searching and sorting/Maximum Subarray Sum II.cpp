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

void solve()
{
}
int main()
{
    fast_cin();
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> prefixsum(n + 1);
    prefixsum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        prefixsum[i] = prefixsum[i - 1] + x;
    }
    multiset<ll> curr;
    ll ans = -2e18;
    for (int i = a; i <= n; i++)
    {
        if (i > b)
        {
            curr.erase(curr.find(prefixsum[i - b - 1]));
        }
        curr.insert(prefixsum[i - a]);
        ans = max(ans, prefixsum[i] - *curr.begin());
    }
    cout << ans << "\n";
    return 0;
}

/*
https://discuss.codechef.com/t/help-with-maximum-subarray-sum-ii-from-cses/73404/2
#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
struct minqueue{
    stack<pair<ll,ll>> front, back;
    void push(ll x){
        if(front.empty()){
            front.push({x,x});
            return;
        }
        front.push({x, min(x,front.top().second)});
    }
    void pop(){
        assert(front.size() + back.size());
        if(!back.empty()){
            back.pop();
            return;
        }
        back.push({front.top().first, front.top().first});
        front.pop();
        while(!front.empty()){
            back.push({front.top().first, min(front.top().first, back.top().second)});
            front.pop();
        }
        back.pop();
    }
    ll getmin(){
        assert(front.size() + back.size());
        if(front.empty()){
            return back.top().second;
        }
        if(back.empty()){
            return front.top().second;
        }
        return min(front.top().second, back.top().second);
    }
};
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> prefixsum(n+1);
    prefixsum[0] = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        prefixsum[i] = prefixsum[i-1] + x;
    }
    minqueue curr;
    ll ans = -2e18;
    for(int i=a;i<=n;i++){
        if(i>b){
            curr.pop();
        }
        curr.push(prefixsum[i-a]);
        ans = max(ans, prefixsum[i] - curr.getmin());
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
*/