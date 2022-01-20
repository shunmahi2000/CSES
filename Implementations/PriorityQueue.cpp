#include <bits/stdc++.h>
using namespace std;
class priorityQueue
{
public:
    vector<int> v;
    int sz;
    priorityQueue()
    {
        v.push_back(-1);
        sz = 1;
    }
    void insert(int val)
    {

        v.push_back(val);
        sz++;
        int ind = sz - 1;
        while (ind != 1)
        {
            int prevIndex = ind / 2;
            if (v[prevIndex] > v[ind])
                swap(v[prevIndex], v[ind]);
            ind = prevIndex;
        }
    }
    void pop()
    {
        swap(v[1], v[sz - 1]);
        v.pop_back();
        sz--;
        int ind = 1;
        while (2 * ind < sz || (2 * ind + 1) < sz)
        {
            if (2 * ind < sz && 2 * ind + 1 < sz)
            {
                int mn = min(v[2 * ind], v[2 * ind + 1]);
                if (mn < v[ind])
                {
                    if (mn == v[2 * ind])
                    {
                        swap(v[2 * ind], v[ind]);
                        ind = 2 * ind;
                    }
                    else
                    {
                        swap(v[2 * ind + 1], v[ind]);
                        ind = 2 * ind + 1;
                    }
                }
                else
                    break;
            }
            else if (2 * ind < sz)
            {
                if (v[2 * ind] < v[ind])
                {
                    swap(v[2 * ind], v[ind]);
                    ind = 2 * ind;
                }
                else
                    break;
            }
            else if (2 * ind + 1 < sz)
            {
                if (v[2 * ind + 1] < v[ind])
                {
                    swap(v[2 * ind + 1], v[ind]);
                    ind = 2 * ind + 1;
                }
                else
                    break;
            }
        }
    }
    int top()
    {
        return v[1];
    }
};
int main()
{
    priorityQueue pq;

    pq.insert(3);
    pq.insert(15);
    pq.insert(56);
    pq.insert(32);
    pq.insert(1);
    pq.insert(31);
    pq.pop();
    pq.pop();
    pq.pop();
    vector<int> t = pq.v;
    for (int i = 0; i < t.size(); i++)
        cout << t[i] << " ";
    cout << endl;
    cout << pq.top() << endl;
    return 0;
}