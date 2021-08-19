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
    ll sum = (n) * (n + 1) / 2;
    if (sum % 2 != 0)
        cout << "NO" << endl;
    else
    {
        sum = sum / 2;
        cout << "YES" << endl;
        vector<bool> v(n, false);
        int i = n - 1;
        int size = 0;
        while (sum != 0)
        {
            if (sum >= (i + 1))
            {
                sum -= (i + 1);
                v[i] = true;
                size++;
            }
            i--;
        }
        ll check1 = 0, check2 = 0;
        cout << size << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == true)
            {
                //check1 += (i + 1);
                cout << (i + 1) << " ";
            }
        }
        // cout << check1 << endl;
        cout << endl;
        int newsize = n - size;
        cout << newsize << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == false)
            {
                //check2 += (i + 1);
                cout << (i + 1) << " ";
            }
        }
        //cout << check2 << endl;
        cout << endl;
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