#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, k;

void f(int len, string &s, vector<bool> &vis){
    if(!k) return;
    if(len == n){
        cout << s << "\n";
        k--;
        return;
    }

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        char ch = (char)(i + 'A');
        s.push_back(ch);
        vis[i] = true;
        f(len + 1, s, vis);
        vis[i] = false;
        s.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s;
        vector<bool> vis(n, false);
        cout << "Case " << ++cs << ":\n";
        f(0, s, vis);
    }
    return 0;
}