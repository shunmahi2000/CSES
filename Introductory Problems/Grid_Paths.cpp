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
    queue<pair<int,int>> q;
    q.push({0,0});
    int ans=0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pair<int,int> p=q.front();
            q.pop();
            if(s[lvl]=='?'){
                for(int i=0;i<4;i++){
                    int nx=
                }
            }else{
                pair<int,int> t=mp[s[lvl]];
                int nx=p.first+t.first;
                int ny=p.second+t.second;
                if(isValid(nx,ny)){
                    q.push({nx,ny});
                }
            }
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