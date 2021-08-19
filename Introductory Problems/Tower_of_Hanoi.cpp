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
void solve(int a, int b, int c, int n, vvi &ans)
{
    if (n == 1)
    {
        ans.push_back({a, b});
        return;
    }
    solve(a, c, b, n - 1, ans);
    ans.push_back({a, b});
    solve(c, b, a, n - 1, ans);
}

int main()
{
    int n;
    cin >> n;
    vvi ans;
    solve(1, 3, 2, n, ans);
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << endl;
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