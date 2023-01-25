#include <bits/stdc++.h>
using namespace std;
vector<bool> check;
vector<vector<int>> tg;
void catch_nodes(int x, int y)
{
    tg[x].push_back(y);
}
void dfs(int x)
{
    queue<int> myque; // dfs use queue
    myque.push(x);
    check[x] = true;
    while (!myque.empty())
    {
        int temp = myque.front();
        cout << temp << " ";
        myque.pop();
        for (auto i : tg[temp])
        {
            if (check[i] == false)
            {
                check[i] = true;
                myque.push(i);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> tg2(n, vector<int>());
    tg = tg2;
    check.assign(n, false);
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        catch_nodes(a, b);
    }
    for (int i = 0; i < n; ++i)
    {
        if (check[i] == false)
        {
            dfs(i);
        }
    }
    return 0;
}
