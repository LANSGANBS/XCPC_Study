#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, L, R;
        cin >> n >> L >> R;
        vector<int> errors(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> errors[i];
        }

        int max_error = INT_MIN;
        int min_error = INT_MAX;

        for (int len = L; len <= R; ++len)
        {
            int current_sum = 0;
            for (int i = 0; i < len; ++i)
            {
                current_sum += errors[i];
            }
            max_error = max(max_error, abs(current_sum));
            min_error = min(min_error, abs(current_sum));

            for (int i = len; i < n; ++i)
            {
                current_sum += errors[i] - errors[i - len];
                max_error = max(max_error, abs(current_sum));
                min_error = min(min_error, abs(current_sum));
            }
        }

        cout << max_error << " " << min_error << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}