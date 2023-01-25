#include <bits/stdc++.h>
using namespace std;
vector<bool> check;
vector<vector<int>> tg;
void catch_nodes(int x, int y)
{
    tg[x].push_back(y);
    tg[y].push_back(x);
}
void dfs(int x)
{
    check[x] = true;
    for (int i = 0; i < tg[x].size(); i++)
    {
        if (!check[tg[x][i]])
        {
            cout << tg[x][i] << " ";
            dfs(tg[x][i]);
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
    cout << "0"
         << " ";
    for (int i = 0; i < n; ++i)
    {
        if (check[i] == false)
        {
            dfs(i);
        }
    }
    return 0;
}
