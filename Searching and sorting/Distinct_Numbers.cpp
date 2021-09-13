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
    ll n;
    cin >> n;
    set<ll> st;
    //can't use unorderded set as in worst Case its time complexity becomes O(n),
    // O(n) because of Hashing Techniques like linear probing,quadratic probing,double hashing etc.
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << endl;
    return 0;
}
/*
pbds arr;
pbds.insert(value);
cout<<*arr.find_by_order(k)<<endl;->kTh largerst element 
cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
Time Complexity ->O(logn)
 */