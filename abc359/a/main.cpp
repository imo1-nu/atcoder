#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> s(n);
    int cnt = 0;
    string a = "Takahashi";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == a) cnt++;
    }
    cout << cnt << endl;
}
