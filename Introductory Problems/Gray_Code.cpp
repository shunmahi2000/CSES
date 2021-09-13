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
vector<string> solve(ll n)
{
    if (n == 1)
    {
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    vector<string> tans = solve(n - 1);
    vector<string> ans;
    for (int i = 0; i < tans.size(); i++)
    {
        ans.push_back("0" + tans[i]);
    }
    for (int i = tans.size() - 1; i >= 0; i--)
    {
        ans.push_back("1" + tans[i]);
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vector<string> res = solve(n);
    for (auto it : res)
    {
        cout << it << endl;
    }

    return 0;
}
/*
pbds arr;
pbds.insert(value);
cout<<*arr.find_by_order(k)<<endl;->kTh largerst element 
cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
Time Complexity ->O(logn)
 */