#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        vector<int> fre1(26, 0);
        for(auto &it : s1){
            if(it >= 'A' && it <= 'Z') fre1[it - 'A']++;
            if(it >= 'a' && it <= 'z') fre1[it - 'a']++;
        }
        for(auto &it : s2){
            if(it >= 'A' && it <= 'Z') fre1[it - 'A']--;
            if(it >= 'a' && it <= 'z') fre1[it - 'a']--;
        }
        bool isFind = true;
        for(int i = 0; i < 26; i++) if(fre1[i]) isFind = false;
        cout << "Case " << ++cs << ": " << (isFind ? "Yes" : "No") << "\n";
    }
    return 0;
}