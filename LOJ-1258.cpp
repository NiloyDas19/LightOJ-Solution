#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1000005;
ll mods[2] = {1000000007,1000000009};
ll bases[2] = {137,281};
ll pwbase[3][MAX];
ll hsh1[2][MAX] , hsh2[2][MAX] , n;

void Preprocess()
{
    pwbase[0][0] = pwbase[1][0] = 1;
    for(int i=0;i<2;i++){
        for(int j=1 ; j < MAX ; j++){
            pwbase[i][j] = (pwbase[i][j-1] % mods[i] * bases[i] % mods[i]) %mods[i];
        }
    }
}


ll GetHash(int i, int j , ll hsh1[][MAX]){
    // assert(i <= j);
    ll temp1 = (hsh1[0][i] - (hsh1[0][j+1] * pwbase[0][j-i+1]) %mods[0]) %mods[0];
    if(temp1 < 0) temp1+=mods[0];
    return temp1;
}



void Build(string &s1 , ll hsh1[][MAX])
{
    for(ll i= n-1; i >= 0 ;i--){
        for(ll j=0 ; j<1 ; j++){
            hsh1[j][i] = (hsh1[j][i + 1] * bases[j] + s1[i]) % mods[j];
            hsh1[j][i] = (hsh1[j][i] + mods[j])%mods[j];
        }
    }
    
}



int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t , j = 0; cin >> t;
    Preprocess();
    while(t--){
        string s; cin >> s;
        n = s.size();
        // memset(hsh1 , 0 , sizeof hsh1);
        // memset(hsh2 , 0 , sizeof hsh2);
        hsh1[0][n] = hsh1[1][n] = hsh2[0][n] = hsh2[1][n] = 0 ;
        Build(s , hsh1);
        reverse(s.begin() , s.end());
        Build(s , hsh2);
        int ans = 2 * n;
        for(int i = n ; i >= 1; i--){
            int half = (i + 1) / 2;
            auto hash1 = GetHash(0LL , half-1 , hsh2);
            auto hash2 = GetHash(n-i , n-i+half-1 , hsh1);
            if(hash1 == hash2){
                ans -= i;
                break;
            }
        }
        cout << "Case " << ++j << ": " << ans << "\n";
    }
    return 0;
}