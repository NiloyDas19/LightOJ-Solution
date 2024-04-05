#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> LIS(vector<ll> &a)
{
    vector<ll> lis, ans;
    for (auto &it : a)
    {
        int indx = lower_bound(lis.begin(), lis.end(), it) - lis.begin();
        if (indx == (int)lis.size())
            lis.push_back(it);
        else
            lis[indx] = it;
        ans.push_back(indx + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (auto &it : v)
            cin >> it;
        vector<ll> forward = LIS(v);
        reverse(v.begin(), v.end());
        vector<ll> backward = LIS(v);
        reverse(backward.begin(), backward.end());
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, 2 * min(forward[i] - 1, backward[i] - 1) + 1);
        }
        cout << "Case " << ++cs << ": " << ans << "\n";
    }
    return 0;
}