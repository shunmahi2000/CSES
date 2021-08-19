#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pqi priority_queue<int>
#define pqii priority_queue<int, vector<int>, greater<int>>
#define mod 1000000007
#define vvi vector<vector<int>>
#define ll long long

int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll sum = 0;
    sort(v.begin(), v.end());
    if (n % 2 == 0)
    {
        sum = ceil(((double)v[n / 2] + (double)v[n / 2 - 1]) / (double)2);
    }
    else
    {
        sum = v[n / 2];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(sum - v[i]);
    }
    cout << ans << endl;
    return 0;
}