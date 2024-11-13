#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.size();
    ll ans = 0;
    for (int i = 0; i < (1 << N - 1); i++) {
        vector<int> a;
        a.push_back(0);
        for (int j = 0; j < N - 1; j++) {
            if (i >> j & 1) {
                a.push_back(j + 1);
            }
        }
        a.push_back(N);
        ll sum = 0;
        for (int j = 0; j < a.size() - 1; j++) {
            sum += stoll(S.substr(a[j], a[j + 1] - a[j]));
        }
        ans += sum;
    }
    cout << ans << endl;
}
