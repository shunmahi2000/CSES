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
    int n, m;
    cin >> n >> m;
    map<int, int> priceOfTicket;
    vi customers(m);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        priceOfTicket[a]++;
    }
    for (int i = 0; i < m; i++)
        cin >> customers[i];
    for (int i = 0; i < m; i++)
    {
        auto it = priceOfTicket.upper_bound(customers[i]);
        if (it == priceOfTicket.begin())
            cout << "-1" << endl;
        else
        {
            it--;
            cout << (it->first) << endl;
            int val = it->first;
            priceOfTicket[val]--;
            if (priceOfTicket[val] == 0)
                priceOfTicket.erase(val);
        }
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