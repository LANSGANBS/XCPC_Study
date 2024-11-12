#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

struct HLD
{
    int n, idx;
    vector<vector<int>> ver;
    vector<int> siz, dep;
    vector<int> top, son, parent;

    HLD(int n)
    {
        this->n = n;
        ver.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);

        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
    }
    void add(int x, int y)
    { // 建立双向边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs1(int x)
    {
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto y : ver[x])
        {
            if (y == parent[x])
                continue;
            parent[y] = x;
            dfs1(y);
            siz[x] += siz[y];
            if (siz[y] > siz[son[x]])
            {
                son[x] = y;
            }
        }
    }
    void dfs2(int x, int up)
    {
        top[x] = up;
        if (son[x])
            dfs2(son[x], up);
        for (auto y : ver[x])
        {
            if (y == parent[x] || y == son[x])
                continue;
            dfs2(y, y);
        }
    }
    int lca(int x, int y)
    {
        while (top[x] != top[y])
        {
            if (dep[top[x]] > dep[top[y]])
            {
                x = parent[top[x]];
            }
            else
            {
                y = parent[top[y]];
            }
        }
        return dep[x] < dep[y] ? x : y;
    }
    int clac(int x, int y)
    { // 查询两点间距离
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    void work(int root = 1)
    { // 在此初始化
        dfs1(root);
        dfs2(root, root);
    }
};

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    HLD tree(n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tree.add(x, y);
    }
    tree.work(s);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << tree.lca(a, b) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}