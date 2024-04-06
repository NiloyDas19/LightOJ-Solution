#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int kmp(string &pattern, string &text)
{
    int n = pattern.size(), i;

    // lps calculation
    vector<int> lps(n);
    int len = 0;
    lps[len] = len;
    for (i = 1; i < n;)
    {
        if (pattern[i] == pattern[len])
        {
            lps[i] = len + 1;
            len++, i++;
        }
        else
        {
            if (len)
                len = lps[len - 1];
            else
                lps[i] = len, i++;
        }
    }

    // pattern finding
    int j = 0, ans = 0;
    for (i = 0; i < text.size();)
    {
        if (text[i] == pattern[j])
            i++, j++;
        else
        {
            if (j)
                j = lps[j - 1];
            else
                i++;
        }

        if (j == n)
        {
            // found the pattern
            // cout << i - n << " ";
            ans++;
            j = lps[j - 1];
        }
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
        string a, b;
        cin >> a >> b;
        cout << "Case " << ++cs << ": " << kmp(b, a)<< "\n";
    }
    return 0;
}