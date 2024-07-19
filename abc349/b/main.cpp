#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;

    int len = S.length();
    vector<int> cnt(26, 0);
    for (int i = 0; i < len; i++) cnt[S[i] - 'a']++;
    vector<int> ans(len + 1, 0);
    for (int i = 0; i < 26; i++) ans[cnt[i]]++;
    int i;
    for (i = 1; i <= len; i++) {
        if (ans[i] != 0 && ans[i] != 2) break; 
    }

    if (i == len + 1)  cout << "Yes" << endl;
    else cout << "No" << endl;

    //for (int i = 1; i <= len; i++) cout << ans[i] << endl;
    //cout << len << endl;
}
