#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> coins;
ll n, k;

void f(int i, ll sum, ll len, vector<ll> &temp)
{
    if (i >= len)
    {
        if (sum)
            temp.push_back(sum);
        return;
    }
    f(i + 1, sum, len, temp);
    f(i + 1, sum + coins[i], len, temp);
    f(i + 1, sum + 2 * coins[i], len, temp);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        coins.resize(n);
        for (auto &coin : coins)
            cin >> coin;

        // Used meet in the middle technique
        vector<ll> first, last;
        f(0, 0, n / 2, first);
        f(n / 2, 0, n, last);
        sort(last.begin(), last.end());
        sort(first.begin(), first.end());

        bool ans = false;
        for (auto &val : first)
        {
            if (val == k)
                ans = true;
            ll tar = k - val;
            auto it = lower_bound(last.begin(), last.end(), tar);
            if (it != last.end() && *it == tar)
                ans = true;
        }
        for (auto &val : last)
        {
            if (val == k)
                ans = true;
            ll tar = k - val;
            auto it = lower_bound(first.begin(), first.end(), tar);
            if (it != first.end() && *it == tar)
                ans = true;
        }
        cout << "Case " << ++cs << ": ";
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}