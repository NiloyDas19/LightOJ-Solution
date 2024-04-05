#include<bits/stdc++.h>
using namespace std;

using ll = long long;
string s1, s2, s3;
int dp[51][51][51];

int lcs(int i, int j, int k){
    if(i == 0 || j == 0 || k == 0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int re = INT32_MIN;
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
        re = 1 + lcs(i-1, j-1, k-1);
    }
    else{
        re = max(re, lcs(i-1, j, k));
        re = max(re, lcs(i, j-1, k));
        re = max(re, lcs(i, j, k-1));
        re = max(re, lcs(i-1, j-1, k));
        re = max(re, lcs(i-1, j, k-1));
        re = max(re, lcs(i, j-1, k-1));
    }
    return dp[i][j][k] = re;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--){
        cin >> s1 >> s2 >> s3;
        int n = s1.size() , m = s2.size(), o = s3.size();
        memset(dp, -1, sizeof dp);
        cout << "Case " << ++cs << ": " << lcs(n, m, o) << "\n";
    }
    return 0;
}