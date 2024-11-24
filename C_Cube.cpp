#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2.01e5;
const int M = 1.01e3;
const int mod = 998244353;
#define endl '\n'
const int inf = 0x7fffffff;

int n;
int grid[12][12][12];
vector<vector<tuple<int, int, int>>> sorted_choices;
int min_sum = 0x7fffffff;
int min_possible[12];
unordered_map<int, int> memo;

void solve()
{
    cin >> n;
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int z = 0; z < n; ++z)
            {
                cin >> grid[x][y][z];
            }
        }
    }
    sorted_choices.assign(n, vector<tuple<int, int, int>>());
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int z = 0; z < n; ++z)
            {
                sorted_choices[x].emplace_back(y, z, grid[x][y][z]);
            }
        }
        sort(sorted_choices[x].begin(), sorted_choices[x].end(), [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b) -> bool
             { return get<2>(a) < get<2>(b); });
        min_possible[x] = get<2>(sorted_choices[x][0]);
    }
    min_sum = inf;
    function<void(int, int, int, int)> dfs = [&](int x, int y_mask, int z_mask, int current_sum) -> void
    {
        if (x == n)
        {
            if (current_sum < min_sum)
            {
                min_sum = current_sum;
            }
            return;
        }
        int state = (x << 24) | (y_mask << 12) | z_mask;
        if (memo.count(state) && memo[state] <= current_sum)
        {
            return;
        }
        memo[state] = current_sum;
        if (current_sum + min_possible[x] >= min_sum)
        {
            return;
        }
        for (auto &[y, z, val] : sorted_choices[x])
        {
            if (!(y_mask & (1 << y)) && !(z_mask & (1 << z)))
            {
                int new_sum = current_sum + val;
                if (new_sum >= min_sum)
                {
                    continue;
                }
                dfs(x + 1, y_mask | (1 << y), z_mask | (1 << z), new_sum);
            }
        }
    };
    dfs(0, 0, 0, 0);
    if (min_sum < inf)
    {
        cout << min_sum << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}