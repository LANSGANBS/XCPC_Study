#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (auto &x : s)
    {
        if (x == '+')
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    cout << abs(ans) << endl;
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}