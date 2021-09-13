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
    int n, targetSum;
    cin >> n >> targetSum;
    vi v(n);
    multimap<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp.insert(pair<int, int>(v[i], i + 1));
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    bool flag = true;
    while (i < j)
    {
        if (v[i] + v[j] == targetSum)
        {
            auto it1 = mp.find(v[i]);
            auto it2 = mp.find(v[j]);
            int val1 = min(it1->second, it2->second);
            int val2 = max(it1->second, it2->second);
            if (v[i] == v[j])
            {
                auto it3 = mp.find(v[i]);
                mp.erase(mp.find(v[i]));
                auto it4 = mp.find(v[i]);
                val1 = min(it3->second, it4->second);
                val2 = max(it3->second, it4->second);
            }

            cout << val1 << " " << val2 << endl;
            flag = false;
            break;
        }
        else if (v[i] + v[j] > targetSum)
            j--;
        else
            i++;
        //cout << "yes<" << endl;
    }
    if (flag)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
/*
pbds arr;
pbds.insert(value);
cout<<*arr.find_by_order(k)<<endl;->kTh largerst element 
cout<<*arr.order_by_key(5)<<endl;->number of elements strictly smaller than k
Time Complexity ->O(logn)
 */