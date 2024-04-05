#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--){
        ll n, q; cin >> n >> q;
        vector<ll> v(n);
        for(auto &it : v) cin >> it;
        cout << "Case " << ++cs << ":\n";
        while(q--){
            ll l , r; cin >> l >> r;
            if(l > r) swap(l , r);
            ll up = upper_bound(v.begin(), v.end(), r) - v.begin();
            ll lo = lower_bound(v.begin(), v.end(), l) - v.begin();
            cout << up - lo << "\n";
        }
    }
    return 0;
} 