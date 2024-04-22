#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9 + 7;

// Point update and range query.
ll bit[100005] , n;
void update(int i,ll val){
    for(;i<=n;i+=(i&(-i))){
        bit[i] += val;
        bit[i] %= mod;
    }
}
ll sum(int i){
    ll re = 0;
    for(;i>0;i-=(i&(-i))){
        re+=bit[i];
        re %= mod;
    }
    return re;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--){
        ll sz; cin >> sz;
        vector<ll> v(sz);
        for(int i = 0; i <= sz + 2; i++) bit[i] = 0;
        unordered_map<ll,ll> num;
        for(auto &it : v) cin >> it;
        
        vector<ll> cpy = v;
        sort(cpy.begin(), cpy.end());

        ll pos = 0;
        for(auto &it : cpy){
            if(num[it] == 0){
                num[it] = ++pos;
            }
        }

        n = pos;
        

        ll ans = 0;
        for(int i = 0; i < sz; i++){
            ll val = sum(num[v[i]]-1);
            val++;
            ans += val;
            ans %= mod;
            update(num[v[i]], val);
        }
        cout << "Case " << ++cs << ": ";
        cout << ans << "\n";
    }
    return 0;
}