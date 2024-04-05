#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, c, d, e, f;
ll dp[10005];
ll mod = 10000007;

ll fn(ll n)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;
    if (n == 3)
        return d;
    if (n == 4)
        return e;
    if (n == 5)
        return f;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (((((fn(n - 1) % mod + fn(n - 2) % mod) % mod + fn(n - 3) % mod) % mod + fn(n - 4) % mod) % mod + fn(n - 5) % mod) % mod + fn(n - 6) % mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, cases;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        cin >> a >> b >> c >> d >> e >> f >> n;
        memset(dp, -1, sizeof(dp));
        cout << "Case " << caseno << ": ";
        cout << fn(n) % 10000007 << "\n";
    }
    return 0;
}
