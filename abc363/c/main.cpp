#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    sort(s.begin(), s.end());
    do{
        //cout << s << endl;
        bool ok = false;
        for(int i = 0; i <= n - k; i++){
            int j;
            for (j = 0; j < k / 2; j++) {
                if (s[i + j] != s[i + k - 1 - j]) break;
            }
            if (j == k / 2) ok = true;
        }
        if (!ok) {
            ans++;
            //cout << s << endl;
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
}
