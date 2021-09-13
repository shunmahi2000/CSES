#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pqi priority_queue<int>
#define pqii priority_queue<int, vector<int>, greater<int>>
#define mod 1000000007
#define vvi vector<vector<int>>
#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll ans = INT_MAX;
ll mxSum;
void solve(vector<ll> &v, ll cur, ll sum)
{
    if (cur == v.size())
    {
        ll newValue = mxSum - sum;
        ans = min(ans, abs(newValue - sum));
        return;
    }
    solve(v, cur + 1, sum + v[cur]);
    solve(v, cur + 1, sum);
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    mxSum = sum;
    solve(v, 0, 0);
    cout << ans << endl;
    return 0;
}
/*
pbds arr;
pbds.insert(value);
cout<<*arr.find_by_order(k)<<endl;->kTh largerst element 
cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
Time Complexity ->O(logn)
 */