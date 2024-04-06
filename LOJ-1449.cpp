#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--){
        string s; cin >> s;
        if(s[4] != 's'){
            string last = s.substr(4);
            s = "https" + last;
        }
        cout << "Case " << ++cs << ": " << s << "\n";
    }
    return 0;
}