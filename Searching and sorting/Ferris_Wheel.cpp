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

int main()
{
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    pair<ll, ll> sum;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (sum.second == 1)
        {
            sum.first += v[i];
            sum.second += 1;
            if (sum.first <= x)
            {
                sum = {0, 0};
            }
            else
            {
                sum = {v[i], 1};
            }
            ans++;
        }
        else
        {
            sum = {v[i], 1};
        }
    }
    if (sum.second == 1)
        ans++;
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