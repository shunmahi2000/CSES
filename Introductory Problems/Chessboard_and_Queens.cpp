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
int ans = 0;
bool isValid(int x, int y, vector<vector<char>> &board)
{
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == '@')
            return false;
    }
    for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] == '@')
            return false;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        if (board[i][y] == '@')
            return false;
    }
    return true;
}
void solve(vector<vector<char>> &board, int cur)
{
    if (cur == 8)
    {
        ans++;
        return;
    }
    for (int j = 0; j < 8; j++)
    {
        if (board[cur][j] == '.')
        {
            if (isValid(cur, j, board))
            {
                board[cur][j] = '@';
                solve(board, cur + 1);
                board[cur][j] = '.';
            }
        }
    }
}
int main()
{
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(board, 0);
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