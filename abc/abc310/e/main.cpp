#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            cnt1 += cnt0;
            cnt0 = 1;
        }
        else {
            swap(cnt0, cnt1);
            cnt1++;
        }
        ans += cnt1;
    }
    cout << ans << endl;
}
