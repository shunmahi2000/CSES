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
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto it : s)
        mp[it]++;
    string fi = "", sec = "";
    bool b = true, f = true;
    char one;
    for (auto it : mp)
    {
        if (it.second % 2 != 0)
        {
            if (b)
            {
                b = false;
                one = it.first;
            }
            else
            {
                f = false;
            }
            int k = it.second;
            k = k / 2;
            char c = it.first;
            for (int i = 0; i < k; i++)
            {
                fi += c;
                sec += c;
            }
        }
        else
        {
            int k = it.second;
            k = k / 2;
            char c = it.first;
            for (int i = 0; i < k; i++)
            {
                fi += c;
                sec += c;
            }
        }
    }
    if (b)
    {
        reverse(sec.begin(), sec.end());
        fi += sec;
        cout << fi << endl;
    }
    else
    {
        if (f)
        {
            reverse(sec.begin(), sec.end());
            fi += one;
            fi += sec;
            cout << fi << endl;
        }
        else
        {
            cout << "NO SOLUTION" << endl;
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