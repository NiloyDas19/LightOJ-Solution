#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll nums[101], n, dp[105][105][2];

ll f(ll l, ll r, ll op){
    if(l > r) return 0;
    if(dp[l][r][op] != INT64_MAX) return dp[l][r][op];
    ll re;
    if(op == 0){
        re = INT32_MIN;
        ll sum = 0;
        for(int i = l; i <= r; i++){
            sum += nums[i];
            re = max(re , sum + f(i + 1, r, op^1));
        }
        sum = 0;
        for(int i = r; i >= l; i--){
            sum += nums[i];
            re = max(re, sum + f(l, i - 1, op^1));
        }
    }
    else{
        re = INT32_MAX;
        ll sum = 0;
        for(int i = l; i <= r; i++){
            sum += nums[i];
            re = min(re , -sum + f(i + 1, r, op^1));
        }
        sum = 0;
        for(int i = r; i >= l; i--){
            sum += nums[i];
            re = min(re, -sum + f(l, i - 1, op^1));
        }
    }
    return dp[l][r][op] = re;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) dp[i][j][0] = dp[i][j][1] = INT64_MAX;
        }
        cout << "Case " << ++cs <<  ": ";
        cout << f(0 , n-1 , 0) << "\n";
    }
    return 0;
}